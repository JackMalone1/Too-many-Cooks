#include "Player.h"

Player::Player(sf::Vector2f t_position) : 
	Entity(t_position, sf::Color::Green, 20)
{
}

Player::~Player()
{
}

void Player::update()
{
	if (m_down)
	{
		setPosition(getPosition() + sf::Vector2f(0.0f, 10.0f));
	}

	if (m_up)
	{
		setPosition(getPosition() + sf::Vector2f(0.0f, -10.0f));
	}

	if (m_left)
	{
		setPosition(getPosition() + sf::Vector2f(-10.0f, 0.0f));
	}

	if (m_right)
	{
		setPosition(getPosition() + sf::Vector2f(10.0f, 0.0f));
	}
}

void Player::processKeyEvents(sf::Event t_event)
{
	if (t_event.type == sf::Event::KeyPressed)
	{
		if (t_event.key.code == sf::Keyboard::W || t_event.key.code == sf::Keyboard::Up)
		{
			m_up = true;
		}
		if (t_event.key.code == sf::Keyboard::A || t_event.key.code == sf::Keyboard::Left)
		{
			m_left = true;
		}
		if (t_event.key.code == sf::Keyboard::D || t_event.key.code == sf::Keyboard::Right)
		{
			m_right = true;
		}
		if (t_event.key.code == sf::Keyboard::S || t_event.key.code == sf::Keyboard::Down)
		{
			m_down = true;
		}
	}

	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::W || t_event.key.code == sf::Keyboard::Up)
		{
			m_up = false;
		}
		if (t_event.key.code == sf::Keyboard::A || t_event.key.code == sf::Keyboard::Left)
		{
			m_left = false;
		}
		if (t_event.key.code == sf::Keyboard::D || t_event.key.code == sf::Keyboard::Right)
		{
			m_right = false;
		}
		if (t_event.key.code == sf::Keyboard::S || t_event.key.code == sf::Keyboard::Down)
		{
			m_down = false;
		}
	}

}
