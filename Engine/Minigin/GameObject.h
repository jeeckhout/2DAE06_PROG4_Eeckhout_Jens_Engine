#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "vector"

class BaseComponent;
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
		void SetPosition(float x, float y);
		void AddComponentToVector(BaseComponent* componentToAdd);

	private:
		Transform mTransform;
		std::vector<BaseComponent*> m_pComponents; 
	};
}
