#include "pch.h"
#include "RightCommand.h"
#include "LookRightState.h"
#include "MovingState.h"
#include "StateComponent.h"


RightCommand::RightCommand()
{
}


RightCommand::~RightCommand()
{
}

void RightCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
{

	StateComponent* pState{};
		auto Components = player->GetComponents();
		for(BaseComponent* pComp : Components)
		{
			pState = dynamic_cast<StateComponent*>(pComp);
			if (pState)
			{
				break;
			}
		}

	pState->SetState(new MovingState{});
	pState->SetState(new LookRightState{});
	auto currPos = player->GetPosition();
	if (currPos.x < 620)
	{
		player->SetPosition(currPos.x += 100.f * deltaTime,currPos.y);
	}
	else
	{
		currPos.x = 620;
		player->SetPosition(currPos.x,currPos.y);
	}
}
