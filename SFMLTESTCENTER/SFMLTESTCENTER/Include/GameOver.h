#pragma once
#include "SFML\Graphics.hpp"
#include "GameState.h"
#include "AttemptsCount.h"
#include "CountDown.h"

class GameOver
{
public:
	GameOver();
	~GameOver();
	void Update(GameStates &state, AttemptsCount &count); 
	void Draw(sf::RenderWindow &window);
	void scrollBackground(GameStates &state, sf::RenderWindow &window);
	void OverAllTime(int timer);

private:
	sf::Font font;
	sf::Text text;
	sf::String string;
	sf::Text text2; 
	sf::String string2;
	sf::String timerString;
	sf::Text timerText;

	sf::Texture texture; 
	sf::Sprite sprite;

	sf::Texture texture2; 
	sf::Sprite sprite2;

	int colorNum = 0;
	float speed = 5.0f;
	float moveX = 0; 
	float moveTwo = 0;

	int time; 
};

