#include "Player.h"

Player::Player()
{
	m_position = sf::Vector2f(30.0f,30.0f);
	m_body.setSize(sf::Vector2f(20.0f, 20.0f));
	m_body.setPosition(m_position);
	m_body.setFillColor(sf::Color::Red);
	m_body.setOrigin(10.0f, 10.0f);
}

Player::Player(sf::Vector2f t_position)
{
	m_position = t_position;
	m_body.setSize(sf::Vector2f(20.0f, 20.0f));
	m_body.setPosition(m_position);
	m_body.setFillColor(sf::Color::Red);
	m_body.setOrigin(10.0f, 10.0f);
}

Player::~Player()
{
}

void Player::update()
{
}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_body);
}

void Player::processKeyEvents(sf::Event t_event)
{
	if (t_event.key.code == sf::Keyboard::W || t_event.key.code == sf::Keyboard::Up)
	{
		m_body.move(0.0f, -10.0f);
	}
	if (t_event.key.code == sf::Keyboard::A || t_event.key.code == sf::Keyboard::Left)
	{
		m_body.move(-10.0f, 0.0f);
	}
	if (t_event.key.code == sf::Keyboard::D || t_event.key.code == sf::Keyboard::Right)
	{
		m_body.move(10.0f, 0.0f);
	}
	if (t_event.key.code == sf::Keyboard::S || t_event.key.code == sf::Keyboard::Down)
	{
		m_body.move(0.0f, 10.0f);
	}
}
