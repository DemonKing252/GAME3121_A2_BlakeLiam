#include "GameObject.h"

GameObject::~GameObject()
{
}

GameObject::GameObject()
{
}

void GameObject::update(float dt)
{
}

void GameObject::setVelocity(Ogre::Vector2 vel)
{
}

void GameObject::setPosition(Ogre::Vector3 position)
{
}

Ogre::Vector2 GameObject::getPosition() const
{
	return Ogre::Vector2::ZERO;
}

ObjectType GameObject::getType() const
{
	return type;
}

void GameObject::setType(ObjectType objType)
{
	type = objType;
}

Ogre::AxisAlignedBox GameObject::getAxisAlignedBox() const
{
	return boundingBox;
}

void GameObject::setAxisAlignedBox(Ogre::AxisAlignedBox box)
{
	boundingBox = box;
}

bool GameObject::IsObjectColliding(GameObject* other)
{
	Ogre::AxisAlignedBox A = getAxisAlignedBox();
	Ogre::AxisAlignedBox B = other->getAxisAlignedBox();

	return A.intersects(B);
}
