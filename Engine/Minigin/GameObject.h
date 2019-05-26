#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include "vector"
#include <SDL.h>

class BaseComponent;
class FPSComponent;
class TextureComponent;
class TypeComponent;
class PookaComponent;
class FygarComponent;
class StateComponent;
class CollisionComponent;

namespace dae
{
	class Font;
	class GameObject final : public SceneObject
	{
	public:
		GameObject() = default;
		~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
		void Update(float deltaTime) override;
		void Render() const override;
		void SetPosition(float x, float y);
		const float3& GetPosition();
		SDL_Rect* GetTextureRect();
		void DeactivateTextureRendering();
		void AddComponentToVector(BaseComponent* componentToAdd);
		void UpdateTexture(std::string fileName);
		TypeComponent* GetTypeComp();
		PookaComponent* GetPookaComp();
		FygarComponent* GetFygarComp();
		StateComponent* GetStateComp();
		CollisionComponent* GetCollisionComp();
		void AddChild(GameObject* child);
		void DeleteChildren();


	private:
		Transform mTransform;
		std::vector<BaseComponent*> m_pComponents;
		std::vector<GameObject*> m_pChildren;
	};
}
