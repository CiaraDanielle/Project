#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "GameState.h"

class AttemptsCount
{
public:
	AttemptsCount();
	void collision();
	void update(Player &player);
	void draw(sf::RenderWindow &window, GameStates &gameState);
	~AttemptsCount();
	int attempts = 1;
private:
	sf::Font font;
	sf::Text attemptText;
	sf::String attemptString;
	int attemptMove = 0;
};

