#include "Game.h"

/// Ogres Engine
///
/// #1 - Scene Manager
/// 
/// #2 - Material Manager
/// 
/// #3 - Tray Manager
/// 
/// #4 - Shader Generator
/// 
/// My Engine:
/// 
/// Input Engine that listens for key events and calls that function when the key is pressed or released (you can listen for Key down and up events)
/// @see Liam::InputEngine
/// 
/// Welcome to the main function
///
/// This is where the magic begins
/// @see Game class and explore what it can do!
int main(int argc, char** argv)
{
    try
    {
        
        Game::GetInstance()->initApp();
        Game::GetInstance()->getRoot()->startRendering();
        Game::GetInstance()->closeApp();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error occurred during execution: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
