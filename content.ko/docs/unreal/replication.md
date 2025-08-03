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


# 사전 지식

* C++ 기초
* 언리얼 기초
    * 게임 프레임워크
    * `AActor`와 `UObject`에 대한 이해
    * 지정자
        * `UPROPERTY` 같은 매크로의 용도
* TCP, UDP

```
언리얼 엔진은 멀티플레이를 상정하여 만들어졌기 때문에 싱글 게임을 만들더라도
엔진코드 동작 방식 분석을 위해서는 언리얼 네트워크에 대한 이해가 필수적이다.
```
<br>

# 언리얼 네트워크: 배경

## 네트워크 게임의 추상화

```
멀티 게임에 필요한 공통요소
```

* **세상과 개인**
    * 현실의 개인은 세상의 일부
        * 개인이 세상을 임의로 조작 불가
    * 서버-클라이언트 모델은 서버에서 세상, 클라이언트에서 개인을 담당
        * 언리얼은 P2P 미 지원
            * 속도, 확장성, 안정성 등
* **주체에 따른 권한 분리**
    * 달려오는 사람을 보고 피할 수는 있음
    * 타인이 달리는 방향을 바꾸는 건 안됨
* **동기화된 세상**
    * 각 개인은 같은 세상을 기반으로 활동
        * 다르게 받아들여도 원본은 동일 (색맹, 청력 등)

## Game Framework 적용

```
* 세상(Game), 개인(Player) 분리
* 접근 권한 분리 (r/w, get/set 등)
* 동일한 세상(Level) 공유
```

|  | Public-role | Private-role | Medium-role |
| --- | --- | --- | --- |
| Game | GameState | GameMode | Level |
| Player | PlayerState | PlayerController | Pawn |

* `AGameModeBase`
    * Game의 규칙
        * 승리 조건, 기본 클래스, 득점 조건, 생성/제거, 로그인 등
    * Game의 Behavior (non-const, setter)
    * 관리자만 접근
* `AGameStateBase`
    * Game의 상태
        * 팀별 점수, 게임 진행도, 남은 시간, PlayerState Array 등
    * Game의 Readable Property (getter)
    * 모두 접근
* `APlayerController`
    * Player의 Facade
        * Pawn Ownership, 입력 등
    * Player의 인터페이스, Behavior (non-const, setter)
    * 사용자만 접근
* `APlayerState`
    * Player의 상태
        * 플레이어 점수, 이름, 소지품 등
    * Player의 Readable Property (getter)
    * 모두 접근
* `ULevel`, `APawn`
    * Game과 Player의 접점
        * 캐릭터, 상호작용하는 Actor 등
    * 동기화된 World의 변화를 Player의 시점에서 표시, 발생
    * 모두 접근

<br>

* **권한에 따른 클래스 분리 -> 유효한 객체를 권한 소지자에게 배포**
    * GameMode : private Game -> 서버만
    * GameState : public Game -> 서버와 모든 클라이언트
    * PlayerController : private Player -> 서버와 개별 클라이언트
    * PlayerState : public Player -> 서버와 모든 클라이언트

![image.png](/images/unreal_replication_1.png)

<br>

* 동일한 세상 공유 -> **Replication**

## Replication

* 서버의 원본을 클라이언트들에게 복제(Replicate)
    * 클라이언트는 주장, 서버가 결정
    * 클라이언트들은 같은 월드에 있다고 느낌
    * `AActor`의 기능
        * `AInfo`가 존재하는 이유 중 하나

<br>

# 레플리케이션: 구조

## Network Mode

```
언리얼 인스턴스의 네트워크 역할
```

* One Project, Multiple Modes
    * 한 실행 프로그램에서 초대/참여 전환 가능
    * `UWorld::NetDriver` 상태로 구분
* `ENetMode`
    * `NM_Standalone`
        * **Authoritative** , ~~호스팅~~ , **로컬플레이어**
    * `NM_Client`
        * ~~Authoritative~~ , ~~호스팅~~, **로컬플레이어** (프록시)
    * `NM_DedicatedServer`
        * **Authoritative** , **호스팅** ,~~로컬플레이어~~
    * `NM_ListenServer`
        * **Authoritative** , **호스팅** , **로컬플레이어**

## Role, RemoteRole

```
액터의 네트워크 역할
    * AActor::Role        : UWorld 내의 액터의 역할
    * AActor::RemoteRole  : 네트워크 상에서 대응하는 액터의 역할
```

* `ENetRole`
    * `ROLE_None`
        * 네트워크로 연동되지 않음
    * `ROLE_Authority`
        * 원본
        * 현재는 Server에만 존재
    * `ROLE_SimulatedProxy`
        * 원본을 따라가는 복제품
            * 서버 값의 외삽을 통해 예측
    * `ROLE_AutonomousProxy`
        * 원본을 따라가는 복제품
            * 서버 값의 외삽 + 로컬 입력을 통해 예측
        * 입력이 유효한 *자신의 액터* 외에는 Simulated Proxy로 대체됨 (*후술: Ownership*)

## Ownership

```
액터의 네트워크 권한 소유자에 대한 참조
```

* PlayerController가 Owner이면 대응하는 플레이어의 소유
    * 이에 빙의 된 Pawn의 Owner는 PlayerController = 플레이어의 소유
    * 해당 Pawn이 Owner인 액터도 플레이어의 소유
    * 소유된 액터의 Subobject도 플레이어의 소유
* 왜 필요한가?
    * 누구에게 해당 액터를 *변경, 실행* 할 권한이 있는지 표기하기 위해 (*후술: RPC*)
    * *갱신 여부에 참조*하기 위해
        * *Relevancy*, *Conditional Property Replication* (*후술*)
    * Owner가 아닌 클라이언트의 Autonomous Proxy를 Simulated Proxy로 대체하기 위해

- - -

![image.png](/images/unreal_replication_2.png)

- - -
![image.png](/images/unreal_replication_3.png)

<br>

# 레플리케이션: 방식

* 모든 레플리케이션은 `AActor::bReplicates`가 `true`이어야 실행

## Property Replication

```
서버의 변화를 주기적으로 배포하는 주요 수단
```

* Needs
    * `UPROPERTY(Replicated)` 혹은 `UPROPERTY(ReplicatedUsing=OnRep_PropertyName)` 지정자
        * `ReplicatedUsing` 사용 시 `OnRep_PropertyName()` 정의
    * `AActor::GetLifetimeReplicatedProps(...)` 오버라이드
        * 안에 `DOREPLIFETIME(ClassName, PropertyName);` 혹은 파생형 (`UnrealNetwork.h` 참조)

``` C++
class ENGINE_API AActor : public UObject
{
    UPROPERTY( Replicated ) // 실제로는 ReplicatedWith 사용 중
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
}

void AActor::PreReplication( IRepChangedPropertyTracker & ChangedPropertyTracker )
{
    DOREPLIFETIME_ACTIVE_OVERRIDE( AActor, ReplicatedMovement, bReplicateMovement );
}

void AActor::OnRep_ReplicatedMovement() { ... }
```

* 서버에서 클라이언트로
* Reliable
    * 값의 최종적인 변화는 보장하지만 모든 변화의 반영을 보장하지는 않음
        * 100 -> 200 -> 300 으로 값이 변환될 때 200이 생략될 수 있음
* `ReplicatedWith=OnRep_PropertyName` 지정자를 사용한 경우 `OnRep_PropertyName()`가 레플리케이션 이후 실행됨

<br>

* `ELifetimeCondition`
    * `COND_None`
    * `COND_InitialOnly`
    * `COND_OwnerOnly`
    * `COND_SkipOwner`
    * `COND_SimulatedOnly`
    * `COND_AutonomousOnly`
    * `COND_SimulatedOrPhysics`
    * `COND_InitialOrOwner`
    * `COND_Custom` + `SetCustonIsActiveOverride(...)`
    * ...
* `DOREPLIFETIME_ACTIVE_OVERRIDE`를 통해 더 가변적으로 갱신 가능
    * 하지만 속도가 느려지며 특정 Condition에는 적용되지 않음

<br>

* `NetUpdateFrequency`를 통해 레플리케이션 빈도를 조절할 수 있음
    * Adaptive Network Update Frequency의 경우는 `MinNetUpdateFrequency`의 사이에서 가변적으로 갱신됨
* `UObject`의 레퍼런스는 자동적으로 `FNetworkGUID`를 통해 레플리케이트 됨
    * `UObject::IsSupportedForNetworking()`로 확인
        * 리플리케이트 중인 액터
        * 정적 명명 액터
        * 리플리케이트 중인 컴포넌트
        * 정적 명명 컴포넌트
        * Packaged UObject
    * 정적 명명?
        * Packaged
        * 생성자로 추가
        * `SetNetAddressable()`로 추가
            * 서버와 클라이언트의 이름이 동일

## Remote Procedure Call (RPC)

```
특정 언리얼 인스턴스에만 변화를 주고자 할 때 사용
```

* Needs
    * `UFUNCTION()` + 지정자
        * 실행 머신 : `Client`, `Server`, `NetMulticast`
        * TCP : `Reliable`
        * 유효성 검사 : `WithValidation`
    * `##_Implementation()` 정의
    * `WithValidation` 지정자 있을 시, `##_Validation()` 정의

``` C++
UFUNCTION(Client)
void ClientRPC();
UFUNCTION(Server, WithValidation)
void ServerRPC();
UFUNCTION(NetMulticast, Reliable)
void MulticastRPC();

void SomeActorClass::ClientRPC_Implementation() {}
void SomeActorClass::ServerRPC_Implementation() {}
bool SomeActorClass::ServerRPC_Validation() {return true;}
void SomeActorClass::MulticastRPC_Implementation() {}
```

* 서버에서 RPC를 호출 할 때 `##_Implementation()`이 실행되는 인스턴스

| 액터 / RPC | none | `NetMulticast` | `Server` | `Client` |
| --- | --- | --- | --- | --- |
| 클라이언트 소유 | 서버에서 | 서버 & 모든 클라이언트에서 | 서버에서 | 소유 클라이언트에서 |
| 서버 소유 | 서버에서 | 서버 & 모든 클라이언트에서 | 서버에서 | 서버에서 |
| 미소유 | 서버에서 | 서버 & 모든 클라리언트에서 | 서버에서 | 서버에서 |

* 클라이언트에서 RPC를 호출 할 때 `##_Implementation()`이 실행되는 인스턴스

| 액터 / RPC | none | `NetMulticast` | `Server` | `Client` |
| --- | --- | --- | --- | --- |
| 자신이 소유 | 자신에게서 | 자신에게서 | 서버에서 | 자신에게서 |
| 다른 클라이언트 소유 | 자신에게서 | 자신에게서 | 실행 안됨 | 자신에게서 |
| 서버 소유 | 자신에게서 | 자신에게서 | 실행 안됨 | 자신에게서 |
| 미소유 | 자신에게서 | 자신에게서 | 실행 안됨 | 자신에게서 |

* NetMulticast RPC는 짧은 시간 내에 연속으로 사용해도 한 번만 호출
* RPC 호출이 보장되기를 원한다면 `Reliable` 지정자를 넣는다
    * RPC는 기본적으로 Unreliable
    * Reliable RPC를 남용할 경우 연결 종료
* `WithValidation` 지정자를 통해 유효성 검사
    * `##_Validation()`가 `true`를 리턴할 경우 `##_Implementation()` 실행
    * `##_Validation()`가 `false`를 리턴할 경우 연결 종료
    * Server RPC의 경우 필수

## Component Replication

```
레플리케이션 분리, 재귀적 레플리케이션
```

* Needs
    * `UActorComponent::SetIsReplicated(true)` 호출
    * 이하 Property Replication과 유사
        * `UPROPERTY(Replicated)` 혹은 `UPROPERTY(ReplicatedUsing=OnRep_PropertyName)` 지정자
            * `ReplicatedUsing` 사용 시 `OnRep_PropertyName()` 정의
        * `UActorComponent::GetLifetimeReplicatedProps(...)` 오버라이드
            * 안에 `DOREPLIFETIME(ClassName, PropertyName);` 혹은 파생형 (`UnrealNetwork.h` 참조)
* 주 사용처
    * 클라이언트에서 동적 컴포넌트 생성/제거
        * 정적 컴포넌트는 자동으로 생성/제거 됨 (Packaged)
    * 타임라인
* 오버헤드 : 4 바이트 헤더, 1바이트 푸터

### Subobject Replication

``` C++
virtual class FObjectReplicatorBase * InstantiateReplicatorForSubObject(UClass *SubobjClass);

virtual bool ReplicateSubobjects(class UActorChannel *Channel, class FOutBunch *Bunch, FReplicationFlags *RepFlags);

virtual void OnSubobjectCreatedFromReplication(UObject *NewSubobject);
```
<br>

# 레플리케이션: 최적화

## Relevancy

```
Ownership 여부 혹은 거리에 따른 액터 레플리케이션 생략/갱신 정책
```

* `AActor::IsNetRelevantFor()` 를 동해 갱신 여부 결정
    1. true : `bIsAlwaysRelevant` \|\| Owned \|\| Pawn \|\| Pawn Instigatee
    2. owner 따름 : `bNetUseOwnerRelevancy` && Owned
    3. false : `bOnlyRelevantToOwner` && 1.에 해당 안됨
    4. base 따름 : 다른 액터의 스켈레톤에 attach
    5. false : `bHidden` && 루트 컴포넌트가 비접촉 (Ignore)
        * 루트 컴포넌트가 없을 경우 Warning
    6. ture : 거리기반 relevancy (`AGameNetworkManager`) && net cull distance보다 가까움
    * Pawn과 PlayerController는 다름 (override)
* bStatic Actor도 갱신 가능
* 다음 경우에 대해 불안정
    * 커다란 액터
    * 배경음의 소리 차폐
    * 하지만 대역폭 감소로 더 큰 오류 차단 가능, 트레이드오프

## Priority

```
한정된 대역폭 내 액터 레플리케이션 우선순위
```

* `NetPriority`
* 기본값
    * Actor = 1.0
    * Matinee = 2.7
    * Pawn = 3.0
    * PlayerController = 3.0
* `AActor::GetNetPriority()` = `NetPriority` \* 갱신 후 대기 시간 (외 위치 및 거리 등)

## Dormancy

```
액터 레플리케이션 휴면 정책
```

* `ENetDormancy`
    * `DORM_Never`
    * `DORM_Awake`
    * `DORM_DormantAll`
    * `DORM_DormantPartial` + `GetNetDormancy()`
    * `DORM_Initial`

## 전반적 팁

* 필요 없는 `bReplicates` 꺼두기
* `NetUpdateFrequency` 줄이기
* Dormancy 사용하기
* Relevancy 사용하기
* `NetClientTicksPerSecond` 줄이기
* 양자화(Quantizing) 사용하기 (`FVector_NetQuantize` 등)
* RPC 최소화 하기 : RepNotify로 바꾸기
    * 클라이언트에서 안쓰는 Server RPC 없애기
    * NetMulticast RPC 최소화 하기
    * RPC 매개변수 `FName` 최소화 하기
    * reliable RPC 연발하지 않기
* 서버 로직 수행할 때 `ROLE_Authority`인지 확인하기
* 소유 Pawn 로직 수행할 때 `IsLocallyControlled()`로 확인하기
    * 생성자에서는 금지

<br>

# 언리얼 네트워크: 기타

## Travelling

```
레벨 전환 : 매끄럽지 않은 이동(non-seamless)과 매끄러운 이동(seamless)
```

* 이동(Travel) 방법
    * `UEngine::Browse`
        * 연결된 클라이언트들을 끊고 완전히 새로운 맵으로 **매끄럽지 않은 이동** (게임 리셋)
    * `UWorld::ServerTravel`
        * 서버에서만 호출 가능
        * 서버와 클라이언트들을 새로운 맵으로 **매끄러운 이동**
    * `APlayerController::ClientTravel`
        * 서버에서 호출 시 새로운 맵으로 **매끄러운 이동**
        * 클라이언트에서 호출 시 새로운 서버로 **매끄럽지 않은 이동**
* 매끄러운 이동(seamless travel) 세팅
    * `UGameMapsSettins::TransitionMap` 지정
        * 없으면 빈 Map 생성
    * `AGameModeBase::bUseSeamlessTravel` 참으로 바꾸기
* 흐름
    1. Transition Level에 지속될 액터 표시
    2. Transition Level로 이동
    3. 최종 레벨에 지속될 액터 표시
    4. 최종 레벨로 이동
* 기본적으로 유지되는 액터들
    * GameMode (서버)
        * `AGameModeBase::GetSeamlessTrabelActorList`로 추가된 액터들
    * PlayerState가 있는 Controller (서버)
    * 모든 PlayerController (서버)
    * 자신의 PlayerController (서버, 클라이언트)
        * 자신의 컨트롤러에서`APlayerController::GetSeamlessTravelActorList`로 추가된 액터들

## `UNetDriver::ServerReplicateActors`

* `##_PrepConnections(...)`
* `##_BuildConsiderList(...)`
    * `AActor::PreReplication()`
* for each connection
    * `##_PrioritizeActors(...)`
    * `##_ProcessPrioritizedActors(...)`
        * `UActorChannel::ReplicateActor()`

### Details

* `##_PrepConnections(...)`
    * 업데이트 해야 할 클라이언트 갯수 산정
    * 0개일 경우, 이번 갱신은 생략
* `##_BuildConsiderList(...)`
    * 레플리케이션 대상 선정
        * `bReplicates`
        * DORM\_Init 아님
        * `NetUpdateFrequency` 확인 (가변일 경우 `OptimalNetUpdateDelta`)
    * `AActor::CallPreReplication()` 호출
    * 제외된 네트워크 액터 제거
* for each connection
    * ConsiderList에 대해
        * Dormant 조건 체크
        * `##_PrioritizeActors(...)` 호출
        * `##_ProcessPrioritizedActors(...)` 호출
        * Relevant한데 Priority 밀린 액터는 다음 틱에 가산점 추가
        * 필요없는 Connection 제거
* `##_PrioritizeActors(...)`
    * 제외 : 채널 없음 && \( 레벨 로딩 안됨 \|\| Not Relevant \)
    * 제외 : `AActor::bOnlyRelevantToOwner` && `AActor::IsRelevancyOwnerFor()`가 거짓
    * 제외 : 액터가 Dormant
        * 필요 시 Dormant로 지정
    * 제외되지 않은 액터들을 Priority로 내림차순 정렬 to OUT param
* `##_ProcessPrioritizedActors(...)`
    * 1초마다 `AActor::IsNetRelevantFor()` 체크
    * 5초 이상 false일 경우, Channel 닫음
    * true인데 Channel이 없을 경우 새로 열음
    * 현재 Relevant 대상들에 대해
        * 1초 이하 존재했으면 다음 틱에 무조건 업데이트
        * 1초 이상 존재했으면 `AActor::IsNetRelevantFor()` 체크
    * Relevant 액터들을 대역폭이 되는데까지 `UActorChannel::ReplicateActor()` 호출
* `UActorChannel::ReplicateActor()`
    * 채널이 열리고 첫 업데이트인 경우 Initialize
    * Channel이 Owner에 해당하지 않는 경우 Autonomous 에서 Simulated로
    * 바뀐 Property 레플리케이트
    * 레플리케이트 중인 모든 컴포넌트의 바뀐 Property 레플리케이트
    * 제거된 컴포넌트에 대해 제거 명령 발신

- - -

### 참조

* [Networking and Multiplayer \| Unreal Engine Documentation](https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/Networking/)
* 팀 스위니, (1999), 네트워크
    * [번역](https://sites.google.com/site/techaht/trans/unreal-net-arch)
