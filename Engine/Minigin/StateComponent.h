#pragma once
#include "BaseComponent.h"
class BaseState;
class StateComponent final : public BaseComponent
{
public:
	StateComponent(dae::GameObject *parent, BaseState* pDefaultState);
	~StateComponent();
	BaseState* GetState() const;
	StateComponent(const StateComponent& other) = delete;
	StateComponent(StateComponent&& other) = delete;
	StateComponent& operator=(const StateComponent& other) = delete;
	StateComponent& operator=(const StateComponent&& other) = delete;
	void Update(const float& deltaTime, float x, float y, float width, float height) override;
private:
	BaseState* pState;
};

