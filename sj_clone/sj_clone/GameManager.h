#pragma once
#include "stdafx.h"
#include "GameManager.h"
#include "ObjectManager.h"


/////////////////////////////////////////////////////////////////
//	Class: GameManager
//	Purpose:
//		-GameLoop
//		-Holds ObjectManagers 
//		-Creates Main Window
//		-Has Game States
//
///////////////
/////////////////////////////////////////////////////////////////


class GameManager{
public:

	////////////////////////////////
	//	Start function 
	//	initialization of game objects occur here
	static void Start();


	////////////////////////////////
	//SETTERS



	////////////////////////////////
	//GETTERS

	static sf::RenderWindow& getWindow();
	static sf::RenderWindow* ptr_getWindow();
	
	const static sf::Event& getInput();

	const static ObjectManager& getObjectManager();
	static ObjectManager* ptr_getObjectManager();

	const static ObjectManager& getStageObjectManager();
	static ObjectManager* ptr_getStageObjectManager();


	////////////////////////////////
	//SCREEN DIMENSIONS

	const static int SCREEN_WIDTH = 1024;
	const static int SCREEN_HEIGHT = 768;

private:


	////////////////////////////////
	//GAMESTATES

	enum GameState{
		Uninitialized,
		ShowingSplash,
		ShowingStartMenu,
		ShowingNextLevelSplash,
		Playing,
		Paused,
		GameOver,
		EndLevel,
		Exiting
	};

	////////////////////////////////
	//GAMESTATE FUNCTIONS

	static bool isExiting();
	static void GameLoop();
	static void ShowSplashScreen();
	static void ShowNextLevelSplash();
	static void ShowMenu();


	////////////////////////////////
	//ATTRIBUTES

	static GameState _gameState;

	static sf::RenderWindow _mainWindow;
	static sf::RenderWindow* _ptrToMainWindow;

	static ObjectManager _gameObjectManager;
	static ObjectManager* _ptrToObjectManager;

	static ObjectManager _stageObjectManager;
	static ObjectManager* _ptrToStageObjectManager;

	//static Camera _mainCamera;

};