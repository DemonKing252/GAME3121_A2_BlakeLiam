#include "Doodle.h"
#include "Game.h"

Doodle::Doodle(Ogre::String name, Ogre::SceneManager* scnMgr, bool useGravity, float grav)
{
	myEntity = scnMgr->createEntity(name);
	doodleShape = scnMgr->getRootSceneNode()->createChildSceneNode();
	doodleShape->setPosition(0, 0, 0);
	doodleShape->setScale(2.f, 2.f, 1.f);
	doodleShape->attachObject(myEntity);

	velocity = Ogre::Vector2::ZERO;
	position = Ogre::Vector2::ZERO;

	if (useGravity)
	{
		m_gravity = grav;
	}
	else 
	{
		m_gravity = 0.f;
	}
	

	//this->ballShape = ballEntity;
}

Doodle::Doodle()
{
}

Doodle::~Doodle()
{
}

Ogre::Vector2 Doodle::getPosition() const
{
	return position;
}

Ogre::SceneNode* Doodle::getShape() const
{
	return doodleShape;
}

Ogre::Vector2 Doodle::getVelocity() const
{
	return velocity;
}

void Doodle::setPosition(Ogre::Vector3 position)
{
	doodleShape->setPosition(position);
	this->position = Ogre::Vector2(position.x, position.y);

	doodleShape->_updateBounds();
	GameObject::setAxisAlignedBox(doodleShape->_getWorldAABB());
}

void Doodle::setVelocity(Ogre::Vector2 vel)
{
	this->velocity = vel;

	if (velocity.x > 0.f)
		doodleShape->setScale(Ogre::Vector3(-2.f, 2.f, 1.f));
	else if (velocity.x < 0.f)
		doodleShape->setScale(Ogre::Vector3(2.f, 2.f, 1.f));
}

void Doodle::update(float dt)
{
	velocity.y += m_gravity * dt;
	position += velocity * dt;


	this->setPosition(Ogre::Vector3(position.x, position.y, 0.f));
}

void Doodle::checkPlatformBounds(GameObject* platformPtr, Game* gamePtr)
{
	
	if (!IsObjectColliding(platformPtr))
		return;

	// expected to be called when its colling
	if (velocity.y < 0.f && position.y - getAxisAlignedBox().getHalfSize().y >= platformPtr->getPosition().y + platformPtr->getAxisAlignedBox().getHalfSize().y - 0.2f)
	{
		if (platformPtr->getIndex() == gamePtr->MAX_PLATFORMS - 1)
		{
			gamePtr->IncrementScore();
			gamePtr->refreshUserInterface();
			gamePtr->SetGameOver(true, GameOutcome::Win);
		}
		else 
		{
			gamePtr->IncrementScore();
			gamePtr->refreshUserInterface();
			setVelocity(Ogre::Vector2(getVelocity().x, 7.f));
		}
	}
}

void Doodle::checkCameraBounds(Game* gamePtr)
{
	// Check if were outside the camera bounds
	if (getPosition().y <= gamePtr->camNode->getPosition().y - 6.0f)
	{
		if (gamePtr->DecrementLives() <= 0)
		{
			gamePtr->refreshUserInterface();
			gamePtr->SetGameOver(true, GameOutcome::Loss);
		}
		else
		{
			gamePtr->refreshUserInterface();
			this->reset(gamePtr);
		}
	}
}

void Doodle::reset(Game* gamePtr)
{
	this->setVelocity(Ogre::Vector2::ZERO);
	this->setPosition(gamePtr->camNode->getPosition());
}
