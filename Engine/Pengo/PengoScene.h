#pragma once
#include "Scene.h"
#include "memory"
class Grid;
namespace dae
{
	class GameObject;
}
class PengoScene final :public dae::Scene
{
public:
	PengoScene(const std::string& name);
	~PengoScene();

	
private:
	Grid* m_pGrid{};
	std::shared_ptr<dae::GameObject> Player1{};
	std::shared_ptr<dae::GameObject> Player2{};
	bool m_HasChosenMode{false};
};

