#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "GameState.h"

class AttemptsCount
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Construct the counter 
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	AttemptsCount();

	////////////////////////////////////////////////////////////
	/// \brief Checking for collisions to increment
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	void collision();

	////////////////////////////////////////////////////////////
	/// \brief Update the count every frame
	///
	/// \param Player to use as a reference on where to put it 
	///
	////////////////////////////////////////////////////////////
	void update(Player &player);

	////////////////////////////////////////////////////////////
	/// \brief Draw the string  
	///
	/// \param Render window used to draw and the game state to check which on the player is on 
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderWindow &window, GameStates &gameState);

	////////////////////////////////////////////////////////////
	/// \brief Destruct the controller  
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	~AttemptsCount();

	// Int to increment everytime there is a collison 
	int attempts = 1;
private:

	//A font to use for drawing the string 
	sf::Font font;

	//A text to use to draw 
	sf::Text attemptText;

	//A string use to draw 
	sf::String attemptString;

	//Move the text when updating so it moves off scren
	int attemptMove = 0;
};

