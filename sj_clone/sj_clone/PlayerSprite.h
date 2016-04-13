#pragma once
#include "stdafx.h"
#include "Vertices.h"

class PlayerSprite : public VisibleObject{
public:

	////////////////////////////////
	//CONSTRUCTORS DESTRUCTORS

	PlayerSprite();
	~PlayerSprite();

	////////////////////////////////
	//DRAW

	void update(float elapsedTime);
	void draw(sf::RenderWindow& rw);

	////////////////////////////////////
	//COLLISION DETECTION AND HANDLING

	//bool isColliding(sf::FloatRect& otherBox);
	bool isColliding();
	void offsetSprite();

	////////////////////////////////
	//GETTERS

	sf::Vector2f getVelocity() const;
	sf::Vector2f getCenter();
	//sf::Vector2f up();
	
	

private:


	////////////////////////////////
	//ATTRIBUTES


	//spacial information
	sf::Vector2f _velocity;
	sf::Vector2f _maxFallVelocity;
	bool _isGrounded;


	//timer related
	sf::Clock _counterClock;

	
	
	//workaround for clock starting immediately
	bool _firstPass;
	Vertices _Vertices;
};