#pragma once
#include "Entity.h"
class Object : public Entity
{
public:
	sf::RectangleShape getShape() { return m_body; }
private:
	bool repaired;
	bool beingInteracted;
	std::vector<Object*> linkedObjects;
};

