#include "MiniginPCH.h"
#include "CollisionComponent.h"
#include "GameObject.h"
#include "TypeComponent.h"
#include "PookaComponent.h"
#include "FygarComponent.h"


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
			if (objectRect && parentRect)
			{
				if (object->GetPosition().x + objectRect->w < m_pParent->GetPosition().x + parentRect->w * 1.5
				&& object->GetPosition().x - objectRect->w > m_pParent->GetPosition().x - parentRect->w * 1)
			{
				if (object->GetPosition().y + objectRect->h < m_pParent->GetPosition().y + parentRect->h * 1.5
				&& object->GetPosition().y - objectRect->h > m_pParent->GetPosition().y - parentRect->h * 1.5)
				{
					if ((m_pParent->GetTypeComp()))
					{
						if (m_pParent->GetTypeComp()->GetType() == GameObjectType::Layer1Block
							|| m_pParent->GetTypeComp()->GetType() == GameObjectType::Layer2Block
							|| m_pParent->GetTypeComp()->GetType() == GameObjectType::Layer3Block
							|| m_pParent->GetTypeComp()->GetType() == GameObjectType::Layer4Block)
						{
							if(object->GetTypeComp()->GetType() == GameObjectType::Player)
							{
								m_pParent->UpdateTexture("AirBlock.png");
								m_pParent->GetTypeComp()->SetType(GameObjectType::AirBlock);
							}
							else
							{
								if (object->GetPookaComp())
								{
									object->GetPookaComp()->StopMovement();
								}
								if(object->GetFygarComp())
								{
									object->GetFygarComp()->StopMovement();
								}
							}
						}

						else if((m_pParent->GetTypeComp()->GetType() == GameObjectType::Pooka ||
							m_pParent->GetTypeComp()->GetType() == GameObjectType::Fygar ||
							m_pParent->GetTypeComp()->GetType() == GameObjectType::Flame) &&
							object->GetTypeComp()->GetType() == GameObjectType::Player)
						{
							object->SetPosition(0,0);
						}

						else if(m_pParent->GetTypeComp()->GetType() == GameObjectType::Pump &&
							(object->GetTypeComp()->GetType() == GameObjectType::Pooka ||
							object->GetTypeComp()->GetType() == GameObjectType::Fygar))
						{
							object->DeactivateTextureRendering();
							if (object->GetTypeComp()->GetType() == GameObjectType::Fygar)
							{
								object->GetFygarComp()->StopFire();
							}
							object->GetTypeComp()->SetType(GameObjectType::AirBlock);
						}
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

void CollisionComponent::SetVecObjectsToCheck(std::vector<dae::GameObject*>& objects)
{
	for(dae::GameObject* pObject : m_pObjects )
	{
		delete pObject;
		pObject = nullptr;
	}
	m_pObjects.clear();
	m_pObjects = objects;
}

std::vector<dae::GameObject*>& CollisionComponent::GetObjectVector()
{
	return m_pObjects;
}
