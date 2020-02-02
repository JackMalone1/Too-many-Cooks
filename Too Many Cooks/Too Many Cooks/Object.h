#pragma once
#include "Entity.h"
#include <iostream>

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
	Object(sf::Vector2f t_pos, sf::Color t_colour, ObjectType t_type, std::string& t_filepath);
	sf::Sprite getShape() { return m_body; }
	ObjectType getType() { return m_type; };
	Object* getLinked() { return linkedObject; };
	void setLinked(Object* t_obj) { linkedObject = t_obj; };
	void setBeingInteracted(bool i) { m_beingInteracted = i; };
	bool getBeingInteracted() { return m_beingInteracted; };
	void setRepairProgress(int t_progress) { m_repairProgress = t_progress; };
	int getRepairProgress() { return m_repairProgress; };
	void repair(sf::Time t_dt) { m_repairProgress -= 1; };
	void print();
private:
	bool m_beingInteracted;
	int m_repairProgress;
	float m_repairRate;
	Object* linkedObject;
	ObjectType m_type;
};

