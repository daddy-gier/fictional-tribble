#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NH_SimpleAIController.generated.h"

UCLASS()
class NYGHTSHADEHOLLOW_API ANH_SimpleAIController : public AAIController
{
    GENERATED_BODY()

public:
    virtual void OnPossess(APawn* InPawn) override;
};
