#include "stdafx.h"
#include "Camera.h"
#include <math.h>


Camera::Camera(){
	_camera.reset(sf::FloatRect(100, 100, 1024, 768));
}

Camera::~Camera(){}


void Camera::setCamera(sf::View camera){
	_camera = camera;
}

void Camera::setCenter(float cx, float cy){
	_camera.setCenter(cx, cy);
}

void Camera::setSize(float width, float height){
	_camera.setSize(width, height);
}

sf::View Camera::getCamera(){
	return _camera;
}

//To update view for player
void Camera::update(float elapsedTime/*, bool inGame*/){
	PlayerSprite* player = dynamic_cast<PlayerSprite*>(GameManager::getObjectManager().get("Player"));
	_camera.setCenter(player->getPosition().x, player->getPosition().y);
}






