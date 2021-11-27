#include "Game.h"

/// Ogres Engines
/// #1 - Scene Manager
/// #2 - Material Manager
/// #3 - Tray Manager
/// #4 - Shader Generator
/// #5 - Frame Listener
/// 
/// My Engine:
/// Input Engine utilizing an unordered map of type SDL Keysym, std::function

/// Welcome to the main function
///
/// This is where the magic begins
/// @see See Game class and explore what it can do!
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
