#pragma once
#include "entity.h"
#include "entity_manager.h"
class player : public entity
{
public:
	player(entity_manager* manager,sf::Texture * spriteSheet, sf::IntRect rect,float x, float y);
	void Update(sf::Texture* spriteSheet, sf::RenderWindow * window);
	~player();

	// Inherited via entity
	void ifCollided(entity * entity) override;
private:
	//entity_manager* manager;
};

