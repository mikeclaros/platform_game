#pragma once


/////////////////////////////////////////////////////
//	Class: mainMenu
//	Purpose:
//		-menu interface
//
//////
//////////////////////////////////////////////////




class mainMenu{
public:


	////////////////////////////////
	//MENU ACTIONS

	enum MenuResult{
		Nothing,
		Start,
		Exit
	};


	////////////////////////////////
	//MENU ITEMS

	struct MenuItem{
	public:
		sf::Rect<int> rect;			// rect for size of button
		MenuResult action;			// actions
	};


	////////////////////////////////
	//DRAW

	MenuResult show(sf::RenderWindow& window);

private:

	////////////////////////////////
	//ATTRIBUTES

	MenuResult getMenuResponse(sf::RenderWindow& window);
	MenuResult handleClick(int x, int y);
	std::list<MenuItem> _menuItems;
};
