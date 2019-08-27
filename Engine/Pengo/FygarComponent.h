#pragma once
#include "BaseComponent.h"
struct float2Fygar
{
	float x{};
	float y{};
};

enum class ActionFygar
{
	Up,
	Down,
	Left,
	Right,
	FireFlame,
};
class FygarComponent final : public BaseComponent
{
public:
	FygarComponent(dae::GameObject *parent);
	~FygarComponent() = default;

	void Update(const float& deltaTime, float, float, float, float) override;
	void Render() override {;};
	void StopMovement();
	void StopFire();
private:
	float m_ActionTimer{};
	float2Fygar m_Velocity{100.f,100.f};

	ActionFygar m_CurrAction{};
	bool m_IsPerformingAction{false};
	void MoveUp(const float& deltaTime);
	void MoveDown(const float& deltaTime);
	void MoveRight(const float& deltaTime);
	void MoveLeft(const float& deltaTime);
	void Fire();
	void UpdateFire(const float& deltaTime);
	bool canFire{true};

};

