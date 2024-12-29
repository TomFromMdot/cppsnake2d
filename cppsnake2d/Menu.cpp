#include "Menu.h"
MenuButton* Menu::currentButton;


void Menu::vInitScene()
{
	std::cout << "init scene" << getSceneName().c_str();
	tittle = new Text;
	tittle->setActorName("Tittle Name");
	tittle->setActorType(TEXT);
	IScene::addActorToScene(tittle, this);

	

	buttons[0] = new MenuButton;
	buttons[0]->setActorName("B_NEWGAME");
	buttons[0]->setActorType(TEXT);
	buttons[0]->setText("Start Game");
	buttons[0]->setPosition(sf::Vector2f(800 / 2, 600 - 300));
	IScene::addActorToScene(buttons[0], this);

	buttons[1] = new MenuButton;
	buttons[1]->setActorName("B_OPTIONS");
	buttons[1]->setActorType(TEXT);
	buttons[1]->setText("Options");
	buttons[1]->setPosition(sf::Vector2f(800 / 2,600 - 250));
	IScene::addActorToScene(buttons[1], this);

	buttons[2] = new MenuButton;
	buttons[2]->setActorName("B_QUIT");
	buttons[2]->setActorType(TEXT);
	buttons[2]->setText("Quit");
	buttons[2]->setPosition(sf::Vector2f(800 / 2, 600 - 200));
	IScene::addActorToScene(buttons[2], this);

}

void Menu::vUpdateScene()
{




}

void Menu::vDrawScene()
{
}


