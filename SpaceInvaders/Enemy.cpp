#include "enemy.h"



enemy::enemy(sf::Texture * spriteSheet, sf::IntRect rect, float x, float y) : entity()
{
	this->active = 1;
	this->idType = 2;
	this->speed = 2;
	this->setPosition(x, y);
	this->Load(spriteSheet, rect);
	this->velocity.x = 1.0f;
}

void enemy::Update(sf::RenderWindow * window)
{
	velocity.y = 0;
	if (this->getPosition().x- this->getGlobalBounds().width / 2<= 0 || this->getPosition().x + this->getGlobalBounds().width / 2 >= window->getSize().x)
	{
		this->velocity.x *= -1;
		this->move(0, 10);
	}
	entity::Update(window);

}


enemy::~enemy()
{
}

void enemy::ifCollided(entity * entity)
{
	switch (entity->GetIdType())
	{
	case 1:
		break;
	}
}
