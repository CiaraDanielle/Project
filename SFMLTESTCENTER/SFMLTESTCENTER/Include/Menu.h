#pragma once

#define MAX_NUMBER_OF_ITEMS 8 
#include <SFML\Graphics.hpp>
#include "Include\GameState.h"
#include "Include\Player.h"
#include "Sound.h"


class Menu
{
public:
	Menu(float width, float height, GameStates state);
	~Menu();

	sf::RenderWindow window;

	//methods
	void draw(sf::RenderWindow & window, GameStates state, Player &player);
	void MoveUp(GameStates state);
	void MoveDown(GameStates state);
	void CheckMenuState(float width, float height, GameStates state);
	void ScrollBackGround(GameStates state, sf::RenderWindow &window);
	void CustomizePlayer(GameStates state, sf::RenderWindow& window, sf::Event event, Player &player);
	void MoveLeft(GameStates &state, Sound &sound);
	void MoveRight(GameStates &state, Sound &sound);
	//will be used for the controller later to change the menu's
	int getPressedItem() { return m_selectedButtonIndex; };
	float speed = -5.0f;

private:

	int m_numberOfButtons;
	int m_selectedButtonIndex = 0;
	sf::Font buttonFont;
	sf::Text buttonText[MAX_NUMBER_OF_ITEMS];

	sf::Texture m_UITexture;
	sf::Sprite m_UIHUD;
	sf::RectangleShape colours[5];
	sf::Sprite sprite[5];
	sf::Texture MainTexture;
	sf::Sprite mainBackground;
	sf::Sprite rollingBack;
	sf::Texture rollingTexture;
	float moveX = 0;
	float moveTwo = 0;
	int colorNum = 0;
	int leftpressed = -1;
	int rightpressed = -1;

	bool leftPressed = false; 
	bool left = false;
	bool rightPressed = false; 
	bool right = false;
	bool up = false;
	bool upPressed = false; 
	bool down = false;
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

	const int m_val = 80;
};

