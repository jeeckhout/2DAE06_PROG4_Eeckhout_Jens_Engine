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
	player->GetStateComp()->SetState(new MovingState{});
	player->GetStateComp()->SetState(new LookLeftState{});
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
