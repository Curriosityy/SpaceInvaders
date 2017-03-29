#include "bullet.h"



bullet::bullet(sf::Texture * spriteSheet, sf::IntRect rect, float x, float y) : entity()
{
	this->active = 1;
	this->idType = 3;
	this->speed = 3;
	this->setPosition(x, y);
	this->Load(spriteSheet, rect);
}

void bullet::Update(sf::RenderWindow * window)
{
	if (this->getPosition().y - this->getGlobalBounds().height / 2 <= 0 || this->getPosition().y + this->getGlobalBounds().height / 2 >= window->getSize().y)
	{
		this->Destroy();
	}
	entity::Update(window);
}


bullet::~bullet()
{
}

void bullet::ifCollided(entity * entity)
{
	switch (entity->GetIdType())
	{
	case 3:
		break;
	default:
		this->Destroy();
		break;
	}
}
