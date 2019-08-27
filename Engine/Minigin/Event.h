#pragma once
class Event
{
public:
	Event();
	~Event();
	int GetScore()const{return m_Value;}
protected:
	int m_Value{};
};

