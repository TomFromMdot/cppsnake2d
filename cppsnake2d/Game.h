#pragma once
#include "AScene.h"
#include "IScene.h"

class Game : public AScene
{
public:

	virtual void vInitScene() override;
	virtual void vUpdateScene() override;
	virtual void vDrawScene() override;

private:



};

