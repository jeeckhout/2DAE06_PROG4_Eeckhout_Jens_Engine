#pragma once
#include <Commands.h>
class StopAttackCommand final : public Command
{
public:
	StopAttackCommand();
	~StopAttackCommand();

	void Execute(dae::GameObject* object, ObjectType, const float&) override;
};

