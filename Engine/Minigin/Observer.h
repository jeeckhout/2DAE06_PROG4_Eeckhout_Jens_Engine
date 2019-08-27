#pragma once
namespace dae 
{
	class GameObject;
}
class Event;
class Observer
{
public:
	Observer();
	virtual ~Observer(){};
	virtual void onNotify(const dae::GameObject* entity, Event* event) = 0;
};

