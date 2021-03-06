/// <summary>
/// @author Peter Lowe
/// @date May 2019
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 1920, 1080, 32U }, "SFML Game" },
	m_exitGame{false}, //when true game will exit
	m_startTime{ sf::seconds(90) },
	m_finished(false)
{
	rooms.push_back(Room(sf::Vector2f(100, 50), 0, m_scoreValue, std::string("ASSETS\\IMAGES\\Left_Room.png")));
	rooms.push_back(Room(sf::Vector2f(1000, 50), 1, m_scoreValue, std::string("ASSETS\\IMAGES\\Right_Room.png")));
	rooms.at(0).setOtherRoom(&rooms.at(1));
	rooms.at(1).setOtherRoom(&rooms.at(0));
	rooms.at(0).init();
	rooms.at(1).init();

	srand(time(NULL));

	if (!m_texture.loadFromFile("ASSETS\\IMAGES\\hus.png"))
	{
		std::cout << "error loading texture" << std::endl;
	}
	m_background.setTexture(m_texture);

	if (!m_music.openFromFile("ASSETS\\AUDIO\\Welcome To The Black Parade.wav"))
	{
		std::cout << "problem loading sound" << std::endl;
	}
	m_music.play();
	setupFontAndText(); // load font 
	setupSprite(); // load texture
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);

		}

		for (Room& r : rooms)
		{
			r.processEvents(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (!m_finished)
	{
		countDownTimer();
		if (m_exitGame)
		{
			m_window.close();
		}

		for (Room& r : rooms)
		{
			r.update(t_deltaTime);
		}
		m_scoreText.setString("Score: " + std::to_string(m_scoreValue));
		if (m_timer <= 0)
		{
			m_finished = true;
		}
	}


}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	m_window.draw(m_background);
	for (int i = 0; i < rooms.size(); i++)
	{
		rooms[i].render(m_window);
	}
	m_window.draw(m_scoreText);
	m_window.draw(m_timerText);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_scoreText.setFont(m_ArialBlackfont);
	m_scoreText.setString("Score: " + std::to_string(m_scoreValue));
	m_scoreText.setStyle(sf::Text::Italic);
	m_scoreText.setCharacterSize(30U);
	m_scoreText.setFillColor(sf::Color::White);
	m_scoreText.setPosition(sf::Vector2f{ 100, 10 });

	m_timerText.setFont(m_ArialBlackfont);
	m_timerText.setString("Time Left: " + std::to_string(m_timer));
	m_timerText.setStyle(sf::Text::Italic);
	m_timerText.setCharacterSize(30U);
	m_timerText.setFillColor(sf::Color::White);
	m_timerText.setPosition(sf::Vector2f{ 1600, 10 });


}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{

}

void Game::countDownTimer()
{
	if (m_startTime.asSeconds() > 0)
	{
		m_startTime -= m_scoreClock.restart();
		m_timer = m_startTime.asSeconds();
		m_timerText.setString("Time Left: " + std::to_string(m_timer));
	}
	
}

