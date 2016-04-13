#include "stdafx.h"
#include "GoalSprite.h"


GoalSprite::GoalSprite():
_position(0,0)
{
	load("images/end_object.png");
	assert(isLoaded());
	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
}

GoalSprite::~GoalSprite(){}

void GoalSprite::draw(sf::RenderWindow& rw){
	VisibleObject::draw(rw);
}



