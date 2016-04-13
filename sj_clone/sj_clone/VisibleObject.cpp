#include "stdafx.h"
#include "VisibleObject.h"

VisibleObject::VisibleObject() :_isLoaded(false){}

VisibleObject::~VisibleObject(){}


void VisibleObject::load(std::string filename){
	if (_image.loadFromFile(filename) == false){
		_filename = "";
		_isLoaded = false;
	}
	else{
		_filename = filename;
		_sprite.setTexture(_image);
		_isLoaded = true;
	}
}

void VisibleObject::draw(sf::RenderWindow& rw){
	if (_isLoaded){
		rw.draw(_sprite);
	}
}

bool VisibleObject::isColliding(){
	return false;
}


void VisibleObject::update(float elapsedTime){}

void VisibleObject::setPosition(float x, float y){
	if (_isLoaded){
		_sprite.setPosition(x, y);
	}
}

sf::Vector2f VisibleObject::getPosition() const{
	if (_isLoaded){
		return _sprite.getPosition();
	}
	return sf::Vector2f();
}

float VisibleObject::getHeight() const{
	return _sprite.getScale().y;
}



float VisibleObject::getWidth() const{
	return _sprite.getScale().x;
}

sf::Sprite& VisibleObject::getSprite(){
	return _sprite;
}

bool VisibleObject::isLoaded() const{
	return _isLoaded;
}

sf::Rect<float> VisibleObject::getBoundingRect() const{
	return _sprite.getGlobalBounds();
}


