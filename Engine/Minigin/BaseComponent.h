#pragma once
namespace dae {
	class GameObject;
}

class BaseComponent
{
public:
	BaseComponent(dae::GameObject* parent);
	virtual ~BaseComponent() = default;
	virtual void Update(float deltaTime) = 0;
	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(const BaseComponent&& other) = delete;
	const dae::GameObject& getParent() const;

private:
	dae::GameObject* m_pParent;
};

