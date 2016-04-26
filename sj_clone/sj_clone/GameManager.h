#pragma once
#include "stdafx.h"
#include "GameManager.h"
#include "ObjectManager.h"


/////////////////////////////////////////////////////////////////
///	@file GameManager.h
/////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////
/// @class	GameManager
///	@brief	manages game content
///
///	-GameLoop
///	-Holds ObjectManagers 
///	-Creates Main Window
///	-Has Game States
///
///
/////////////////////////////////////////////////////////////////
class GameManager{
public:

	/// Start function
	static void Start();


	////////////////////////////////
	//SETTERS



	////////////////////////////////////////////////////////
	//GETTERS


	////////////////////////////////////////////
	/// @brief		reference to window
	/// @return		reference to sf::RenerWindow 
	///				object
	///
	///	reference to window object, used to set
	/// view of where to draw objects on
	///	
	////////////////////////////////////////////
	static sf::RenderWindow& getWindow();

	////////////////////////////////////////////
	/// @brief		pointer to window
	///	@return		pointer to sf::RenderWindow
	///				object
	///	optional pointer method to window
	////////////////////////////////////////////
	static sf::RenderWindow* ptr_getWindow();
	
	////////////////////////////////////////////
	/// @brief		grabs keyboard input
	/// @return		reference to sf::Event object
	///
	///	reference to Event object used for getting
	///	input from keyboard
	////////////////////////////////////////////
	const static sf::Event& getInput();

	////////////////////////////////////////////
	/// @brief		reference to objectmanager
	/// @return		a reference to ObjectManager
	///
	///	reference to ObjectManager, used to access
	///	objects to draw onto window
	////////////////////////////////////////////
	const static ObjectManager& getObjectManager();

	////////////////////////////////////////////
	/// @brief		pointer to ObjectManager
	/// @return		a pointer to ObjectManager
	///
	///	optional pointer to ObjectManager
	////////////////////////////////////////////
	static ObjectManager* ptr_getObjectManager();


	////////////////////////////////////////////
	/// @brief		reference to stageManager
	///	@return		a reference to 
	///				the stageObjectManager
	///
	///	reference to stageObjectManager for use
	/// with platform objects
	////////////////////////////////////////////
	const static ObjectManager& getStageObjectManager();

	////////////////////////////////////////////
	/// @brief		description
	///	@return		a pointer to stageObjectManager
	///
	///	optional pointer to stageObjectManager
	////////////////////////////////////////////
	static ObjectManager* ptr_getStageObjectManager();


	//
	////////////////////////////////////////////////////////////

	////////////////////////////////
	//SCREEN DIMENSIONS

	const static int SCREEN_WIDTH = 1024;		///< Screen width
	const static int SCREEN_HEIGHT = 768;		///< Screen height

	//
	////////////////////////////////

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
};