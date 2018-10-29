#include "DynamicsObject.h"

void DynamicObject::UpdateModelMatrix()
{
	//setPos, orientation and scale

	_modelMatrix = glm::translate(glm::mat4(1.0f), _position);
	_modelMatrix = glm::scale(_modelMatrix, _scale);
}

DynamicObject::DynamicObject()
{
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::Update(float deltaTs)
{
	/*
	if (_start == true)
	{
		ClearForces();
		glm::vec3 f = ComputeForces();
		AddForce(f);
		if (_position.y <= 0.3f)
		{
			_position = 0.03f;
			glm::vec3 bounceForce = vec3(0.0f, 150.0f, 0.0f);
			AddForce(bounceForce);
		}
		Euler(deltaTs);
	}
	UpdateModelMatrix();
	*/
}

void DynamicObject::Euler(float deltaTs)
{
}
