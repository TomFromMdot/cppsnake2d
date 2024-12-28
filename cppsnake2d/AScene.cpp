#include "AScene.h"

AScene::~AScene()
{
	std::cout << sceneName << " was deleted !\n";
}

bool AScene::isLoaded()
{
	return isLoad;
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
			std::cout << "Scene state: update\n";
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
			std::cout << "Scene state: draw\n";
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
		if (state == CLOSE)
		{
			std::cout << "Scene state: draw\n";
			for (int it = 0; it != sceneActors.size(); it++)
			{
				std::cout << "Unload actor: " << sceneActors[it]->getActorName() << "\n";
				sceneActors.erase(sceneActors.begin() + it);
			}
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

void AScene::vInitScene()
{

}

void AScene::vUpdateScene()
{

}

void AScene::vDrawScene()
{

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
	std::cout << "update " << sceneName << "\n";
	vUpdateScene();
	actorsPlay(UPDATE);
}

void AScene::drawScene()
{
	std::cout << "draw" << sceneName << "\n";
	vDrawScene();
	actorsPlay(DRAW);
}

void AScene::closeScene()
{
	std::cout << "close " << sceneName << "\n";
	actorsPlay(CLOSE);
}
