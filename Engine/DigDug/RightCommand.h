#pragma once
#include <Commands.h>
class RightCommand final : public Command
{
public:
	RightCommand();
	~RightCommand();
	void Execute(dae::GameObject* player, ObjectType, const float& deltaTime) override;
};

