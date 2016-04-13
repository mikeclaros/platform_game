#pragma once
#include "stdafx.h"
#include "Vertices.h"


/////////////////////////////////////////////
//	Class: platform	
//	purpose:
//		h file for platform sprites
//		inherited from VisibleObject
/////
/////////////////////////////////////////////



class platform : public VisibleObject{
public:
	////////////////////////////////////
	//constructors, desctructors
	platform();
	~platform();


	////////////////////////////////
	//setters


	////////////////////////////////////
	//getters


	////////////////////////////////////
	//	Vertices information 
	//	instantiated during construction

	Vertices _Vertices;

	////////////////////////////////////
	// draw information

	void draw(sf::RenderWindow& rw);	//draw platforms on window
	


private:
	sf::Vector2f _position;
	bool _isColliding;
	
};
