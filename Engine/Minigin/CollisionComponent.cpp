#include "MiniginPCH.h"
#include "CollisionComponent.h"
#include "GameObject.h"
#include "TypeComponent.h"
#include "PookaComponent.h"


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
					bool HasTypeComp{false};
					TypeComponent* pTypeComp{};
					for(BaseComponent* pComp : m_pParent->GetComponents())
					{
						pTypeComp = dynamic_cast<TypeComponent*>(pComp);
						if (pTypeComp)
						{
							HasTypeComp = true;
						}
					}
					if (HasTypeComp)
					{
						if (pTypeComp->GetType() == GameObjectType::EggBlock
							|| pTypeComp->GetType() == GameObjectType::IceBlock
							|| pTypeComp->GetType() == GameObjectType::SpecialBlock
							|| pTypeComp->GetType() == GameObjectType::Snowbee
							|| pTypeComp->GetType() == GameObjectType::Wire)
						{
								
								bool HasEnemyComp{false};
								PookaComponent* pEnemyComp{};
								for(BaseComponent* pComp : object->GetComponents())
								{
									pEnemyComp = dynamic_cast<PookaComponent*>(pComp);
									if(pEnemyComp)
									{
										HasEnemyComp = true;
									}
								}
								if (HasEnemyComp)
								{
									pEnemyComp->StopMovement();
								}
						}

						//else if((m_pParent->GetTypeComp()->GetType() == GameObjectType::Pooka ||
						//	m_pParent->GetTypeComp()->GetType() == GameObjectType::Fygar ||
						//	m_pParent->GetTypeComp()->GetType() == GameObjectType::Flame) &&
						//	object->GetTypeComp()->GetType() == GameObjectType::Player)
						//{
						//	object->SetPosition(0,0);
						//}
						
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
