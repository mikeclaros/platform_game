#include "GameManager.h"
#include "SplashScreen.h"
#include "mainMenu.h"
#include "platform.h"
#include "stdafx.h"

void GameManager::Start(void){
	if (_gameState != Uninitialized)
		return;


	//////////////////////////////////
	//NOTE:
	// This section needs some work

	////////////////////////////////
	//Create necessary game objects

	//---
	std::cout << "in start" << std::endl;

	PlayerSprite* player = new PlayerSprite();
	player->setPosition((1024 / 2) - 45, 700 - 200 * (player->getHeight()));

	_mainWindow.create(sf::VideoMode(1024, 768, 32), "Squid Hop");
	
	_ptrToMainWindow = &_mainWindow;
	int start_tolerance = 20;
	float start_x = 0;
	float start_y = 700 + start_tolerance;
	
	//make stages and store them
	_stageObjectManager.setSize(5);

	for (int i = 0; i < _stageObjectManager.getSize(); i++){
		std::string object_name = "platform";
		std::string store_char = std::to_string(i);
		object_name += store_char;

		platform* start_platform = new platform();
		start_platform->setPosition(start_x, start_y);
		if (i % 2 == 0)
			start_x += 575;		
		else
			start_x -= 1000;

		start_y -= 300;
		start_platform->_Vertices.setVertices(start_platform->getSprite().getGlobalBounds());
		_stageObjectManager.add(object_name, start_platform);

	}
	
	//pointer to stage object manager to access platforms
	_ptrToStageObjectManager = &_stageObjectManager;

	//create end object
	GoalSprite* end_object = new GoalSprite();
	end_object->setPosition(start_x + 50, start_y + 50);
	_gameObjectManager.add("EndObject", end_object);
	
	
	
	//main camera
	Camera* mainCamera = new Camera();
	mainCamera->setCamera(_mainWindow.getView());
	
	//add objects to appropriate containers
	_gameObjectManager.add("Player", player);
	
	_gameObjectManager.add("MainCamera", mainCamera);
	_gameState = GameManager::ShowingSplash;
	_ptrToObjectManager = &_gameObjectManager;
	while (!isExiting()){
		GameLoop();
	}
	std::cout << "Exiting game loop..." << std::endl;
}

bool GameManager::isExiting(){
	if (_gameState == GameManager::Exiting)
		return true;
	else
		return false;
}

sf::RenderWindow& GameManager::getWindow(){
	return _mainWindow;
}

sf::RenderWindow* GameManager::ptr_getWindow(){
	return _ptrToMainWindow;
}
ObjectManager* GameManager::ptr_getObjectManager(){
	return _ptrToObjectManager;
}

const ObjectManager& GameManager::getObjectManager(){
	return GameManager::_gameObjectManager;
}

const ObjectManager& GameManager::getStageObjectManager(){
	return GameManager::_stageObjectManager;
}

ObjectManager* GameManager::ptr_getStageObjectManager(){
	return GameManager::_ptrToStageObjectManager;
}

const sf::Event& GameManager::getInput(){
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	return currentEvent;
}

void GameManager::GameLoop(){
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);

	switch (_gameState){
	case GameManager::ShowingStartMenu:
		
		std::cout << "In show start menu " << std::endl;
		
		ShowMenu();
		break;
	case GameManager::ShowingSplash:
		ShowSplashScreen();
		break;
	case GameManager::Playing:
		_mainWindow.clear(sf::Color(0, 0, 0));
		_gameObjectManager.UpdateAll();
		_stageObjectManager.UpdateAll();
		

		_gameObjectManager.drawAll(_mainWindow);
		_stageObjectManager.drawAll(_mainWindow);
		_mainWindow.setView(dynamic_cast<Camera*>(_gameObjectManager.get("MainCamera"))->getCamera());
		_mainWindow.display();

		if (currentEvent.type == sf::Event::Closed)
			_gameState = GameManager::Exiting;
		if (currentEvent.type == sf::Event::KeyPressed){
			if (currentEvent.key.code == sf::Keyboard::Escape){
				_mainWindow.setView(_mainWindow.getDefaultView());
				ShowMenu();
			}
		}
		//Check for end conditions
		// player bounding rectangle must intersect end goal object
		if (_gameObjectManager.get("Player")->getBoundingRect().intersects(_gameObjectManager.get("EndObject")->getBoundingRect())){
			_gameState = GameManager::EndLevel;
			
		}


		break;
	case GameManager::ShowingNextLevelSplash:
		ShowNextLevelSplash();
		break;
	case GameManager::EndLevel:
		_mainWindow.clear(sf::Color::Black);
		sf::View view;
		view.reset(sf::FloatRect(0, 0, 1024, 768));
		_mainWindow.setView(view);
		
		std::cout << "LEVEL ENDS" << std::endl;

		_gameState = ShowingNextLevelSplash;
		break;
	}
	
}

void GameManager::ShowSplashScreen(){
	SplashScreen splashscreen;
	splashscreen.Show(_mainWindow, "background");
	_gameState = GameManager::ShowingStartMenu;
}

void GameManager::ShowNextLevelSplash(){
	SplashScreen splashscreen;
	splashscreen.Show(_mainWindow, "nextLevel");
	_gameState = GameManager::Exiting;
}

void GameManager::ShowMenu(){
	mainMenu mainMenu;
	mainMenu::MenuResult result = mainMenu.show(_mainWindow);
	switch (result){
	case mainMenu::Exit:
		_gameState = GameManager::Exiting;
		break;
	case mainMenu::Start:
		_gameState = GameManager::Playing;
		break;
	}
}


GameManager::GameState GameManager::_gameState = Uninitialized;
sf::RenderWindow GameManager::_mainWindow;
sf::RenderWindow* GameManager::_ptrToMainWindow;

ObjectManager GameManager::_gameObjectManager;
ObjectManager* GameManager::_ptrToObjectManager;

ObjectManager GameManager::_stageObjectManager;
ObjectManager* GameManager::_ptrToStageObjectManager;
