#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "FPSComponent.h"
#include "TextureComponent.h"
#include "Font.h"

dae::GameObject::~GameObject()
{
	delete test;
	delete mTexture;
};

void dae::GameObject::Update(float deltaTime)
{
	test->Update(deltaTime);
	totalTime += deltaTime;
	const auto pos = mTransform.GetPosition();
	mTexture->UpdateTextureData(pos.x,pos.y);
}

void dae::GameObject::Render() const
{
	mTexture->Render();
	test->Render();
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	mTexture = new TextureComponent(this,filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	mTransform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::InitializeFPS()
{
	test = new FPSComponent{ this };
}

void dae::GameObject::SetFontFPS(std::shared_ptr<dae::Font> font)
{
	test->MakeFont(font);
}

void dae::GameObject::SetFontFPS(const std::string& fontPath, unsigned fontSize)
{
	test->MakeFont(fontPath, fontSize);
}
