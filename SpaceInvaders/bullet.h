#pragma once
#include "entity.h"
class bullet : public entity
{
public:
	bullet(sf::Texture * spriteSheet, sf::IntRect rect, float x, float y);
	void Update(sf::RenderWindow * window);
	~bullet();

	// Inherited via entity
	void ifCollided(entity * entity) override;
private:
};

