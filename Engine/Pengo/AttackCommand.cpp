#include "pch.h"
#include "AttackCommand.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "TypeComponent.h"
#include "StateComponent.h"
#include "CollisionComponent.h"
#include "LookUpState.h"
#include "LookDownState.h"
#include "LookRightState.h"
#include "LookLeftState.h"


AttackCommand::AttackCommand()
{
}


AttackCommand::~AttackCommand()
{
}

void AttackCommand::Execute(dae::GameObject* object, ObjectType type, const float&)
{
	if (type == ObjectType::Pengo)
	{
		StateComponent* pState{};
		auto Components = object->GetComponents();
		for(BaseComponent* pComp : Components)
		{
			pState = dynamic_cast<StateComponent*>(pComp);
			if (pState)
			{
				break;
			}
		}

		LookUpState* pUpCheck = dynamic_cast<LookUpState*>(pState);
		LookDownState* pDownCheck = dynamic_cast<LookDownState*>(pState);
		LookLeftState* pLeftCheck = dynamic_cast<LookLeftState*>(pState);
		LookRightState* pRightCheck = dynamic_cast<LookRightState*>(pState);
		TextureComponent* pTexture = nullptr;

		if (pRightCheck)
		{

		}
		if(pLeftCheck)
		{
			
		}
		
		if(pUpCheck)
		{
			
		}

		if(pDownCheck)
		{
			
		}
	}

	if (type == ObjectType::Enemy)
	{
		
		StateComponent* pState{};
		auto Components = object->GetComponents();
		for(BaseComponent* pComp : Components)
		{
			pState = dynamic_cast<StateComponent*>(pComp);
			if (pState)
			{
				break;
			}
		}
		
		
		LookUpState* pUpCheck = dynamic_cast<LookUpState*>(pState);
		LookDownState* pDownCheck = dynamic_cast<LookDownState*>(pState);
		LookLeftState* pLeftCheck = dynamic_cast<LookLeftState*>(pState);
		LookRightState* pRightCheck = dynamic_cast<LookRightState*>(pState);
		
		TextureComponent* pTexture = nullptr;

		if (pRightCheck)
		{
			
		}
			
		if(pLeftCheck)
		{
			
		}
		
		if(pUpCheck)
		{
			
		}

		if(pDownCheck)
		{
		}
		
	}
}
