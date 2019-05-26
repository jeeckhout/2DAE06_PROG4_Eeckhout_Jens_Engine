#pragma once
#include "BaseComponent.h"
#include <string>
#include <memory>
#include <SDL.h>
namespace dae {
	class Texture2D;
}

class TextureComponent final : public BaseComponent
{
public:
	TextureComponent(dae::GameObject *parent, std::string fileName);
	~TextureComponent();
	void Render() override;
	void Update(const float&, float x, float y , float width = 0, float height = 0 ) override;
	void ChangeTexture(std::string fileName);
	void DeactivateRendering();
	SDL_Rect* GetTextureData();
	TextureComponent(const TextureComponent& other) = delete;
	TextureComponent(TextureComponent&& other) = delete;
	TextureComponent& operator=(const TextureComponent& other) = delete;
	TextureComponent& operator=(const TextureComponent&& other) = delete;

private:
	std::shared_ptr<dae::Texture2D> mTexture = nullptr;
	SDL_Rect* textureData{};
	bool m_ShouldRender{true};
};

