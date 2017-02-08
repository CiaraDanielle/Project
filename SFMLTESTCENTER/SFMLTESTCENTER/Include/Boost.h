#pragma once
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "GameState.h"


class Boost
{
public:
	Boost();
	void Update(Player &player, int &moveAmount);
	void Draw(sf::RenderWindow &window, GameStates &gameState);
	void CanBoost(); 
	bool canBoost = false;
	int remaining = 0;
	sf::Clock timer;
	sf::Time elapsed;
	~Boost();

private:
	sf::RectangleShape boostBar;
	sf::RectangleShape innerBoost;
	const int maxBoost = 16;
	const int minBoost = 0;
	int boost = 0;
	bool go = false;
	int increase = 1;
};

