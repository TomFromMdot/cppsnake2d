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

void AActor::setActorType(EActorType t)
{
	if (t != actorType)
		actorType = t;
}

sf::RectangleShape* AActor::getActorShape()
{
	return &actorShape;
}

sf::Text* AActor::getActorText()
{
	return &actorText;
}

sf::Vector2f AActor::getActorSize()
{
	return actorShape.getPosition();
}

void AActor::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(actorType == SHAPE)
		target.draw(actorShape, states);
	if (actorType == TEXT)
	{
		target.draw(actorText, states);
	}
}
