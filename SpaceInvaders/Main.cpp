#include "game_state.h"
#include "menu_state.h"

game_state coreState;
bool bQuit = false;
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	coreState.SetWindow(&window);
	coreState.SetState(new menu_state);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		coreState.Update();
		coreState.Render();
		window.display();
		if (bQuit)
		{
			window.close();
		}
	}

	return 0;
}