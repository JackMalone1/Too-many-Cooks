#include "Object.h"

Object::Object(sf::Vector2f t_pos, sf::Color t_colour, ObjectType t_type, std::string& t_filepath) :
	Entity(t_pos, t_colour, 100, t_filepath),
	m_beingInteracted(false),
	m_repairProgress(100),
	m_repairRate(5),
	m_type(t_type),
	linkedObject(nullptr)
{
}
