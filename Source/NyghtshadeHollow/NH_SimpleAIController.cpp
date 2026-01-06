#include "NH_SimpleAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

void ANH_SimpleAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (UBehaviorTree* BehaviorTree = LoadObject<UBehaviorTree>(
        nullptr, TEXT("/Game/Core/AI/BT_NPC_Schedule.BT_NPC_Schedule")))
    {
        RunBehaviorTree(BehaviorTree);
    }
}
