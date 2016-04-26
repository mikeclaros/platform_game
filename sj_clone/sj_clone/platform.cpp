#include "stdafx.h"
#include "platform.h"

platform::platform() :
_position(0, 0)
{
	load("images/bottom_platform.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
	
}

platform::~platform(){}

void platform::draw(sf::RenderWindow& rw){
	VisibleObject::draw(rw);
}




