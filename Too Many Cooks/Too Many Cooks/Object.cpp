#include "Object.h"

Object::Object(sf::Vector2f t_pos, sf::Color t_colour, ObjectType t_type) :
	Entity(t_pos, t_colour, 100),
	m_beingInteracted(false),
	m_repairProgress(100),
	m_repairRate(5),
	m_type(t_type),
	linkedObject(nullptr)
{
}

void Object::print()
{
	switch (m_type)
	{
	case ObjectType::Type1:
		std::cout << "type1" << std::endl;
		break;
	case ObjectType::Type2:
		std::cout << "type2" << std::endl;
		break;
	case ObjectType::Type3:
		std::cout << "type3" << std::endl;
		break;
	case ObjectType::Type4:
		std::cout << "type4" << std::endl;
		break;
	case ObjectType::Type5:
		std::cout << "type5" << std::endl;
		break;
	case ObjectType::Type6:
		std::cout << "type6" << std::endl;
		break;
	case ObjectType::Type7:
		std::cout << "type7" << std::endl;
		break;
	case ObjectType::Type8:
		std::cout << "type8" << std::endl;
		break;
	default:
		break;
	}
}
