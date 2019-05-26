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
	player->GetStateComp()->SetState(new MovingState{});
	player->GetStateComp()->SetState(new LookUpState{});
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
