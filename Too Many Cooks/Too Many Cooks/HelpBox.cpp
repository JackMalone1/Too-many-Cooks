#include "HelpBox.h"

#define ENUM_TO_STRING(ENUM) std::string(#ENUM)

void HelpBox::render(sf::RenderWindow& t_window, sf::Vector2f t_offset)
{
	if (m_current != nullptr)
	{
		m_body.setPosition(t_offset + sf::Vector2f(0.0f,800.0f));
		t_window.draw(m_body);
		m_objectShape = m_current->getShape();
		m_objectShape.setPosition(sf::Vector2f(t_offset.x, t_offset.y + 850));
		t_window.draw(m_objectShape);


		text.setFont(font);
		text.setString(setObjectTypeText(m_current->getType()));
		text.setPosition(t_offset + sf::Vector2f(0.0f, 950.0f));

		t_window.draw(text);

		if (m_current->getLinked() != nullptr)
		{
			m_objectShape = m_current->getLinked()->getShape();
			m_objectShape.setPosition(sf::Vector2f(t_offset.x + 200, m_position.y + 850));
			t_window.draw(m_objectShape);


			text.setFont(font);
			text.setString(setObjectTypeText(m_current->getLinked()->getType()));
			text.setPosition(t_offset + sf::Vector2f(200.0f, 950.0f));

			t_window.draw(text);
		}
	}
}

HelpBox::HelpBox(sf::Vector2f t_position) : m_position{ t_position }, m_current{ nullptr }
{
	sf::Color grey = sf::Color(211, 211, 211, 255);
	m_body.setFillColor(grey);
	m_body.setSize(sf::Vector2f(800, 200));
	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	text.setFillColor(sf::Color::Red);
}

std::string HelpBox::setObjectTypeText(ObjectType t_type)
{
	std::string string;
	switch (t_type)
	{
	case ObjectType::Type1:
		string = "Circut Board";
		break;
	case ObjectType::Type2:
		string = "Fridge";
		break;
	case ObjectType::Type3:
		string = "Cooker";
		break;
	case ObjectType::Type4:
		string = "Sink";
		break;
	case ObjectType::Type5:
		string = "Washing Machine";
		break;
	case ObjectType::Type6:
		string = "A.C Unit";
		break;
	case ObjectType::Type7:
		string = "Freezer";
		break;
	case ObjectType::Type8:
		string = "Micro Wave";
		break;
	}

	return string;
}
