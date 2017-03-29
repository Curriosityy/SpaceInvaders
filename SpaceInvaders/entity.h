#pragma once
#include <SFML\Graphics.hpp>
class entity:public sf::Sprite
{
public:
	entity();
	void Load(std::string filename);
	void Load(sf::Texture* spriteSheet, sf::IntRect rect);
	virtual void Update( sf::RenderWindow * window);
	bool CheckCollision(entity* entity);
	void SetSpeed(sf::Int32 speed);
	virtual void ifCollided(entity* entity) = 0;
	int GetActive();
	int GetIdType();
	void Destroy();
	~entity();
private:
	sf::Texture* texutre;
protected:
	sf::Vector2f velocity;
	sf::Int32 speed=0;
	int active;
	int idType;
};

