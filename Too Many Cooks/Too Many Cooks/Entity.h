#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
private:
public:
	sf::Vector2f getPosition() { return m_position; }
	void setPosition(sf::Vector2f t_position) { m_position = t_position; }

	Entity();
	Entity(sf::Vector2f t_pos);

	virtual void update();
	virtual void render(sf::RenderWindow& t_window);
protected:
	sf::Vector2f m_position{ sf::Vector2f(0.0f,0.0f) };
	sf::RectangleShape m_body;
};

