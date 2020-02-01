#include "HelpBox.h"

#define ENUM_TO_STRING(ENUM) std::string(#ENUM)

void HelpBox::render(sf::RenderWindow& t_window, sf::Vector2f t_offset)
{
	if (m_current != nullptr)
	{
		sf::RectangleShape rectangleBackground;
		rectangleBackground.setSize(sf::Vector2f(800, 200));
		sf::Color grey = sf::Color(211, 211, 211,255);
		rectangleBackground.setFillColor(grey);
		rectangleBackground.setPosition(t_offset + sf::Vector2f(0.0f,800.0f));
		t_window.draw(rectangleBackground);
		m_current->render(t_window, m_position);
		m_current->setPosition(sf::Vector2f(m_position.x + t_offset.x, m_position.y + 850));

		std::string string = "";
		setObjectTypeText(string);
		sf::Text text;
		sf::Font font;

		if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
		{
			std::cout << "problem loading arial black font" << std::endl;
		}

		text.setFont(font);
		text.setString(string);
		text.setPosition(t_offset + sf::Vector2f(0.0f, 950.0f));
		text.setFillColor(sf::Color::Red);

		t_window.draw(text);
	}
}

HelpBox::HelpBox(sf::Vector2f t_position) : m_position{ t_position }, m_current{ nullptr }
{
	m_current = new Object(sf::Vector2f(250, 0), sf::Color::Blue);
}

void HelpBox::setObjectTypeText(std::string& t_string)
{
	ObjectType type = m_current->getType();


	switch (type)
	{
	case ObjectType::Type1:
		t_string = "type1";
		break;
	case ObjectType::Type2:
		t_string = "type2";
		break;
	case ObjectType::Type3:
		t_string = "type3";
		break;
	case ObjectType::Type4:
		t_string = "type4";
		break;
	case ObjectType::Type5:
		t_string = "type5";
		break;
	case ObjectType::Type6:
		t_string = "type6";
		break;
	case ObjectType::Type7:
		t_string = "type7";
		break;
	case ObjectType::Type8:
		t_string = "type8";
		break;
	}
}
