#include "DynamicsObject.h"

void DynamicObject::UpdateModelMatrix()
{
	//setPos, orientation and scale
	_modelMatrix = glm::translate(glm::mat4(1.0f), _position);
	_modelMatrix = glm::scale(_modelMatrix, _scale);
}

DynamicObject::DynamicObject()
{
	SetMass(1.0f);
	_position = glm::vec3(0.0f, 100.0f, 0.0f);
}

DynamicObject::~DynamicObject()
{
	
}

void DynamicObject::Update(float deltaTs)
{
	if (_start == true)
	{
		ClearForces();
		glm::vec3 f = ComputeForces();
		AddForce(f);
		if (_position.y <= 0.3f)
		{
			_position.y = 0.03f;
			glm::vec3 bounceForce = glm::vec3(0.0f, 150.0f, 0.0f);
			AddForce(bounceForce);
		}
		Euler(deltaTs);
	}
	UpdateModelMatrix();
}

void DynamicObject::Euler(float deltaTs)
{
	_velocity += (_force / _mass) * deltaTs;
	_position += _velocity * deltaTs;
}

glm::vec3 DynamicObject::ComputeForces()
{
	glm::vec3 gravity_force= glm::vec3(0.0f, 0.001f *_mass, 0.0f);
	return gravity_force;
}