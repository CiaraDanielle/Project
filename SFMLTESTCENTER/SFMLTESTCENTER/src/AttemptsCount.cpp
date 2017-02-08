#include "Include\AttemptsCount.h"



AttemptsCount::AttemptsCount()
{
	if (!font.loadFromFile("DESIB___.TTF"))
	{

	}

	attemptString = std::to_string(attempts) + ": Attempts";
	attemptText.setCharacterSize(50);
	attemptText.setFillColor(sf::Color::White);
	attemptText.setFont(font);
	attemptText.setString(attemptString);
}


AttemptsCount::~AttemptsCount()
{
}

void AttemptsCount::update(Player &player)
{
	attemptString = "Attempt: " + std::to_string(attempts);

	if (attemptMove < 100) // moving the text
	{
		attemptMove++;
		attemptText.setPosition(player.X() - 40, 40);
		attemptText.setString(attemptString);
	}
	else if (attemptMove < 200)
	{
		attemptMove++;
		attemptText.setPosition(500, 40);
		attemptText.setString(attemptString);
	}
}
void AttemptsCount::draw(sf::RenderWindow &window, GameStates &gameState)
{
	window.draw(attemptText);
}
void AttemptsCount::collision()
{
	attemptString = "Attempt: " + std::to_string(attempts);
	attemptText.setString(attemptString);
	attemptText.setPosition(40, 40);
}
