#include "MiniginPCH.h"
#include "Subject.h"
#include "Observer.h"
#include "GameObject.h"
#include "Event.h"
Subject::Subject()
{
}


Subject::~Subject()
{

}

void Subject::AddObserver(Observer * observer)
{
	m_VecObservers.push_back(observer);
	++m_NumObservers;
}

void Subject::RemoveObserver(Observer * observer)
{
	for(int i{}; i < int(m_VecObservers.size()); ++i)
		{
			if (observer == m_VecObservers[i])
			{
				std::swap(m_VecObservers[i],m_VecObservers[m_VecObservers.size()]);
				delete m_VecObservers[m_VecObservers.size()];
				m_VecObservers.pop_back();
				--m_NumObservers;
			}
		}
}

void Subject::Notify(const dae::GameObject* object, Event* event)
{
  for(Observer* pObserver : m_VecObservers)
  {
	  pObserver->onNotify(object,event);
  }
}
