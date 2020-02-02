/// <summary>
/// author Pete Lowe May 2019
/// Pete don't steal our game
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include <array>
#include "Player.h"
#include "Room.h"

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();
	void countDownTimer();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_scoreText;
	sf::Text m_timerText;
	sf::Time m_startTime;
	sf::Clock m_scoreClock;

	int m_scoreValue;
	int m_timer;
	bool m_exitGame; // control exiting game


	std::vector<Room> rooms;
};

#endif // !GAME_HPP

