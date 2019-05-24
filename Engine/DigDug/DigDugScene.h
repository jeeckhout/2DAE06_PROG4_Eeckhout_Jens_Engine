#pragma once
#include  "Scene.h"
class DigDugScene final : public dae::Scene
{
public:
	DigDugScene(const std::string& name);
	~DigDugScene() = default;
	void Initialize() override;
};

