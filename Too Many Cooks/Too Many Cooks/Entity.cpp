#include "Entity.h"

Entity::Entity(sf::Vector2f t_pos, sf::Color t_colour, int size) :
	m_position(t_pos)
{
	m_body.setFillColor(t_colour);
	m_body.setPosition(m_position);
	m_body.setSize(sf::Vector2f(size, size));
}

void Entity::update()
{

}

void Entity::render(sf::RenderWindow& t_window, sf::Vector2f t_offset)
{
	m_body.setPosition(m_position + t_offset);
	t_window.draw(m_body);
}

float Entity::distanceBetween(sf::Vector2f t_other)
{
	sf::Vector2f distance = m_position - t_other;
	return sqrt(distance.x * distance.x + distance.y * distance.y);
}
