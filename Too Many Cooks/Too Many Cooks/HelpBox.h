#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class HelpBox
{
public:
	sf::Sprite getSprite() { return m_body; }
private:
	sf::Sprite m_body;
	sf::Texture m_texture;
};

