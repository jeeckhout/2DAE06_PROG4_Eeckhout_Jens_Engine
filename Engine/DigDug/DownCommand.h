#pragma once
#include <Commands.h>
class DownCommand final : public Command
{
public:
	DownCommand();
	~DownCommand();
	void Execute(dae::GameObject* player, PlayerType, const float& deltaTime) override;
};

