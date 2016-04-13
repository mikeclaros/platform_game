#include "GameManager.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager(){}

//delete objects in map once ObjectManager goes out of scope
ObjectManager::~ObjectManager(){
	std::for_each(_gameObjects.begin(), _gameObjects.end(), ObjectDeallocator());
}

void ObjectManager::add(std::string name, VisibleObject* gameObject){
	_gameObjects.insert(std::pair<std::string, VisibleObject*>(name, gameObject));
}

void ObjectManager::remove(std::string name){
	std::map<std::string, VisibleObject*>::iterator results = _gameObjects.find(name);
	if (results != _gameObjects.end()){
		delete results->second;
		_gameObjects.erase(results);
	}
}

//void ObjectManager::removeAll(){
//	std::for_each(_gameObjects.begin(), _gameObjects.end(), ObjectDeallocator());
//}

void ObjectManager::setSize(int size){
	_size = size;
}

int ObjectManager::getSize(){
	return _size;
}


VisibleObject* ObjectManager::get(std::string name) const{
	std::map<std::string, VisibleObject*>::const_iterator results = _gameObjects.find(name);
	if (results == _gameObjects.end())
		return NULL;
	return results->second;
}

int ObjectManager::getObjectCount() const{
	return _gameObjects.size();
}

void ObjectManager::drawAll(sf::RenderWindow& renderWindow){
	std::map<std::string, VisibleObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end()){
		itr->second->draw(renderWindow);
		itr++;
	}
}

void ObjectManager::UpdateAll(){
	std::map<std::string, VisibleObject*>::const_iterator itr = _gameObjects.begin();
	float timeDelta = clock.restart().asSeconds();

	while (itr != _gameObjects.end()){
		//itr->second->update(timeDelta, true);
		itr->second->update(timeDelta * 0.5);
		itr++;
	}
}


void ObjectManager::printObjectNames(){
	std::map<std::string, VisibleObject*>::const_iterator itr = _gameObjects.begin();
	while (itr != _gameObjects.end()){
		std::cout << itr->first << std::endl;
		itr++;
	}
}