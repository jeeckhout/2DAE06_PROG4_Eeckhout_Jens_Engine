#pragma once
#include <Commands.h>
class LeftCommand final : public Command
{
public:
	LeftCommand();
	~LeftCommand();
	void Execute(dae::GameObject* player, ObjectType, const float& deltaTime) override;
};

