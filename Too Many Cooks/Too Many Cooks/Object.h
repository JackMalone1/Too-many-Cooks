#pragma once
#include "Entity.h"
class Object : public Entity
{
public:
	Object(sf::Vector2f t_pos, sf::Color t_colour);
	sf::RectangleShape getShape() { return m_body; }
private:
	bool repaired;
	bool beingInteracted;
	std::vector<Object*> linkedObjects;
};

