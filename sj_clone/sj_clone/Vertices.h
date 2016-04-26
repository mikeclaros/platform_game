#pragma once
#include "stdafx.h"

/////////////////////////////////////////////////////////////////////
/// @file		Vertices.h
/////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////
/// @class Vertices
/// @brief wrapper for accessing vertices information
///
///	Purpose:
///	<BR>
/// - Quick accessibility for Vertices of a sf::Rect<float> box
/// <BR>
///	Notes:
///	<BR>
/// - add extensibility or funcitons for other shapes
///
////////////////////////////////////////////////////////////////////
class Vertices{
public:

	////////////////////////////////
	//SETTERS

	////////////////////////////////////////////
	/// @brief		sets vertices for a
	///				sf::Rect<Float> object
	/// @param[in]	box	bounding rectangle
	////////////////////////////////////////////

	void setVertices(sf::Rect<float> box);

	///////////////////////////////////////
	//CONTAINER AND ACCESSOR FOR VERTICES



	////////////////////////////////////////////
	/// @brief		array of vertices, holds
	///				sf::Vector2f object
	/// 
	///	initialize in constructor
	/// <BR>
	/// <BR> update vertices in update function
	/// <BR>
	/// - 0 -> top left
	/// - 1 -> top right
	/// - 2 -> bottom left
	/// - 3 -> bottom right
	////////////////////////////////////////////
	sf::Vector2f vertices[4];				
	


private:

	////////////////////////////////
	//ATTRIBUTES

	sf::Vector2f _tl;	//top left
	sf::Vector2f _tr;	//top right
	sf::Vector2f _bl;	//bottom left
	sf::Vector2f _br;	//bottom right
	
};