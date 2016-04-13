#pragma once
#include "stdafx.h"
#include "VisibleObject.h"


/////////////////////////////////////////////////////////////////////
//class: Camera
//Purpose: container for sf::view to place into gameobject manager
///
///
/////////////////////////////////////////////////////////////////////

class Camera : public VisibleObject{
public:
	////////////////////////////////////
	//CONSTRUCTORS, DESCTRUCTORS


	Camera();
	~Camera();

	////////////////////////////////
	//SETTERS
	void setCamera(sf::View camera);
	void setCenter(float cx, float cy);
	void setSize(float width, float height);

	////////////////////////////////////
	//GETTERS

	sf::View getCamera();

	


	///////////////////////////////////
	//UPDATES 

	//void update(float elapsedTime, bool inGame);
	void update(float elapsedTime);


private:


	////////////////////////////////
	//ATTRIBUTES

	float _position;
	float _target;
	float _size;
	float _speed;
	sf::View _camera;
};