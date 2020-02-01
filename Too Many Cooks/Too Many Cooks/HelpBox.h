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
	HelpBox(sf::Vector2f t_position);
	void setObjectTypeText(std::string& t_string);
	void setCurrent(Object t_current) { m_current = &t_current; }
private:
	sf::Vector2f m_position;
	sf::RectangleShape m_body;
	Object* m_current;
};              

