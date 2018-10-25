#include "GameObject.h"
#include "glm/glm.hpp"

class KinematicsObject : public GameObject
{
private:
	glm::vec3 velocity;
	glm::vec3 displacement;

public:
	KinematicsObject();
	glm::vec3 getVelocity();
	void setVelocity(glm::vec3 _value);
	
	void updatePhysics();
	void updateVelocity();
	void updateDisplacement();
	


};