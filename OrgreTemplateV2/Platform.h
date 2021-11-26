#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include "GameObject.h"

/// Pong Bat
///
/// A class which manages the behaviour of the paddle.
class Platform : public GameObject
{
private:
	float m_gravity = 0.f;

	/**
	* @brief (batShape) Prefab type plane to represent the bat
	*/
	Ogre::SceneNode* batShape;

	/**
	* @brief (velocity) Current Velocity for the ball
	*/
	Ogre::Vector2 velocity;

	/**
	* @brief (position) Current position of the ball
	*/
	Ogre::Vector2 position;


	Ogre::Entity* myEntity;


public:

	/// Constructor for the ball class.
	/// 
	/// @param ballEntity A refrence to the entity you want to use
	/// @param scnMgr A refrence to the scene managerwhat 
	/// @see Assignment1::setup()
	Platform(Ogre::String name, Ogre::SceneManager* scnMgr, bool useGravity, float grav);


	/// Constructor.
	/// 
	/// @param no parameters
	Platform();

	/// Destructor
	/// 
	/// @param no parameters
	~Platform();


	/// Gets the position of the ball.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 getPosition() const;

	/// Gets the bat shape.
	/// 
	/// @param no parameters
	/// @returns Returns the shape as a Ogre::SceneNode reference
	Ogre::SceneNode* getShape() const;

	/// Gets the bat velocity.
	/// 
	/// @param no parameters
	/// @returns Returns the velocity of the ball as an Ogre::Vector2
	Ogre::Vector2 getVelocity() const;

	/// Set ball position.
	/// 
	/// @param (position) desired position to be set
	/// @returns no return type
	void setPosition(Ogre::Vector3 position);

	/// Set ball velocity.
	/// 
	/// @param (vel) Velocity to be set
	/// @returns no return type
	void setVelocity(Ogre::Vector2 vel);

	/// update
	///
	/// called once per frame  
	/// @param (dt) time elapsed since previous frame (consider using a frame listener to get delta time!)
	/// @returns no return type
	void update(float dt);
};