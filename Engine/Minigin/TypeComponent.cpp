#include "MiniginPCH.h"
#include "TypeComponent.h"

TypeComponent::TypeComponent(dae::GameObject* parent, GameObjectType type)
: BaseComponent(parent)
,m_Type(type)
{
}

GameObjectType TypeComponent::GetType()
{
	return m_Type;
}
