#include "Text.h"

void Text::init()
{
	sf::Font* font = new sf::Font;
	if (!font->loadFromFile("C:/Users/Admin/Desktop/Projekty/cppsnake2d/cppsnake2d/fonts/ttf/JetBrainsMono-Bold.ttf"))
	{
		std::cout << "Cant load font\n";
		return;
	}
	getActorText()->setString("Rapid Snake 2D");
	getActorText()->setFont(*font);
	getActorText()->setCharacterSize(24);
	getActorText()->setFillColor(sf::Color::White);
	getActorText()->setOrigin(getActorText()->getLocalBounds().getSize().x / 2, getActorText()->getLocalBounds().getSize().y / 2);
	getActorText()->setPosition((800 / 2) , 100 );
}
void Text::update()
{

}
