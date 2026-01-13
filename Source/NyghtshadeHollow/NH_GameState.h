#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NH_GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(
    FOnNHMinuteChanged,
    int32, Hour,
    int32, Minute
);

/**
 * Global game clock. Ticks in minutes and broadcasts minute changes.
 */
UCLASS()
class NYGHTSHADEHOLLOW_API ANH_GameState : public AGameStateBase
{
    GENERATED_BODY()

public:
    ANH_GameState();

    virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // Current in-game time
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_Time, Category="Time")
    int32 CurrentHour = 6;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_Time, Category="Time")
    int32 CurrentMinute = 0;

    // In-game minutes advanced per real second.
    // e.g. set to 1.0 => 1 real second = 1 in-game minute.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Time")
    float TimeScale = 1.0f;

    // Fired after time updates
    UPROPERTY(BlueprintAssignable, Category="Time")
    FOnNHMinuteChanged OnMinuteChanged;

    UFUNCTION(BlueprintCallable, Category="Time")
    void SetTime(int32 Hour, int32 Minute);

    UFUNCTION(BlueprintCallable, Category="Time")
    void GetTime(int32& OutHour, int32& OutMinute) const;

protected:
    UFUNCTION()
    void OnRep_Time();

    // Accumulates fractional minutes until a full minute(s) pass
    float MinuteAccumulator = 0.0f;
};
