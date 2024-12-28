#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32



#include "IScene.h"



#include "Menu.h"



class Window
{
public:
	Window(const std::string& n, unsigned int w, unsigned h);
	~Window();

	void windowStart();

	

private:
	std::string windowName;
	unsigned int width, height;

	sf::RenderWindow* window;
	sf::Event event;

	void init();


};

