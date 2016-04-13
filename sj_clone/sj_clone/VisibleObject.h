#pragma once
#include "stdafx.h"


////////////////////////////////////////////////////////////////////
//	Class: VisibleObject
//	Purpose: 
//			-Base class for all objects that are
//			 visible on screen
//
//			-primary functions are to load,draw,and update
//			 an image on screen
//			
//			-notice virtual keywords as this is the base class
//			 for all game object types to derive from
//
////////
////////////////////////////////////////////////////////////////////



class VisibleObject{
	
public:

	////////////////////////////////
	//CONSTRUCTORS DESTRUCTORS


	VisibleObject();
	virtual ~VisibleObject();

	
	////////////////////////////////
	//DRAW

	virtual void load(std::string filename);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float elapsedTime);
	virtual bool isLoaded() const;

	/////////////////////////////////
	//DIMENSION INFORMATION

	virtual void setPosition(float x, float y);
	virtual sf::Vector2f getPosition() const;
	virtual float getWidth() const;
	virtual float getHeight() const;

	
	

	////////////////////////////////
	//COLLISION DETECTION

	//default is box can be overridden for other things
	//such as sphere
	virtual bool isColliding();



	////////////////////////////////
	//SETTERS

	////////////////////////////////
	//GETTERS
	virtual sf::Rect<float> getBoundingRect() const;
	
	

//protected: conflicted about this function here
// so far it seems better to keep it public?
	sf::Sprite& getSprite();

private:


	////////////////////////////////
	//ATTRIBUTES


	sf::Sprite _sprite;
	sf::Texture _image;
	sf::Text _text;
	sf::FloatRect _boundingBox;
	std::string _filename;
	bool _isLoaded;
	bool _isColliding;
	

	
	
};


