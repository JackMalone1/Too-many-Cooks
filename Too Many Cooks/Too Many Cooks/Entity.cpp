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

void Entity::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}
