#include "MenuButton.h"

void MenuButton::init()
{
	sf::Font* font = new sf::Font;
	if (!font->loadFromFile("C:/Users/Admin/Desktop/Projekty/cppsnake2d/cppsnake2d/fonts/ttf/JetBrainsMono-Bold.ttf"))
	{
		std::cout << "Cant load font\n";
		return;
	}
	getActorText()->setFont(*font);
	getActorText()->setCharacterSize(18);
	getActorText()->setFillColor(sf::Color::White);
	getActorText()->setOrigin(getActorText()->getLocalBounds().getSize().x / 2, getActorText()->getLocalBounds().getSize().y / 2);
}

void MenuButton::update()
{

}

void MenuButton::setText(const std::string& text)
{
	getActorText()->setString(text);
}

void MenuButton::setPosition(sf::Vector2f pos)
{
	getActorText()->setPosition(pos);
}
