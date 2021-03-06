#include "Room.h"

Room::Room(sf::Vector2f t_pos, int controls, int& t_score, std::string & t_texturePath) :
	m_player(sf::Vector2f(300, 300)),
	score(t_score),
	m_helpBox{ t_pos },
	repairPressed(false),
	isRepairing(false),
	m_currentBroken(nullptr),
	m_otherRoom(nullptr),
	controlType(controls),
	m_texturePath(t_texturePath)
{
	m_position = t_pos;
	m_body.setPosition(t_pos);
	if (!m_texture.loadFromFile(m_texturePath))
	{
		std::cout << "error" << std::endl;
	}
	m_body.setTexture(m_texture);
	//m_body.setSize(sf::Vector2f(800, 700));
	//m_body.setFillColor(sf::Color::Black);
	m_objects.push_back(Object(sf::Vector2f(300, 100), sf::Color::Magenta, ObjectType::Type1,std::string("ASSETS\\IMAGES\\Circut_Breaker.png")));
	m_objects.push_back(Object(sf::Vector2f(700, 200), sf::Color::Magenta, ObjectType::Type2, std::string("ASSETS\\IMAGES\\Frodge.png")));
	m_objects.push_back(Object(sf::Vector2f(700, 400), sf::Color::Magenta, ObjectType::Type3, std::string("ASSETS\\IMAGES\\Hob.png")));
	m_objects.push_back(Object(sf::Vector2f(600, 600), sf::Color::Magenta, ObjectType::Type4, std::string("ASSETS\\IMAGES\\Sonk.png")));
	m_objects.push_back(Object(sf::Vector2f(0, 0), sf::Color::Magenta, ObjectType::Type5, std::string("ASSETS\\IMAGES\\Wish_Washer.png")));
	m_objects.push_back(Object(sf::Vector2f(0, 300), sf::Color::Magenta, ObjectType::Type6, std::string("ASSETS\\IMAGES\\A.C.Png")));
	m_objects.push_back(Object(sf::Vector2f(0, 600), sf::Color::Magenta, ObjectType::Type7, std::string("ASSETS\\IMAGES\\Cold_Boi.png")));
	m_objects.push_back(Object(sf::Vector2f(200, 600), sf::Color::Magenta, ObjectType::Type8, std::string("ASSETS\\IMAGES\\Mickro_Wav.png")));

	if (!font.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setCharacterSize(36);
}

void Room::init()
{
}

void Room::handleCollisions()
{
	if (m_player.getPosition().x + m_position.x < m_position.x)
	{
		m_player.setPosition(sf::Vector2f(2, m_player.getPosition().y));
	}
	if (m_player.getPosition().x + m_position.x + m_player.getBody().getGlobalBounds().width >= m_position.x + 800)
	{
		m_player.setPosition(sf::Vector2f(800 - m_player.getBody().getGlobalBounds().width - 2, m_player.getPosition().y));
	}
	if (m_player.getPosition().y + m_position.y < m_position.y)
	{
		m_player.setPosition(sf::Vector2f(m_player.getPosition().x, 2));
	}
	if (m_player.getPosition().y + m_position.y + m_player.getBody().getGlobalBounds().height >= m_position.y + 700)
	{
		m_player.setPosition(sf::Vector2f(m_player.getPosition().x, 700 - m_player.getBody().getGlobalBounds().height - 2));
	}
}

void Room::newBrokenObject()
{
	if (m_currentBroken->getLinked() != nullptr)
	{
		m_currentBroken->setLinked(nullptr);
	}
	m_currentBroken = getRandomObject();
	m_currentBroken->setLinked(m_otherRoom->getRandomObject());
	m_currentBroken->setRepairProgress(100);
}

void Room::render(sf::RenderWindow& t_window)
{
	m_body.setTexture(m_texture);
	t_window.draw(m_body);
	m_player.render(t_window, m_position);
	for (auto& object : m_objects)
	{
		object.render(t_window, m_position);
	}
	m_helpBox.render(t_window, m_position);
	if (m_currentBroken != nullptr)
	{
		text.setFont(font);
		text.setString(std::to_string(m_currentBroken->getRepairProgress()));
		text.setPosition(m_currentBroken->getPosition() - sf::Vector2f(0, 50) + m_position);
		t_window.draw(text);
	}
}

void Room::update(sf::Time t_dt)
{
	if (m_currentBroken == nullptr)
	{
		m_currentBroken = getRandomObject();
		newBrokenObject();
	}
	m_player.update();

	m_helpBox.setCurrent(findClosestToPlayer());
	if (m_player.getInteracting() != nullptr)
	{
		m_player.getInteracting()->setBeingInteracted(false);
		m_player.setInteracting(nullptr);
	}
	if (repairPressed)
	{
		if (findClosestToPlayer()->distanceBetween(m_player.getPosition()) < 150)
		{
			m_player.setInteracting(findClosestToPlayer());
			m_player.getInteracting()->setBeingInteracted(true);
			if (m_player.getInteracting() == m_currentBroken)
			{
				m_currentBroken->repair(t_dt);
			}
		}
	}

	if (m_currentBroken->getRepairProgress() <= 0)
	{
		m_otherRoom;
		if (m_currentBroken->getLinked()->getBeingInteracted())
		{
			score += 100;
		}
		else
		{
			score -= 100;
		}
		newBrokenObject();
	}

	if (score < 0)
	{
		score == 0;
	}
	handleCollisions();
}

void Room::processEvents(sf::Event t_event)
{
	if (t_event.type == sf::Event::KeyPressed)
	{
		if (t_event.key.code == sf::Keyboard::E && controlType == 0)
		{
			repairPressed = true;
		}
		if (t_event.key.code == sf::Keyboard::RControl && controlType == 1)
		{
			repairPressed = true;
		}
	}

	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::E && controlType == 0)
		{
			repairPressed = false;
		}
		if (t_event.key.code == sf::Keyboard::RControl && controlType == 1)
		{
			repairPressed = false;
		}
	}
	if (!repairPressed)
	{
		m_player.processKeyEvents(t_event, controlType);
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
