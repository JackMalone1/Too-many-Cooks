#pragma once



#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Object.h"
#include "HelpBox.h"

class Room
{
private:
	Player m_player;
	std::vector<Object> m_objects;
	HelpBox m_helpBox;
	sf::Sprite m_body;
public:
	void render(sf::RenderWindow& t_window);
	void update();
	void processEvents(sf::Event t_event);

	Room(sf::Vector2f t_pos);
	Room();
};

