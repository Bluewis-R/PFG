#ifndef __GAME_OBJECT__
#define __GAME_OBJECT__

#include "Mesh.h"
#include "Material.h"

/*! \brief Brief description.
*  GameObject class contains a mesh, a material, a position and an orientation information
*  about the game object. This should be a base class for different types of game object. 
*
*/

class GameObject
{
protected:
	Mesh * _mesh;
	Material *_material;
	glm::mat4 _modelMatrix;
	glm::mat4 _invModelMatrix;
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

public:
	/** GameObject constructor
	* 
	*/
	GameObject();
	/** GameObject distructor
	*/
	~GameObject();

	// Function for setting mesh geometry for the game object 
	void SetMesh(Mesh *input) {_mesh = input;}
	
	// Function for setting material for the game object
	void SetMaterial(Material *input) {_material = input;}
	
	// Function for setting position for the game object
	void SetPosition( float posX, float posY, float posZ ) {_position.x = posX; _position.y = posY; _position.z = posZ;}
	
	// Function for setting position for the game object
	void SetPosition( glm::vec3 value) {_position = value;}
	
	// Function for setting rotation for the game object
	void SetRotation( float rotX, float rotY, float rotZ ) {_rotation.x = rotX; _rotation.y = rotY; _rotation.z = rotZ;}
	
	// Function for setting scale for the game object
	void SetScale(const float _x, float _y, float _z ) { _scale.x = _x; _scale.y = _y; _scale.z = _z; }
	void SetScale(const glm::vec3 scale) { _scale = scale; }

	glm::vec3 GetPosition() {return _position;}
	
	// A virtual function for updating the simulation result at each time frame
	virtual void Update( float deltaTs );
	
	// A virtual function for drawing the simulation result
	virtual void Draw(glm::mat4 &viewMatrix, glm::mat4 &projMatrix);
};



#endif
