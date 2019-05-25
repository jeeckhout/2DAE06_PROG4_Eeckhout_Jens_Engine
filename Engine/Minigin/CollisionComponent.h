#pragma once
#include "BaseComponent.h"
#include "vector"

namespace dae 
{
	class GameObject;
}
class CollisionComponent : public BaseComponent
{
public:
	CollisionComponent(dae::GameObject *parent);
	~CollisionComponent();
    void Update(const float&, float, float, float, float);
	void Render(){;};
	void SetObjectsToCheck(dae::GameObject* object);

private:
	std::vector<dae::GameObject*> m_pObjects;
};

