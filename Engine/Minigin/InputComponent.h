#pragma once
#include "BaseComponent.h"

class Command;
enum class ObjectType
{
	Pengo,
	Enemy
};

class InputComponent final : public BaseComponent
{
public:
	InputComponent(dae::GameObject *parent, int ID, ObjectType type);
	~InputComponent() = default;
	void Update(const float& deltaTime, float x, float y, float width, float height) override;
	void Render() override{;};

private:
	int m_ControllerID;
	ObjectType m_Type;
	Command* triggeredCommand;
};

