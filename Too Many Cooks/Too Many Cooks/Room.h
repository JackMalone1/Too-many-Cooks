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
	Object* m_currentBroken;
	HelpBox m_helpBox;
	sf::RectangleShape m_body;
	sf::Vector2f m_position;

	void handleCollisions();
public:
	Room(sf::Vector2f t_pos);
	void init();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_dt);
	void processEvents(sf::Event t_event);
	Object* getRandomObject();
	void setOtherRoom(Room* t_otherRoom) { m_otherRoom = t_otherRoom; };
	Object* findClosestToPlayer();
	Room* m_otherRoom;
};

