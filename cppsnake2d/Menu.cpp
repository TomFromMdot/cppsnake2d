#include "Menu.h"



void Menu::vInitScene()
{
	player = new Player;
	player->setActorName("Player");
	IScene::addActorToScene(player, this);

}

void Menu::vUpdateScene()
{
}

void Menu::vDrawScene()
{
}
