#include "pch.h"
#include "LeftCommand.h"
#include "MovingState.h"
#include "LookLeftState.h"
#include "StateComponent.h"

LeftCommand::LeftCommand()
{
}


LeftCommand::~LeftCommand()
{
}

void LeftCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
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
	pState->SetState(new LookLeftState{});
	auto currPos = player->GetPosition();
	if (currPos.x > 0)
	{
		player->SetPosition(currPos.x -= 100.f * deltaTime,currPos.y);
	}
	else
	{
		currPos.x = 0;
		player->SetPosition(currPos.x,currPos.y);
	}
}
