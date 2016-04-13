#include "stdafx.h"

mainMenu::MenuResult mainMenu::show(sf::RenderWindow& window){
	//load menu image

	std::string menuFile = "images/mainMenu.png";
	std::cout << "grabbing mainMenu image" << std::endl;
	sf::Texture image;
	image.loadFromFile(menuFile);
	sf::Sprite sprite(image);
	

	//setup clickable areas

	//start menu area coordinates

	MenuItem startButton;
	startButton.rect.top = 235;
	startButton.rect.left = 0;
	startButton.rect.width = 1022;
	startButton.rect.height = 450;
	startButton.action = Start;
	//exit button area coordinates

	MenuItem exitButton;
	exitButton.rect.top = 449;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1022;
	exitButton.rect.height = 654;
	exitButton.action = Exit;

	_menuItems.push_back(startButton);
	_menuItems.push_back(exitButton);

	window.draw(sprite);
	window.display();

	return getMenuResponse(window);
}

mainMenu::MenuResult mainMenu::handleClick(int x, int y){
	std::list<MenuItem>::iterator it;
	for (it = _menuItems.begin(); it != _menuItems.end(); it++){
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.width > y && menuItemRect.top < y && menuItemRect.left < x && menuItemRect.height > x)
			return (*it).action;
	}
	return Nothing;
}

mainMenu::MenuResult mainMenu::getMenuResponse(sf::RenderWindow& window){
	sf::Event menuEvent;
	while (true){
		while (window.pollEvent(menuEvent)){
			if (menuEvent.type == sf::Event::MouseButtonPressed)
				return handleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			if (menuEvent.type == sf::Event::Closed)
				return Exit;
		}
	}
}