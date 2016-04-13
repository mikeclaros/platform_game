#include "stdafx.h"
#include "platform.h"
#include "GameManager.h"
#include "Vertices.h"
#include <cmath>

////////////////////////////////////////////////
// NOTES:
//	-velocity name is used, however what we are actually storing
//	 are height values but the end result is to calculate a velocity
//
//

PlayerSprite::PlayerSprite() :
_velocity(0, 0),
_maxFallVelocity(0.5f, 0.5f),
_isGrounded(false),
_firstPass(true)
{
	load("images/squid.png");
	assert(isLoaded());
	

	getSprite().setOrigin(getSprite().getScale().x / 2, getSprite().getScale().y / 2);
	//set up vertices
	


}

PlayerSprite::~PlayerSprite(){
}

void PlayerSprite::draw(sf::RenderWindow& rw){
	VisibleObject::draw(rw);
}

sf::Vector2f PlayerSprite::getVelocity() const{
	return _velocity;
}


bool PlayerSprite::isColliding(){
	ObjectManager* platform_objects = dynamic_cast<ObjectManager*>(GameManager::ptr_getStageObjectManager());
	


	int stage_size = 5;
	// iterate through platfrom objects platform0 - platform4
	for (int i = 0; i < stage_size; i++){
		std::string name = "platform";
		std::string store_char = std::to_string(i);
		name += store_char;
		

		platform* platforms = dynamic_cast<platform*>(platform_objects->get(name));
		

		sf::Rect<float> plat_box = platforms->getBoundingRect();
				
		/////////////////////////////////////////////////////////
		// COLLISION CONDITIONS
		//
		//	if the bottom of the character sprite hits the top of the platform
		//	sprite then there is a collision


		//focus collision detection on the bottom coordinates
		// Vertices array
		// 0 - top left
		// 1 - top right
		// 2 - bottom left
		// 3 - bottom right


		if (getSprite().getGlobalBounds().intersects(plat_box)){
			//quick easy check for base platform
			if (name == "platform0"){
				getSprite().move(0, -0.5);	//to avoid getting character stuck in platform
				return true;
			}
			// magic number 20 is a buffer, when this check happens the sprite needs
			// a buffer so that the condition is correctly met
			if (_Vertices.vertices[2].y - 20 < platforms->_Vertices.vertices[0].y){
				getSprite().move(0, -0.5);
				if (((_Vertices.vertices[2].x > platforms->_Vertices.vertices[0].x) &&
					(_Vertices.vertices[3].x < platforms->_Vertices.vertices[1].x))){
					return true;
				}
			}
		}
	}
	
	return false;
}


sf::Vector2f PlayerSprite::getCenter(){
	return(getSprite().getOrigin());
}


void PlayerSprite::update(float elapsedTime){

	///////////////////////////////////////////////////////////
	// handle the movement and velocity of the sprite
	// based of the users inputs
	// checks needed
	// is sprite not grounded: use gravity
	//
	// 
	// if the player is not grounded then have
	// have gravity pull the player down


	_Vertices.setVertices(getSprite().getGlobalBounds());

	//clock reset on first pass for correct timing
	if (_firstPass){
		_counterClock.restart();
		_firstPass = false;
	}
	

	
	//////////////////////////////
	// player states
	// check if on something
	//		check for next move
	//		make next move
	// else apply gravity
	//		check for next move
	//		make next move
	// repeat	


	//get pointer to rf window
	//sf::RenderWindow* ref_window = dynamic_cast<sf::RenderWindow*>(GameManager::ptr_getWindow());

	if(isColliding()){
		//on top of platform
		_velocity.y = 0;
		_velocity.x = 0;
		_isGrounded = true;
	}

	//if in the air
	if (!_isGrounded){
		_velocity.y += _maxFallVelocity.y;
	}
	


	
	///handle jumping velocties and inputs
	// work on adjusting time and forces 4/5/2015*****
	float currentJumpCounter = 0;
	const float move_force = 20;
	while (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _isGrounded){
		//check if space is held
		//	if space is being held
		//	start counting how long space is held for
		currentJumpCounter = _counterClock.getElapsedTime().asSeconds();
	}


	if (_isGrounded && currentJumpCounter > 0){
		float maxVel_y = 250.0f;
		_velocity.y -= 5 * currentJumpCounter * (exp(currentJumpCounter) * move_force);
		if (fabs(_velocity.y) > maxVel_y){		
			//std::cout << "Cap vel" << std::endl;
			_velocity.y = -maxVel_y;
		}
		_isGrounded = false;
	}

	//std::cout << "vel.y: " << _velocity.y << std::endl;
	//float maxVelocity_x = 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !_isGrounded){
		//if s is pressed move the player left x units
		if (_velocity.x > -_maxFallVelocity.x)
			_velocity.x = -_maxFallVelocity.x;
		else
			_velocity.x -= _maxFallVelocity.x;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !_isGrounded){
		//if f is pressed move the player right x units
		if (_velocity.x < _maxFallVelocity.x)
			_velocity.x = _maxFallVelocity.x;
		else
			_velocity.x += _maxFallVelocity.x;
	}
	
	currentJumpCounter = 0;
	_counterClock.restart();


	//debugging purposes
	//std::cout << "Player pos: " << getPosition().x << " " << getPosition().y << std::endl;
	//std::cout << "velocity: " << _velocity.x * elapsedTime << ", " << _velocity.y * elapsedTime << std::endl;
	getSprite().move(_velocity * elapsedTime);

}