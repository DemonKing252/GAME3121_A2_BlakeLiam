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

enum GameOutcome
{
    Win,
    Loss
};

/// Game class
///
/// Main base class, inherits from Application Listener and Input Listener. Any type of keyboard/mouse event based entities should be done from here
/// @see Bat
/// @see Ball
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

    int IncrementScore(int by = 1);
    int DecrementLives();


    /**
    * @brief Tray listener used for GUI
    * @warning You need the tray listener for any type of GUI!
    */
    OgreBites::TrayListener myTrayListener;

    enum class MeshType
    {
        Cube,
        Plane
    };

    ManualObject* createMesh(MeshType meshType, const char* name, const char* matName, Ogre::Vector2 uvMap);
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

    OgreBites::Label* m_winLabel;
    
    OgreBites::Label* m_gameOverLabel;

    OgreBites::TrayManager* mTrayMgr;
    /**
    * @brief Graphic User Interface button used to quit the game if you lose the game
    */
    OgreBites::Button* m_quitBtn = nullptr;

    
    std::shared_ptr<GameObject> m_doodle;
    std::vector<std::shared_ptr<GameObject>> m_platforms;

    void SetGameOver(bool paused, GameOutcome outcome);
    bool getIsPaused() const;

    const int MAX_PLATFORMS = 36;

    SceneNode* camNode;

    static void OnAKeyDown();
    static void OnDKeyDown();
    static void QuitGame();

    static Game* GetInstance();

private:

    static Game* instance;

    /// Constructor
    ///
    /// called in main.cpp
    Game();

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
    * @brief set to true when the ball first collides with the paddle
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */
    //bool collisionenter = false;
    /**
    * @brief set to true when you lose all lives
    * @note This variable is used for main game logic, do not modify it unless you want to break the game, or your curious about what its used for
    */



    SceneManager* scnMgr;
    Root* root;


    Ogre::Vector2 vel;




};