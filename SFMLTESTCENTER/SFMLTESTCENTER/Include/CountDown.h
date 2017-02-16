#pragma once
#include <SFML/Graphics.hpp>
#include"Player.h"
#include "GameState.h"


class CountDown
{
public:
	CountDown();
	~CountDown();
	void Update(Player &player, GameStates &state);
	void Draw(sf::RenderWindow &window, GameStates &gameState);
	void Reset();
	int counter = 310;
	int remaining = 0;
	int GetTimer();

private:
	int textX = 200;

	sf::Clock timer;
	sf::Time elapsed;

	sf::String text;
	sf::Font font;
	sf::Text theText;
};

