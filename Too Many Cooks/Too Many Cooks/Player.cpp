#include "Player.h"

Player::Player()
{
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
