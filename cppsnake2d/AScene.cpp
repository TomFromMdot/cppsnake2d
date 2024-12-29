#include "AScene.h"

AScene::~AScene()
{
	std::cout << sceneName << " was deleted !\n";
}



std::string AScene::getSceneName()
{
	return sceneName;
}

std::vector<AActor*> AScene::getSceneActors()
{
	return sceneActors;
}

void AScene::setSceneName(const std::string& n)
{
	if (n.empty())
	{
		std::cout << "Scene name is empty\n";
		return;
	} 
	std::cout << "Set name: " << n << "\n";
	sceneName = n;
}

void AScene::addActor(AActor* a)
{
	sceneActors.push_back(a);
}

inline void AScene::actorsPlay(ESceneAction state)
{
	if (state == CLOSE)
	{
		for (int it = 0; it != sceneActors.size(); it++)
		{
			std::cout << "Remove: " << sceneActors[it]->getActorName()->c_str() << " from " << sceneName << "\n";
			delete sceneActors[it];
		}
		sceneActors.clear();
	}
	
	if (state == INIT && isLoad == false)
	{
		std::cout << "Scene state: init\n";
		if (sceneActors.size() == 0)
		{
			std::cout << "Zero actors !\n";
			return;
		}

		for (int it = 0; it != sceneActors.size(); it++)
		{
			sceneActors[it]->init();
		}
	}
	if (checkActorsCount())
	{
		if (state == UPDATE && isLoad == true)
		{

			if (sceneActors.size() == 0)
			{
				std::cout << "Zero actors !\n";
				return;
			}
			for (int it = 0; it != sceneActors.size(); it++)
			{
				sceneActors[it]->update();
			}
		}
		if (state == DRAW && isLoad == true)
		{

			if (sceneActors.size() == 0)
			{
				std::cout << "Zero actors !\n";
				return;
			}
			if (windowTarget != nullptr)
				for (int it = 0; it != sceneActors.size(); it++)
				{
					windowTarget->draw(*sceneActors[it]);
				}
			else
				std::cout << "Cannot find window target\n";
		}
	}
}

inline bool AScene::checkActorsCount()
{
	if (sceneActors.size() == 0)
	{
		std::cout << "Zero actors !\n";
		return false;
	}
	return true;
}


void AScene::initScene(sf::RenderWindow* window)
{
	if (window != nullptr)
		windowTarget = window;
	if (isLoad == false)
	{
		vInitScene();
		actorsPlay(INIT);
		isLoad = true;
	}
}

void AScene::updateScene()
{
	vUpdateScene();
	actorsPlay(UPDATE);
}

void AScene::drawScene()
{
	vDrawScene();
	actorsPlay(DRAW);
}

void AScene::closeScene()
{
	isLoad = false;
	std::cout << "unload\n";
}
