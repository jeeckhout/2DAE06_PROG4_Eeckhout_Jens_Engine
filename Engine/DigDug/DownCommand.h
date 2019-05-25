#pragma once
#include <Commands.h>
class DownCommand final : public Command
{
public:
	DownCommand();
	~DownCommand();
	void Execute(dae::GameObject* player, ObjectType, const float& deltaTime) override;
};

