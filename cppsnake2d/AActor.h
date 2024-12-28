#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class AActor : public sf::Drawable
{
public:
	AActor();
	virtual ~AActor();


	virtual void init();
	virtual void update();
	

	virtual std::string* getActorName();

	virtual void setActorName(const std::string& n);

	virtual sf::RectangleShape* getActorShape();

private:
	std::string actorName;

	sf::RectangleShape actorShape;
	sf::Vector2i actorSize, actorPosition;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

