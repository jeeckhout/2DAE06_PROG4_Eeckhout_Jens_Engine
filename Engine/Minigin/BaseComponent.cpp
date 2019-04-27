#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "GameObject.h"


BaseComponent::BaseComponent(dae::GameObject* parent)
{
	m_pParent = parent;
}

const dae::GameObject& BaseComponent::getParent() const
{
	return *m_pParent;
}


