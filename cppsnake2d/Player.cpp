#include "Player.h"

void Player::init()
{
	std::cout << "Start initalizate " << getActorName()->c_str() << "\n";
	getActorShape()->setFillColor(sf::Color::White);
	getActorShape()->setSize(sf::Vector2f(100,100));
	getActorShape()->setPosition(sf::Vector2f(100,100));
	std::cout << "Finish initalizate " << getActorName()->c_str() << "\n";

}

void Player::update()
{

}
