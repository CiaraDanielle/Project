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
	/// \param Gamestates to know which screen you're on  
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

	void APressed(GameStates& state, Player &player, Menu& start, sf::RenderWindow& window, Sound &sound, LevelStates &level);

	void BPressed(GameStates& state, Menu& start, sf::RenderWindow& window, Sound &sound);

	void Update(GameStates& state, Menu& start, sf::RenderWindow &window, Player &player, Boost &boost, LevelStates &level, Sound &sound);

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

	bool a = sf::Joystick::isButtonPressed(0, 0);

	bool aPressed = false;

	bool b = sf::Joystick::isButtonPressed(0, 1); 
	bool bPressed = false; 

	bool start = sf::Joystick::isButtonPressed(0, 7); 
	bool startPressed = false; 

	/// Constant value to use for the DPad axis detection 
	const int m_val = 80;
};