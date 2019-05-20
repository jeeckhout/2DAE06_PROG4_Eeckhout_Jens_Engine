#pragma once
#include "BaseComponent.h"

class Command;
enum class PlayerType
{
	Player,
	Fygar
};

class InputComponent final : public BaseComponent
{
public:
	InputComponent(dae::GameObject *parent);
	~InputComponent();
	void Update(const float& deltaTime, float x, float y, float width, float height) override;
	void Render() override = 0;

private:
	int controllerID;
	PlayerType type;
	Command* triggeredCommand;
};

