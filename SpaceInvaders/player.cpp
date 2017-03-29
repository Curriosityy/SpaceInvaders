#include "player.h"
#include "bullet.h"


player::player(sf::Texture * spriteSheet, sf::IntRect rect,float x,float y) : entity()
{
	this->active = 1;
	this->idType = 1;
	this->speed = 2;
	this->setPosition(x, y);
	this->Load(spriteSheet,rect);
}

void player::Update(sf::Texture* spriteSheet, sf::RenderWindow * window, entity_manager* manager)
{
	this->velocity.x = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		manager->Add("bullet", new bullet(spriteSheet, sf::IntRect(174, 7, 4, 18), this->getOrigin().x,this->getOrigin().y-20));
	}
	entity::Update( window);
}


player::~player()
{
}

void player::ifCollided(entity * entity)
{
	switch (entity->GetIdType())
	{
	case 1:
		break;
	case 2:
		this->Destroy();
		break;
	}
}
