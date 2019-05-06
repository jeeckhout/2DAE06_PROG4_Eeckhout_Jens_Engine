#pragma once
#include "BaseComponent.h"
#include <string>
#include <memory>
#include "Texture2D.h"
#include <SDL.h>



class TextureComponent final : public BaseComponent
{
public:
	TextureComponent(dae::GameObject *parent, std::string fileName);
	void Render() override;
	void Update(const float&, float x, float y , float width = 0, float height = 0 ) override;

private:
	std::shared_ptr<dae::Texture2D> mTexture = nullptr;
	SDL_Rect textureData{};
};

