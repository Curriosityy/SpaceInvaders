#include "entity.h"



entity::entity()
{
	this->texutre = new sf::Texture;
	this->active = 1;
}

void entity::Load(std::string filename)
{
	this->texutre->loadFromFile(filename);
	this->setTexture(*this->texutre);
}

void entity::Load(sf::Texture* spriteSheet, sf::IntRect rect)
{
	this->setTexture(*spriteSheet);
	this->setTextureRect(rect);
	this->setOrigin(sf::Vector2f(rect.height, rect.width / 2));
}

void entity::Update( sf::RenderWindow * window)
{
	this->move(velocity.x *speed,velocity.y *speed);
}

bool entity::CheckCollision(entity* entity)
{
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

void entity::SetSpeed(sf::Int32 speed)
{
	this->speed = speed;
}

int entity::GetActive()
{
	return this->active;
}

int entity::GetIdType()
{
	return this->idType;
}

void entity::Destroy()
{
	this->active = 0;
}


entity::~entity()
{
	delete this->texutre;
}
