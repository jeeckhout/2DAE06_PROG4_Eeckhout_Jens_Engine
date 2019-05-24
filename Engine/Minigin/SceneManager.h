#pragma once
#include "Singleton.h"

namespace dae
{
	enum class SceneType
	{
		Standard,
		DigDugLevel1,
		DigDugLevel2,
		MainMenu,
		GameOverMenu,
	};
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		void CreateScene(const std::string& name, SceneType type);

		void Update(float deltaTime);
		void Render();

	private:
		std::vector<std::shared_ptr<Scene>> mScenes;
	};

}
