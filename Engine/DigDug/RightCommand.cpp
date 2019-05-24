#include "pch.h"
#include "RightCommand.h"


RightCommand::RightCommand()
{
}


RightCommand::~RightCommand()
{
}

void RightCommand::Execute(dae::GameObject* player, PlayerType, const float& deltaTime)
{
	auto currPos = player->GetPosition();
	player->SetPosition(currPos.x += 50.f * deltaTime, currPos.y);
}
