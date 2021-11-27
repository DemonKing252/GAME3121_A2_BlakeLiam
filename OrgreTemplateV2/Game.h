#pragma once
#include <iostream>
#include "Doodle.h"
#include "Platform.h"
#include "GameObject.h"
#include <memory>
#include <cassert>
#include "InputEngine.h"

using namespace Ogre;
using namespace OgreBites;
/// GameOutcome
/// 
/// GameOutcome enumerator for determining win/loss
enum GameOutcome
{
    Win,
    Loss
};

/// Game class
///
/// Main base class, inherits from Application Listener and Input Listener. Any type of keyboard/mouse event based entities should be done from here
/// @see Doodle
/// @see Platform
class Game
    : public ApplicationContext
    , public InputListener
{
public:

    /// Virtual Destructor
    ///
    /// called after application quits
    virtual ~Game() {}

    /// called when the game is constructed
    /// 
    /// @param no parameters
    void setup();

    /// called when a key is pressed
    /// 
    /// @returns boolean always true
    /// @param evt reference to keyboard event
    bool keyPressed(const KeyboardEvent& evt);


    /// keyReleased
    /// 
    /// called when a key is released
    /// @returns boolean always true
    /// @param evt reference to keyboard event
    bool keyReleased(const KeyboardEvent& evt);

    /// called once per tick
    /// 
    /// @returns boolean always true
    /// @param evt reference to frame event
    bool frameRenderingQueued(const FrameEvent& evt);

    /// refresh all Labels
    /// 
    /// @warning Labels are expensive, don't call this function when not needed!
    /// @returns no return type
    /// @param no parameters
    void refreshUserInterface();


    /// called when the mouse is moved
    /// 
    /// @returns boolean always true
    /// @param evt a reference to mouse motion event
    bool mouseMoved(const MouseMotionEvent& evt) override;


    /// IncrementScore
    /// 
    /// Increases the score by (by)
    /// @returns score
    /// @param (by) increment the score by this amount
    int IncrementScore(int by = 1);

    /// DecrementLives
    /// 
    /// Decrements the lives by 1
    /// @returns lives
    /// @param no parameters
    int DecrementLives();


    /**
    * @brief Tray listener used for GUI
    * @warning You need the tray listener for any type of GUI!
    */
    OgreBites::TrayListener myTrayListener;
    
    /// MeshType
    /// 
    /// Entity type for this object (cube or plane)
    enum class MeshType
    {
        Cube,
        Plane
    };
    /// IncrementScore
    /// 
    /// Increases the score by (by)
    /// @returns ManualObject
    /// @param (meshType) the mesh type
    /// @param (name) the name of the mesh
    /// @param (matName) the material name
    /// @param (uvMap) uv scaling
    ManualObject* createMesh(MeshType meshType, const char* name, const char* matName, Ogre::Vector2 uvMap);
    
    /// addVertex
    /// 
    /// Adds a vertex to a mesh
    /// @returns no return type
    /// @param (meshRef) mesh reference
    /// @param (pos) vertex position
    /// @param (col) colour of the vertex
    /// @param (uv) uv scaling
    void addVertex(ManualObject* meshRef, Ogre::Vector3 pos, Ogre::Vector3 col, Ogre::Vector2 uv);
    /**
    * @brief Graphic User Interface label used as score
    */
    OgreBites::Label* m_scoreLabel;
    /**
    * @brief Graphic User Interface label used as lives
    */
    OgreBites::Label* m_livesLabel;
    /**
    * @brief Graphic User Interface label used as lives
    */
    OgreBites::Label* m_fpsLabel;
    /**
    * @brief Graphic User Interface label used as the framerate
    */
    OgreBites::Label* m_mspfLabel;  // Milleseconds per frame
    /**
    * @brief Graphic User Interface label used as milliseconds per frame
    */
    
    /**
    * @brief Win label when the doodle wins the game
    */
    OgreBites::Label* m_winLabel;
    
    /**
    * @brief game over label when the doodle loses the game
    */
    OgreBites::Label* m_gameOverLabel;

    /**
    * @brief Tray manager for handling all onscreen UI
    */
    OgreBites::TrayManager* mTrayMgr;
    /**
    * @brief Graphic User Interface button used to quit the game if you lose the game
    */
    OgreBites::Button* m_quitBtn = nullptr;

    /**
    * @brief reference to the doodle
    * @see Doodle
    */
    std::shared_ptr<GameObject> m_doodle;

    /**
    * @brief a vector of references of all the platforms in the scene
    * @see Platform
    */
    std::vector<std::shared_ptr<GameObject>> m_platforms;

    /// SetGameOver
    /// 
    /// Decrements the lives by 1
    /// @returns lives
    /// @param (paused) should the game be paused
    /// @param (outcome) determine if if its a win or loss
    void SetGameOver(bool paused, GameOutcome outcome);

    /// getIsPaused
    /// 
    /// Decrements the lives by 1
    /// @returns is the game paused
    /// @param no parameters
    bool getIsPaused() const;

    /**
    * @brief number of platforms to draw
    */
    const int MAX_PLATFORMS = 36;

    /**
    * @brief Camera node (depended on Doodle class)
    */
    SceneNode* camNode;


    /// OnAKeyDown
    /// 
    /// Decrements the lives by 1
    /// @returns lives
    /// @param (paused) should the game be paused
    /// @param (outcome) determine if if its a win or loss
    static void OnAKeyDown();


    /// OnDKeyDown
    /// 
    /// Decrements the lives by 1
    /// @returns no returns
    /// @param no parameters
    static void OnDKeyDown();

    /// QuitGame
    /// 
    /// Decrements the lives by 1
    /// @returns no returns
    /// @param no parameters
    static void QuitGame();

    /// GetInstance
    /// 
    /// gets the game instance
    /// @returns the singleton instance
    /// @param no parameters
    static Game* GetInstance();

private:
    /**
    * @brief our singleton instance
    */
    static Game* s_pInstance;

    /// Constructor
    ///
    /// called in main.cpp
    Game();
    /**
    * @brief is the game paused
    */
    bool isPaused = false;

    /**
    * @brief aspect ratio x
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    float aspectX = 325.0f;
    /**
    * @brief aspect ratio y
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    float aspectY = 243.0f;
    /**
    * @brief game score
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    int score = 0;
    /**
    * @brief lives counter
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    int lives = 5;
    /**
    * @brief counter used to refresh fps ui
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    int numofframes = 0;
    /**
    * @brief time passed since last frame fps was updated
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    float timesincelastframe = 0.0f;
    /**
    * @brief framerate last recorded
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    float latestframerate = 0.0f;
    /**
    * @brief how often to refresh the frame rate ui
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    float m_refreshTime = 0.02f;
    /**
    * @brief character stream for setting the captions for all GUI elements (see the various Labels used in Game class)
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    char buffer[50];
    
    /**
    * @brief Scene manager for creating the scene
    */
    SceneManager* scnMgr;
    /**
    * @brief Root for various ogre functions such as queueEndRendering()
    */
    Root* root;

    /**
    * @brief Input from A and D keys
    */
    Ogre::Vector2 vel;

};