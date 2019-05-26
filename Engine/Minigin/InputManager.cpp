#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>
#include "Commands.h"


bool dae::InputManager::ProcessInput()
{
	for (int i = 0; i < m_ActiveControllers; ++i)
	{
		ZeroMemory(&m_State, sizeof(XINPUT_STATE));
		XInputGetState(i, &m_State);

		SDL_Event e;
		while (SDL_PollEvent(&e)) 
		{
			if (e.type == SDL_QUIT) 
			{
				return false;
			}
			if (e.type == SDL_KEYDOWN) 
			{
				
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) 
			{
				
			}
		}
		if (IsPressed(ControllerButton::Start))
		{
			return false;
		}
	}
	return  true;
}
	
Command* dae::InputManager::HandleInput(int controllerID)
{
		RtlZeroMemory(&m_State, sizeof(XINPUT_STATE));
		if (XInputGetState(controllerID, &m_State) == ERROR_SUCCESS)
		{
		}
		else
		{
			--m_ActiveControllers;
		}



		if (IsPressed(ControllerButton::ButtonA) || IsPressed(ControllerButton::E))
		{
			m_IsAPressed = true;
			return ButtonA_Cmd;
		}
		if (IsPressed(ControllerButton::ButtonB))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return ButtonB_Cmd;
		}
		if (IsPressed(ControllerButton::ButtonX))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return ButtonX_Cmd;
		}
		if (IsPressed(ControllerButton::ButtonY))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return ButtonY_Cmd;
		}
		if (IsPressed(ControllerButton::DpadRight) || (IsPressed(ControllerButton::D) && controllerID == 0))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return DPadRight_Cmd;
		}
		if (IsPressed(ControllerButton::DpadLeft) || (IsPressed(ControllerButton::A) && controllerID == 0))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return DPadLeft_Cmd;
		}
		if (IsPressed(ControllerButton::DpadUp) || (IsPressed(ControllerButton::W) && controllerID == 0))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return DPadUp_Cmd;
		}
		if (IsPressed(ControllerButton::DpadDown) || (IsPressed(ControllerButton::S) && controllerID == 0))
		{
			if (m_IsAPressed == true)
			{
				m_IsAPressed = false;
				return ButtonAReleased_Cmd;
			}
			return DPadDown_Cmd;
		}

	return DefaultCommand;
}

bool dae::InputManager::IsPressed(ControllerButton button) const
{
		switch (button)
		{
		case ControllerButton::ButtonA:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_A;
		case ControllerButton::ButtonB:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_B;
		case ControllerButton::ButtonX:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_X;
		case ControllerButton::ButtonY:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
		case ControllerButton::DpadDown:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN;
		case ControllerButton::DpadUp:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP;
		case ControllerButton::DpadLeft:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT;
		case ControllerButton::DpadRight:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT;
		case ControllerButton::Start:
			return m_State.Gamepad.wButtons & XINPUT_GAMEPAD_START;
		case ControllerButton::W:
			return GetKeyState('W') & 0x8000;
		case ControllerButton::A:
			return GetKeyState('A') & 0x8000;
		case ControllerButton::S:
			return GetKeyState('S') & 0x8000;
		case ControllerButton::D:
			return GetKeyState('D') & 0x8000;
		case ControllerButton::E:
			return GetKeyState('E') & 0x8000;
		case ControllerButton::Num1:
			return GetKeyState(VK_NUMPAD1) & 0x8000;
		case ControllerButton::Num2:
			return GetKeyState(VK_NUMPAD2) & 0x8000;
		case ControllerButton::Num3:
			return GetKeyState(VK_NUMPAD3) & 0x8000;
		}
	return false;
}

void dae::InputManager::AssignCommand(Command* command, ControllerButton buttonToAssign)
{
	switch (buttonToAssign)
	{
		case ControllerButton::ButtonA:
			ButtonA_Cmd = command;
			break;

		case ControllerButton::ButtonB:
			ButtonB_Cmd = command;
			break;

		case ControllerButton::ButtonX:
			ButtonX_Cmd = command;
			break;

		case ControllerButton::ButtonY:
			ButtonY_Cmd = command;
			break;

		case ControllerButton::DpadUp:
			DPadUp_Cmd = command;
			break;

		case ControllerButton::DpadDown:
			DPadDown_Cmd = command;
			break;

		case ControllerButton::DpadLeft:
			DPadLeft_Cmd = command;
			break;

		case ControllerButton::DpadRight:
			DPadRight_Cmd = command;
			break;

		default:;
	}
}

void dae::InputManager::CheckControllers()
{
	m_ActiveControllers = 0;
	for(int i = 0; i < 4; ++i)
	{
		RtlZeroMemory(&m_State, sizeof(XINPUT_STATE));
		if (XInputGetState(i, &m_State) == ERROR_SUCCESS)
		{
			++m_ActiveControllers;
		}
	}
}

void dae::InputManager::SetAReleasedCommand(Command* cmd)
{
	ButtonAReleased_Cmd = cmd;
}

