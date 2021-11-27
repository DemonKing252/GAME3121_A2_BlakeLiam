#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
#include <Windows.h>


#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"


using namespace Ogre;
using namespace OgreBites;

// Behaviour is extended from std::exception in case while were checking for duplicated key exceptions
// we run into a out of bounds exception
struct KeyOverrideException : public std::exception
{

	KeyOverrideException(std::string msg) : message(msg) {}
	std::string get() const;
private:
	std::string message;
};

class InputEngine
{
protected:
	std::unordered_map<Keycode, std::function<void()>> m_keyDownDelegates;
	std::unordered_map<Keycode, std::function<void()>> m_keyUpDelegates;

	InputEngine();

	static InputEngine* s_pInstance;
public:
	~InputEngine();

	static InputEngine* GetInstance();

	void AddKeyDownListener(Keycode param1, void(*callback)());
	void AddKeyUpListener(Keycode param1, void(*callback)());

	void RemoveInputListener(Keycode param1);
	void PollEvents(const KeyboardEvent& evt);
	
	// To whom it may concern:
	// I don't recommend you define your callbacks here
	// Your methods have to be type static void (no return type) for this to work
};