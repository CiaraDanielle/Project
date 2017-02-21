#pragma once

#define MAX_NUMBER_OF_ITEMS 8 
#include <SFML\Graphics.hpp>
#include "Include\GameState.h"
#include "Include\Player.h"
#include "Sound.h"


class Menu
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Construct the menu 
	///
	/// \param the desired width and height and game state
	///
	////////////////////////////////////////////////////////////
	Menu(float width, float height, GameStates state);

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	/// \param None
	///
	////////////////////////////////////////////////////////////
	~Menu();


	////////////////////////////////////////////////////////////
	/// \brief Draw Method 
	///
	/// \param the render window, the game state and the player 
	///
	////////////////////////////////////////////////////////////
	void draw(sf::RenderWindow & window, GameStates state, Player &player);

	////////////////////////////////////////////////////////////
	/// \brief Move up through the menu 
	///
	/// \param game states
	///
	////////////////////////////////////////////////////////////
	void MoveUp(GameStates state);

	////////////////////////////////////////////////////////////
	/// \brief Move down through the menu 
	///
	/// \param game states
	///
	////////////////////////////////////////////////////////////
	void MoveDown(GameStates state);

	////////////////////////////////////////////////////////////
	/// \brief Check and see if the game state has changed
	///
	/// \param game states and the desired width and height of the menu
	///
	////////////////////////////////////////////////////////////
	void CheckMenuState(float width, float height, GameStates state);

	////////////////////////////////////////////////////////////
	/// \brief Scroll the background 
	///
	/// \param game states and the render window
	///
	////////////////////////////////////////////////////////////
	void ScrollBackGround(GameStates state, sf::RenderWindow &window);

	////////////////////////////////////////////////////////////
	/// \brief Customise the player 
	///
	/// \param game states, render window, the event for key pressed and the player 
	///
	////////////////////////////////////////////////////////////
	void CustomizePlayer(GameStates state, sf::RenderWindow& window, sf::Event event, Player &player);

	////////////////////////////////////////////////////////////
	/// \brief Move left through the menu 
	///
	/// \param game states and sound 
	///
	////////////////////////////////////////////////////////////
	void MoveLeft(GameStates &state, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Move right through the menu 
	///
	/// \param game states and sound 
	///
	////////////////////////////////////////////////////////////
	void MoveRight(GameStates &state, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Get the index of the pressed button
	///
	/// \param game states
	///
	////////////////////////////////////////////////////////////
	int getPressedItem() { return m_selectedButtonIndex; };

	/// The speed to scroll at 
	float speed = -5.0f;

private:

	//To get the number of buttons
	int m_numberOfButtons;

	//To get the button selected index
	int m_selectedButtonIndex = 0;

	//Font for the button 
	sf::Font buttonFont;

	//Creating an array for the maximum about of items needed
	sf::Text buttonText[MAX_NUMBER_OF_ITEMS];

	/// An array of rectangles used to show the user the different colors available
	sf::RectangleShape colours[5];

	/// An array of rectangles used to show the user the different sprites available
	sf::Sprite sprite[5];

	/// Texture for the first scrolling background
	sf::Texture MainTexture;

	/// The sprite for the first scrolling background 
	sf::Sprite mainBackground;

	/// the sprite for the second scrolling background 
	sf::Sprite rollingBack;

	/// Texture for the second scrolling background
	sf::Texture rollingTexture;

	/// The new position to move to for the background 1
	float moveX = 0;

	/// The new position to move to for the background 1
	float moveTwo = 0;

	/// A colour number count as after a certain amount change the color
	int colorNum = 0;

	///Check to seehow many times the left arrow was pressed 
	int leftpressed = -1;

	///Check to seehow many times the right arrow was pressed 
	int rightpressed = -1;

	///Check to see if the left arrow key has been pressed 
	bool leftPressed = false; 

	/// If left is not pressed
	bool left = false;

	///Check to see if the right arrow key has been pressed 
	bool rightPressed = false; 

	/// If right is not pressed
	bool right = false;

	///Check to see if the up arrow key has been pressed 
	bool up = false;

	/// If up is not pressed 
	bool upPressed = false; 

	///Check to see if the Down arrow key has been pressed 
	bool down = false;

	/// if down is not pressed
	bool downPressed = false;


	/// Getting the axis for left on the DPad 
	bool dPadLeft = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -m_val;

	/// Boolean to know when left has been pressed 
	bool dPadleftPress = false;

	/// Getting the axis for Up on the DPad 
	bool dPadUp = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY)  < -m_val;

	/// Boolean to know when Up has been pressed 
	bool dPadUpPress = false;

	/// Getting the axis for right on the DPad 
	bool dPadRight = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < m_val;

	/// Boolean to know when right has been pressed 
	bool dPadRightPress = false;

	/// Getting the axis for Down on the DPad 
	bool dPadDown = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < m_val;

	/// Boolean to know when down has been pressed 
	bool dPadDownPress = false;

	//Value to check when a button is pressed on the controller
	const int m_val = 80;
};

