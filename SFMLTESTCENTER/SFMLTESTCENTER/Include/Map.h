#pragma once
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "LevelState.h"
#include "AttemptsCount.h"
#include "CountDown.h"
#include "Sound.h"
#include "GameOver.h"

class Map
{
private:
	////////////////////////////////////////////////////////////
	/// \brief Overloaded constructor
	///
	/// \param A map object of constant value
	///
	////////////////////////////////////////////////////////////
	Map(Map const & m);

	/// The first level 
	tmx::MapLoader m_ml;

	/// The second Level 
	tmx::MapLoader m_ml2;

	/// The third level 
	tmx::MapLoader m_ml3;

public:

	////////////////////////////////////////////////////////////
	/// \brief Default Constructor 
	///
	/// \param None 
	///
	////////////////////////////////////////////////////////////
	Map();

	////////////////////////////////////////////////////////////
	/// \brief Destructor 
	///
	/// \param None 
	///
	////////////////////////////////////////////////////////////
	~Map();

	////////////////////////////////////////////////////////////
	/// \brief Draw the map
	///
	/// \param the render window and the level state, to know which level to draw
	///
	////////////////////////////////////////////////////////////
	void Draw(sf::RenderWindow &window, LevelStates &level);

	////////////////////////////////////////////////////////////
	/// \brief Update everything using this method, so only one thing needs to be called 
	///
	/// \param A player object, a level state, the game state, the attempts taken, the timer, sound and the overtext
	///
	////////////////////////////////////////////////////////////
	void Update(Player &player, GameStates &level, LevelStates &state, AttemptsCount &count, CountDown &timer, Sound &sound, GameOver &overText);

	////////////////////////////////////////////////////////////
	/// \brief Check to see if the player has collided with something on map 1 
	///
	/// \param player, the game state, the level state, the timer, the attempts, sound and game over text
	///
	////////////////////////////////////////////////////////////
	void CollisionCheckLevel1(Player &player, GameStates &state, LevelStates &level, AttemptsCount &count, CountDown &timer, Sound &sound, GameOver &overText);

	////////////////////////////////////////////////////////////
	/// \brief Check to see if the player has collided with something on map 2
	///
	/// \param player, the game state, the level state, the timer, the attempts, sound and game over text
	///
	////////////////////////////////////////////////////////////
	void CollisionCheckLevel2(Player &player, GameStates &state, LevelStates &level, AttemptsCount &count, CountDown &timer, Sound &sound, GameOver &overText);

	////////////////////////////////////////////////////////////
	/// \brief Check to see if the player has collided with something on map 3
	///
	/// \param player, the game state, the level state, the timer, the attempts, sound and game over text
	///
	////////////////////////////////////////////////////////////
	void CollisionCheckLevel3(Player &player, GameStates &state, LevelStates &level, AttemptsCount &count, CountDown &timer, Sound &sound, GameOver &overText);

	////////////////////////////////////////////////////////////
	/// \brief Used to load in the new map if the level has changed
	///
	/// \param Level states
	///
	////////////////////////////////////////////////////////////
	void CheckState(LevelStates &level);
};

