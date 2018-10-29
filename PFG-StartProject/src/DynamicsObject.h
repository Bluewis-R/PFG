#ifndef _DynamicObject_H_
#define _DynamicObject_H_

#include "GameObject.h"
#include "glm/ext.hpp"

class DynamicObject : public GameObject
{
private:
	void UpdateModelMatrix();

	glm::vec3 _force;
	glm::vec3 _position;
	glm::vec3 _velocity;
	float _mass;
	float _bRadius;
	glm::mat4 _orientation;

	bool _start;
public:
	DynamicObject();
	~DynamicObject();

	// Update function to override the base class function
	virtual void Update(float deltaTs);
	
	// Add force that acts on the object to the total force for physics computation
	void AddForce(const glm::vec3 force) { _force += force; }
	
	// Clear Forces
	void ClearForces() { _force = glm::vec3(0.0f, 0.0f, 0.0f); }
	
	// Numerical integration function to compute the current velocity and the current position
	void Euler(float deltaTs);

	// Set force for the object
	void SetForce(const glm::vec3 force) { _force = force; }
	
	// Set mass for the object
	void SetMass(float mass) { _mass = mass; }
	
	// Set a sphere bounding volume for the object
	void SetBoundingRadius(float r) { _bRadius = r; }
	
	//	set Orientation
	void SetOrientation(const glm::mat4 ori) { _orientation = ori; }
	
	// Set velocity for the object
	void SetVelocity(const glm::vec3 vel) { _velocity = vel; }
	
	// Get the force acting on the object
	const glm::vec3 GetForce() const { return _force; }
	
	// Get the mass of the object
	const float GetMass() const { return _mass; }
	
	// Get the radius of the bounding sphere of the object
	const float GetBoundingRadius() const { return _bRadius; }
	
	// Get the orientation of the object
	const glm::mat4 GetOrientation() const { return _orientation; }
	
	// A boolean variable to control the start of the simulation This matrix is the camera's lens
	void StartSimulation(bool start) { _start = start; }

};

#endif //!_DynamicObject_H_

