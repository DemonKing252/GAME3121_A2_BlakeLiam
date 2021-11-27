#pragma once

#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"
#include "GameObject.h"	

/// Doodle
///
/// A class which manages the behaviour of the pong doodle. 
class Doodle : public GameObject
{
private:
	
	/**
	* @brief (doodleShape) Prefab type sphere to represent the main doodle
	*/
	Ogre::SceneNode* doodleShape;

	/**
	* @brief (velocity) Current velocity of the doodle
	*/
	Ogre::Vector2 velocity;

	/**
	* @brief (position) Current position of the doodle
	*/
	Ogre::Vector2 position;


	/**
	* @brief (myEntity) Entity for the doodle
	*/
	Ogre::Entity* myEntity;

	/**
	* @brief (m_gravity) Gravity for this object (in ogre units per second)
	*/
	float m_gravity = 0.f;

public:

	/// Constructor for the doodle class.
	/// 
	/// @param (name) A refrence to the entity you want to use
	/// @param (scnMgr) A refrence to the scene manager
	/// @param (useGravity) If gravity should be enabled
	/// @param (grav) Gravity in ogre units per second
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


	/// Gets the position of the doodle.
	/// 
	/// @param no parameters
	/// @returns Returns the position as an Ogre::Vector2
	Ogre::Vector2 getPosition() const;

	/// Gets the doodle shape.
	/// 
	/// @param no parameters
	/// @returns Returns the shape as a Ogre::SceneNode reference
	Ogre::SceneNode* getShape() const;

	/// Gets the doodle velocity.
	/// 
	/// @param no parameters
	/// @returns Returns the velocity of the doodle as an Ogre::Vector2
	Ogre::Vector2 getVelocity() const;


	/// @brief Set doodle position.
	/// 
	/// @param (position) desired position to be set
	/// @returns no return type
	void setPosition(Ogre::Vector3 position);


	/// Set doodle velocity.
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

	/// checkPlatformBounds
	///
	/// performs an AABB collision test and deflects doodle velocity accordingly 
	/// @see Doodle::setVelocity(Ogre::Vector2 vel) this method is what gets called after a direction is determined
	/// @param (go) reference to the game object that this is being compared with
	/// @returns no return type
	void checkPlatformBounds(GameObject* go);
	
	/// checkCameraBounds
	///
	/// checks if doodle is in the view of the camera. Since this method is only needed for Doodle, it does not have to be abstract. Accessable from GameObject using static_cast
	/// @param no returns
	/// @returns no return type
	void checkCameraBounds();

	/// reset
	///
	/// this method is called the moment the doodle leaves the boundary. The doodle velocity is set to be a random diagonal direction (that is either (1, 1)/(1, -1)/(-1,1)/(-1,-1)
	/// @param no parameters
	/// @returns no return type
	void reset();



};
