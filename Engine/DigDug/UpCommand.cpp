#include "pch.h"
#include "UpCommand.h"


UpCommand::UpCommand()
{
}


UpCommand::~UpCommand()
{
}

void UpCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
{
	auto currPos = player->GetPosition();
	player->SetPosition(currPos.x , currPos.y -= 100.f * deltaTime);
}
