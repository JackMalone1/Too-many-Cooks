#include "Room.h"

Room::Room(sf::Vector2f t_pos) :
	m_player(sf::Vector2f(370, 320))
{
	m_position = t_pos;
	m_body.setPosition(t_pos);
	m_body.setSize(sf::Vector2f(800, 700));
	m_body.setFillColor(sf::Color::Black);
	m_objects.push_back(Object(sf::Vector2f(250, 0), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(450, 0), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(700, 200), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(700, 400), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(0, 200), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(0, 400), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(250, 600), sf::Color::Magenta));
	m_objects.push_back(Object(sf::Vector2f(450, 600), sf::Color::Magenta));

	currentBroken = getRandomObject();
	//Set up room bounds
}

void Room::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	m_player.render(t_window, m_position);
	for (auto& object : m_objects)
	{
		object.render(t_window, m_position);
	}
}

void Room::update(sf::Time t_dt)
{
	m_player.update();
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
