#include "pch.h"
#include "Block.h"
#include "TextureComponent.h"
#include "GameObject.h"

Block::~Block()
{

}

std::shared_ptr<dae::GameObject> Block::GetGameObject() const
{
	return m_GameObj;
}

void Block::ChangeBlockType(BlockType type)
{
	m_Type = type;

	switch (m_Type)
	{
	case BlockType::Layer1:
		m_TextComp->ChangeTexture("Layer1Block.png");
		break;

	case BlockType::Layer2:
		m_TextComp->ChangeTexture("Layer2Block.png");
		break;

	case BlockType::Layer3:
		m_TextComp->ChangeTexture("Layer3Block.png");
		break;

	case BlockType::Layer4:
		m_TextComp->ChangeTexture("Layer4Block.png");
		break;

	case BlockType::Rock:
		m_TextComp->ChangeTexture("RockBlock.png");
		break;

	case BlockType::Air:
		m_TextComp->ChangeTexture("AirBlock.png");
		break;
	}
}

void Block::CreateObject(BlockType type)
{
	m_Type = type;

	m_GameObj = std::make_shared<dae::GameObject>();

	switch (m_Type)
	{
	case BlockType::Layer1:
		m_TextComp = new TextureComponent{m_GameObj.get(),"Layer1Block.png"};
		m_TextComp->Update(0,0,0,35,35);
		break;

	case BlockType::Layer2:
		m_TextComp = new TextureComponent{m_GameObj.get(),"Layer2Block.png"};
		m_TextComp->Update(0,0,0,35,35);
		break;

	case BlockType::Layer3:
		m_TextComp = new TextureComponent{m_GameObj.get(),"Layer3Block.png"};
		m_TextComp->Update(0,0,0,35,35);
		break;

	case BlockType::Layer4:
		m_TextComp = new TextureComponent{m_GameObj.get(),"Layer4Block.png"};
		m_TextComp->Update(0,0,0,35,35);
		break;

	case BlockType::Rock:
		m_TextComp = new TextureComponent{m_GameObj.get(),"RockBlock.png"};
		m_TextComp->Update(0,0,0,35,35);
		break;

	case BlockType::Air:
		m_TextComp = new TextureComponent{m_GameObj.get(),"AirBlock.png"};
		m_TextComp->Update(0,0,0,35,35);
		break;
	}

	m_GameObj->AddComponentToVector(m_TextComp);
}

void Block::UpdateTextureToFitGridSize(float width, float height)
{
	m_TextComp->Update(0,0,0,width,height);
}
