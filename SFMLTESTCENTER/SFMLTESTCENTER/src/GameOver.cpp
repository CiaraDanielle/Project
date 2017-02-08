#include "GameOver.h"



GameOver::GameOver()
{
	if (!font.loadFromFile("DESIB___.TTF"))
	{

	}
	texture.loadFromFile("gameover.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(400, 0));
}


GameOver::~GameOver()
{
}

void GameOver::Update(GameStates &state, AttemptsCount &count)
{
	string = std::to_string(count.attempts) + ": Attempts";
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::White);
	text.setFont(font);
	text.setString(string);
	text.setPosition(1400, 300);

	if (state == GameStates::GameWin)
	{
		string2 = "You won! \n It took you ";
		text2.setCharacterSize(50);
		text2.setFillColor(sf::Color::White);
		text2.setFont(font);
		text2.setString(string2);
		text2.setPosition(1000, 300);
	}

	if (state == GameStates::GameLose)
	{
		string2 = "You Lost! \n It took you ";
		text2.setCharacterSize(50);
		text2.setFillColor(sf::Color::White);
		text2.setFont(font);
		text2.setString(string2);
		text2.setPosition(1000, 300);
	}
}

void GameOver::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	window.draw(text);
	window.draw(text2);
}