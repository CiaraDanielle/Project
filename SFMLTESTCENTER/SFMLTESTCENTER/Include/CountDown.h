#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
#include "GameState.h"


class CountDown
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Construct the timer  
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	CountDown();

	////////////////////////////////////////////////////////////
	/// \brief Destructor the controller  
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	~CountDown();

	////////////////////////////////////////////////////////////
	/// \brief Update the timer 
	///
	/// \param Player and the Gamestate
	///
	////////////////////////////////////////////////////////////
	void Update(Player &player, GameStates &state);

	////////////////////////////////////////////////////////////
	/// \brief Draw the timer  
	///
	/// \param The window and gamestate
	///
	////////////////////////////////////////////////////////////
	void Draw(sf::RenderWindow &window, GameStates &gameState);

	////////////////////////////////////////////////////////////
	/// \brief Reset the timer
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	void Reset();

	/// the counter used for time 
	int counter = 395;

	/// The time remaining
	int remaining = 0;

	////////////////////////////////////////////////////////////
	/// \brief Get the time left
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	int GetTimer();

private:

	/// an int that holds the position of the text
	int textX = 200;

	// A clock used as a timer 
	sf::Clock timer;

	/// Getting the elapsed time from a timer
	sf::Time elapsed;

	///String to draw the timer
	sf::String text;

	///A font used to draw the timer 
	sf::Font font;

	///Text used to draw the timer
	sf::Text theText;
};

