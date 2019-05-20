#pragma once
#include <XInput.h>
#include "Singleton.h"
class Command;
namespace dae
{
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY,
		DpadLeft,
		DpadRight,
		DpadUp,
		DpadDown,
		Start
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		Command* HandleInput(int controllerID);
		bool IsPressed(ControllerButton button) const;
		void AssignCommand(Command* command, ControllerButton buttonToAssign);
		void CheckControllers();
	private:
		XINPUT_STATE m_State{};
		Command* DefaultCommand{};
		Command* ButtonA_Cmd{};
		Command* ButtonX_Cmd{};
		Command* ButtonY_Cmd{};
		Command* ButtonB_Cmd{};

		Command* DPadUp_Cmd{};
		Command* DPadDown_Cmd{};
		Command* DPadLeft_Cmd{};
		Command* DPadRight_Cmd{};
		int m_ActiveControllers{};
	};

}
