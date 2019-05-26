#pragma once
#include "BaseComponent.h"
class BaseState;
class StateComponent final : public BaseComponent
{
public:
	StateComponent(dae::GameObject *parent, BaseState* pDefaultState, BaseState* pDefaultAimState);
	~StateComponent();
	BaseState* GetState() const;
	void SetState(BaseState* newState);
	void SetAimState(BaseState* newState);
	void Update(const float&, float, float, float, float) override{;};
	void Render() override {;};
	StateComponent(const StateComponent& other) = delete;
	StateComponent(StateComponent&& other) = delete;
	StateComponent& operator=(const StateComponent& other) = delete;
	StateComponent& operator=(const StateComponent&& other) = delete;

private:
	BaseState* pState{};
	BaseState* pAimState{};
};

