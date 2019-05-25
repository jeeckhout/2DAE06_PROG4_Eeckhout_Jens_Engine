#include "pch.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "Locator.h"
#include "Audio.h"
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include "FPSComponent.h"
#include "TextureComponent.h"
#include "RightCommand.h"
#include "UpCommand.h"
#include "DownCommand.h"
#include "LeftCommand.h"
#include "AttackCommand.h"


void dae::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		550,
		SDL_WINDOW_OPENGL
	);
	if (window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}
	cmdRight = new RightCommand{};
	cmdLeft = new LeftCommand{};
	cmdUp = new UpCommand{};
	cmdDown = new DownCommand{};
	Renderer::GetInstance().Init(window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	Locator::Initialize();
	InputManager::GetInstance().AssignCommand(cmdRight,ControllerButton::DpadRight);
	InputManager::GetInstance().AssignCommand(cmdLeft,ControllerButton::DpadLeft);
	InputManager::GetInstance().AssignCommand(cmdDown,ControllerButton::DpadDown);
	InputManager::GetInstance().AssignCommand(cmdUp,ControllerButton::DpadUp);
	SceneManager::GetInstance().CreateScene("Demo",SceneType::DigDugLevel1);
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	window = nullptr;

	delete cmdRight;
	cmdRight = nullptr;
	delete cmdLeft;
	cmdLeft = nullptr;
	delete cmdUp;
	cmdUp = nullptr;
	delete cmdDown;
	cmdDown = nullptr;
	
	SDL_Quit();
}

void dae::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();
	{
		auto t = std::chrono::high_resolution_clock::now();
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();
		bool doContinue = true;
		while (doContinue)
		{
			input.CheckControllers();
			auto current = std::chrono::high_resolution_clock::now();
			float deltaTime(std::chrono::duration<float>(current - t).count());
			doContinue = input.ProcessInput();
			sceneManager.Update(deltaTime);
			renderer.Render();
			t = current;
		}
	}

	Cleanup();
}
