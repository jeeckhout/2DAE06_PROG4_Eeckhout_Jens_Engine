#include "pch.h"
#include "Score.h"
#include "Event.h"
#include "GameObject.h"
#include <iostream>

Score::Score()
{
}


Score::~Score()
{
}

void Score::onNotify(const dae::GameObject* entity, Event* event)
{
	m_Score += event->GetScore();
	std::cout << std::endl << m_Score << std::endl;
}
