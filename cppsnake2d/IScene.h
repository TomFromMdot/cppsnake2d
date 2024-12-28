#pragma once
#include <SFML/Graphics.hpp>
#include "AScene.h"


/*
* SCENES INTERFACE
* 
*/

class IScene
{
public:
	static void setTarget(sf::RenderWindow& target);
	static sf::RenderWindow* getTarget();


	static void bindNewScene(AScene* scene);
	static AScene* getCurrentScene();
	static void setCurrentScene(const std::string& n);

	static void addActorToScene(AActor* actor, AScene* target);
	static void removeActorFromScene(const std::string& n);


private:

	/*
	*	Check current scene
	*	If currentScene is nullptr return void to stop other metods
	*/
	static inline void checkCurrentScene();

	static AScene* currentScene;
	static sf::RenderWindow* targetWindow;
	static std::vector<AScene*> scenesList;


};

