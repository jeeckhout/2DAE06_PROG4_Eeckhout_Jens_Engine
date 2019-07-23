#pragma once
#include <Commands.h>
class AttackCommand final : public Command
{
public:
	AttackCommand();
	~AttackCommand();

	void Execute(dae::GameObject* object, ObjectType type, const float&) override;
};

