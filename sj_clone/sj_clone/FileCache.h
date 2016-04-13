#pragma once
#include "stdafx.h"

class FileCache{
public:
	FileCache(void);
	~FileCache(void);

	sf::Image getImage(std::string) const;
	sf::Text getText(std::string) const;

	sf::Sound getSound(std::string) const;
	sf::Music* getSong(std::string) const;

private:
	static std::map<std::string, sf::Image*> _images;
	static std::map<std::string, sf::Text*> _texts;
	static std::map<std::string, sf::SoundBuffer*> _sounds;
	static std::map<std::string, sf::Music*> _music;

	template <typename T>
	struct Deallocator{
		void operator()(const std::pair<std::string, T> &p > {
			delete p.second;
		}
	};
};

class ContentNotFoundException : public std::runtime_error{
public:
	ContentNotFoundException(std::string const& msg) :
		std::runtime_error(msg){}
};
	

