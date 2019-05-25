#pragma once
#include  "Scene.h"
#include "memory"
class Grid;
namespace dae
{
	class GameObject;
}
class DigDugScene final : public dae::Scene
{
public:
	DigDugScene(const std::string& name);
	~DigDugScene();

private:
	Grid* m_pGrid{};
	std::shared_ptr<dae::GameObject> Player1{};
	std::shared_ptr<dae::GameObject> Player2{};
	bool m_HasChosenMode{false};

	void Initialize() override;
	void CreateCoop();
	void CreateSingle();
	void CreateVersus();
	void DoLevelDesign();

};

