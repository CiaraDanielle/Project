#pragma once

#define MAX_NUMBER_OF_ITEMS 8 
#include <SFML\Graphics.hpp>
#include "Include\GameState.h"
#include "Include\Player.h"


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
	void updateGameOptions(int lvl, int numberOfWaves);
	void updateSoundOptions(bool &mute, int &volume);
	void ScrollBackGround(GameStates state, sf::RenderWindow &window);
	void CustomizePlayer(GameStates state, sf::RenderWindow& window, sf::Event event, Player &player);

	//will be used for the controller later to change the menu's
	int getPressedItem() { return m_selectedButtonIndex; };


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
	bool leftPressed = false; 
	bool left = false;
	bool rightPressed = false; 
	bool right = false;
	bool up = false;
	bool upPressed = false; 
	bool down = false;
	bool downPressed = false;
};

