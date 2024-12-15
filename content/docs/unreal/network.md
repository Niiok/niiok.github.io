---
title: "Unreal Network"
author: "Niiok"
categories: ["Unreal"]
date: 2022-05-17T00:00:00+00:00
#draft: true
weight: 1


# searchHidden: true

#cover:
#    image: "<image path/url>"    # can also paste direct link from external site
#    alt: "<alt text>"
#    caption: "<text>"
#    relative: false 	# To use relative path for cover image, used in hugo Page-bundles

#ShowBreadCrumbs: false
---


# Intro
- Unreal network system is based on [Server-Client model](https://docs.unrealengine.com/4.27/InteractiveExperiences/Networking/Server/).
- If developers consider about "Replication", game can support both singleplayer and multiplayer.
- UE4 Clients can not communicate without Server (p2p is not currently supported)



# Struct

## Network Mode
- `ENetMode`
  - `NM_Standalone`
    - Authoritative : true
    - Listening : false
    - LocalPlayer : true
  - `NM_DedicatedServer`
    - Authoritative : true
    - Listening : true
    - LocalPlayer : false
  - `NM_ListenServer`
    - Authoritative : true
    - Listening : true
    - LocalPlayer : true
  - `NM_Client`
    - Authoritative : false
    - Listening : false
    - LocalPlayer : true
  - ~~`NM_MAX`~~

## Role, RemoteRole
- `ENetRole`
  - `ROLE_None`
    - not related with replication
  - `ROLE_SimulatedProxy`
    - copy of `ROLE_Authority`
    - extrapolative-predicted with server values
  - `ROLE_AutonomousProxy`
    - copy of `ROLE_Authority`
    - extrapolative-predicted with server values + local functions (e.g. player input)
    - currently, only for possessed actor with ownership
  - `ROLE_Authority`
    - origin
    - not available for `NM_Client` currently
  - ~~`ROLE_MAX`~~

## Ownership
- PlayerController is root of ownership
  - Pawn that possessed by PlayerController and Actors owned by the Pawn is owned by the Player
  - Subobjects owned by its outer's owner
- needed for
  - Client RPC destination
  - replication relevancy
    - `bOnlyRelevantToOwner`
  - conditional property replication
    - `COND_OwnerOnly`, `COND_InitialOrOwner`, `COND_SkipOwner`
  - `ROLE_AutonomousProxy` to `ROLE_SimulatedProxy`
    - `ROLE_AutonomousProxy` is only allowed for owner client



# Method

## Property Replication
``` C++
class ENGINE_API AActor : public UObject
{
    UPROPERTY( Replicated ) // originally, it's ReplicatedWith specifier
    AActor * Owner;

    UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_ReplicatedMovement, Category=Replication, AdvancedDisplay)
    struct FRepMovement ReplicatedMovement;

    UFUNCTION()
    virtual void OnRep_ReplicatedMovement();
};

void AActor::GetLifetimeReplicatedProps( TArray< FLifetimeProperty > & OutLifetimeProps ) const
{
    DOREPLIFETIME( AActor, Owner );
    DOREPLIFETIME_CONDITION( AActor, ReplicatedMovement, COND_SimulatedOnly );
	// check "UnrealNetwork.h" for more variations
}

void AActor::PreReplication( IRepChangedPropertyTracker & ChangedPropertyTracker )
{
    DOREPLIFETIME_ACTIVE_OVERRIDE( AActor, ReplicatedMovement, bReplicateMovement );
}

void AActor::OnRep_ReplicatedMovement() { ... }
```
- server to client only
- reliable
- `ELifetimeCondition`
  - `COND_None`
  - `COND_InitialOnly`
  - `COND_OwnerOnly`
  - `COND_SkipOwner`
  - `COND_SimulatedOnly`
  - `COND_AutonomousOnly`
  - `COND_SimulatedOrPhysics`
  - `COND_InitialOrOwner`
  - `COND_Custom` + `SetCustonIsActiveOverride(...)`
  - `COND_ReplayOrOwner`
  - `COND_ReplayOnly`
  - `COND_SimulatedOnlyNoReplay`
  - `COND_SimulatedOrPhysicsNoReplay`
  - `COND_SkipReplay`
  - `COND_Never`
  - ~~`COND_Max`~~
- `NetUpdateFrequency`
  - and `MinNetUpdateFrequency` for _Adaptive Network Frequency_
- with `UPROPERTY(replicated)`, UObject references are replicated via `FNetworkGUID`
  - check with `UObject::IsSupportedForNetwork()`
  - refernce replication occurs in one of them :
    - replicated actor
	- stably named actor
	- replicated component
	- stably named component
	- UObject from loaded package
  - "stably named" means
    - existing in both server and client with exactly same name
	- actors from package are stably named (not spawned during gameplay)
	- components under are stably named
	  - from package
	  - added with construction script (static component)
	  - manually marked (via `UActorComponent::SetNetAddressable(...)`)
	    - need same name

## Remote Procedure Call (RPC)
``` C++
UFUNCTION(Server, WithValidation)
void FunctionThatCalledOnServer();

UFUNCTION(Client, Reliable)
void FunctionThatCalledOnOwnerClient();

UFUNCTION(NetMulticast)
void FunctionThatCalledOnEveryActor();

void ClassName::FunctionThatCalledOnServer_Implementation() {}
bool ClassName::FunctionThatCalledOnServer_Validation() {return true;}
void ClassName::FunctionThatCalledOnOwnerClient_Implementation() {}
void ClassName::FunctionThatCalledOnEveryActor_Implementation() {}
```
- Only executed on Actor that is replicating
- If you want to make sure RPC executed. you should set `Reliable` specifier on RPC's UFUNCTION().
  - RPC is Unreiiable by default.
  - If you spam `Reliable` like every ticks, client may get disconnected due to preventation of DDOS.
- `WithValidation` specifier declares `_Validation` function with bool return and same parameters. 
  - `_Validation` function must be followed after `WithValidation` specifier.
  - disconnect client if return is `false`
  - execute RPC if return is `true`
  - Server RPC requires WithValidation
- when calling RPC on Server  
| actor \ specifier | none   | `NetMulticast`       | `Server` | `Client`      |  
|-------------------|--------|----------------------|----------|---------------|  
| Owned by client   | server | server & all clients | server   | owning client |  
| Owned by server   | server | server & all clients | server   | server        |  
| Unowned           | server | server & all clients | server   | server        |  
- when calling RPC on Client  
| actor \ specifier | none   | `NetMulticast`       | `Server` | `Client`      |  
|-------------------|--------|----------------------|----------|---------------|  
| Owned by self     | self   | self                 | server   | self          |  
| Owned by other    | self   | self                 | none     | self          |  
| Owned by server   | self   | self                 | none     | self          |  
| Unowned           | self   | self                 | none     | self          |  

## ~~Component Replication~~
- tbd
<!--
- Component Replication
  - only some special components replicated directly
  - static component (not need replicate)
    - spawned with actor together
  - dynamic component (need replicate)
    - spawned separted with actor in runtime
  - Needs
    - implement of `GetLifetimeReplicatedProps(...)` just like actors docs
	- `AActorComponent::SetIsReplicated(true)` (can be skipped if it's default subobject)
  - other subobjects can be replicated too
    ``` C++
	```
-->


# Optimization

## Relevancy
- `AActor::IsNetRelevantFor()`
  1. return true : `bIsAlwaysRelevant` | Owned | Pawn | Instigated by Pawn
  2. return owner's : `bNetUseOwnerRelevancy` & Owned
  3. return false : `bOnlyRelevantToOwner` & not **1.**
  4. return base's : attached to skeleton of another actor
  5. return false : `bHidden` & root component not collide
     - warning if there is no root component
  6. return ture : distance based relevancy (AGameNetworkManager) & closer than net cull distance
- Pawn and PlayerController return different result (overriding)
- bStatic Actors can also be replicated
- imperfect
  - large actor
  - sound occlusion of ambient sound
  - though, packet loss is more critical so it's affordable

## Priority
- `NetPriority`
- weight for bandwidth load balancing
- default values
  - Actor = 1.0
  - Matinee = 2.7
  - Pawn = 3.0
  - PlayerController = 3.0
- `AActor::GetNetPriority()` = `NetPriority` * replication waiting time (plus location and distance, etc)

## Dormancy
- `ENetDormancy`
  - `DORM_Never`
  - `DORM_Awake`
  - `DORM_DormantAll`
  - `DORM_DormantPartial` + `GetNetDormancy()`
  - `DORM_Initial`
  - ~~`DORM_Max`~~


## ~~NetClientTicksPerSecond~~
- tbd

## ~~Replication Graph~~
- tbd

## Conceptual Tips
- reduce bReplicates
- reduce NetUpdateFrequency
- use Dormancy
- use Relevancy
- reduce NetClientTicksPerSecond
- use Quantizing (e.g. FVector_NetQuantize)
- minimize RPC : replace into RepNotify
  - remove Server RPC that unused on clients
  - reduce NetMulticast RPC
  - reduce FName as RPC parameter
  - don't spam reliable RPC
- check `ROLE_Authority` for server logic
- check `IsLocallyControlled` for owner logic
  - but not in constructor



# Flow

## ~~UNetDriver::ServerReplicateActors flow~~
- tbd

## ~~Character Movement Component flow~~
- tbd



# Others

## Travelling
- Seamless (non-blocking)
  - highly recommended
- Non-Seamless (blocking)
  - first map loading
  - client-to-server first connect
  - ending game, starting new game
- `UEngine::Browse(...)`
- `UWorld::ServerTravel(...)`
- `APlayerController::ClientTravel(...)`
- Transition Map
  - `UGameMapSetting::TransitionMap`
  - `AGameModeBase::bUseSeamlessTravel`
- Seamless Travel Flow
  1. Mark persistent actors to transition map
  2. Travel to transition map
  3. Mark persistent actors to final map
  3. Travel to final map
- Persistent actors
  - GameMode actor (server only)
    - Actors added by `AGameModeBase::GetSeamlessTravelActorList`
  - Controllers with valid PlayerState (server only)
  - All PlayerControllers (server only)
  - All local PlayerControllers (server and clients)
    - Actors added by `APlayerController::GetSeamlessTravelActorList` on local

## ~~Online Subsystem~~
- tbd

## ~~Session~~
- tbd

## ~~Online Beacons~~
- tbd



# Practical

## ~~Network Profiler~~
- tbd

## ~~Testing Multiplay~~
- tbd

