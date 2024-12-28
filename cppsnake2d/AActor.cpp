#include "AActor.h"

AActor::AActor()
{

}

AActor::~AActor()
{
}

void AActor::init()
{
}

void AActor::update()
{
}

std::string* AActor::getActorName()
{
	return &actorName;
}

void AActor::setActorName(const std::string& n)
{
	actorName = n;
}

sf::RectangleShape* AActor::getActorShape()
{
	return &actorShape;
}

void AActor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(actorShape, states);
}
