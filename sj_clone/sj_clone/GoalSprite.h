#pragma once
#include "stdafx.h"


/////////////////////////////////////////////////
//	Class: GoalSprite
//	Purpose:
//			-sprite image for end of level object
//
//
//////
/////////////////////////////////////////////////////





class GoalSprite : public VisibleObject{
public:

	////////////////////////////////
	//CONSTRUCTORS DESTRUCTORS

	GoalSprite();
	~GoalSprite();


	////////////////////////////////
	//DRAW
	
	void draw(sf::RenderWindow& rw);





private:

	////////////////////////////////
	//ATTRIBUTES


	sf::Vector2f _position;



	
};