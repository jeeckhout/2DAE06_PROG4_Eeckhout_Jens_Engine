#pragma once
#include "BaseComponent.h"
struct float2
{
	float x{};
	float y{};
};

enum class Action
{
	Up,
	Down,
	Left,
	Right
};

class PookaComponent final : public BaseComponent
{
public:
	PookaComponent(dae::GameObject *parent);
	~PookaComponent() = default;
	void Update(const float& deltaTime, float, float, float, float) override;
	void Render() override {;};
	void StopMovement();
private:
	float m_ActionTimer{};
	float2 m_Velocity{100.f,100.f};
	Action m_CurrAction{};
	bool m_IsPerformingAction{false};
	void MoveUp(const float& deltaTime);
	void MoveDown(const float& deltaTime);
	void MoveRight(const float& deltaTime);
	void MoveLeft(const float& deltaTime);
};

