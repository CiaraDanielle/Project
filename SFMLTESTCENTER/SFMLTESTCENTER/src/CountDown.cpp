#include "Include\CountDown.h"

CountDown::CountDown()
{
	font.loadFromFile("DESIB___.TTF");
	text = std::to_string(counter) + ": Seconds";

	theText.setCharacterSize(50);
	theText.setFillColor(sf::Color::Green);
	theText.setFont(font);
	theText.setString(text);
}

CountDown::~CountDown()
{
}

void CountDown::Update(Player &player, GameStates &state)
{
	if (state == GameStates::Play)
	{
		elapsed = timer.getElapsedTime();  // start the timer
		remaining = elapsed.asSeconds();
		if (remaining >= 1)
		{
			counter = counter - remaining;  // counter is time remaining, remaining is at max 1
			if (counter > 120)
			{
				text = std::to_string(counter / 60) + ": Minutes";
			}
			else if (counter >= 60 && counter <= 119)
			{
				text = std::to_string(counter / 60) + ": Minute";
			}
			else if (counter < 60)
			{
				text = std::to_string(counter) + ": Seconds";
				theText.setFillColor(sf::Color::Red);
			}
			timer.restart();
		}
		if (counter == 0)
		{
			state = GameStates::GameLose;
		}
		textX = player.X() + 330;
		theText.setPosition(textX, 40);
		theText.setString(text);
	}
}
void CountDown::Draw(sf::RenderWindow &window, GameStates &gameState)
{
	if (gameState == GameStates::Play)
	{
		window.draw(theText);
	}
}

void CountDown::Reset()
{
	counter = 310;
}

int CountDown::GetTimer()
{
	return counter;
}