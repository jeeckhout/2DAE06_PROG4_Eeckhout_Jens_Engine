#include "MiniginPCH.h"
#include "StateComponent.h"
#include "BaseState.h"


StateComponent::StateComponent(dae::GameObject* parent, BaseState* pDefaultState) : BaseComponent(parent)
{
	pState = pDefaultState;
}

StateComponent::~StateComponent()
{
	delete pState;
	pState = nullptr;
}

BaseState* StateComponent::GetState() const
{
	return pState;
}

void StateComponent::Update(const float&, float, float, float, float)
{
	pState->Update(*m_pParent);
}
