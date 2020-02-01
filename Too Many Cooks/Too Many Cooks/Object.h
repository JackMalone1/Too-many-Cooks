#pragma once
#include "Entity.h"

enum class ObjectType
{
	Type1,
	Type2,
	Type3,
	Type4,
	Type5,
	Type6,
	Type7,
	Type8
};

class Object : public Entity
{
public:
	Object(sf::Vector2f t_pos, sf::Color t_colour);
	sf::RectangleShape getShape() { return m_body; }

private:
	bool m_beingInteracted;
	sf::Time m_repairtimer;
	std::vector<Object*> linkedObjects;
	ObjectType m_type;
};

