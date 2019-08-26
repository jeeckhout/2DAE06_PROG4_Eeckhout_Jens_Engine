#include "pch.h"
#include "Windows.h"
#include "Grid.h"
#include "PengoScene.h"
#include "InputManager.h"
#include <iostream>
#include "LookRightState.h"
#include "IdleState.h"
#include "StateComponent.h"
#include <TypeComponent.h>
#include "InputComponent.h"
#include "TextureComponent.h"
#include "GameObject.h"
#include "RightCommand.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "LeftCommand.h"
#include "AttackCommand.h"
#include "CollisionComponent.h"
#include "PookaComponent.h"


PengoScene::PengoScene(const std::string& name) : Scene(name)
{
}

PengoScene::~PengoScene()
{
	delete cmdRight;
	cmdRight = nullptr;
	delete cmdLeft;
	cmdLeft = nullptr;
	delete cmdUp;
	cmdUp = nullptr;
	delete cmdDown;
	cmdDown = nullptr;
	delete cmdAttack;
	cmdAttack = nullptr;

	delete m_pGrid;
	m_pGrid = nullptr;
}

void PengoScene::Initialize()
{
	//SET UP CONTROLS
	cmdRight = new RightCommand{};
	cmdLeft = new LeftCommand{};
	cmdUp = new UpCommand{};
	cmdDown = new DownCommand{};
	cmdAttack = new AttackCommand{};

	dae::InputManager::GetInstance().AssignCommand(cmdRight, dae::ControllerButton::DpadRight);
	dae::InputManager::GetInstance().AssignCommand(cmdLeft, dae::ControllerButton::DpadLeft);
	dae::InputManager::GetInstance().AssignCommand(cmdDown, dae::ControllerButton::DpadDown);
	dae::InputManager::GetInstance().AssignCommand(cmdUp, dae::ControllerButton::DpadUp);
	dae::InputManager::GetInstance().AssignCommand(cmdAttack, dae::ControllerButton::ButtonA);

	//SET UP GRID
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
		{
			CreateSingle();
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

	CreateLevel();
}

void PengoScene::CreateCoop()
{
		Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Pengo};
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
	auto input2 = new InputComponent{Player2.get(),1,ObjectType::Pengo};
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

void PengoScene::CreateSingle()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Pengo};
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

void PengoScene::CreateVersus()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Pengo};
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
	auto input2 = new InputComponent{Player2.get(),1,ObjectType::Pengo};
	auto type2 = new TypeComponent{Player2.get(),GameObjectType::Snowbee};
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

void PengoScene::CreateLevel()
{
	m_pGrid->GetGrid()[182].ChangeBlockType(BlockType::IceBlock);
	auto blockComponents = m_pGrid->GetGrid()[182].GetGameObject()->GetComponents();
	TypeComponent* pType{};
	bool foundType{false};
	for(BaseComponent* pComp : blockComponents)
	{
		pType = dynamic_cast<TypeComponent*>(pComp);
		if (pType)
		{
			foundType = true;
		}
	}
	if (foundType)
	{
		pType->SetType(GameObjectType::IceBlock);
	}

	auto PookaEnemy1 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{PookaEnemy1.get(),"PookaSprite.png"};
	text2->Update(0,0,0,25,25);
	PookaEnemy1->AddComponentToVector(text2);
	PookaEnemy1->SetPosition(m_pGrid->GetGrid()[108].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[108].GetGameObject()->GetPosition().y);

	CollisionComponent* PookaCollision1 = new CollisionComponent{PookaEnemy1.get()};
	PookaComponent* PookaAI = new PookaComponent{PookaEnemy1.get(),true,0.f};
	TypeComponent* pookaType1 = new TypeComponent{PookaEnemy1.get(),GameObjectType::Snowbee};
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

	auto PookaEnemy2 = std::make_shared<dae::GameObject>();
	auto text3 = new TextureComponent{PookaEnemy2.get(),"IceBlock.png"};
	text3->Update(0,0,0,25,25);
	PookaEnemy2->AddComponentToVector(text3);
	PookaEnemy2->SetPosition(m_pGrid->GetGrid()[60].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[60].GetGameObject()->GetPosition().y);

	CollisionComponent* PookaCollision2 = new CollisionComponent{PookaEnemy2.get()};
	PookaComponent* PookaAI2 = new PookaComponent{PookaEnemy2.get(),false,10.f};
	TypeComponent* pookaType2 = new TypeComponent{PookaEnemy2.get(),GameObjectType::EggBlock};
	if (Player1)
	{
		PookaCollision2->SetObjectsToCheck(Player1.get());
	}
	if(Player2)
	{
		PookaCollision2->SetObjectsToCheck(Player2.get());
	}
	PookaEnemy2->AddComponentToVector(PookaCollision2);
	PookaEnemy2->AddComponentToVector(PookaAI2);
	PookaEnemy2->AddComponentToVector(pookaType2);
	this->Add(PookaEnemy2);
}
