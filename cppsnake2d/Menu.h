#pragma once
#include <iostream>
#include "IScene.h"
#include "AScene.h"
#include "Player.h"
#include "Text.h"
#include "MenuButton.h"
class Menu : public AScene
{
public:
	
	virtual void vInitScene() override;
	virtual void vUpdateScene() override;
	virtual void vDrawScene() override;

private:

	Text* tittle;
	MenuButton* buttons[2];

	MenuButton* startGame;
	MenuButton* optionsGame;
	MenuButton* quitGame;
	Player* player;
	int n;
	static MenuButton* currentButton;

	sf::Clock* clock;
	float time;

};

