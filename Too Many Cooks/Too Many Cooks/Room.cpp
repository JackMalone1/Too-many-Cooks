#include "Room.h"

Room::Room(sf::Vector2f t_pos) :
	m_player(sf::Vector2f(370, 320)),
	m_helpBox{ t_pos },
	repairPressed(false),
	isRepairing(false)
{
	m_position = t_pos;
	m_body.setPosition(t_pos);
	m_body.setSize(sf::Vector2f(800, 700));
	m_body.setFillColor(sf::Color::Black);
	m_objects.push_back(Object(sf::Vector2f(250, 0), sf::Color::Magenta, ObjectType::Type1));
	m_objects.push_back(Object(sf::Vector2f(450, 0), sf::Color::Magenta, ObjectType::Type2));
	m_objects.push_back(Object(sf::Vector2f(700, 200), sf::Color::Magenta, ObjectType::Type3));
	m_objects.push_back(Object(sf::Vector2f(700, 400), sf::Color::Magenta, ObjectType::Type4));
	m_objects.push_back(Object(sf::Vector2f(0, 200), sf::Color::Magenta, ObjectType::Type5));
	m_objects.push_back(Object(sf::Vector2f(0, 400), sf::Color::Magenta, ObjectType::Type6));
	m_objects.push_back(Object(sf::Vector2f(250, 600), sf::Color::Magenta, ObjectType::Type7));
	m_objects.push_back(Object(sf::Vector2f(450, 600), sf::Color::Magenta, ObjectType::Type8));

	m_currentBroken = getRandomObject();
	//Set up room bounds
}

void Room::init()
{
	m_currentBroken->setLinked(m_otherRoom->getRandomObject());
}

void Room::handleCollisions()
{
	if (m_player.getPosition().x + m_position.x < m_position.x)
	{
		m_player.setPosition(sf::Vector2f(2, m_player.getPosition().y));
	}
	if (m_player.getPosition().x + m_position.x + m_player.getBody().getSize().x >= m_position.x + 800)
	{
		m_player.setPosition(sf::Vector2f(800 - m_player.getBody().getSize().x - 2, m_player.getPosition().y));
	}
	if (m_player.getPosition().y + m_position.y < m_position.y)
	{
		m_player.setPosition(sf::Vector2f(m_player.getPosition().x, 2));
	}
	if (m_player.getPosition().y + m_position.y + m_player.getBody().getSize().y >= m_position.y + 700)
	{
		m_player.setPosition(sf::Vector2f(m_player.getPosition().x, 700 - m_player.getBody().getSize().y - 2));
	}
}

void Room::newBrokenObject()
{
	m_currentBroken->setLinked(nullptr);
	m_currentBroken = getRandomObject();
	m_currentBroken->setLinked(m_otherRoom->getRandomObject());
}

void Room::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
	m_player.render(t_window, m_position);
	for (auto& object : m_objects)
	{
		object.render(t_window, m_position);
	}
	m_helpBox.render(t_window, m_position);
}

void Room::update(sf::Time t_dt)
{
	m_player.update();

	m_helpBox.setCurrent(findClosestToPlayer());

	handleCollisions();
}

void Room::processEvents(sf::Event t_event)
{
	if (t_event.type == sf::Event::KeyPressed)
	{
		if (t_event.key.code == sf::Keyboard::E)
		{
			repairPressed = true;
		}
	}

	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::E)
		{
			repairPressed = false;
		}
	}
	if (!repairPressed)
	{
		m_player.processKeyEvents(t_event);
	}
	else
	{
		m_player.setDown(false);
		m_player.setLeft(false);
		m_player.setRight(false);
		m_player.setUp(false);
	}
}

Object* Room::getRandomObject()
{
	if (m_objects.size() > 0)
	{
		return &m_objects[int(rand() % m_objects.size())];
	}
	return nullptr;
}

Object* Room::findClosestToPlayer()
{
	Object* current = &m_objects[0];
	float closestDisctance = m_player.distanceBetween(m_objects[0].getPosition());
	for (int i = 1; i < m_objects.size(); i++)
	{
		float newDistance = m_player.distanceBetween(m_objects[i].getPosition());
		if (newDistance < closestDisctance)
		{
			current = &m_objects[i];
			closestDisctance = newDistance;
		}
	}
	return current;
}
