#include "MiniginPCH.h"
#include "StateComponent.h"
#include "BaseState.h"


StateComponent::StateComponent(dae::GameObject* parent, BaseState* pDefaultState, BaseState* pDefaultAimState) 
:  BaseComponent(parent)
,pState(pDefaultState)
,pAimState(pDefaultAimState)
{
}

StateComponent::~StateComponent()
{
	delete pState;
	pState = nullptr;

	delete pAimState;
	pAimState = nullptr;
}

BaseState* StateComponent::GetState() const
{
	return pState;
}

void StateComponent::SetState(BaseState* newState)
{
	delete pState;
	pState = nullptr;
	pState = newState;
}

void StateComponent::SetAimState(BaseState* newState)
{
	delete pAimState;
	pAimState = nullptr;
	pAimState = newState;
}
