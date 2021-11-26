#include "Platform.h"

Platform::Platform(Ogre::Entity* batEntity, Ogre::SceneManager* scnMgr, bool useGravity, float grav)
{

    batShape = scnMgr->getRootSceneNode()->createChildSceneNode();
    batShape->setPosition(0, 0, 0);
    batShape->setScale(3.f, 1.f, 1.f);
    batShape->attachObject(batEntity);

    if (useGravity)
    {
        m_gravity = grav;
    }
    else 
    {
        m_gravity = 0.f;
    }
}

Platform::Platform()
{
}

Platform::~Platform()
{
}

Ogre::Vector2 Platform::getPosition() const
{
    return position;
}

Ogre::SceneNode* Platform::getShape() const
{
    return batShape;
}

Ogre::Vector2 Platform::getVelocity() const
{
    return Ogre::Vector2();
}

void Platform::setPosition(Ogre::Vector3 position)
{
    batShape->setPosition(position);
    this->position = Ogre::Vector2(position.x, position.y);

    batShape->_updateBounds();
    GameObject::setAxisAlignedBox(batShape->_getWorldAABB());
}

void Platform::setVelocity(Ogre::Vector2 vel)
{
    this->velocity = vel;
}

void Platform::update(float dt)
{
}
