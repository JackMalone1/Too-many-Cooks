#include "Object.h"

Object::Object(sf::Vector2f t_pos, sf::Color t_colour, ObjectType t_type) :
	Entity(t_pos, t_colour, 100),
	m_beingInteracted(false),
	m_repairtimer(sf::Time::Zero),
	m_type(t_type),
	linkedObject(nullptr)
{
}
