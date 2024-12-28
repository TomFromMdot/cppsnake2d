#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "AActor.h"
enum ESceneAction
{
	INIT,
	UPDATE,
	DRAW,
	CLOSE
};


class AScene
{
public:

	virtual ~AScene();


	/*Virtual Methods*/

	virtual void vInitScene();
	virtual void vUpdateScene();
	virtual void vDrawScene();

	/* Get Methods */

	bool isLoaded();
	std::string getSceneName();
	std::vector<AActor*> getSceneActors();

	/* Set Methods */

	void setSceneName(const std::string& n);


	void initScene(sf::RenderWindow* window);
	void updateScene();
	void drawScene();

	void closeScene();

	/* Add Methods */

	void addActor(AActor* a);

	
private:

	bool isLoad = false;
	std::string sceneName;
	std::vector<AActor*> sceneActors;
	sf::RenderWindow* windowTarget;
	virtual inline void actorsPlay(ESceneAction state);

	/*
	*  This method return true if actorsList != 0
	*/
	virtual inline bool checkActorsCount();


};
