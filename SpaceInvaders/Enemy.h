#pragma once
#include "entity.h"
class enemy : public entity
{
public:
	enemy(sf::Texture * spriteSheet, sf::IntRect rect, float x, float y);
	void Update( sf::RenderWindow * window);
	~enemy();

	// Inherited via entity
	void ifCollided(entity * entity) override;
private:
};

