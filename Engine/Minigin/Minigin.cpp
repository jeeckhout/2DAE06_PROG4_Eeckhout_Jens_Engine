#include "MiniginPCH.h"
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
		480,
		SDL_WINDOW_OPENGL
	);
	if (window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(window);
}

/**
 * Code constructing the scene world starts here
 */
void dae::Minigin::LoadGame() const
{
	Locator::Initialize();

	Audio *service = new ConsoleAudio;
	std::string Music{"./Resources/Music.wav"};
	service->AddMusic(Music);
	Locator::Provide(service);
	service->PlayMusic(0);
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");
	auto go = std::make_shared<GameObject>();
	go->SetTexture("logo.png");
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go->SetPosition(216, 180);
	go->InitializeFPS();
	go->SetFontFPS(font);
	scene.Add(go);

	
	auto to = std::make_shared<TextObject>("Programming 4 Assignment", font);
	to->SetPosition(80, 20);
	scene.Add(to);
}

void dae::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(window);
	window = nullptr;
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
		Locator::Initialize();
		Audio *service = new ConsoleAudio;
		std::string Music{"Resources/Music.wav"};
		service->AddMusic(Music);
		Locator::Provide(service);
		service->PlayMusic(0);
		bool doContinue = true;
		while (doContinue)
		{
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
