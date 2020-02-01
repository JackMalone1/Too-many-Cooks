#pragma once
#include "Entity.h"
class Player : public Entity
{
private:

public:
	Player(sf::Vector2f t_position);
	~Player();

	virtual  void update() override;
};

