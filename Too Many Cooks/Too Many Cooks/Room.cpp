#include "Room.h"

Room::Room(sf::Vector2f t_pos) :
	m_player(sf::Vector2f(50, 50) + t_pos)
{
	m_position = t_pos;
	m_body.setPosition(t_pos);
	m_body.setSize(sf::Vector2f(800, 400));
	m_body.setFillColor(sf::Color::Black);
	//Set up room bounds
}

void Room::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	t_window.draw(m_helpBox.getSprite());
	m_player.render(t_window);
	for (auto& object : m_objects)
	{
		t_window.draw(object.getShape());
	}
}

void Room::update()
{
}

void Room::processEvents(sf::Event t_event)
{
	m_player.processKeyEvents(t_event);
}

Object* Room::getRandomObject()
{
	if (m_objects.size() > 0)
	{
		return &m_objects[int(rand() % m_objects.size())];
	}
	return nullptr;
}
