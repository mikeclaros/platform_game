#pragma once
#include "stdafx.h"


///////////////////////////////////
///	@file	 VisibleObject.h
///////////////////////////////////




////////////////////////////////////////////////////////////////////
/// @class	VisibleObject
/// @brief	base class for all visible objects
///
///	Purpose:
/// <BR>
///	- Base class for all objects that are
///	  visible on screen
/// - primary functions are to load,draw,and update
///	  an image on screen		
///	- notice virtual keywords as this is the base class
///   for all game object types to derive from
///
///
////////////////////////////////////////////////////////////////////
class VisibleObject{
	
public:

	////////////////////////////////
	//CONSTRUCTORS DESTRUCTORS

	/// Constructor
	VisibleObject();
	/// Destructor
	virtual ~VisibleObject();

	
	////////////////////////////////
	//DRAW

	////////////////////////////////////////////
	/// @brief		load a file
	///	@param[in]	filename the file's name
	///	
	///	overload to work in with different type
	/// <BR> of visible objects
	////////////////////////////////////////////

	virtual void load(std::string filename);

	////////////////////////////////////////////
	/// @brief		draw to render window
	/// @param[in]	window reference window 
	///				necessary to draw into
	///
	///	overload this function for use with
	/// <BR> different visible objects
	////////////////////////////////////////////

	virtual void draw(sf::RenderWindow& window);

	////////////////////////////////////////////
	/// @brief		call objects update function
	/// @param[in]	elapsedTime elapsed time
	///				in seconds
	////////////////////////////////////////////
	virtual void update(float elapsedTime);

	////////////////////////////////////////////
	/// @brief		check to see if file loaded
	///				correctly
	///@return		true if image loaded correctly
	////////////////////////////////////////////
	virtual bool isLoaded() const;


	/////////////////////////////////
	//DIMENSION INFORMATION



	////////////////////////////////////////////
	/// @brief		set position of object
	///	@param[in]	x x-coordinate of object
	/// @param[in]	y y-coordinate of object
	////////////////////////////////////////////
	virtual void setPosition(float x, float y);

	////////////////////////////////////////////
	/// @brief		get position of object
	/// @return		return sf::Vector2f that holds
	///				position of object
	////////////////////////////////////////////
	virtual sf::Vector2f getPosition() const;

	////////////////////////////////////////////
	/// @brief		width of object
	///
	////////////////////////////////////////////
	virtual float getWidth() const;

	////////////////////////////////////////////
	/// @brief		get height of object
	///
	////////////////////////////////////////////
	virtual float getHeight() const;

	
	

	////////////////////////////////
	//COLLISION DETECTION

	
	////////////////////////////////////////////
	/// @brief		collision detection
	///
	/// default detection is for a box 
	/// <BR> can be overridden for other things
	/// <BR> such as a sphere
	////////////////////////////////////////////
	virtual bool isColliding();



	////////////////////////////////
	//SETTERS

	////////////////////////////////
	//GETTERS

	////////////////////////////////////////////
	/// @brief		get bounding rectangle of
	///				object
	/// @return		sf::Rect<Float> with bounding
	///				rectangle information of
	///				object
	////////////////////////////////////////////
	virtual sf::Rect<float> getBoundingRect() const;
	
	

//protected: conflicted about this function here
// so far it seems better to keep it public?

	////////////////////////////////////////////
	/// @brief		get sprite object
	/// @return		reference to sprite object
	////////////////////////////////////////////
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


