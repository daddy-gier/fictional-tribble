#include "NH_GameState.h"

#include "Net/UnrealNetwork.h"

ANH_GameState::ANH_GameState()
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
}

void ANH_GameState::BeginPlay()
{
    Super::BeginPlay();
    MinuteAccumulator = 0.0f;
}

void ANH_GameState::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (!HasAuthority())
    {
        return;
    }

    if (TimeScale <= 0.0f)
    {
        return;
    }

    MinuteAccumulator += DeltaSeconds * TimeScale;

    while (MinuteAccumulator >= 1.0f)
    {
        MinuteAccumulator -= 1.0f;
        CurrentMinute++;

        if (CurrentMinute >= 60)
        {
            CurrentMinute = 0;
            CurrentHour = (CurrentHour + 1) % 24;
        }

        OnMinuteChanged.Broadcast(CurrentHour, CurrentMinute);
    }
}

void ANH_GameState::SetTime(int32 Hour, int32 Minute)
{
    CurrentHour = FMath::Clamp(Hour, 0, 23);
    CurrentMinute = FMath::Clamp(Minute, 0, 59);
    MinuteAccumulator = 0.0f;

    OnMinuteChanged.Broadcast(CurrentHour, CurrentMinute);
}

void ANH_GameState::GetTime(int32& OutHour, int32& OutMinute) const
{
    OutHour = CurrentHour;
    OutMinute = CurrentMinute;
}

void ANH_GameState::OnRep_Time()
{
    OnMinuteChanged.Broadcast(CurrentHour, CurrentMinute);
}

void ANH_GameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ANH_GameState, CurrentHour);
    DOREPLIFETIME(ANH_GameState, CurrentMinute);
}
