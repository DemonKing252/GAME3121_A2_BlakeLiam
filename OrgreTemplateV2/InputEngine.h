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


namespace Liam
{

	/// KeyOverrideException class
	///
	/// Used for exception handling in my Input engine class
	class KeyOverrideException : public std::exception
	{
	public:
		/// KeyOverrideException Constructor
		/// @param (msg) message to show when the exception is caught
		/// @returns no returns
		KeyOverrideException(std::string msg) : message(msg) {}

		/// get
		///
		/// returns the exception message
		std::string get() const;
	private:
		/**
		* @brief Exception message
		*/
		std::string message;
	};


	/// InputEngine class
	///
	/// A engine subsystem for listening for key events 
	/// @note This is my custom engine subsystem
	class InputEngine
	{
	protected:
		/**
		* @brief Key down delegates
		* @warning Delegates have to have a void return type with no arguements
		*/
		std::unordered_map<Keycode, std::function<void()>> m_keyDownDelegates;

		/**
		* @brief Key down delegates
		* @warning Delegates have to have a void return type with no arguements
		*/
		std::unordered_map<Keycode, std::function<void()>> m_keyUpDelegates;

		/// InputEngine Constructor
		///
		/// called in game class
		/// @param (param1) Keycode, (void*(callback()) the function that gets called if this key is pressed down
		/// @returns no return type
		InputEngine();
		/**
		* @brief Singleton instance for this class
		* @warning Delegates have to have a void return type with no arguements
		*/
		static InputEngine* s_pInstance;
	public:

		/// InputEngine Destructor
		///
		/// called in game class
		/// @param (param1) Keycode, (void*(callback()) the function that gets called if this key is pressed down
		/// @returns no return type
		~InputEngine();

		/// Delete copy constructor
		///
		/// standard practice for singletons
		InputEngine(InputEngine& rhs) = delete;

		/// operator assignment function
		///
		/// standard practice for singletons
		void operator=(InputEngine& rhs) = delete;

		/// GetInstance
		///
		/// Method that returns the singleton instance
		static InputEngine* GetInstance();

		/// AddKeyDownListener
		///
		/// called in game class
		/// @param (param1) Keycode, (void*(callback()) the function that gets called if this key is pressed down
		/// @returns no return type
		/// @warning I highly recommend you DO NOT define your callbacks here in this class
		void AddKeyDownListener(Keycode param1, void(*callback)());


		/// AddKeyUpListener
		///
		/// Called when invoking key up events
		/// @param (param1) Keycode, (void*(callback()) the function that gets called if this key is pressed up
		/// @returns no return type
		/// @warning I highly recommend you DO NOT define your callbacks here in this class
		void AddKeyUpListener(Keycode param1, void(*callback)());


		/// RemoveInputListener
		///
		/// Called when invoking key up events
		/// @param (param1) Keycode, (void*(callback()) the function that gets called if this key is pressed down
		/// @returns no return type
		void RemoveInputListener(Keycode param1);


		/// PollEvents
		///
		/// Call this function whenever a key is pressed up or down
		/// @see Game::keyPressed
		/// @param (evt) KeyboardEvent
		/// @returns no return type
		/// @warning Make sure your calling this function, nothing will happen if you don't check for events.
		void PollEvents(const KeyboardEvent& evt);

	};
}