#pragma once
namespace dae {
	class GameObject;
}


class BaseState
{
public:
	virtual ~BaseState() = default;
	virtual void HandleInput(dae::GameObject& player) = 0;
	virtual void Update(dae::GameObject& player) = 0;
	virtual void Enter(dae::GameObject& player) = 0;
	virtual void Exit(dae::GameObject& player) = 0;

	BaseState(const BaseState& other) = delete;
	BaseState(BaseState&& other) = delete;
	BaseState& operator=(const BaseState& other) = delete;
	BaseState& operator=(const BaseState&& other) = delete;
};

