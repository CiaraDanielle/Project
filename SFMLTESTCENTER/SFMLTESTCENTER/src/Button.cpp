#include "Include\Button.h"


Button::Button(GameStates state) //constructor
{
	m_buttonTexture.loadFromFile("button.png");

	for (int i = 0; i < 4; i++)
	{
		buttons[i].setTexture(m_buttonTexture);
	}
	for (int i = 0; i < 4; i++)
	{
		buttons[i].setPosition(-500, 0);
	}

	m_selectedButtonIndex = 0;
	setButtonSize(state);
}

Button::~Button()
{
}

void Button::setButtonPositions(float width, float height, GameStates state) //sets the position of the button depending on the game state
{
	if (state == GameStates::MainMenu) //main menu
	{
		buttons[0].setPosition(sf::Vector2f(width / 2 - 45, height / 4 * 1 - 20));

		buttons[1].setPosition(sf::Vector2f(width / 2 - 90, height / 4 * 2 - 120));

		buttons[2].setPosition(sf::Vector2f(width / 2 - 55, height / 4 * 3 - 200));

		buttons[3].setPosition(sf::Vector2f(width / 2 - 40, height / 4 * 4 - 290));
	}
	else if (state == GameStates::Customise) //sound options
	{
		buttons[0].setPosition(sf::Vector2f(-500, 0));

		buttons[1].setPosition(sf::Vector2f(-500,0));


		buttons[2].setPosition(sf::Vector2f(-500, 0));

		buttons[3].setPosition(sf::Vector2f(-500, 0));
	}
	else if (state == GameStates::GameOptions) //difficulty options
	{
		buttons[0].setPosition(sf::Vector2f(width / 2 - 270, height / 4 * 1 + 30));

		buttons[1].setPosition(sf::Vector2f(width / 2 - 320, height / 4 * 2 + 50));

		buttons[2].setPosition(sf::Vector2f(-500, 0));

		buttons[3].setPosition(sf::Vector2f(-500, 0));

	}
	else if (state == GameStates::Pause) //pause menu
	{
		buttons[0].setPosition(sf::Vector2f(width / 2 - 100, height / 4 * 1 + 80));

		buttons[1].setPosition(sf::Vector2f((width / 2 - 90), height / 4 * 2 + 30));

		buttons[2].setPosition(sf::Vector2f(-500, 0));

		buttons[3].setPosition(sf::Vector2f(-500, 0));
	}
}

void Button::setButtonSize(GameStates state) //sets the size of the buttons on screen depending on the state of the game
{
	m_selectedButtonIndex = 0;
	if (state == GameStates::MainMenu) //main menu
	{
		buttons[0].setScale(0.45, 1.1);

		buttons[1].setScale(0.68, 1);

		buttons[2].setScale(0.5, 1);

		buttons[3].setScale(0.4, 1);
	}
	else if (state == GameStates::Customise) //sound options
	{
		buttons[0].setScale(0.6, 1.1);

		buttons[1].setScale(0.4, 1);

	}
	else if (state == GameStates::GameOptions) //difficulty options
	{
		buttons[0].setScale(0.5, 1.1);

		buttons[1].setScale(0.78, 1);
	}

	else if (state == GameStates::Pause) //pause menu
	{
		buttons[0].setScale(0.5, 1);

		buttons[1].setScale(0.4, 1);
	}
}

void Button::draw(sf::RenderWindow &window, GameStates state) //draws buttons on screen
{
	if (state != GameStates::Play)
	{
		for (int i = 0; i < 4; i++)
		{
			window.draw(buttons[i]);
		}
	}
}

void Button::ButtonScaleUp(GameStates state) //will scale up depending on what button it is on
{
	if (m_selectedButtonIndex - 1 >= 0)
	{
		setButtonScaleDown(state);
		m_selectedButtonIndex--;
		setButtonScaleUp(state);
	}
}

void Button::ButtonScaleDown(GameStates state)  //will scale down when the player has moved off the button
{
	if (m_selectedButtonIndex + 1 < 4)
	{
		setButtonScaleDown(state);
		m_selectedButtonIndex++;
		setButtonScaleUp(state);
	}
}

void Button::setButtonScaleUp(GameStates state) //sets the scale sizes for each individula button
{

	if (state == GameStates::MainMenu)
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.45, 1.1);
		}
		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.8, 1.1);
		}
		if (m_selectedButtonIndex == 2)
		{
			buttons[2].setScale(0.55, 1.1);
		}
		if (m_selectedButtonIndex == 3)
		{
			buttons[3].setScale(0.45, 1.1);
		}
	}

	else if (state == GameStates::Customise) //sound options
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.7, 1.1);
		}
		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.5, 1.1);
		}

	}

	else if (state == GameStates::GameOptions) //difficulty options
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.5, 1.1);
		}

		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.9, 1.1);
		}
	}

	else if (state == GameStates::Pause) //pause menu
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.5, 1.1);
		}
		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.5, 1.1);
		}
	}
}

void Button::setButtonScaleDown(GameStates state) //sets the buttons back to their original size
{
	if (state == GameStates::MainMenu)
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.4, 1);
		}
		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.67, 1);
		}
		if (m_selectedButtonIndex == 2)
		{
			buttons[2].setScale(0.5, 1);
		}
		if (m_selectedButtonIndex == 3)
		{
			buttons[3].setScale(0.4, 1);
		}
	}

	else if (state == GameStates::Customise) //sound options
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.5, 1);
		}
		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.4, 1);
		}

	}

	else if (state == GameStates::GameOptions) //difficulty options
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.45, 1);
		}

		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.78, 1);
		}
	}

	else if (state == GameStates::Pause) //pause menu
	{
		if (m_selectedButtonIndex == 0)
		{
			buttons[0].setScale(0.45, 1);
		}
		if (m_selectedButtonIndex == 1)
		{
			buttons[1].setScale(0.4, 1);
		}
	}
}