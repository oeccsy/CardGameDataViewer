#include "InputSystem.h"
#include <Windows.h>

InputSystem* InputSystem::instance = nullptr;

InputSystem::InputSystem()
{
    instance = this;
}

bool InputSystem::GetKey(int keyCode)
{
    return keyStates[keyCode].isKeyDown;
}

bool InputSystem::GetKeyDown(int keyCode)
{
    return !keyStates[keyCode].previouseKeyDown && keyStates[keyCode].isKeyDown;
}

bool InputSystem::GetKeyUp(int keyCode)
{
    return keyStates[keyCode].previouseKeyDown && !keyStates[keyCode].isKeyDown;
}

InputSystem& InputSystem::Get()
{
    return *instance;
}

void InputSystem::ProcessInput()
{
    for (int i = 0; i < 255; ++i)
    {
        keyStates[i].isKeyDown = GetAsyncKeyState(i) & 0x8000;
    }
}

void InputSystem::SavePreviousKeyStates()
{
    for (int i = 0; i < 255; ++i)
    {
        keyStates[i].previouseKeyDown = keyStates[i].isKeyDown;
    }
}
