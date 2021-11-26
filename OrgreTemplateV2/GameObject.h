#pragma once
#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include "OgreTrays.h"

enum class ObjectType 
{
	Doodle = 0,
	Platform = 1,

};

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	

	virtual void update(float dt);

	virtual void setVelocity(Ogre::Vector2 vel);
	virtual void setPosition(Ogre::Vector3 position);

	virtual Ogre::Vector2 getPosition() const;

	ObjectType getType() const;
	void setType(ObjectType objType);

	Ogre::AxisAlignedBox getAxisAlignedBox() const;
	void setAxisAlignedBox(Ogre::AxisAlignedBox);

	bool IsObjectColliding(GameObject* other);


private:
	ObjectType type;

	Ogre::AxisAlignedBox boundingBox;

};

