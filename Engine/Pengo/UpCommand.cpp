#include "pch.h"
#include "UpCommand.h"
#include "MovingState.h"
#include "LookUpState.h"
#include "StateComponent.h"


UpCommand::UpCommand()
{
}


UpCommand::~UpCommand()
{
}

void UpCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
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
	pState->SetState(new LookUpState{});
	auto currPos = player->GetPosition();
	if (currPos.y > 0)
	{
		player->SetPosition(currPos.x , currPos.y -= 100.f * deltaTime);
	}
	else
	{
		currPos.y = 0;
		player->SetPosition(currPos.x,currPos.y);
	}
}
