#pragma once
#include "SFML\Graphics.hpp"
#include "GameState.h"
#include "AttemptsCount.h"
#include "CountDown.h"

class GameOver
{
public:


	////////////////////////////////////////////////////////////
	/// \brief Construct the gameOver screen 
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	GameOver();

	////////////////////////////////////////////////////////////
	/// \brief Destruct the game over screen  
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	~GameOver();

	////////////////////////////////////////////////////////////
	/// \brief Update the game over screen 
	///
	/// \param Gamestates to know which state it is "win - lose" and 
	/// the count to know how many attempts it took 
	////////////////////////////////////////////////////////////
	void Update(GameStates &state, AttemptsCount &count); 

	////////////////////////////////////////////////////////////
	/// \brief Draw the gameover screen 
	///
	/// \param Gamestate to know if it's win or lose 
	///
	////////////////////////////////////////////////////////////
	void Draw(sf::RenderWindow &window);

	////////////////////////////////////////////////////////////
	/// \brief Scroll the background   
	///
	/// \param gamestates to know which state and window to draw 
	///
	////////////////////////////////////////////////////////////
	void scrollBackground(GameStates &state, sf::RenderWindow &window);

	////////////////////////////////////////////////////////////
	/// \brief Get the over time it took   
	///
	/// \param int used for the time taken 
	///
	////////////////////////////////////////////////////////////
	void OverAllTime(int timer);

private:
	/// Font used to write some text to the screen 
	sf::Font font;

	/// Text used to write some text to the screen 
	sf::Text text;

	/// String used to write some text to the screen 
	sf::String string;

	/// Text used to write some text to the screen 
	sf::Text text2; 

	/// String used to write some text to the screen 
	sf::String string2;

	/// The string used for the timer
	sf::String timerString;

	/// The text used for the timer 
	sf::Text timerText;

	/// Texture for the background 1 to scroll 
	sf::Texture texture; 

	/// The sprite used to scroll 
	sf::Sprite sprite;

	/// Texture for the background 2 to scroll 
	sf::Texture texture2; 

	/// The sprite used to scroll
	sf::Sprite sprite2;

	// An int to change the colour 
	int colorNum = 0;

	/// The speed it scrolls at 
	float speed = 5.0f;

	/// New position to scroll to 
	float moveX = 0; 

	/// New position to scroll too 
	float moveTwo = 0;
	
	/// To hold the over all time it took 
	int time; 
};

