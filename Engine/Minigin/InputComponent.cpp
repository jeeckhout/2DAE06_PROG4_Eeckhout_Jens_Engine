#include "MiniginPCH.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "Commands.h"

InputComponent::InputComponent(dae::GameObject *parent, int ID, ObjectType type) 
: BaseComponent(parent),
m_ControllerID(ID),
m_Type{type},
triggeredCommand(nullptr)
{
}


void InputComponent::Update(const float& deltaTime, float, float, float,float)
{
	triggeredCommand = dae::InputManager::GetInstance().HandleInput(m_ControllerID);
	if (triggeredCommand != nullptr)
	{
		triggeredCommand->Execute(m_pParent,m_Type,deltaTime);
	}
}
