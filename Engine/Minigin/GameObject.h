#pragma once
#include <memory>
#include "Transform.h"
#include "Texture2D.h"
#include "SceneObject.h"
class FPSComponent;
class TextureComponent;

namespace dae
{
	class Font;
	class GameObject final : public SceneObject
	{
	public:
		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
		void Update(float deltaTime) override;
		void Render() const override;
		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
		void InitializeFPS();
		void SetFontFPS(std::shared_ptr<Font> font);
		void SetFontFPS(const std::string& fontPath, unsigned fontSize);

	private:
		Transform mTransform;
		TextureComponent* mTexture{nullptr};
		float totalTime{};
		FPSComponent* test{};

	};
}
