#include "pch.h"
#include "DownCommand.h"


DownCommand::DownCommand()
{
}


DownCommand::~DownCommand()
{
}

void DownCommand::Execute(dae::GameObject* player, ObjectType, const float& deltaTime)
{
	auto currPos = player->GetPosition();
	if(currPos.y < 460)
	{
		player->SetPosition(currPos.x , currPos.y += 100.f * deltaTime);
	}
	else
	{
		currPos.y = 460;
		player->SetPosition(currPos.x,currPos.y);
	}
}
