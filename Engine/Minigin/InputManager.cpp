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
	
Command* dae::InputManager::HandleInput()
{
	for(int i = 0; i < m_ActiveControllers; ++i)
	{
		RtlZeroMemory(&m_State, sizeof(XINPUT_STATE));
		if (XInputGetState(i, &m_State) == ERROR_SUCCESS)
		{
		}
		else
		{
			--m_ActiveControllers;
		}

		if (IsPressed(ControllerButton::ButtonA))
		{
			return ButtonA_Cmd;
		}
		if (IsPressed(ControllerButton::ButtonB))
		{
			return ButtonB_Cmd;
		}
		if (IsPressed(ControllerButton::ButtonX))
		{
			return ButtonX_Cmd;
		}
		if (IsPressed(ControllerButton::ButtonY))
		{
			return ButtonY_Cmd;
		}
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
	default: return false;
	}
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

