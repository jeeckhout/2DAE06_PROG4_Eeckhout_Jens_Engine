#include "pch.h"
#include "DigDugScene.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "InputComponent.h"


DigDugScene::DigDugScene(const std::string& name) : Scene{name}
{

}

void DigDugScene::Initialize()
{
	auto go = std::make_shared<dae::GameObject>();
	auto text = new TextureComponent{go.get(),"PlayerSprite.png"};
	auto input = new InputComponent{go.get(),0,PlayerType::Player};
	text->Update(0,0,0,35,35);
	go->AddComponentToVector(text);
	go->AddComponentToVector(input);
	go->SetPosition(440, 280);
	this->Add(go);
	
	auto go2 = std::make_shared<dae::GameObject>();
	auto text2 = new TextureComponent{go2.get(),"PlayerSprite.png"};
	auto input2 = new InputComponent{go2.get(),1,PlayerType::Player};
	text2->Update(0,0,0,35,35);
	go2->AddComponentToVector(text2);
	go2->AddComponentToVector(input2);
	go2->SetPosition(240, 180);
	this->Add(go2);
}

