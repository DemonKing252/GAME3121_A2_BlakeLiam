#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include "GameObject.h"

/// Platform
///
/// A class which manages the behaviour of the platform.
class Platform : public GameObject
{
private:
	/**
	* @brief (m_gravity) Gravity for this object (in ogre units per second)
	*/
	float m_gravity = 0.f;

	/**
	* @brief (batShape) Prefab type plane to represent the bat
	*/
	Ogre::SceneNode* batShape;

	/**
	* @brief (velocity) Current Velocity for the platform
	*/
	Ogre::Vector2 velocity;

	/**
	* @brief (position) Current position of the platform
	*/
	Ogre::Vector2 position;

	/**
	* @brief (myEntity) Entity for the platform
	*/
	Ogre::Entity* myEntity;


public:

	/// Constructor for the platform class.
	/// 
	/// @param (name) A refrence to the entity you want to use
	/// @param (scnMgr) A refrence to the scene manager
	/// @param (useGravity) If gravity should be enabled
	/// @param (grav) Gravity in ogre units per second
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


	/// Gets the position of the platform.
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
	/// @returns Returns the velocity of the platform as an Ogre::Vector2
	Ogre::Vector2 getVelocity() const;

	/// Set platform position.
	/// 
	/// @param (position) desired position to be set
	/// @returns no return type
	void setPosition(Ogre::Vector3 position);

	/// Set platform velocity.
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