#include "pch.h"
#include "iostream"
#include "DigDugScene.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "Grid.h"
#include "CollisionComponent.h"
#include "TypeComponent.h"
#include "PookaComponent.h"
#include "FygarComponent.h"
#include "StateComponent.h"
#include "IdleState.h"
#include "LookRightState.h"


DigDugScene::DigDugScene(const std::string& name) : Scene{name}
{

}

DigDugScene::~DigDugScene()
{
	delete m_pGrid;
	m_pGrid = nullptr;
}

void DigDugScene::Initialize()
{
	m_pGrid = new Grid{640,480,16,16};
	auto ObjectsToAdd = m_pGrid->GetGameObjects();
	for (auto Object : ObjectsToAdd)
	{
		this->Add(Object);
	}

	std::cout << "\nPRESS A/1 FOR SOLO, B/2 FOR COOP OR X/3 FOR VERSUS";
	
	while (!m_HasChosenMode)
	{
		dae::InputManager::GetInstance().CheckControllers();
		dae::InputManager::GetInstance().ProcessInput();
		if (dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonA) || dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::Num1))
		{			CreateSingle();
			m_HasChosenMode = true;
		}
		else if(dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonB)|| dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::Num2))
		{
			CreateCoop();
			m_HasChosenMode = true;
		}
		else if (dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonX)|| dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::Num3))
		{
			CreateVersus();
			m_HasChosenMode = true;
		}

	}

		DoLevelDesign();

	
}

void DigDugScene::CreateCoop()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Player};
	auto type = new TypeComponent{Player1.get(),GameObjectType::Player};
	auto state = new StateComponent{Player1.get(), new IdleState{}, new LookRightState{}};
	text->Update(0,0,0,25,25);
	Player1->AddComponentToVector(text);
	Player1->AddComponentToVector(type);
	Player1->AddComponentToVector(input);
	Player1->AddComponentToVector(state);
	Player1->SetPosition(0,0);
	this->Add(Player1);
	
	Player2 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{Player2.get(),"PlayerSprite.png"};
	auto input2 = new InputComponent{Player2.get(),1,ObjectType::Player};
	auto type2 = new TypeComponent{Player2.get(),GameObjectType::Player};
	auto state2 = new StateComponent{Player2.get(), new IdleState{}, new LookRightState{}};
	text2->Update(0,0,0,25,25);
	Player2->AddComponentToVector(text2);
	Player2->AddComponentToVector(input2);
	Player2->AddComponentToVector(type2);
	Player2->AddComponentToVector(state2);
	Player2->SetPosition(600, 0);
	this->Add(Player2);
}

void DigDugScene::CreateSingle()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Player};
	auto type = new TypeComponent{Player1.get(),GameObjectType::Player};
	auto state = new StateComponent{Player1.get(), new IdleState{}, new LookRightState{}};
	text->Update(0,0,0,25,25);
	Player1->AddComponentToVector(text);
	Player1->AddComponentToVector(type);
	Player1->AddComponentToVector(input);
	Player1->AddComponentToVector(state);
	Player1->SetPosition(0,0);
	this->Add(Player1);
}

void DigDugScene::CreateVersus()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Player};
	auto type = new TypeComponent{Player1.get(),GameObjectType::Player};
	auto state = new StateComponent{Player1.get(), new IdleState{}, new LookRightState{}};
	text->Update(0,0,0,25,25);
	Player1->AddComponentToVector(text);
	Player1->AddComponentToVector(type);
	Player1->AddComponentToVector(input);
	Player1->AddComponentToVector(state);
	Player1->SetPosition(0,0);
	this->Add(Player1);
	
	Player2 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{Player2.get(),"FygarSprite.png"};
	auto input2 = new InputComponent{Player2.get(),1,ObjectType::Fygar};
	auto type2 = new TypeComponent{Player2.get(),GameObjectType::Fygar};
	auto state2 = new StateComponent{Player2.get(), new IdleState{}, new LookRightState{}};
	CollisionComponent* FygarCollision1 = new CollisionComponent{Player2.get()};
	FygarCollision1->SetObjectsToCheck(Player1.get());
	text2->Update(0,0,0,25,25);
	Player2->AddComponentToVector(text2);
	Player2->AddComponentToVector(FygarCollision1);
	Player2->AddComponentToVector(input2);
	Player2->AddComponentToVector(type2);
	Player2->AddComponentToVector(state2);
	Player2->SetPosition(600, 0);
	this->Add(Player2);
}

void DigDugScene::DoLevelDesign()
{
	//Set Air Blocks
	



	//Set Enemies
	auto FygarEnemy1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{FygarEnemy1.get(),"FygarSprite.png"};
	auto fygarState1 = new StateComponent{FygarEnemy1.get(), new IdleState, new LookRightState};
	auto fygarAI = new FygarComponent{FygarEnemy1.get()};
	text->Update(0,0,0,25,25);
	FygarEnemy1->AddComponentToVector(text);
	FygarEnemy1->SetPosition(m_pGrid->GetGrid()[180].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[180].GetGameObject()->GetPosition().y);

	CollisionComponent* FygarCollision1 = new CollisionComponent{FygarEnemy1.get()};
	TypeComponent* FygarType1 = new TypeComponent{FygarEnemy1.get(),GameObjectType::Fygar};
	if (Player1)
	{
		FygarCollision1->SetObjectsToCheck(Player1.get());
	}
	if(Player2)
	{
		FygarCollision1->SetObjectsToCheck(Player2.get());
	}
	FygarEnemy1->AddComponentToVector(FygarCollision1);
	FygarEnemy1->AddComponentToVector(FygarType1);
	FygarEnemy1->AddComponentToVector(fygarState1);
	FygarEnemy1->AddComponentToVector(fygarAI);
	this->Add(FygarEnemy1);

	auto PookaEnemy1 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{PookaEnemy1.get(),"PookaSprite.png"};
	text2->Update(0,0,0,25,25);
	PookaEnemy1->AddComponentToVector(text2);
	PookaEnemy1->SetPosition(m_pGrid->GetGrid()[108].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[108].GetGameObject()->GetPosition().y);

	CollisionComponent* PookaCollision1 = new CollisionComponent{PookaEnemy1.get()};
	PookaComponent* PookaAI = new PookaComponent{PookaEnemy1.get()};
	TypeComponent* pookaType1 = new TypeComponent{PookaEnemy1.get(),GameObjectType::Pooka};
	if (Player1)
	{
		PookaCollision1->SetObjectsToCheck(Player1.get());
	}
	if(Player2)
	{
		PookaCollision1->SetObjectsToCheck(Player2.get());
	}
	PookaEnemy1->AddComponentToVector(PookaCollision1);
	PookaEnemy1->AddComponentToVector(PookaAI);
	PookaEnemy1->AddComponentToVector(pookaType1);
	this->Add(PookaEnemy1);

	auto FygarEnemy2 = std::make_shared<dae::GameObject>();
	auto text3 = new TextureComponent{FygarEnemy1.get(),"FygarSprite.png"};
	auto FygarType2 = new TypeComponent{FygarEnemy2.get(),GameObjectType::Fygar};
	auto FygarState2 = new StateComponent{FygarEnemy2.get(),new IdleState, new LookRightState};
	auto FygarAI2 = new FygarComponent{FygarEnemy2.get()};
	auto FygarCollision2 = new CollisionComponent{FygarEnemy2.get()};
	if (Player1)
	{
		FygarCollision2->SetObjectsToCheck(Player1.get());
	}
	if(Player2)
	{
		FygarCollision2->SetObjectsToCheck(Player2.get());
	}
	text3->Update(0,0,0,25,25);
	FygarEnemy2->AddComponentToVector(text3);
	FygarEnemy2->AddComponentToVector(FygarCollision2);
	FygarEnemy2->AddComponentToVector(FygarState2);
	FygarEnemy2->AddComponentToVector(FygarAI2);
	FygarEnemy2->AddComponentToVector(FygarType2);
	FygarEnemy2->SetPosition(m_pGrid->GetGrid()[70].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[70].GetGameObject()->GetPosition().y);
	this->Add(FygarEnemy2);

	auto ObjectsToAdd = m_pGrid->GetGameObjects();
	for (auto Object : ObjectsToAdd)
	{
		CollisionComponent* blockCollision = new CollisionComponent{Object.get()};
		if (Player1)
		{
			blockCollision->SetObjectsToCheck(Player1.get());
		}
		if(Player2)
		{
			blockCollision->SetObjectsToCheck(Player2.get());
		}
		blockCollision->SetObjectsToCheck(PookaEnemy1.get());
		blockCollision->SetObjectsToCheck(FygarEnemy1.get());
		blockCollision->SetObjectsToCheck(FygarEnemy2.get());
		Object->AddComponentToVector(blockCollision);
	}

	auto collision = new CollisionComponent{Player1.get()};
	collision->SetObjectsToCheck(FygarEnemy1.get());
	collision->SetObjectsToCheck(FygarEnemy2.get());
	collision->SetObjectsToCheck(PookaEnemy1.get());

	

	if(Player2)
	{

		{
			auto collision2 = new CollisionComponent{Player2.get()};
			collision2->SetObjectsToCheck(FygarEnemy1.get());
			collision2->SetObjectsToCheck(FygarEnemy2.get());
			collision2->SetObjectsToCheck(PookaEnemy1.get());
			Player2->AddComponentToVector(collision2);
		}
	}
	Player1->AddComponentToVector(collision);

}

