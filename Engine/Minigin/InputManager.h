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
		W,
		A,
		S,
		D,
		E,
		Num1,
		Num2,
		Num3,
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
		void SetAReleasedCommand(Command* cmd);
	private:
		XINPUT_STATE m_State{};
		Command* DefaultCommand{};
		Command* ButtonA_Cmd{};
		Command* ButtonX_Cmd{};
		Command* ButtonY_Cmd{};
		Command* ButtonB_Cmd{};
		Command* ButtonAReleased_Cmd{};
		Command* DPadUp_Cmd{};
		Command* DPadDown_Cmd{};
		Command* DPadLeft_Cmd{};
		Command* DPadRight_Cmd{};
		int m_ActiveControllers{};

		bool m_IsAPressed{false};
	};

}
