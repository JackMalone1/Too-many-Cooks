#pragma once
#include "Entity.h"
class Player : public Entity
{
private:

public:
	Player();
	Player(sf::Vector2f t_position);
	~Player();

	virtual  void update() override;
	virtual void render(sf::RenderWindow& t_window) override;

	void processKeyEvents(sf::Event t_event);
};

