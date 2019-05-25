#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "FPSComponent.h"
#include "TextureComponent.h"
#include "InputComponent.h"
#include "TypeComponent.h"
#include "Font.h"

dae::GameObject::~GameObject()
{
	for (BaseComponent* pComp : m_pComponents)
	{
		delete pComp;
	}
};

void dae::GameObject::Update(float deltaTime)
{
	const auto pos = mTransform.GetPosition();
	for (BaseComponent* pComp : m_pComponents)
	{
		pComp->Update(deltaTime,pos.x,pos.y);
	}
}

void dae::GameObject::Render() const
{
	for (BaseComponent* pComp : m_pComponents)
	{
		pComp->Render();
	}
}

void dae::GameObject::SetPosition(float x, float y)
{
	mTransform.SetPosition(x, y, 0.0f);
}

const dae::float3& dae::GameObject::GetPosition()
{
	return mTransform.GetPosition();
}

SDL_Rect* dae::GameObject::GetTextureRect()
{
	for(auto comp : m_pComponents)
	{
		TextureComponent* derived = dynamic_cast<TextureComponent*>(comp);
		if (derived)
		{
			return derived->GetTextureData();
		}
	}

	return nullptr;
}

void dae::GameObject::AddComponentToVector(BaseComponent* componentToAdd)
{
	m_pComponents.push_back(componentToAdd);
}

void dae::GameObject::UpdateTexture(std::string fileName)
{
	for(auto comp : m_pComponents)
	{
		TextureComponent* derived = dynamic_cast<TextureComponent*>(comp);
		if (derived)
		{
			derived->ChangeTexture(fileName);
		}
	}
}

TypeComponent* dae::GameObject::GetTypeComp()
{
	for(auto comp : m_pComponents)
	{
		TypeComponent* derived = dynamic_cast<TypeComponent*>(comp);
		if (derived)
		{
			return derived;
		}
	}
	return nullptr;
}
