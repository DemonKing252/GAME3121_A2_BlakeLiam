#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"

/// ObjectType enumerator
///
/// Identifying the type of object
enum class ObjectType 
{
	Doodle = 0,
	Platform = 1,

};

/// GameObject class
///
/// Base class for all objects
/// @see Platform Doodle
class GameObject
{
public:

	/// GameObject constructor
	///
	/// @returns no returns
	/// @param no parameters
	GameObject();

	/// GameObject destructor 
	///
	/// @note This is an abstract function
	/// @returns no returns
	/// @param no parameters
	virtual ~GameObject();
	

	/// update 
	///
	/// @note This is an abstract function
	/// @returns no returns
	/// @param (dt) delta time
	virtual void update(float dt);

	/// setVelocity 
	///
	/// @note This is an abstract function
	/// @returns no returns
	/// @param (vel) velocity
	virtual void setVelocity(Ogre::Vector2 vel);


	/// setVelocity 
	///
	/// @note This is an abstract function
	/// @returns no returns
	/// @param (vel) velocity
	virtual void setPosition(Ogre::Vector3 position);


	/// getPosition (abstract)
	///
	/// @note This is an abstract function
	/// @returns no returns
	/// @param no parameters
	virtual Ogre::Vector2 getPosition() const;

	/// getType 
	///
	/// gets the object type
	/// @returns ObjectType
	/// @param no parameters
	ObjectType getType() const;

	/// setType 
	///
	/// sets the object type
	/// @returns no returns
	/// @param ObjectType
	void setType(ObjectType objType);

	/// getAxisAlignedBox 
	///
	/// gets the AABB of this object
	/// @returns Ogre::AxisAlignedBox
	/// @param no parameters
	Ogre::AxisAlignedBox getAxisAlignedBox() const;

	/// setAxisAlignedBox 
	///
	/// sets the AABB of this object
	/// @returns Ogre::AxisAlignedBox
	/// @param no parameters
	void setAxisAlignedBox(Ogre::AxisAlignedBox);

	/// setAxisAlignedBox 
	///
	/// sets the AABB of this object
	/// @returns Ogre::AxisAlignedBox
	/// @param no parameters
	bool IsObjectColliding(GameObject* other);

	/// setIndex 
	///
	/// sets the object index
	/// @returns no returns
	/// @param (i) index
	void setIndex(int i);

	/// getIndex 
	///
	/// gets the object index
	/// @returns index
	/// @param no parameters
	int getIndex() const;

private:
	/**
	* @brief ObjectType for identifying which type of object this is
	*/
	ObjectType type;
	/**
	* @brief Bounding box for this object, used for collision detection
	* @see IsObjectColliding
	*/
	Ogre::AxisAlignedBox boundingBox;
	/**
	* @brief This objects index
	*/
	int indexOrder = 0;
};

