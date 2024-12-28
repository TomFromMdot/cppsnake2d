#pragma once
#include <iostream>
#include "IScene.h"
#include "AScene.h"
#include "Player.h"
class Menu : public AScene
{
public:
	
	virtual void vInitScene() override;
	virtual void vUpdateScene() override;
	virtual void vDrawScene() override;

private:

	Player* player;

};

