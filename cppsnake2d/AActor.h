#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum EActorType
{
	SHAPE,
	TEXT
};
 
class AActor : public sf::Drawable
{
public:
	AActor();
	virtual ~AActor();


	virtual void init();
	virtual void update();
	

	virtual std::string* getActorName();

	virtual void setActorName(const std::string& n);
	virtual void setActorType(EActorType t);

	virtual sf::RectangleShape* getActorShape();
	virtual sf::Text* getActorText();
	virtual sf::Vector2f getActorSize();


private:
	std::string actorName;
	EActorType actorType = SHAPE;


	sf::RectangleShape actorShape;
	sf::Text actorText;


	sf::Vector2i actorSize, actorPosition;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

