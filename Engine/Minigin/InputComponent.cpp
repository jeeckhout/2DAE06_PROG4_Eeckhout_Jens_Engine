#include "MiniginPCH.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "Commands.h"

InputComponent::InputComponent(dae::GameObject *parent) : BaseComponent(parent)
{
}


InputComponent::~InputComponent()
{
}

void InputComponent::Update(const float& deltaTime, float, float, float,float)
{
	triggeredCommand = dae::InputManager::GetInstance().HandleInput(controllerID);
	triggeredCommand->Execute(m_pParent,type,deltaTime);
}
