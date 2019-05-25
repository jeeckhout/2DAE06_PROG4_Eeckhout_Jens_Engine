#include "MiniginPCH.h"
#include "CollisionComponent.h"
#include "GameObject.h"
#include "TypeComponent.h"


CollisionComponent::CollisionComponent(dae::GameObject *parent)
: BaseComponent(parent)
{
}


CollisionComponent::~CollisionComponent()
{
}

void CollisionComponent::Update(const float&, float, float, float, float)
{
	for (auto object : m_pObjects)
	{
		if (object->GetTextureRect())
		{
			auto objectRect = object->GetTextureRect();
			auto parentRect = m_pParent->GetTextureRect();
			if (object->GetPosition().x + objectRect->w < m_pParent->GetPosition().x + parentRect->w * 1.5
				&& object->GetPosition().x - objectRect->w > m_pParent->GetPosition().x - parentRect->w * 1)
			{
				if (object->GetPosition().y + objectRect->h < m_pParent->GetPosition().y + parentRect->h * 1.5
				&& object->GetPosition().y - objectRect->h > m_pParent->GetPosition().y - parentRect->h * 1.5)
				{
					if ((m_pParent->GetTypeComp()))
					{
						if (m_pParent->GetTypeComp()->GetType() == GameObjectType::Block)
						{
							m_pParent->UpdateTexture("AirBlock.png");
						}

						else if(m_pParent->GetTypeComp()->GetType() == GameObjectType::Pooka &&
							object->GetTypeComp()->GetType() == GameObjectType::Player)
						{
							object->SetPosition(0,0);
						}

						else if(m_pParent->GetTypeComp()->GetType() == GameObjectType::Fygar &&
							object->GetTypeComp()->GetType() == GameObjectType::Player)
						{
							object->SetPosition(0,0);
						}
					}
				}
			}
		}
	}
}

void CollisionComponent::SetObjectsToCheck(dae::GameObject* object)
{
	m_pObjects.push_back(object);
}
