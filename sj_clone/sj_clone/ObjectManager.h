#pragma once
#include "stdafx.h"
#include "VisibleObject.h"

//////////////////////////////////////////////////////////////////////
/// @file	ObjectManager.h
//////////////////////////////////////////////////////////////////////






///////////////////////////////////////////////////////////////////////
/// @class	ObjectManager
/// @brief	manages sprite objects
///
///	-Container for VisibleObjects
///	-through ObjectManager all Objects inside ObjectManager
///	 <BR> will have their updates functions called through function
///	 <BR> UpdateAll
///	-can be used for different objects in GameManager
///
/////////////////////////////////////////////////////////////////////
class ObjectManager{
public:
	/// Constructor
	ObjectManager();
	/// Destructor
	~ObjectManager();

	////////////////////////////////
	//ADDING REMOVING OBJECT METHODS


	/////////////////////////////////////////////////////
	/// @brief		add a VisibleObject
	///	@param[in]	name	Name of VisibleObject
	/// @param[in]	Object	pointer to VisibleObject
	//////////////////////////////////////////////////////
	void add(std::string name, VisibleObject* Object);

	/////////////////////////////////////////////////////
	/// @brief		remove a VisibleObject
	///	@param[in]	name Name of VisibleObject
	//////////////////////////////////////////////////////
	void remove(std::string name);

	//
	////////////////////////////////
	

	//size information

	////////////////////////////////////////////
	/// @brief		set size of ObjectManager
	///	@param[in]	size integer size of
	///				ObjectManager
	////////////////////////////////////////////
	void setSize(int size);

	////////////////////////////////////////////
	/// @brief		get size of ObjectMangager
	/// @return		integer size of ObjectManager
	///
	////////////////////////////////////////////
	int getSize();

	////////////////////////////////////////////
	/// @brief		get current size of 
	///				ObjectManager	
	/// @return		integer, size of 
	///				ObjectManager
	////////////////////////////////////////////
	int getObjectCount() const;

	////////////////////////////////////////////
	/// @brief		gets a VisibleObject
	///	@param[in]	name Name of VisibleObject
	/// @return		a pointer to VisibleObject
	///
	////////////////////////////////////////////
	VisibleObject* get(std::string name) const;

	////////////////////////////////////////////
	/// @brief		draws all the visible objects
	///				to the window specified
	///	@param[in]	renderWindow window to render
	///				VisibleObjects
	////////////////////////////////////////////
	void drawAll(sf::RenderWindow& renderWindow);

	////////////////////////////////////////////
	/// @brief		calls update for objects in
	///				ObjectManager
	////////////////////////////////////////////
	void UpdateAll();



	////////////////////////////////////////////
	/// @brief		for debugging purposes
	///
	////////////////////////////////////////////
	void printObjectNames();


private:
	////////////////////////////////
	//ATTRIBUTES


	int _size;											//size of ObjectManager
	sf::Clock clock;									//Internal clock for update all
	std::map<std::string, VisibleObject*> _gameObjects; //actual container for objects

	//to be used with for_each to deallocate _gameObjects
	struct ObjectDeallocator{
		void operator()(const std::pair<std::string, VisibleObject*> &p) const{
			delete p.second;
		}
	};

	//
	////////////////////////////////

};