#include "Ball.h"

Doodle::Doodle(Ogre::Entity* ballEntity, Ogre::SceneManager* scnMgr, bool useGravity, float grav)
{
	ballShape = scnMgr->getRootSceneNode()->createChildSceneNode();
	ballShape->setPosition(0, 0, 0);
	ballShape->setScale(2.f, 2.f, 1.f);
	ballShape->attachObject(ballEntity);

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
	return ballShape;
}

Ogre::Vector2 Doodle::getVelocity() const
{
	return velocity;
}

void Doodle::setPosition(Ogre::Vector3 position)
{
	ballShape->setPosition(position);
	this->position = Ogre::Vector2(position.x, position.y);

	ballShape->_updateBounds();
	GameObject::setAxisAlignedBox(ballShape->_getWorldAABB());
}

void Doodle::setVelocity(Ogre::Vector2 vel)
{
	this->velocity = vel;

	if (velocity.x > 0.f)
		ballShape->setScale(Ogre::Vector3(-2.f, 2.f, 1.f));
	else if (velocity.x < 0.f)
		ballShape->setScale(Ogre::Vector3(2.f, 2.f, 1.f));
}

void Doodle::update(float dt)
{
	velocity.y += m_gravity * dt;
	position += velocity * dt;


	this->setPosition(Ogre::Vector3(position.x, position.y, 0.f));
}

void Doodle::checkBounds(GameObject* platformPtr)
{
	if (!IsObjectColliding(platformPtr))
		return;

	// expected to be called when its colling
	if (velocity.y < 0.f && position.y - getAxisAlignedBox().getHalfSize().y >= platformPtr->getPosition().y + platformPtr->getAxisAlignedBox().getHalfSize().y - 0.2f)
		setVelocity(Ogre::Vector2(getVelocity().x, 7.f));
	// Handle death
	/*if (position.x > x * 0.5f)
		velocity.x *= -1.0f;
	if (position.x < -x * 0.5f)
		velocity.x *= -1.0f;
	if (position.y > y * 0.5f)
		velocity.y *= -1.0f;*/

}

void Doodle::reset()
{

	//// 45-> -45
	////float randomDir = static_cast<float>(( rand() % 90) - 45);
	//int ran = rand() % 4;
	//float randomDir = 0.0f;

	//switch (ran)
	//{
	//case 0: randomDir = 45.0f; break;
	//case 1: randomDir = 135.0f; break;
	//case 2: randomDir = 225.0f; break;
	//case 3: randomDir = 315.0f; break;
	//}

	//float desiredX = 160.0f * cos(randomDir * 3.14159f / 180.0f);
	//float desiredY = 160.0f * sin(randomDir * 3.14159f / 180.0f);

	//this->setPosition(Ogre::Vector3::ZERO);
	//this->setVelocity(Ogre::Vector2(desiredX, desiredY));
}
