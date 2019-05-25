#pragma once
#include "Commands.h"

class UpCommand final : public Command
{
public:
	UpCommand();
	~UpCommand();
	void Execute(dae::GameObject* player, ObjectType, const float& deltaTime) override;
};

