#pragma once
#include "SFML\Graphics.hpp"
#include "GameState.h"
#include "AttemptsCount.h"

class GameOver
{
public:
	GameOver();
	~GameOver();
	void Update(GameStates &state, AttemptsCount &count); 
	void Draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text text;
	sf::String string;
	sf::Text text2; 
	sf::String string2;

	sf::Texture texture; 
	sf::Sprite sprite;
};

