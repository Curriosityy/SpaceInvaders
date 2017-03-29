#pragma once
#include "game_state.h"
class menu_state : public tiny_state
{
public:

	menu_state();
	~menu_state();

	// Inherited via tiny_state
	void Initialize(sf::RenderWindow * window) override;
	void Update(sf::RenderWindow * window) override;
	void Render(sf::RenderWindow * window) override;
	void Destroy(sf::RenderWindow * window) override;
private:
	sf::Font* font;
	sf::Text* title;
	sf::Text* play;
	sf::Text* quit;
	int selected = 0;
	bool upKey, downKey;

};

