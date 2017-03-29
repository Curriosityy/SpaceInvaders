#pragma once
#include "game_state.h"
#include "entity_manager.h"
#include "player.h"
class play_state : public tiny_state
{
public:
	play_state();
	~play_state();

	// Inherited via tiny_state
	void Initialize(sf::RenderWindow * window) override;
	void Update(sf::RenderWindow * window) override;
	void Render(sf::RenderWindow * window) override;
	void Destroy(sf::RenderWindow * window) override;
private:
	sf::Texture* spriteSheet;
	entity_manager manager;
};

