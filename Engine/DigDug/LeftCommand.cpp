#include "pch.h"
#include "LeftCommand.h"


LeftCommand::LeftCommand()
{
}


LeftCommand::~LeftCommand()
{
}

void LeftCommand::Execute(dae::GameObject* player, PlayerType, const float& deltaTime)
{
	auto currPos = player->GetPosition();
	player->SetPosition(currPos.x -= 50.f * deltaTime, currPos.y);
}
