#include "pch.h"
#include "LeftCommand.h"


LeftCommand::LeftCommand()
{
}


LeftCommand::~LeftCommand()
{
}

void LeftCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
{
	auto currPos = player->GetPosition();
	player->SetPosition(currPos.x -= 100.f * deltaTime, currPos.y);
}
