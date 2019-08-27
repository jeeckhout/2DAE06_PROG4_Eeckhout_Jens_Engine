#pragma once
class Observer;
class Event;
namespace dae 
{
	class GameObject;
}
class Subject
{
public:
	Subject();
	~Subject();
	void AddObserver(Observer* observer);
	void RemoveObserver(Observer* observer);
	void Notify(const dae::GameObject* object, Event* event);
private:
	std::vector<Observer*> m_VecObservers{};
	int m_NumObservers{};
};

