#include "Include\Boost.h"

Boost::Boost()
{
	boostBar.setSize(sf::Vector2f(160, 40));
	boostBar.setFillColor(sf::Color::Transparent);
	boostBar.setOutlineColor(sf::Color::Green);
	boostBar.setOutlineThickness(4);

	innerBoost.setSize(sf::Vector2f(10, 40));
	innerBoost.setFillColor(sf::Color::Red);
}


Boost::~Boost()
{
}

void Boost::Update(Player &player, int &moveAmount, GameStates &state)
{
	//if (state == GameStates::Play)
	//{
		elapsed = timer.getElapsedTime();  // start the timer
		remaining = elapsed.asSeconds();
		boostBar.setPosition(player.X() - 40, 60);
		innerBoost.setPosition(player.X() - 40, 40);
		if (canBoost == true)
		{
			go = true;
		}

		boostBar.setPosition(player.X() - 600, 60);
		innerBoost.setPosition(player.X() - 600, 60);
		innerBoost.setScale(increase, 1);

		if (remaining >= 1)
		{
			if (boost < maxBoost && canBoost == false)
			{
				if (increase < 16)
				{
					increase = increase + 1;
				}
				boost = boost + remaining;
			}
			if (boost > maxBoost)
			{
				boost = maxBoost;
			}
			if (boost > minBoost && canBoost == true && go == true)
			{
				if (increase > 0)
				{
					increase -= 2;
				}
				boost -= 2;

				moveAmount = 9;
				player.updateSpeed = 9.0f;
			}
			if (boost <= minBoost)
			{
				increase = 0;
				go = false;
				canBoost = false;
				moveAmount = 5;
				player.updateSpeed = 4.9f;
			}
			if (boost < 0)
			{
				boost = 0;
				canBoost = false;
			}
			if (increase < 0)
			{
				increase = 0;
				canBoost = false;
			}
			timer.restart();
		}
	//}
}

void Boost::Draw(sf::RenderWindow &window, GameStates &state)
{
	if (state == GameStates::Play)
	{
		window.draw(boostBar);
		window.draw(innerBoost);
	}
}

void Boost::CanBoost()
{
	canBoost = true;
}