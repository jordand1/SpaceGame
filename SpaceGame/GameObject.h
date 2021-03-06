
/*Author: Austin Hulse
 * Space Game
 */
 ////////////////////////////////////////////////////////////////////////////////
 // GAME OBJECT CLASS
 ////////////////////////////////////////////////////////////////////////////////

/* This class is the basic class for objects in the game.  Subclasses of this 
 * class include: ActiveObject, Camera, Character, Player, etc.
 *
 */
#include "windows.h"
#include "Quaternion.h"
#include "Mesh.h"

//Abstract class GameObject
class GameObject{
private:
	//Pointer to the GameMesh stored elsewhere
	GameMesh* meshptr;
	Vec3f position;
	Quaternion rotation;
	float scale;
	bool isModified;

	//TEXTURE POINTER txtptr;
	
	//Thread Lock (mutex_t ?) object lock;
	//Sound link sound??  Play sound indirectly?

public:

	//constructor
	GameObject::GameObject()
	{
		isModified = false;
		position = Vec3f(0,0,0);
		scale = 1.f;
		/*TO DO: Initialize lock*/
	}
	
	//destructor
	GameObject::~GameObject(){}

	//Get a POINTER to the current Object's mesh
	GameMesh* GameObject::GetMesh(){return meshptr;}

	//Redefine the object's mesh
	void GameObject::SetMesh(GameMesh* NewMesh){meshptr = NewMesh;}

	//Getters and Setters//////////////////////////////////
	Vec3f GameObject::GetPosition(){return position;}
	void GameObject::MovePositon(Vec3f &delta){position += delta;}
	void GameObject::MovePositon(float x, float y, float z)
	{
		position[0] = position[0] + x;
		position[1] = position[1] + y;
		position[2] = position[2] + z;
	}
	void GameObject::SetPosition(Vec3f &newPos){position = newPos;}
	Quaternion GameObject::GetRotation(){return rotation;}
	void GameObject::SetRotation(Quaternion &newRotation){rotation = newRotation;}
	void GameObject::RotateByQuaternion(Quaternion &deltaQ){rotation = rotation + deltaQ;}
	float GameObject::GetScale(){return scale;}
	void GameObject::SetScale(float &newScale){scale = newScale;}

	/////////////////////////////////////////////////////////////////////////////////

	//Bools in case of error when locking...
	bool GameObject::Lock(){/*ToDo: write function for lock*/}
	bool GameObject::Unlock(){/*ToDo:: write function for unlock*/}

	//TO DO: Create linker function to link sound object to object.
	//TO DO: Create a getter/setter for an objects textures
};