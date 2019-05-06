#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "SDL.h"


TextureComponent::TextureComponent(dae::GameObject *parent, std::string fileName) : BaseComponent(parent)
{
	mTexture = dae::ResourceManager::GetInstance().LoadTexture(fileName);	
}

void TextureComponent::Render()
{
	dae::Renderer::GetInstance().RenderTexture(*mTexture,textureData);
}

void TextureComponent::Update(const float&, float x, float y, float width, float height)
{
	textureData.x = int(x);
	textureData.y = int(y);
	textureData.w = int(width);
	textureData.h = int(height);
}
