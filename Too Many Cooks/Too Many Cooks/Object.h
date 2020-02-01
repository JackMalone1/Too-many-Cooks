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
	Object(sf::Vector2f t_pos, sf::Color t_colour, ObjectType t_type);
	sf::RectangleShape getShape() { return m_body; }
	ObjectType getType() { return m_type; };
	Object* getLinked() { return linkedObject; };
	void setLinked(Object* t_obj) { linkedObject = t_obj; };

private:
	bool m_beingInteracted;
	sf::Time m_repairtimer;
	Object* linkedObject;
	ObjectType m_type;
};

