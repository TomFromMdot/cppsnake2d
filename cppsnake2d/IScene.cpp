#include "IScene.h"
AScene* IScene::currentScene = nullptr;
sf::RenderWindow* IScene::targetWindow = nullptr;
std::vector<AScene*> IScene::scenesList = {};

void IScene::setTarget(sf::RenderWindow& target)
{
	targetWindow = &target;
}

sf::RenderWindow* IScene::getTarget()
{
	if(targetWindow != nullptr)
		return targetWindow;
	return nullptr;
}

void IScene::bindNewScene(AScene* scene)
{
	if (scene != nullptr)
	{
		scenesList.push_back(scene);
		return;
	}
	std::cout << "Add " << scene->getSceneName().c_str() << " to list\n";
}

AScene* IScene::getCurrentScene()
{
	return currentScene;
}

void IScene::setCurrentScene(const std::string& n)
{
	if (!n.empty())
	{
		for (int it = 0; it != scenesList.size(); it++)
		{
			if (scenesList[it]->getSceneName().c_str() == n )
			{
				if(currentScene != nullptr)
					currentScene->closeScene();
				std::cout << "Set current scene: " << scenesList[it]->getSceneName()<< " \n";
				currentScene = scenesList[it];
				return;
			}

		}
	}
	std::cout << "Can't find scene by name:" << n << "\n";
}

void IScene::addActorToScene(AActor* actor, AScene* target)
{
	if (actor != nullptr && target != nullptr)
	{
		std::cout << "Add actor: " << actor->getActorName()->c_str() << " to scene: " << target->getSceneName() << "\n";
		target->addActor(actor);
	}
}



