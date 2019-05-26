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
    void Update(const float&, float, float, float, float) override;
	void Render() override {;};
	void SetObjectsToCheck(dae::GameObject* object);
	void SetVecObjectsToCheck(std::vector<dae::GameObject*>& objects);
	std::vector<dae::GameObject*>& GetObjectVector();
private:
	std::vector<dae::GameObject*> m_pObjects;
};

