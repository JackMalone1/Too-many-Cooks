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
	sf::Sprite m_body;
	sf::Texture m_texture;
	std::string m_texturePath;
	sf::Vector2f m_position;
	bool isRepairing;
	bool repairPressed;
	int controlType;
	Room* m_otherRoom;
	int& score;
	sf::Text text;
	sf::Font font;

	void handleCollisions();
	void newBrokenObject();
public:
	Room(sf::Vector2f t_pos, int controls, int& t_score, std::string & t_texturePath);
	void init();
	void render(sf::RenderWindow& t_window);
	void update(sf::Time t_dt);
	void processEvents(sf::Event t_event);
	Object* getRandomObject();
	void setOtherRoom(Room* t_otherRoom) { m_otherRoom = t_otherRoom; };
	Object* findClosestToPlayer();
};

