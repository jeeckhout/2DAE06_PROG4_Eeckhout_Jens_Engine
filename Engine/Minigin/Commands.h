#pragma once
#include "GameObject.h"
#include "InputComponent.h"

namespace dae 
{
	class GameObject;
}

class Command
{
public:
	virtual ~Command() = default;
	virtual void Execute(dae::GameObject*, PlayerType type, const float& deltaTime) = 0;
};
