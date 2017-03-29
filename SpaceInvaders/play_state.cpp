#include "play_state.h"
#include "menu_state.h"
#include "Enemy.h"
#include <iostream>
play_state::play_state()
{
}


play_state::~play_state()
{
}

void play_state::Initialize(sf::RenderWindow * window)
{
	spriteSheet = new sf::Texture();
	spriteSheet->loadFromFile("spriteSheet.png");
	this->manager.Add("player", new player(&this->manager,this->spriteSheet, sf::IntRect(132, 15, 28, 14), window->getSize().x/2, window->getSize().y));
	this->manager.Add("enemy", new enemy(this->spriteSheet, sf::IntRect(0, 11, 32, 16), window->getSize().x / 2, window->getSize().y / 2));
	this->manager.Add("enemy", new enemy(this->spriteSheet, sf::IntRect(0, 11, 32, 16), window->getSize().x / 2 + 40, window->getSize().y / 2));
	this->manager.Add("enemy", new enemy(this->spriteSheet, sf::IntRect(0, 11, 32, 16), window->getSize().x / 2 + 80, window->getSize().y / 2));
}

void play_state::Update(sf::RenderWindow * window)
{
	this->manager.Update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		coreState.SetState(new menu_state);
	}

}

void play_state::Render(sf::RenderWindow * window)
{
	this->manager.Render(window);
	sf::RectangleShape rect(sf::Vector2f(1, window->getSize().y));
}

void play_state::Destroy(sf::RenderWindow * window)
{
}
