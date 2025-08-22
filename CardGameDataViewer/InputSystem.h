#pragma once

class InputSystem
{
	struct KeyState
	{
		bool isKeyDown = false;
		bool previouseKeyDown = false;
	};

public:
	InputSystem();

	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	static InputSystem& Get();

	void ProcessInput();
	void SavePreviousKeyStates();

private:
	KeyState keyStates[255] = { };

	static InputSystem* instance;
};