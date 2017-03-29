#include "menu_state.h"
#include "play_state.h"
#include <iostream>


menu_state::menu_state()
{
}

menu_state::~menu_state()
{
}


void menu_state::Initialize(sf::RenderWindow * window)
{
	std::cout << "init\n";
	this->font = new sf::Font();
	this->font->loadFromFile("font.ttf");
	this->title = new sf::Text("Space Invaders",*this->font,70U);
	this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
	this->title->setPosition(window->getSize().x / 2, window->getSize().y / 4);
	this->play = new sf::Text("Play", *this->font, 40U);
	this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->title->getGlobalBounds().height /4);
	this->play->setPosition(this->title->getPosition().x, this->title->getPosition().y + this->title->getGlobalBounds().height+30);
	this->quit = new sf::Text("Quit", *this->font, 40U);
	this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 4);
	this->quit->setPosition(this->play->getPosition().x, this->play->getPosition().y + this->play->getGlobalBounds().height + 30);
}

void menu_state::Update(sf::RenderWindow * window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		selected -= 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		selected += 1;
	}
	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

	if (selected<0)
	{
		selected = 1;
	}
	if (selected > 1)
	{
		selected = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
	{
		switch (this->selected)
		{
		case 0:
			coreState.SetState(new play_state);
			break;
		case 1:
			bQuit = true;
			break;
		default:
			break;
		}
	}
}

void menu_state::Render(sf::RenderWindow * window)
{

	this->play->setColor(sf::Color::White);
	this->quit->setColor(sf::Color::White);
	switch (selected)
	{
	case 0:
		this->play->setColor(sf::Color::Green);
		break;
	case 1:
		this->quit->setColor(sf::Color::Green);
		break;
	}
	window->draw(*this->title);
	window->draw(*this->play);
	window->draw(*this->quit);

}

void menu_state::Destroy(sf::RenderWindow * window)
{
	delete this->font;
	delete this->title;
	std::cout << "dest\n";
}

