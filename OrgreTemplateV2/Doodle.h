#pragma once

#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include "GameObject.h"	

/// Pong Ball
///
/// A class which manages the behaviour of the pong ball. 
class Doodle : public GameObject
{
private:
	
	/**
	* @brief (ballShape) Prefab type sphere to represent the main ball
	*/
	Ogre::SceneNode* doodleShape;

	/**
	* @brief (velocity) Current velocity of the bat
	*/
	Ogre::Vector2 velocity;

	/**
	* @brief (position) Current position of the bat
	*/
	Ogre::Vector2 position;

	Ogre::Entity* myEntity;


	float m_gravity = 0.f;

public:

	/// Constructor for the ball class.
	/// 
	/// @param ballEntity A refrence to the entity you want to use
	/// @param scnMgr A refrence to the scene managerwhat 
	/// @see Assignment1::setup()
	Doodle(Ogre::String name, Ogre::SceneManager* scnMgr, bool useGravity = true, float grav = 9.8f);
	

	/// Constructor.
	/// 
	/// @param no parameters
	Doodle();

	/// Destructor
	/// 
	/// @param no parameters
	~Doodle();


	/// Gets the position of the ball.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 getPosition() const;

	/// Gets the ball shape.
	/// 
	/// @param no parameters
	/// @returns Returns the shape as a Ogre::SceneNode reference
	Ogre::SceneNode* getShape() const;

	/// Gets the ball velocity.
	/// 
	/// @param no parameters
	/// @returns Returns the velocity of the ball as an Ogre::Vector2
	Ogre::Vector2 getVelocity() const;


	/// @brief Set ball position.
	/// 
	/// @param (position) desired position to be set
	/// @returns no return type
	void setPosition(Ogre::Vector3 position);


	/// Set ball velocity.
	/// 
	/// @param (vel) Velocity to be set
	/// @returns no return type
	void setVelocity(Ogre::Vector2 vel);


	/// Called once per tick
	///
	/// called in game class
	/// @see Game::frameRenderingQueued(const FrameEvent& evt) to see where this is called from
	/// @param (dt) time elapsed since previous frame (consider using a frame listener to get delta time!)
	/// @returns no return type
	void update(float dt);

	/// checkbounds
	///
	/// performs an AABB collision test and deflects ball velocity accordingly 
	/// @see Ball::setVelocity(Ogre::Vector2 vel) this method is what gets called after a direction is determined
	/// @param (dt) time elapsed since previous frame (consider using a frame listener to get delta time!)
	/// @returns no return type
	void checkPlatformBounds(GameObject* go);

	void checkCameraBounds();

	/// reset
	///
	/// this method is called the moment the ball leaves the boundary. The balls velocity is set to be a random diagonal direction (that is either (1, 1)/(1, -1)/(-1,1)/(-1,-1)
	/// @param no parameters
	/// @returns no return type
	void reset();



};

