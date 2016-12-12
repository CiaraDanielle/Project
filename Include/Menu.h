#pragma once

#define MAX_NUMBER_OF_ITEMS 8 
#include <SFML\Graphics.hpp>
#include "I:\Project\Include\GameState.h"


class Menu
{
public:
	Menu(float width, float height, GameStates state);
	~Menu();

	sf::RenderWindow window;

	//methods
	void draw(sf::RenderWindow &window, GameStates state);
	void MoveUp(GameStates state);
	void MoveDown(GameStates state);
	void CheckMenuState(float width, float height, GameStates state);
	void updateGameOptions(int lvl, int numberOfWaves);
	void updateSoundOptions(bool &mute, int &volume);
	void ScrollBackGround(GameStates state, sf::RenderWindow &window);

	//will be used for the controller later to change the menu's
	int getPressedItem() { return m_selectedButtonIndex; };


private:

	int m_numberOfButtons;
	int m_selectedButtonIndex;
	sf::Font buttonFont;
	sf::Text buttonText[MAX_NUMBER_OF_ITEMS];

	sf::Texture m_UITexture;
	sf::Sprite m_UIHUD;

	sf::Texture MainTexture;
	sf::Sprite mainBackground;
	sf::Sprite rollingBack;
	sf::Texture rollingTexture;

	float moveX = 0;
	float moveTwo = 0;
	int colorNum = 0;
};

