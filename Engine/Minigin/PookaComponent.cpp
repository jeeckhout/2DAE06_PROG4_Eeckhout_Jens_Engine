#include "MiniginPCH.h"
#include "PookaComponent.h"
#include "GameObject.h"

PookaComponent::PookaComponent(dae::GameObject* parent)
	:BaseComponent(parent)
{
}

void PookaComponent::Update(const float& deltaTime, float, float, float, float)
{
	if (!m_IsPerformingAction)
	{
		const int randNum = rand() % 4;
		switch (randNum)
		{
			case 0:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveUp(deltaTime);
				m_CurrAction = Action::Up;
				m_ActionTimer = 1.f;
				break;

			case 1:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveDown(deltaTime);
				m_CurrAction = Action::Down;
				m_ActionTimer = 1.f;
				break;

			case 2:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveRight(deltaTime);
				m_CurrAction = Action::Right;
				m_ActionTimer = 1.f;
				break;

			case 3:
				m_Velocity.x = 100.f;
				m_Velocity.y = 100.f;
				MoveLeft(deltaTime);
				m_CurrAction = Action::Left;
				m_ActionTimer = 1.f;
				break;

			default:
			break;

		}
	}
	else
	{
		switch (m_CurrAction)
		{
			case  Action::Up:
				MoveUp(deltaTime);
				break;

			case Action::Down:
				MoveDown(deltaTime);
				break;

			case Action::Left:
				MoveLeft(deltaTime);
				break;


			case Action::Right:
				MoveRight(deltaTime);
				break;
		}
		m_ActionTimer -= deltaTime;
		if (m_ActionTimer <= 0)
		{
			m_IsPerformingAction = false;
		}
	}
}

void PookaComponent::StopMovement()
{
	m_Velocity.x = 0;
	m_Velocity.y = 0;
}

void PookaComponent::MoveUp(const float& deltaTime)
{
	m_IsPerformingAction = true;
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

void PookaComponent::MoveDown(const float& deltaTime)
{
	m_IsPerformingAction = true;
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

void PookaComponent::MoveRight(const float& deltaTime)
{
	m_IsPerformingAction = true;
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

void PookaComponent::MoveLeft(const float& deltaTime)
{
	m_IsPerformingAction = true;
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
