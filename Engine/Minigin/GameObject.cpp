#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "FPSComponent.h"
#include "TextureComponent.h"
#include "InputComponent.h"
#include "StateComponent.h"
#include "Font.h"

dae::GameObject::~GameObject()
{
	for (BaseComponent* pComp : m_pComponents)
	{
		delete pComp;
		pComp = nullptr;
	}
	m_pComponents.clear();
	for(GameObject* pChild : m_pChildren)
	{
		delete pChild;
		pChild = nullptr;
	}
	m_pChildren.clear();
};

void dae::GameObject::Update(float deltaTime)
{
	const auto pos = mTransform.GetPosition();
	for (BaseComponent* pComp : m_pComponents)
	{
		if (pComp)
		{
			pComp->Update(deltaTime,pos.x,pos.y);
		}
	}
	for( GameObject* pChild : m_pChildren)
	{
		if(pChild)
		{
			pChild->Update(deltaTime);
		}
	}
}

void dae::GameObject::Render() const
{
	for (BaseComponent* pComp : m_pComponents)
	{
		if(pComp)
		pComp->Render();
	}
	for( GameObject* pChild : m_pChildren)
	{
		if(pChild)
		pChild->Render();
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

void dae::GameObject::DeactivateTextureRendering()
{
	for(auto comp : m_pComponents)
	{
		TextureComponent* derived = dynamic_cast<TextureComponent*>(comp);
		if (derived)
		{
			derived->DeactivateRendering();
		}
	}
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

void dae::GameObject::AddChild(GameObject* child)
{
	m_pChildren.push_back(child);
}

void dae::GameObject::DeleteChildren()
{
	for( GameObject* pChild : m_pChildren)
	{
		delete pChild;
		pChild = nullptr;
	}
	m_pChildren.clear();
}

std::vector<BaseComponent*>& dae::GameObject::GetComponents()
{
	// TODO: insert return statement here
	return m_pComponents;
}
