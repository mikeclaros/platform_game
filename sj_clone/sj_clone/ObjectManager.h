#pragma once
#include "stdafx.h"
#include "VisibleObject.h"

//////////////////////////////////////////////////////////////////////
// Class: ObjectManager
// Purpose: 
//		-Container for VisibleObjects
//		-through ObjectManager all Objects inside ObjectManager
//		  will have their updates functions called through function
//		  UpdateAll
//		-can be used for different objects in GameManager
////
/////////////////////////////////////////////////////////////////////



class ObjectManager{
public:
	//Constructors Destructor
	ObjectManager();
	~ObjectManager();

	//alloctation and deallocation of objects
	void add(std::string name, VisibleObject* Object);
	void remove(std::string name);
	//void removeAll();

	//size information
	void setSize(int size);
	int getSize();
	int getObjectCount() const;

	//get particualar object's pointer
	VisibleObject* get(std::string name) const;

	//update and draw
	void drawAll(sf::RenderWindow& renderWindow);
	void UpdateAll();

	//for debugging
	void printObjectNames();


private:
	int _size;				//size of ObjectManager
	sf::Clock clock;		//Internal clock for update all
	std::map<std::string, VisibleObject*> _gameObjects; //actual container for objects

	//to be used with for_each to deallocate _gameObjects
	struct ObjectDeallocator{
		void operator()(const std::pair<std::string, VisibleObject*> &p) const{
			delete p.second;
		}
	};
};