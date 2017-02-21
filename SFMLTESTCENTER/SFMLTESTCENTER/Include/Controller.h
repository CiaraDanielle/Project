#pragma once

#include "Menu.h"
#include "Player.h"
#include "GameState.h"
#include "Boost.h"
#include "LevelState.h"
#include "Sound.h"

class Controller
{
public: 

	////////////////////////////////////////////////////////////
	/// \brief Construct the controller  
	///
	/// \param none
	///
	////////////////////////////////////////////////////////////
	Controller();

	////////////////////////////////////////////////////////////
	/// \brief Moving the DPad on the controller left 
	///
	/// \param Gamestate to know which screen, Sound so you can 
	/// move through it as well as Sound Manager and Menu 
	////////////////////////////////////////////////////////////
	void DPadMoveLeft(GameStates state, Menu& start, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Moving the DPad on the controller Right 
	///
	/// \param Gamestate to know which screen, Sound so you can 
	/// move through it as well as Sound Manager and Menu 
	////////////////////////////////////////////////////////////
	void DPadMoveRight(GameStates state, Menu& start, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Moving the DPad on the controller up
	///
	/// \param Gamestate to know which screen, Menu to be able 
	/// to scroll through it 
	////////////////////////////////////////////////////////////
	void DPadMoveUp(GameStates &state, Menu& start, Sound &sound);


	////////////////////////////////////////////////////////////
	/// \brief Moving the DPad on the controller down 
	///
	/// \param Gamestate to know which screen, Menu to be able 
	/// to scroll through it 
	////////////////////////////////////////////////////////////
	void DPadMoveDown(GameStates &state, Menu& start, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Pressing A on the controller 
	///
	/// \param game state to know which screen your on, a player object to jump. the menu to know when a button is pressed
	/// the render window to sent to the menu, sound so to play a sound when jumping or on the menu, the level to know which level to load
	////////////////////////////////////////////////////////////
	void APressed(GameStates& state, Player &player, Menu& start, sf::RenderWindow& window, Sound &sound, LevelStates &level);

	////////////////////////////////////////////////////////////
	/// \brief Pressing B on the controller 
	///
	/// \param Gamestate to know which screen, Sound so you can 
	/// move through it as well as Sound Manager and Menu also the render window
	////////////////////////////////////////////////////////////
	void BPressed(GameStates& state, Menu& start, sf::RenderWindow& window, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Update method: So instead of calling all the functions above
	/// individually you can just call the update method
	///
	/// \param Gamestate to know which screen, Sound so you can 
	/// move through it as well as Sound Manager and Menu 
	/// a player object, a boost object and the levelstate 
	////////////////////////////////////////////////////////////
	void Update(GameStates& state, Menu& start, sf::RenderWindow &window, Player &player, Boost &boost, LevelStates &level, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Pressing start on the controller 
	///
	/// \param Gamestate to know which screen, boost to know can you, and level states 
	////////////////////////////////////////////////////////////
	void StartPressed(GameStates& state, Boost &boost, LevelStates &level);
private:

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

	/// Getting the axis for A 
	bool a = sf::Joystick::isButtonPressed(0, 0);

	/// A boolean to see if A has been pressed 
	bool aPressed = false;

	/// Getting the axis for B
	bool b = sf::Joystick::isButtonPressed(0, 1); 

	/// Boolean to know when B has been pressed
	bool bPressed = false; 

	/// Getting the axis for the Start button
	bool start = sf::Joystick::isButtonPressed(0, 7); 

	/// Boolean to know when Start is pressed
	bool startPressed = false; 

	/// Constant value to use for the DPad axis detection 
	const int m_val = 80;
};