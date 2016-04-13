#pragma once
#include "stdafx.h"

/////////////////////////////////////////////////////////////////////
//	Class:		Vertices
//	Purpose:
//			- Quick accessibility for Vertices of a rect float box
//
//	Notes:
//		- add extensibility or funcitons for other shapes
//
/////////////
////////////////
////////////////////////////////////////////////////////////////////




class Vertices{
public:

	////////////////////////////////
	//SETTERS

	void setVertices(sf::Rect<float> box);

	///////////////////////////////////////
	//CONTAINER AND ACCESSOR FOR VERTICES

	sf::Vector2f vertices[4];				/////////////////////////
											// 0 - top left
											// 1 - top right
											// 2 - bottom left
											// 3 - bottom right
	


private:

	////////////////////////////////
	//ATTRIBUTES

	sf::Vector2f _tl;	//top left
	sf::Vector2f _tr;	//top right
	sf::Vector2f _bl;	//bottom left
	sf::Vector2f _br;	//bottom right
	
};