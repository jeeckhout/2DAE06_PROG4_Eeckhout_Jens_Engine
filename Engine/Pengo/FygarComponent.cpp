#include "MiniginPCH.h"
#include "FygarComponent.h"
#include "GameObject.h"
#include "StateComponent.h"
#include "TypeComponent.h"
#include "CollisionComponent.h"
#include "TextureComponent.h"
#include "../DigDug/LookRightState.h"
#include "../DigDug/LookLeftState.h"
#include "../DigDug/LookUpState.h"
#include "../DigDug/LookDownState.h"
#include "BaseState.h"


FygarComponent::FygarComponent(dae::GameObject *parent)
	:BaseComponent(parent)
{
}

void FygarComponent::Update(const float& deltaTime, float, float, float, float)
{
	if (!m_IsPerformingAction)
	{
		const int randNum = rand() % 5;
		switch (randNum)
		{
			case 0:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveUp(deltaTime);
				m_CurrAction = ActionFygar::Up;
				m_ActionTimer = 1.f;
				break;

			case 1:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveDown(deltaTime);
				m_CurrAction = ActionFygar::Down;
				m_ActionTimer = 1.f;
				break;

			case 2:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveRight(deltaTime);
				m_CurrAction = ActionFygar::Right;
				m_ActionTimer = 1.f;
				break;

			case 3:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveLeft(deltaTime);
				m_CurrAction = ActionFygar::Left;
				m_ActionTimer = 1.f;
				break;

			case 4:
				if (canFire)
				{
					m_Velocity.x = 100.f;
					m_Velocity.y = 100.f;
					Fire();
					m_CurrAction = ActionFygar::FireFlame;
					m_ActionTimer = 1.f;
				}
				break;

			default:
			break;

		}
	}
	else
	{
		switch (m_CurrAction)
		{
			case  ActionFygar::Up:
				MoveUp(deltaTime);
				m_ActionTimer -= deltaTime;
				break;

			case ActionFygar::Down:
				MoveDown(deltaTime);
				m_ActionTimer -= deltaTime;
				break;

			case ActionFygar::Left:
				MoveLeft(deltaTime);
				m_ActionTimer -= deltaTime;
				break;


			case ActionFygar::Right:
				MoveRight(deltaTime);
				m_ActionTimer -= deltaTime;
				break;

			case ActionFygar::FireFlame:
				UpdateFire(deltaTime);
				break;
		}
		if (m_ActionTimer <= 0)
		{
			m_IsPerformingAction = false;
		}
	}
}

void FygarComponent::StopMovement()
{
	m_Velocity.x = 0;
	m_Velocity.y = 0;
}

void FygarComponent::StopFire()
{
	canFire = false;
}

void FygarComponent::MoveUp(const float& deltaTime)
{
	m_IsPerformingAction = true;
	m_pParent->GetStateComp()->SetState(new LookUpState);
	auto currPos = m_pParent->GetPosition();
	if (currPos.y > 0)
	{
		m_pParent->SetPosition(currPos.x , currPos.y -= m_Velocity.y * deltaTime);
	}
	else
	{
		currPos.y = 0;
		m_pParent->SetPosition(currPos.x,currPos.y);
	}
}

void FygarComponent::MoveDown(const float& deltaTime)
{
	m_IsPerformingAction = true;
	m_pParent->GetStateComp()->SetState(new LookDownState);
	auto currPos = m_pParent->GetPosition();
	if(currPos.y < 460)
	{
		m_pParent->SetPosition(currPos.x , currPos.y += m_Velocity.y * deltaTime);
	}
	else
	{
		currPos.y = 460;
		m_pParent->SetPosition(currPos.x,currPos.y);
	}
}

void FygarComponent::MoveRight(const float& deltaTime)
{
	m_IsPerformingAction = true;
	m_pParent->GetStateComp()->SetState(new LookRightState);
	auto currPos = m_pParent->GetPosition();
	if (currPos.x < 620)
	{
		m_pParent->SetPosition(currPos.x += m_Velocity.x * deltaTime,currPos.y);
	}
	else
	{
		currPos.x = 620;
		m_pParent->SetPosition(currPos.x,currPos.y);
	}
}

void FygarComponent::MoveLeft(const float& deltaTime)
{
	m_IsPerformingAction = true;
	m_pParent->GetStateComp()->SetState(new LookLeftState);
	auto currPos = m_pParent->GetPosition();
	if (currPos.x > 0)
	{
		m_pParent->SetPosition(currPos.x -= m_Velocity.x * deltaTime,currPos.y);
	}
	else
	{
		currPos.x = 0;
		m_pParent->SetPosition(currPos.x,currPos.y);
	}
}

void FygarComponent::Fire()
{
		m_IsPerformingAction = true;
		auto pState = m_pParent->GetStateComp()->GetState();
		LookUpState* pUpCheck = dynamic_cast<LookUpState*>(pState);
		LookDownState* pDownCheck = dynamic_cast<LookDownState*>(pState);
		LookLeftState* pLeftCheck = dynamic_cast<LookLeftState*>(pState);
		LookRightState* pRightCheck = dynamic_cast<LookRightState*>(pState);
		
		TextureComponent* pTexture = nullptr;

		if (pRightCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(m_pParent->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireRight.png"};
			pTexture->Update(0,0,0,75,50);
			flame->SetPosition(m_pParent->GetPosition().x + (float(pTexture->GetTextureData()->w) / 4),m_pParent->GetPosition().y - (float(pTexture->GetTextureData()->h) / 4));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			m_pParent->AddChild(flame);
		}
			
		if(pLeftCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(m_pParent->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireLeft.png"};
			pTexture->Update(0,0,0,75,50);
			flame->SetPosition(m_pParent->GetPosition().x - (float(pTexture->GetTextureData()->w)),m_pParent->GetPosition().y - (float(pTexture->GetTextureData()->h) / 4));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			m_pParent->AddChild(flame);
		}
		
		if(pUpCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(m_pParent->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireUp.png"};
			pTexture->Update(0,0,0,50,75);
			flame->SetPosition(m_pParent->GetPosition().x - (float(pTexture->GetTextureData()->w) / 5),m_pParent->GetPosition().y - (float(pTexture->GetTextureData()->h)));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			m_pParent->AddChild(flame);
		}

		if(pDownCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(m_pParent->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireDown.png"};
			pTexture->Update(0,0,0,50,75);
			flame->SetPosition(m_pParent->GetPosition().x - (float(pTexture->GetTextureData()->w) / 5),m_pParent->GetPosition().y + (float(pTexture->GetTextureData()->h) / 3));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			m_pParent->AddChild(flame);
		}
}

void FygarComponent::UpdateFire(const float& deltaTime)
{
	m_ActionTimer -= deltaTime;
	if (m_ActionTimer <= 0)
	{
		m_pParent->DeleteChildren();
	}
}
