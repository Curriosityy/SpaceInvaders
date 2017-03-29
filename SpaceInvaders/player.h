#pragma once
#include "entity.h"
#include "entity_manager.h"
class player : public entity
{
public:
	player(sf::Texture * spriteSheet, sf::IntRect rect,float x, float y);
	void Update(sf::Texture* spriteSheet, sf::RenderWindow * window, entity_manager* manager);
	~player();

	// Inherited via entity
	void ifCollided(entity * entity) override;
private:
	//entity_manager* manager;
};

