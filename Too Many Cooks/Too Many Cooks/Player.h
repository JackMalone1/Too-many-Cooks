#pragma once
#include "Entity.h"
#include "Object.h"
#include <iostream>
class Player : public Entity
{
private:
	bool m_up{ false };
	bool m_down{ false };
	bool m_left{ false };
	bool m_right{ false };
	Object* interacting;
public:
	Player(sf::Vector2f t_position);
	~Player();

	virtual  void update() override;
	void processKeyEvents(sf::Event t_event);

	void setLeft(bool t_left) { m_left = t_left; }
	void setRight(bool t_right) { m_right = t_right; }
	void setUp(bool t_up) { m_up = t_up; }
	void setDown(bool t_down) { m_down = t_down; }
	void setInteracting(Object* obj) { interacting = obj; };
	Object* getInteracting() { return interacting; };
	sf::RectangleShape getBody() { return m_body; }
};

