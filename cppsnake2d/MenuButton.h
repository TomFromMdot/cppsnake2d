#pragma once
#include "AActor.h"
class MenuButton : public AActor
{
public:
	virtual void init() override;
	virtual void update() override;
	void setText(const std::string& text);
	void setPosition(sf::Vector2f pos);
private:

};

