#include "pch.h"
#include "RightCommand.h"


RightCommand::RightCommand()
{
}


RightCommand::~RightCommand()
{
}

void RightCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
{
	auto currPos = player->GetPosition();
	player->SetPosition(currPos.x += 100.f * deltaTime, currPos.y);
}
