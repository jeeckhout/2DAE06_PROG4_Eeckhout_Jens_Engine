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
	if (type == ObjectType::Player)
	{
		
		auto pState = object->GetStateComp()->GetState();

		LookUpState* pUpCheck = dynamic_cast<LookUpState*>(pState);
		LookDownState* pDownCheck = dynamic_cast<LookDownState*>(pState);
		LookLeftState* pLeftCheck = dynamic_cast<LookLeftState*>(pState);
		LookRightState* pRightCheck = dynamic_cast<LookRightState*>(pState);
		TextureComponent* pTexture = nullptr;

		if (pRightCheck)
		{
			dae::GameObject* pump = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{pump,GameObjectType::Pump};
			auto pCollision = new CollisionComponent{pump};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			pump->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{pump,"PumpRight.png"};
			pTexture->Update(0,0,0,75,50);
			pump->SetPosition(object->GetPosition().x + (float(pTexture->GetTextureData()->w) / 4),object->GetPosition().y - (float(pTexture->GetTextureData()->h) / 4));
			pump->AddComponentToVector(pType);
			pump->AddComponentToVector(pTexture);
			object->AddChild(pump);
		}
			
		if(pLeftCheck)
		{
			dae::GameObject* pump = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{pump,GameObjectType::Pump};
			auto pCollision = new CollisionComponent{pump};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			pump->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{pump,"PumpLeft.png"};
			pTexture->Update(0,0,0,75,50);
			pump->SetPosition(object->GetPosition().x - (float(pTexture->GetTextureData()->w)),object->GetPosition().y - (float(pTexture->GetTextureData()->h) / 4));
			pump->AddComponentToVector(pType);
			pump->AddComponentToVector(pTexture);
			object->AddChild(pump);
		}
		
		if(pUpCheck)
		{
			dae::GameObject* pump = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{pump,GameObjectType::Pump};
			auto pCollision = new CollisionComponent{pump};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			pump->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{pump,"PumpUp.png"};
			pTexture->Update(0,0,0,50,75);
			pump->SetPosition(object->GetPosition().x - (float(pTexture->GetTextureData()->w) / 5),object->GetPosition().y - (float(pTexture->GetTextureData()->h)));
			pump->AddComponentToVector(pType);
			pump->AddComponentToVector(pTexture);
			object->AddChild(pump);
		}

		if(pDownCheck)
		{
			dae::GameObject* pump = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{pump,GameObjectType::Pump};
			auto pCollision = new CollisionComponent{pump};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			pump->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{pump,"PumpDown.png"};
			pTexture->Update(0,0,0,50,75);
			pump->SetPosition(object->GetPosition().x - (float(pTexture->GetTextureData()->w) / 5),object->GetPosition().y + (float(pTexture->GetTextureData()->h) / 3));
			pump->AddComponentToVector(pType);
			pump->AddComponentToVector(pTexture);
			object->AddChild(pump);
		}
	}

	if (type == ObjectType::Fygar)
	{
		
		auto pState = object->GetStateComp()->GetState();
		
		
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
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireRight.png"};
			pTexture->Update(0,0,0,75,50);
			flame->SetPosition(object->GetPosition().x + (float(pTexture->GetTextureData()->w) / 4),object->GetPosition().y - (float(pTexture->GetTextureData()->h) / 4));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			object->AddChild(flame);
		}
			
		if(pLeftCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireLeft.png"};
			pTexture->Update(0,0,0,75,50);
			flame->SetPosition(object->GetPosition().x - (float(pTexture->GetTextureData()->w)),object->GetPosition().y - (float(pTexture->GetTextureData()->h) / 4));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			object->AddChild(flame);
		}
		
		if(pUpCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireUp.png"};
			pTexture->Update(0,0,0,50,75);
			flame->SetPosition(object->GetPosition().x - (float(pTexture->GetTextureData()->w) / 5),object->GetPosition().y - (float(pTexture->GetTextureData()->h)));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			object->AddChild(flame);
		}

		if(pDownCheck)
		{
			dae::GameObject* flame = new dae::GameObject{};
			TypeComponent* pType = new TypeComponent{flame,GameObjectType::Flame};
			auto pCollision = new CollisionComponent{flame};
			pCollision->SetVecObjectsToCheck(object->GetCollisionComp()->GetObjectVector());
			flame->AddComponentToVector(pCollision);
			pTexture = new TextureComponent{flame,"FireDown.png"};
			pTexture->Update(0,0,0,50,75);
			flame->SetPosition(object->GetPosition().x - (float(pTexture->GetTextureData()->w) / 5),object->GetPosition().y + (float(pTexture->GetTextureData()->h) / 3));
			flame->AddComponentToVector(pType);
			flame->AddComponentToVector(pTexture);
			object->AddChild(flame);
		}
		
	}
}
