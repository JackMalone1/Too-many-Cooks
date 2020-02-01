#include "Object.h"

Object::Object(sf::Vector2f t_pos, sf::Color t_colour) :
	Entity(t_pos, t_colour, 100),
	m_beingInteracted(false),
	m_repairtimer(sf::Time::Zero),
	m_type(ObjectType::Type1)
{
}
