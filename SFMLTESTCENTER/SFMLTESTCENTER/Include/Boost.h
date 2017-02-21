#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "GameState.h"


class Boost
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Construct the Boost meter
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	Boost();


	////////////////////////////////////////////////////////////
	/// \brief Update the boost meter
	///
	/// \param a player object to change the speed, a int used to move the player by a certain value and a gamestate 
	///
	////////////////////////////////////////////////////////////
	void Update(Player &player, int &moveAmount, GameStates &state);


	////////////////////////////////////////////////////////////
	/// \brief Draw the boost meter
	///
	/// \param The render window and a game state
	///
	////////////////////////////////////////////////////////////
	void Draw(sf::RenderWindow &window, GameStates &gameState);


	////////////////////////////////////////////////////////////
	/// \brief Checking to see the player can boost  
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	void CanBoost(); 

	// a bool to see if the player can boost
	bool canBoost = false;

	// an int to see the time remaining for boost 
	int remaining = 0;

	// a clock to decrement 
	sf::Clock timer;

	// a timer 
	sf::Time elapsed;


	////////////////////////////////////////////////////////////
	/// \brief Destruct the boost meter
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	~Boost();

private:
	// a rectangle to draw the outter boost bar
	sf::RectangleShape boostBar;

	// a rectangle to draw the inner boost bar 
	sf::RectangleShape innerBoost;

	// a constant amount for the maximum boost 
	const int maxBoost = 16;

	// a constant amount for the minimum boost 
	const int minBoost = 0;

	//The actual value 
	int boost = 0;

	//a bool to see can the player move 
	bool go = false;

	// a int to increase
	int increase = 16;
};

