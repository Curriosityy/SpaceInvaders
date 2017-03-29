#pragma once
#include <SFML\Graphics.hpp>
class tiny_state
{
public:
	virtual void Initialize(sf::RenderWindow* window) = 0;
	virtual void Update(sf::RenderWindow* window) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Destroy(sf::RenderWindow* window) = 0;
private:
};

class game_state
{
public:
	game_state()
	{
		this->state = NULL;
	}
	void SetWindow(sf::RenderWindow* window)
	{
		this->window = window;
	}
	void SetState(tiny_state* state)
	{
		if (this->state != NULL)
		{
			this->state->Destroy(this->window);
		}
		delete this->state;
		this->state = state;
		if (this->state != NULL)
		{
			this->state->Initialize(this->window);
		}
	}
	void Update()
	{
		if (this->state != NULL)
		{
			this->state->Update(window);
		}
	}
	void Render()
	{
		if (this->state != NULL)
		{
			this->state->Render(window);
		}
	}
	~game_state()
	{
		if(this->state !=NULL)
		this->state->Destroy(window);
	}
private:
	tiny_state* state;
	sf::RenderWindow* window;
};

extern game_state coreState;
extern bool bQuit;
extern int window_x, window_y;