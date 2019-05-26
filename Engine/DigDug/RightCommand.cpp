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
	player->GetStateComp()->SetState(new MovingState{});
	player->GetStateComp()->SetState(new LookRightState{});
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
