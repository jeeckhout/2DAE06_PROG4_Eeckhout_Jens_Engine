#pragma once
namespace dae 
{
	class GameObject;
}

class BaseComponent
{
public:
	BaseComponent(dae::GameObject* parent);
	virtual ~BaseComponent() = default;
	virtual void Update(const float& deltaTime, float x, float y, float width = 0, float height = 0) = 0;
	virtual void Render() = 0;
	BaseComponent(const BaseComponent& other) = delete;
	BaseComponent(BaseComponent&& other) = delete;
	BaseComponent& operator=(const BaseComponent& other) = delete;
	BaseComponent& operator=(const BaseComponent&& other) = delete;
	const dae::GameObject& getParent() const;

protected:
	dae::GameObject* m_pParent;
};

