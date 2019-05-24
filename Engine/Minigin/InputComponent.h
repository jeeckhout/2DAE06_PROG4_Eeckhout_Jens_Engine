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
	InputComponent(dae::GameObject *parent, int ID, PlayerType type);
	~InputComponent();
	void Update(const float& deltaTime, float x, float y, float width, float height) override;
	void Render() override{;};

private:
	int m_ControllerID;
	PlayerType m_Type;
	Command* triggeredCommand;
};

