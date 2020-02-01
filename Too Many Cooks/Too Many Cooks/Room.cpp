#include "Room.h"

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
}
