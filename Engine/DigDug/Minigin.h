#pragma once

struct SDL_Window;
class RightCommand;
class LeftCommand;
class UpCommand;
class DownCommand;
class AttackCommand;
class StopAttackCommand;

namespace dae
{
	class Minigin
	{
		const int msPerFrame = 16; //16 for 60 fps, 33 for 30 fps
		SDL_Window* window{};
	public:
		void Initialize();
		void LoadGame() const;
		void Cleanup();
		void Run();

	private:
		RightCommand* cmdRight{};
		LeftCommand* cmdLeft{};
		UpCommand* cmdUp{};
		DownCommand* cmdDown{};
		AttackCommand* cmdAttack{};
		StopAttackCommand* cmdStopAttack{};
	};
}