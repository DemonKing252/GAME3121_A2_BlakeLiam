#include "Game.h"
Game::Game()
    : ApplicationContext("GAME3121 - Game Engine Development I - Assignment 2 - by Liam Blake")
{
}

bool Game::frameRenderingQueued(const FrameEvent& evt)
{
    if (isPaused) 
        if (m_quitBtn->getState() == OgreBites::ButtonState::BS_DOWN)
            getRoot()->queueEndRendering();


    if (isPaused)
        return true;    

    if (timesincelastframe < m_refreshTime)
    {
        timesincelastframe += evt.timeSinceLastFrame;
        numofframes++;
    
    }
    else
    {
        latestframerate = (float)numofframes / timesincelastframe;
        numofframes = 0;
        timesincelastframe = 0.0f;
    
        sprintf_s(buffer, "FPS: %.1f", latestframerate);
        m_fpsLabel->setCaption(buffer);
    
    
        sprintf_s(buffer, "m/s %.5f", evt.timeSinceLastFrame);
        m_mspfLabel->setCaption(buffer);
    }
    
    static_cast<Doodle*>(m_doodle.get())->checkCameraBounds();
    for (auto go : m_platforms)
    {
        go->update(evt.timeSinceLastFrame);
        if (go->IsObjectColliding(m_doodle.get()))
        {
            // Safe cast
            // Since we don't have a virtual method in the base class, since our platform doesn't depend on that method
            static_cast<Doodle*>(m_doodle.get())->checkPlatformBounds(go.get());
        }

    }
    m_doodle->update(evt.timeSinceLastFrame);

    if (m_doodle->getPosition().y > camNode->getPosition().y)
    {

        camNode->setPosition(0, m_doodle->getPosition().y, 15);
        camNode->lookAt(Ogre::Vector3(0, m_doodle->getPosition().y, 0), Node::TS_WORLD);
    }


    return true;
}
bool Game::mouseMoved(const MouseMotionEvent& evt)
{
    // Pause game when the game is over
    if (isPaused)
        return true;

    float mouseToWorld = (evt.x - (float)getRenderWindow()->getWidth() / 2.0f) * 0.5f;

    //m_playerBat->setPosition(Vector3(mouseToWorld, -70.f, 0.f));
    return true;
}
int Game::IncrementScore(int by)
{
    score += by;
    return score;
}
int Game::DecrementLives()
{
    lives--;
    return lives;
}
ManualObject* Game::createMesh(MeshType meshType, const char* name, const char* matName, Ogre::Vector2 uvMap)
{
    ManualObject* mesh = new ManualObject(name);
    mesh->begin(matName, RenderOperation::OT_TRIANGLE_LIST);

    switch (meshType)
    {
    case Game::MeshType::Cube:

        mesh->position(0.5, -0.5, 1.0);  mesh->colour(1, 0.2, 0.2); mesh->textureCoord(uvMap.x, 0);   //0
        mesh->position(-0.5, -0.5, 0.0); mesh->colour(1, 0.2, 0.2); mesh->textureCoord(0, uvMap.y);  //1
        mesh->position(0.5, -0.5, 0.0);  mesh->colour(1, 0.2, 0.2); mesh->textureCoord(uvMap.x, uvMap.y);    //2
        mesh->position(-0.5, -0.5, 1.0); mesh->colour(1, 0.2, 0.2); mesh->textureCoord(0, 0);   //3
        mesh->position(0.5, 0.5, 1.0);   mesh->colour(0.2, 1, 0.2); mesh->textureCoord(uvMap.x, 0);       //4
        mesh->position(-0.5, -0.5, 1.0); mesh->colour(0.2, 1, 0.2); mesh->textureCoord(0, uvMap.y);   //5 
        mesh->position(0.5, -0.5, 1.0);  mesh->colour(0.2, 1, 0.2); mesh->textureCoord(uvMap.x, uvMap.y);     //6
        mesh->position(-0.5, 0.5, 1.0);  mesh->colour(0.2, 1, 0.2); mesh->textureCoord(0, 0);     //7
        mesh->position(-0.5, 0.5, 0.0);  mesh->colour(0.2, 0.2, 1); mesh->textureCoord(0, uvMap.y);    //8
        mesh->position(-0.5, -0.5, 0.0); mesh->colour(0.2, 0.2, 1); mesh->textureCoord(uvMap.x, uvMap.y);  //9
        mesh->position(-0.5, -0.5, 1.0); mesh->colour(0.2, 0.2, 1); mesh->textureCoord(uvMap.x, 0);    //10
        mesh->position(0.5, -0.5, 0.0);  mesh->colour(0.2, 0.2, 1); mesh->textureCoord(0, uvMap.y);    //11
        mesh->position(0.5, 0.5, 0.0);   mesh->colour(1, 1, 0.2); mesh->textureCoord(uvMap.x, uvMap.y);      //12
        mesh->position(0.5, -0.5, 1.0);  mesh->colour(1, 1, 0.2); mesh->textureCoord(0, 0);    //13
        mesh->position(0.5, -0.5, 0.0);  mesh->colour(1, 1, 0.2); mesh->textureCoord(uvMap.x, 0);   //14
        mesh->position(-0.5, -0.5, 0.0); mesh->colour(1, 1, 0.2); mesh->textureCoord(0, 0);   //15
        mesh->position(-0.5, 0.5, 1.0);  mesh->colour(0.2, 0.2, 1); mesh->textureCoord(uvMap.x, 0);     //16
        mesh->position(0.5, 0.5, 0.0);   mesh->colour(0.2, 0.2, 1); mesh->textureCoord(0, uvMap.y);    //17
        mesh->position(-0.5, 0.5, 0.0);  mesh->colour(0.2, 0.2, 1); mesh->textureCoord(uvMap.x, uvMap.y);   //18
        mesh->position(0.5, 0.5, 1.0);   mesh->colour(0.2, 0.2, 1); mesh->textureCoord(0, 0);      //19

        mesh->triangle(0, 1, 2);		mesh->triangle(3, 1, 0);
        mesh->triangle(4, 5, 6);		mesh->triangle(4, 7, 5);
        mesh->triangle(8, 9, 10);		mesh->triangle(10, 7, 8);
        mesh->triangle(4, 11, 12);	mesh->triangle(4, 13, 11);
        mesh->triangle(14, 8, 12);	mesh->triangle(14, 15, 8);
        mesh->triangle(16, 17, 18);	mesh->triangle(16, 19, 17);
        mesh->end();
        mesh->convertToMesh(name);

        break;
    case Game::MeshType::Plane:

        mesh->position(-0.5, -0.5, 0.0); mesh->colour(1, 1, 1); mesh->textureCoord(0, 0);   //0
        mesh->position( 0.5, -0.5, 0.0); mesh->colour(1, 1, 1); mesh->textureCoord(uvMap.x, 0);  //1
        mesh->position( 0.5,  0.5, 0.0); mesh->colour(1, 1, 1); mesh->textureCoord(uvMap.x, uvMap.y);    //2
        mesh->position(-0.5,  0.5, 0.0); mesh->colour(1, 1, 1); mesh->textureCoord(0, uvMap.y);   //3

        mesh->triangle(0, 1, 2);		
        mesh->triangle(2, 3, 0);
        
        mesh->end();
        mesh->convertToMesh(name);

        break;
    }

    

    return mesh;
}
void Game::addVertex(ManualObject* meshRef, Ogre::Vector3 pos, Ogre::Vector3 col, Ogre::Vector2 uv)
{
    meshRef->position(pos.x, pos.y, pos.z);
    meshRef->colour(col.x, col.y, col.z);
    meshRef->textureCoord(uv.x, uv.y);
}
void Game::SetGameOver(bool paused, GameOutcome outcome)
{
    this->isPaused = paused;

    if (outcome == GameOutcome::Win)
    {
        m_winLabel = mTrayMgr->createLabel(TL_CENTER, "L_GAMEOVER", "YOU WIN!", 150);
        m_quitBtn = mTrayMgr->createButton(TL_CENTER, "B_QUIT", "Quit", 150);
    }
    else if (outcome == GameOutcome::Loss)
    {
        m_gameOverLabel = mTrayMgr->createLabel(TL_CENTER, "L_GAMEOVER", "YOU LOSE!", 150);
        m_quitBtn = mTrayMgr->createButton(TL_CENTER, "B_QUIT", "Quit", 150);
    }
}
bool Game::getIsPaused() const
{
    return isPaused;
}
void Game::OnAKeyDown()
{
    Game::GetInstance()->vel = Ogre::Vector2(-5.f, static_cast<Doodle*>(Game::GetInstance()->m_doodle.get())->getVelocity().y);
    Game::GetInstance()->m_doodle->setVelocity(Game::GetInstance()->vel);
}
void Game::OnDKeyDown()
{
    Game::GetInstance()->vel = Ogre::Vector2(+5.f, static_cast<Doodle*>(Game::GetInstance()->m_doodle.get())->getVelocity().y);
    Game::GetInstance()->m_doodle->setVelocity(Game::GetInstance()->vel);
}
void Game::QuitGame()
{
    Game::GetInstance()->getRoot()->queueEndRendering();
    Game::GetInstance()->m_doodle->setVelocity(Game::GetInstance()->vel);
}
Game* Game::s_pInstance = nullptr;
Game* Game::GetInstance()
{
    if (s_pInstance == nullptr)
        s_pInstance = new Game();

    return s_pInstance;
}
void Game::refreshUserInterface()
{

    // Score UI
    {
        sprintf_s(buffer, "Score: %d", score);
        m_scoreLabel->setCaption(buffer);
    }
    // Lives ui
    {
        sprintf_s(buffer, "Lives: %d", lives);
        m_livesLabel->setCaption(buffer);
    }
}

void Game::setup()
{
    // ------------------------------------------------------------------------------------
    ApplicationContext::setup();
    addInputListener(this);

    // get a pointer to the already created root
    root = getRoot();
    scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);
   
    // --
    // -- tutorial section start --
    //! [turnlights]
    scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    //! [turnlights]

    //! [newlight]
    //
    Light* light1 = scnMgr->createLight("Light1");
    light1->setType(Ogre::Light::LT_DIRECTIONAL);
    // Set Light Color
    light1->setDiffuseColour(1.0f, 1.0f, 1.0f);
    // Set Light Reflective Color
    light1->setSpecularColour(1.0f, 0.0f, 0.0f);
    // Set Light (Range, Brightness, Fade Speed, Rapid Fade Speed)
    light1->setAttenuation(10, 0.5, 0.045, 0.0);

    //
    Entity* lightEnt = scnMgr->createEntity("LightEntity", "sphere.mesh");
    SceneNode* lightNode = scnMgr->createSceneNode("LightNode");
    //lightNode->attachObject(lightEnt);
    lightNode->attachObject(light1);
    lightNode->setScale(0.01f, 0.01f, 0.01f);


    scnMgr->getRootSceneNode()->addChild(lightNode);
    //! [newlight]



    //! [lightpos]
    lightNode->setPosition(0, 4, 10);
    //! [lightpos]


    // ---
    //! [camera]
    camNode = scnMgr->getRootSceneNode()->createChildSceneNode();

    // create the camera
    Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(0.1); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);
    camNode->setPosition(0, 0, 10);
    camNode->lookAt(Ogre::Vector3(0, 0, 0), Node::TS_WORLD);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);


    camNode->setPosition(0, 4, 10);
    camNode->lookAt(Ogre::Vector3(0, 0, 0), Node::TS_WORLD);


    camNode->setPosition(0, 4, 15);
    camNode->lookAt(Ogre::Vector3(0, 0, 0), Node::TS_WORLD);
    
    mTrayMgr = new OgreBites::TrayManager("InterfaceName", getRenderWindow());


    //you must add this in order to add a tray
    scnMgr->addRenderQueueListener(mOverlaySystem);
    //Once you have your tray manager, make sure you relay input events to it.
    addInputListener(mTrayMgr);

    mTrayMgr->showLogo(TL_TOPRIGHT);

    m_scoreLabel = mTrayMgr->createLabel(TL_TOPLEFT, "L_SCORE", "SCORE: XX", 150);
    m_livesLabel = mTrayMgr->createLabel(TL_TOPLEFT, "L_LIVES", "LIVES: XX", 150);

    m_fpsLabel = mTrayMgr->createLabel(TL_BOTTOMLEFT, "L_FPS", "FPS: 60", 150);
    m_mspfLabel = mTrayMgr->createLabel(TL_BOTTOMRIGHT, "L_MSPF", "m/s: 0.1667", 150);

    //m_gameOverLabel = mTrayMgr->createLabel(TL_CENTER, "L_GAMEOVER", "GAME OVER!", 150);
    

    Ogre::ManualObject* ManualCube = NULL;
    ManualCube = createMesh(Game::MeshType::Cube, "MyCube", "LiamBlakeMaterialRock", Ogre::Vector2(3.0, 1.0));


    Ogre::ManualObject* ManualPlane = NULL;
    ManualPlane = createMesh(Game::MeshType::Plane, "MyPlane", "LiamBlakeMaterialDoodle", Ogre::Vector2(1.0, -1.0));

    srand(unsigned(time(NULL)));

    this->refreshUserInterface();

    // Doodle is given a platform to stand on
    auto platform = std::make_shared<Platform>("MyCube", scnMgr, false, 0.f);
    platform->setPosition(Ogre::Vector3(0.f, 0.f, 0.f));
    platform->setIndex(0);
    m_platforms.push_back(platform);


    float yoffset = ( (((float)(rand() % 255) / 255.0f) + 0.3f) * 3.8f);

    for (int row = 1; row < MAX_PLATFORMS; row++)
    {
        float randX = (((float)(rand() % 255) / 255.0f) - 0.5f) * 13.0f;

        auto platform1 = std::make_shared<Platform>("MyCube", scnMgr, false, 0.f);
        platform1->setPosition(Ogre::Vector3(randX, yoffset, 0.f));
        platform1->setIndex(row);

        m_platforms.push_back(platform1);

        yoffset += ((((float)(rand() % 255) / 255.0f) + 0.3f) * 3.8f);
    }

    auto doodle = std::make_shared<Doodle>("MyPlane", scnMgr, true, -4.8f);
    doodle->setPosition(Ogre::Vector3(0.f, 0.f, +0.f));
    doodle->setVelocity(Ogre::Vector2(0.f, 7.f));

    m_doodle = doodle;


    camNode->setPosition(0, m_doodle->getPosition().y, 15);
    camNode->lookAt(Ogre::Vector3(0, m_doodle->getPosition().y, 0), Node::TS_WORLD);


    // Input engine
    Liam::InputEngine::GetInstance()->AddKeyDownListener('a' | 'A', Game::OnAKeyDown);
    Liam::InputEngine::GetInstance()->AddKeyDownListener('d' | 'D', Game::OnDKeyDown);

    Liam::InputEngine::GetInstance()->AddKeyDownListener(SDLK_ESCAPE, Game::QuitGame);


}


bool Game::keyPressed(const KeyboardEvent& evt)
{
    Liam::InputEngine::GetInstance()->PollEvents(evt);
    
    return true;
}

bool Game::keyReleased(const KeyboardEvent& evt)
{
    Liam::InputEngine::GetInstance()->PollEvents(evt);
    vel = Ogre::Vector2(+0.f, static_cast<Doodle*>(m_doodle.get())->getVelocity().y);
    m_doodle->setVelocity(vel);
    return true;
}
