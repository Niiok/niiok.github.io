---
title: "Unreal Network"
author: "Niiok"
categories: ["Unreal"]
date: 2022-03-16T23:41:59+09:00
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


## Intro
- Unreal network system is based on [Server-Client model](https://docs.unrealengine.com/InteractiveExperiences/Networking/Server/).
- If developers consider about "Replication", game can support both single player and multiplayer.


## Network Mode
- NM_Standalone
  - Authoritive : true
  - Listening : false
  - LocalPlayer : true
- NM_Client
  - Authoritive : false
  - Listening : false
  - LocalPlayer : true
- NM_ListenServer
  - Authoritive : true
  - Listening : true
  - LocalPlayer : true
- NM_DedicatedServer
  - Authoritive : true
  - Listening : true
  - LocalPlayer : false


## Replication Role
- ROLE_None
- ROLE_Authority
- ROLE_SimulatedProxy
- ROLE_AutonomousProxy


## Replicate with property
``` C++
UFUNCTION()
void void_function();

UPROPERTY(Replicated)
int SimpleReplicateProperty;

UPROPERTY(ReplicatedUsing = void_function)
int ReplicatePropertyCallsRepNotifies;
```

## Replicate with Function (RPC)
``` C++
UFUNCTION(Server, Reliable, WithValidation)
void FunctionThatCalledOnServer();

UFUNCTION(Client, Reliable, WithValidation)
void FunctionThatCalledOnOwnerClient();

UFUNCTION(NetMulticast, Reliable, WithValidation)
void FunctionThatCalledOnEveryActor();

void ClassName::FunctionThatCalledOnServer_Implementation() {}
bool ClassName::FunctionThatCalledOnServer_Validation() {}
void ClassName::FunctionThatCalledOnOwnerClient_Implementation() {}
bool ClassName::FunctionThatCalledOnOwnerClient_Validation() {}
void ClassName::FunctionThatCalledOnEveryActor_Implementation() {}
bool ClassName::FunctionThatCalledOnEveryActor_Validation() {}
```
- You should set `Reliable`(TCP) or `Unreliable`(UDP) specifier on RPC's UFUNCTION().
  - If you spam `Reliable` like every ticks, client may get disconnected due to preventation of DDOS.
- `WithValidation` specifier is selective. (`_Validation` function must be followed with `WithValidation` specifier.).
