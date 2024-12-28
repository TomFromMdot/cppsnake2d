#include "Window.h"

Window::Window(const std::string& n, unsigned int w, unsigned h) :
	windowName(n),
	width(w),
	height(h)
{

}

Window::~Window()
{
	delete window;
}

void Window::windowStart()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), windowName);

	init();

	while (window->isOpen())
	{

		IScene::getCurrentScene()->initScene(window);

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		IScene::getCurrentScene()->updateScene();
		window->clear();
		IScene::getCurrentScene()->drawScene();
		window->display();

	}
}

void Window::init()
{

	IScene::setTarget(*window);
	
	Menu* menu = new Menu;
	menu->setSceneName("Menu");
	IScene::bindNewScene(menu);
	IScene::setCurrentScene("Menu");


	




}
