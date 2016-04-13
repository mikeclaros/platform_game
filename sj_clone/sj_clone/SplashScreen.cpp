#include "stdafx.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow, std::string name){
	sf::Texture image;
	std::string imageName;
	if (name == "nextLevel"){
		std::cout << "should be here" << std::endl;
		imageName = "images/next_level_screen.png";
	}
	else if (name == "background"){
		imageName = "images/background.png";
	}
	else{
		imageName = "images/background.png";
	}

	if (!image.loadFromFile(imageName))
		return;
	sf::Sprite sprite(image);
	renderWindow.draw(sprite);
	renderWindow.display();
	sf::Event event;
	while (true){
		while (renderWindow.pollEvent(event)){
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed){
				return;
			}
		}
	}
}