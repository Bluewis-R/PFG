#include "KinematicsObject.h"

KinematicsObject::KinematicsObject()
{
	velocity = glm::vec3(0, 0, 0);
	displacement = glm::vec3(0, 0, 0);
}

glm::vec3 KinematicsObject::getVelocity()
{
	return velocity;
}

void KinematicsObject::setVelocity(glm::vec3 _value)
{
	velocity = _value;
}

void KinematicsObject::updateVelocity()
{
	//gravity
	if (GetPosition().y - 0.3 >= 0.0f)
	{
		//	Gravity
		velocity = glm::vec3(0, velocity.y - 0.1, 0);
	}
	else
	{
		velocity.y *= -1.0f;
	}


}

void KinematicsObject::updateDisplacement()
{
	SetPosition(glm::vec3(0, GetPosition().y + velocity.y, 0));
}

void KinematicsObject::updatePhysics()
{
	updateVelocity();
	updateDisplacement();
}

/*
if (pos.y - 0.3 >= _level->GetPosition().y)
{
	pos += glm::vec3(0.0, -0.981, 0.0);
}
else
{
	
}

		*/