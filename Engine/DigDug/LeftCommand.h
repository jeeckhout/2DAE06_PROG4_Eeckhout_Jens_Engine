#pragma once
#include <Commands.h>
class LeftCommand final : public Command
{
public:
	LeftCommand();
	~LeftCommand();
	void Execute(dae::GameObject* player, PlayerType, const float& deltaTime) override;
};

