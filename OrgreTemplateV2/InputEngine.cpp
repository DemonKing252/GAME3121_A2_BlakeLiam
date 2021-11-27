#include "InputEngine.h"

Liam::InputEngine* Liam::InputEngine::s_pInstance = nullptr;

Liam::InputEngine::InputEngine()
{
}

Liam::InputEngine::~InputEngine()
{
}

Liam::InputEngine* Liam::InputEngine::GetInstance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Liam::InputEngine();
	}
	return s_pInstance;
}

void Liam::InputEngine::AddKeyDownListener(Keycode param1, void(*callback)())
{
	try
	{
	
		for (auto& c : m_keyDownDelegates)
		{
			if (c.first == param1)
				throw KeyOverrideException("There is already bound to this listener!");
		}
	
	}
	catch (KeyOverrideException except)
	{
		std::cerr << "Exception in Input Listener: " << except.get() << std::endl;
		DebugBreak();
	}
	
	
	m_keyDownDelegates[param1] = callback;
}

void Liam::InputEngine::AddKeyUpListener(Keycode param1, void(*callback)())
{
	try
	{

		for (auto& c : m_keyUpDelegates)
		{
			if (c.first == param1)
				throw KeyOverrideException("There is already bound to this listener!");
		}

	}
	catch (KeyOverrideException except)
	{
		std::cerr << "Exception in Input Listener: " << except.get() << std::endl;
		DebugBreak();
	}


	m_keyUpDelegates[param1] = callback;
}

void Liam::InputEngine::RemoveInputListener(Keycode param1)
{
	m_keyDownDelegates.erase(param1);
}

void Liam::InputEngine::PollEvents(const KeyboardEvent& evt)
{
	for (std::pair<Keycode, std::function<void(void)>> del : m_keyDownDelegates)
	{
		if (del.first == evt.keysym.sym)
			del.second();
	}
	for (std::pair<Keycode, std::function<void(void)>> del : m_keyUpDelegates)
	{
		if (del.first == evt.keysym.sym)
			del.second();
	}
}

std::string Liam::KeyOverrideException::get() const
{
	return message;
}
