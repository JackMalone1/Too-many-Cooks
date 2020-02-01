#pragma once
#include "Entity.h"

#include <iostream>
class Player : public Entity
{
private:
	bool m_up{ false };
	bool m_down{ false };
	bool m_left{ false };
	bool m_right{ false };
public:
	Player(sf::Vector2f t_position);
	~Player();

	virtual  void update() override;
	void processKeyEvents(sf::Event t_event);
};

