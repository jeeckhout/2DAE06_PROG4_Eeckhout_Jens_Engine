#pragma once
#include "Observer.h"

class Score : public Observer
{
public:
	Score();
	~Score();
	void onNotify(const dae::GameObject* entity, Event* event) override;

private:
	int m_Score{};
};

