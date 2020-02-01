#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Object.h"

class HelpBox
{
public:
	sf::RectangleShape getSprite() { return m_body; }
	void setCurrent(Object* t_obj) { m_current = t_obj; };
	void render(sf::RenderWindow& t_window, sf::Vector2f t_offset);
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_body;
	Object* m_current;
};              

