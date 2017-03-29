#include "entity_manager.h"



entity_manager::entity_manager()
{

}

void entity_manager::Add(std::string name, entity* entitys)
{
	std::unordered_map<std::string, entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.end())
	{
		name += "0";
		found = this->entities.find(name);
	}
	this->entities.insert(std::make_pair(name, entitys));
}

void entity_manager::Update( sf::RenderWindow * window)
{
	std::vector<std::string> toRemove;
	for(auto& iterator : this->entities)
	{
		for (auto& iterator2 : this->entities)
		{
			if (iterator.first != iterator2.first && iterator.second->CheckCollision(iterator2.second))
			{
				iterator.second->ifCollided(iterator2.second);
			}
		}
		switch (iterator.second->GetActive())
		{
		case 0:
			toRemove.push_back(iterator.first);
			break;
		default:	
			iterator.second->Update(window);
			break;
		}
	}
	for (auto& iterator : toRemove)
	{
		std::unordered_map<std::string, entity*>::const_iterator found = this->entities.find(iterator);
		if (found != this->entities.end())
		{
			delete found->second;
			this->entities.erase(iterator);
		}
	}
	toRemove.clear();
}

void entity_manager::Render(sf::RenderWindow * window)
{
	for (auto& iterator : this->entities)
	{
		window->draw(*iterator.second);
	}
}

entity * entity_manager::getName(std::string name)
{
	std::unordered_map<std::string, entity*>::const_iterator found = this->entities.find(name);
	if (found == this->entities.end())
	{
		return nullptr;
	}
	else
	{
		return found->second;
	}
	
}


entity_manager::~entity_manager()
{
	for (auto& iterator : this->entities)
	{
		delete iterator.second;
	}
	entities.clear();
}
