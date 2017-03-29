#pragma once
#include "entity.h"
#include <unordered_map>
#include <vector>
class entity_manager
{
public:
	entity_manager();
	void Add(std::string name,entity* entitys);
	void Update( sf::RenderWindow * window);
	void Render(sf::RenderWindow* window);
	entity* getName(std::string name);
	~entity_manager();
private:
	std::unordered_map<std::string, entity*> entities;
};

