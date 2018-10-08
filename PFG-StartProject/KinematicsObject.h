#include "GameObject.h"
#include "glm/glm.hpp"

class KinematicsObject : public GameObject
{
private:
	int startVelocity;
	float finalVelocity;
	glm::vec3 displacement;

public:
	getStartVelocity();
	getFinalVelocity();
	setStartVelocity();
	setFinalVelocity();

	updateVelocity();
	updateDisplacement();


};