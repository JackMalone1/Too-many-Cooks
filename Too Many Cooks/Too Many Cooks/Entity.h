#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
private:
public:
	Entity(sf::Vector2f t_pos, sf::Color t_colour, int size, std::string& t_filepath);
	sf::Vector2f getPosition() { return m_position; }
	void setPosition(sf::Vector2f t_position) { m_position = t_position; }

	virtual void update();
	virtual void render(sf::RenderWindow& t_window, sf::Vector2f t_offset);

	float distanceBetween(sf::Vector2f t_other);
protected:
	sf::Vector2f m_position;
	sf::Sprite m_body;
	sf::Texture m_texture;
	std::string m_texturePath;
};

