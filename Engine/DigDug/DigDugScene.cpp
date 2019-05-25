#include "pch.h"
#include "DigDugScene.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "InputComponent.h"
#include "InputManager.h"
#include "Grid.h"
#include "CollisionComponent.h"
#include "TypeComponent.h"


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

	while (!m_HasChosenMode)
	{
		dae::InputManager::GetInstance().CheckControllers();
		dae::InputManager::GetInstance().ProcessInput();
		if (dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonA))
		{
			CreateSingle();
			m_HasChosenMode = true;
		}
		else if(dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonB))
		{
			CreateCoop();
			m_HasChosenMode = true;
		}
		else if (dae::InputManager::GetInstance().IsPressed(dae::ControllerButton::ButtonX))
		{
			CreateVersus();
			m_HasChosenMode = true;
		}

	}

		DoLevelDesign();

	for (auto Object : ObjectsToAdd)
	{
		CollisionComponent* blockCollision = new CollisionComponent{Object.get()};
		TypeComponent* blockType = new TypeComponent{Object.get(),GameObjectType::Block};
		if (Player1)
		{
			blockCollision->SetObjectsToCheck(Player1.get());
		}
		if(Player2)
		{
			blockCollision->SetObjectsToCheck(Player2.get());
		}
		Object->AddComponentToVector(blockCollision);
		Object->AddComponentToVector(blockType);

	}
}

void DigDugScene::CreateCoop()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Player};
	text->Update(0,0,0,25,25);
	Player1->AddComponentToVector(text);
	Player1->AddComponentToVector(input);
	Player1->SetPosition(0,0);
	this->Add(Player1);
	
	Player2 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{Player2.get(),"PlayerSprite.png"};
	auto input2 = new InputComponent{Player2.get(),1,ObjectType::Player};
	text2->Update(0,0,0,25,25);
	Player2->AddComponentToVector(text2);
	Player2->AddComponentToVector(input2);
	Player2->SetPosition(600, 0);
	this->Add(Player2);
}

void DigDugScene::CreateSingle()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Player};
	auto type = new TypeComponent{Player1.get(),GameObjectType::Player};
	text->Update(0,0,0,25,25);
	Player1->AddComponentToVector(text);
	Player1->AddComponentToVector(type);
	Player1->AddComponentToVector(input);
	Player1->SetPosition(0,0);
	this->Add(Player1);
}

void DigDugScene::CreateVersus()
{
	Player1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{Player1.get(),"PlayerSprite.png"};
	auto input = new InputComponent{Player1.get(),0,ObjectType::Player};
	text->Update(0,0,0,25,25);
	Player1->AddComponentToVector(text);
	Player1->AddComponentToVector(input);
	Player1->SetPosition(0,0);
	this->Add(Player1);
	
	Player2 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{Player2.get(),"FygarSprite.png"};
	auto input2 = new InputComponent{Player2.get(),1,ObjectType::Fygar};
	text2->Update(0,0,0,25,25);
	Player2->AddComponentToVector(text2);
	Player2->AddComponentToVector(input2);
	Player2->SetPosition(600, 0);
	this->Add(Player2);
}

void DigDugScene::DoLevelDesign()
{
	//Set Air Blocks
	m_pGrid->GetGrid()[69].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[70].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[71].ChangeBlockType(BlockType::Air);

	m_pGrid->GetGrid()[96].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[97].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[98].ChangeBlockType(BlockType::Air);

	m_pGrid->GetGrid()[92].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[108].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[124].ChangeBlockType(BlockType::Air);

	m_pGrid->GetGrid()[180].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[181].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[182].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[179].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[178].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[164].ChangeBlockType(BlockType::Air);
	m_pGrid->GetGrid()[196].ChangeBlockType(BlockType::Air);


	//Set Enemies
	auto FygarEnemy1 = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{FygarEnemy1.get(),"FygarSprite.png"};
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
	this->Add(FygarEnemy1);

	auto PookaEnemy1 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{PookaEnemy1.get(),"PookaSprite.png"};
	text2->Update(0,0,0,25,25);
	PookaEnemy1->AddComponentToVector(text2);
	PookaEnemy1->SetPosition(m_pGrid->GetGrid()[108].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[108].GetGameObject()->GetPosition().y);

	CollisionComponent* PookaCollision1 = new CollisionComponent{PookaEnemy1.get()};
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
	PookaEnemy1->AddComponentToVector(pookaType1);
	this->Add(PookaEnemy1);

	auto FygarEnemy2 = std::make_shared<dae::GameObject>();
	auto text3 = new TextureComponent{FygarEnemy1.get(),"FygarSprite.png"};
	text3->Update(0,0,0,25,25);
	FygarEnemy2->AddComponentToVector(text3);
	FygarEnemy2->SetPosition(m_pGrid->GetGrid()[70].GetGameObject()->GetPosition().x,m_pGrid->GetGrid()[70].GetGameObject()->GetPosition().y);
	this->Add(FygarEnemy2);
}

