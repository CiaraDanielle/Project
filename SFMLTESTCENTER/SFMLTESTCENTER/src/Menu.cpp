#include "Include\Menu.h"
#include "Include\Button.h"
#include <iostream>

Button thisButton(GameStates::MainMenu);

Menu::Menu(float width, float height, GameStates state)
{
	sprite[1].setScale(sf::Vector2f(1.5, 1.5));

	if (!buttonFont.loadFromFile("DESIB___.TTF"))
	{
	
	}
	MainTexture.loadFromFile("scrollbackground.png");
	mainBackground.setTexture(MainTexture);
	mainBackground.setPosition(sf::Vector2f(0, 0));
	rollingTexture.loadFromFile("scrollbackground2.png");
	rollingBack.setTexture(rollingTexture);
	rollingBack.setPosition(16000, 0);

	if (state == GameStates::MainMenu) //main menu
	{

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Play");
		buttonText[0].setPosition(sf::Vector2f(width / 2, height / 4 * 1));
		buttonText[0].setCharacterSize(35);


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("  Customise");
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 65), height / 4 * 2 - 100));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString(" Sound");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 25), height / 4 * 3 - 180));

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("Exit");
		buttonText[3].setPosition(sf::Vector2f(width / 2, height / 4 * 4 - 270));


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString(""); //will need change due to sound controller
		buttonText[4].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 2 - 95));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));


		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);

	}
	else if (state == GameStates::Customise) //sound options
	{
		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("");
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 290, height / 4 * 1));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("");
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 2 - 95));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 3 - 180));

		//ad if statement later to change this
		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("");
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1));

		buttonText[4].setFont(buttonFont);
		buttonText[4].setString(""); //will need change due to sound controller
		buttonText[4].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 2 - 95));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));

		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);



	}


	thisButton.m_selectedButtonIndex = 0;
	m_selectedButtonIndex = 0;
	buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
}

Menu::~Menu()
{
}

void Menu::ScrollBackGround(GameStates state, sf::RenderWindow &window)
{
		moveX = mainBackground.getPosition().x - speed;
		mainBackground.setPosition(sf::Vector2f(moveX, 0));
		moveTwo = rollingBack.getPosition().x - speed;
		rollingBack.setPosition(sf::Vector2f(moveTwo, 0));
		if (mainBackground.getPosition().x <= -15000)
		{
			std::cout << mainBackground.getPosition().x << std::endl;
			mainBackground.setPosition(sf::Vector2f(15000, 0));
		}
		if (rollingBack.getPosition().x <= -15000)
		{
			rollingBack.setPosition(sf::Vector2f(15000, 0));
		}
		if (colorNum == 0)
		{
			mainBackground.setColor(sf::Color::Blue);
			rollingBack.setColor(sf::Color::Blue);
		}
		if (colorNum == 105)
		{
			mainBackground.setColor(sf::Color::Red);
			rollingBack.setColor(sf::Color::Red);
		}
		if (colorNum == 205)
		{
			mainBackground.setColor(sf::Color::Green);
			rollingBack.setColor(sf::Color::Green);
		}
		if (colorNum == 305)
		{
			mainBackground.setColor(sf::Color::Magenta);
			rollingBack.setColor(sf::Color::Magenta);
		}
		if (colorNum == 405)
		{
			mainBackground.setColor(sf::Color::Yellow);
			rollingBack.setColor(sf::Color::Yellow);
		}
		if (colorNum == 505)
		{
			colorNum = 0;
		}
		colorNum++;
}

void Menu::draw(sf::RenderWindow& window, GameStates state, Player &player) //draw method
{

	window.draw(mainBackground);
	window.draw(rollingBack);

	thisButton.draw(window, state);
	if (state != GameStates::Play)
	{
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
		{
			window.draw(buttonText[i]);
		}
		speed = 5.0f;
	}
	
	if (state == GameStates::Customise)
	{
		window.draw(mainBackground);
		window.draw(rollingBack);
		player.Draw(&window, state);

		for (int i = 0; i < 5; i++)
		{
			window.draw(colours[i]);
		}
		for (int i = 0; i < 5; i++)
		{
			window.draw(sprite[i]);
		}
	}

	if (state == GameStates::GameLose)
	{
		window.draw(rollingBack);
	}
}



void Menu::CheckMenuState(float width, float height, GameStates state) //checks the current state of the game changing to the corrosponding menu
{
	thisButton.setButtonSize(state);
	m_selectedButtonIndex = 0;

	if (state == GameStates::GameWin)
	{
		buttonText[0].setPosition(sf::Vector2f(-2000, -2000));
		buttonText[1].setPosition(sf::Vector2f(-2000, -2000));
		buttonText[2].setPosition(sf::Vector2f(-2000, -2000));
		buttonText[3].setPosition(sf::Vector2f(-2000, -2000));
		buttonText[4].setPosition(sf::Vector2f(-2000, -2000));
		buttonText[5].setPosition(sf::Vector2f(-2000, -2000));

		thisButton.setButtonPositions(-2000, -2000, state);
		thisButton.setButtonSize(state);
		}

	if (state == GameStates::MainMenu) //main menu
	{
		m_selectedButtonIndex = 0;
		thisButton.m_selectedButtonIndex = 0;

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Play");
		buttonText[0].setCharacterSize(35);
		buttonText[0].setFillColor(sf::Color::Yellow);
		buttonText[0].setPosition(sf::Vector2f(width / 2, height / 4 * 1));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("  Customise");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 65), height / 4 * 2 - 100));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString(" Sound");
		buttonText[2].setCharacterSize(30);
		buttonText[2].setFillColor(sf::Color::White);
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 25), height / 4 * 3 - 180));

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("Exit");
		buttonText[3].setCharacterSize(30);
		buttonText[3].setFillColor(sf::Color::White);
		buttonText[3].setPosition(sf::Vector2f(width / 2, height / 4 * 4 - 270));


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString(""); //will need change due to sound controller
		buttonText[4].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 2 - 95));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));


		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);

	}
	else if (state == GameStates::Customise) //sound options
	{
		m_selectedButtonIndex = 0;
		thisButton.m_selectedButtonIndex = 0;

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("");
		buttonText[0].setCharacterSize(35);
		buttonText[0].setFillColor(sf::Color::Yellow);
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 290, height / 4 * 1));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 2 - 95));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("");
		buttonText[2].setCharacterSize(30);
		buttonText[2].setFillColor(sf::Color::White);
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 3 - 180));

		//ad if statement later to change this
		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("");
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1));

		buttonText[4].setFont(buttonFont);
		buttonText[4].setString(""); //will need change due to sound controller
		buttonText[4].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 2 - 95));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));

		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);



	}
	else if (state == GameStates::Sound) //Game options
	{
		m_selectedButtonIndex = 0;
		thisButton.m_selectedButtonIndex = 0;

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Sound Effects");
		buttonText[0].setCharacterSize(35);
		buttonText[0].setFillColor(sf::Color::Yellow);
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 250, height / 4 * 1 + 50));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Music");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 270), height / 4 * 2 + 70));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("OFF");
		buttonText[2].setCharacterSize(30);
		buttonText[2].setPosition(sf::Vector2f((width / 2 + 250), height / 4 * 3 - 350));
		buttonText[2].setFillColor(sf::Color::White);

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("ON"); 
		buttonText[3].setCharacterSize(30);
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1 + 50));
		buttonText[3].setFillColor(sf::Color::Yellow);


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString("ON"); 
		buttonText[4].setCharacterSize(30);
		buttonText[4].setPosition(sf::Vector2f((width / 2 + 150), height / 4 * 2 + 70));
		buttonText[4].setFillColor(sf::Color::Yellow);

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString("OFF"); 
		buttonText[5].setCharacterSize(30);
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 250, height / 4 * 3 - 130));
		buttonText[5].setFillColor(sf::Color::White);

		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);
	}
}
void Menu::MoveLeft(GameStates &state, Sound &sound)
{
	leftpressed++;
	if (state == GameStates::Sound)
	{
		if (m_selectedButtonIndex == 1)
		{
			buttonText[4].setFillColor(sf::Color::Yellow);
			buttonText[5].setFillColor(sf::Color::White);
			if (leftPressed == 0)
			{
				sound.muteMusic = false;
				sound.PlayMenuBackGround();
				rightpressed = -1;
			}
		}
		if (m_selectedButtonIndex == 0)
		{
			buttonText[3].setFillColor(sf::Color::Yellow);
			buttonText[2].setFillColor(sf::Color::White);
			if (leftPressed == 0)
			{
				sound.muteSFX = false;
				rightpressed = -1;
			}
		}
		
	}
}

void Menu::MoveRight(GameStates &state, Sound &sound)
{
	rightpressed++;
	if (state == GameStates::Sound)
	{
		if (m_selectedButtonIndex == 1)
		{ 
			buttonText[4].setFillColor(sf::Color::White);
			buttonText[5].setFillColor(sf::Color::Yellow);
			if (rightpressed == 0)
			{
				sound.muteMusic = true;
				sound.StopMenuBackGround();
				rightpressed = -1;
			}
		}
		if (m_selectedButtonIndex == 0)
		{
			
			buttonText[3].setFillColor(sf::Color::White);
			buttonText[2].setFillColor(sf::Color::Yellow);

			if (rightpressed == 0)
			{
				sound.muteSFX = true;
				rightpressed = -1;
			}
		}
	}
}
void Menu::MoveUp(GameStates state)
{
	if (state == GameStates::MainMenu) //main menu
	{
		if (m_selectedButtonIndex - 1 >= 0)
		{
			buttonText[m_selectedButtonIndex].setCharacterSize(30);
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::White);
			m_selectedButtonIndex--;
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
			buttonText[m_selectedButtonIndex].setCharacterSize(35);
			thisButton.ButtonScaleUp(state);
		}
	}


	if (state == GameStates::Sound) //main menu
	{
		if (m_selectedButtonIndex - 1 >= 0)
		{
			buttonText[m_selectedButtonIndex].setCharacterSize(30);
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::White);
			m_selectedButtonIndex--;
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
			buttonText[m_selectedButtonIndex].setCharacterSize(35);
			thisButton.ButtonScaleUp(state);
		}
	}

	if (state == GameStates::Customise) //main menu
	{
		if (m_selectedButtonIndex - 1 >= 0)
		{
			buttonText[m_selectedButtonIndex].setCharacterSize(30);
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::White);
			m_selectedButtonIndex--;
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
			buttonText[m_selectedButtonIndex].setCharacterSize(35);
			thisButton.ButtonScaleUp(state);
		}
	}
}

void Menu::MoveDown(GameStates state) {

	if (state == GameStates::MainMenu) //main menu
	{
		if (m_selectedButtonIndex + 1 < 4)
		{
			buttonText[m_selectedButtonIndex].setCharacterSize(30);
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::White);
			m_selectedButtonIndex++;
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
			buttonText[m_selectedButtonIndex].setCharacterSize(35);
			thisButton.ButtonScaleDown(state);
		}
	}

	if (state == GameStates::Sound) //difficulty menu
	{
		if (m_selectedButtonIndex + 1 < 2)
		{
			buttonText[m_selectedButtonIndex].setCharacterSize(30);
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::White);
			m_selectedButtonIndex++;
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
			buttonText[m_selectedButtonIndex].setCharacterSize(35);
			thisButton.ButtonScaleDown(state);
		}
	}

	if (state == GameStates::Customise) //sound options menu
	{
		if (m_selectedButtonIndex + 1 < 3)
		{
			buttonText[m_selectedButtonIndex].setCharacterSize(30);
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::White);
			m_selectedButtonIndex++;
			buttonText[m_selectedButtonIndex].setFillColor(sf::Color::Yellow);
			buttonText[m_selectedButtonIndex].setCharacterSize(35);
			thisButton.ButtonScaleDown(state);
		}
	}
}


void Menu::CustomizePlayer(GameStates state, sf::RenderWindow& window, sf::Event event, Player &player)
{
	if (state == GameStates::Customise)
	{
		player.SetPosition(730, 300);
		colours[0].setPosition(200, 100);
		colours[1].setPosition(200, 200);
		colours[2].setPosition(200, 300);
		colours[3].setPosition(200, 400);
		colours[4].setPosition(200, 500);
		colours[0].setFillColor(sf::Color::Magenta);
		colours[1].setFillColor(sf::Color::Red);
		colours[2].setFillColor(sf::Color::Cyan);
		colours[3].setFillColor(sf::Color::Green);
		colours[4].setFillColor(sf::Color::Yellow);
		sprite[0].setPosition(300, 700);
		sprite[1].setPosition(500, 700);
		sprite[2].setPosition(700, 700);
		sprite[3].setPosition(900, 700);
		sprite[4].setPosition(1100,700);
		sprite[0].setTexture(player.texture[0]);
		sprite[1].setTexture(player.texture[1]);
		sprite[2].setTexture(player.texture[2]);
		sprite[3].setTexture(player.texture[3]);
		sprite[4].setTexture(player.texture[4]);

		for (int i = 0; i < 5; i++)
		{
			colours[i].setSize(sf::Vector2f(45, 45));
		}
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		if (left && !leftPressed)
		{
			sprite[player.textureCount].setScale(sf::Vector2f(1.0, 1.0));
			sprite[player.textureCount-1].setScale(sf::Vector2f(1.5,1.5));
			player.textureCount -= 1;
			leftPressed = left;
		}

		if (!left && leftPressed)
		{
			leftPressed = false;
		}

		dPadLeft = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -m_val;
		if (dPadLeft && !dPadleftPress)
		{
			sprite[player.textureCount].setScale(sf::Vector2f(1.0, 1.0));
			sprite[player.textureCount - 1].setScale(sf::Vector2f(1.5, 1.5));
			player.textureCount -= 1;
			dPadleftPress = dPadLeft;
		}

		if (!dPadLeft && dPadleftPress)
		{
			dPadleftPress = false;
		}

		right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		if (right && !rightPressed)
		{
			sprite[player.textureCount].setScale(sf::Vector2f(1.0, 1.0));
			player.textureCount += 1;
			sprite[player.textureCount].setScale(sf::Vector2f(1.5, 1.5));
			rightPressed = right;
		}

		if (!right && rightPressed)
		{
			rightPressed = false;
		}

		dPadRight = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < m_val;
		if (dPadRight && !dPadRightPress)
		{
			sprite[player.textureCount].setScale(sf::Vector2f(1.0, 1.0));
			player.textureCount += 1;
			sprite[player.textureCount].setScale(sf::Vector2f(1.5, 1.5));
			dPadRightPress = dPadRight;
		}

		if (!dPadRight && dPadRightPress)
		{
			dPadRightPress = false;
		}

		up = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		if (up && !upPressed)
		{
			colours[player.colourCount].setOutlineThickness(0);
			player.colourCount -= 1;
			upPressed = up;
		}

		if (!up && upPressed)
		{
			upPressed = false;
		}

		down = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
		if (down && !downPressed)
		{
			colours[player.colourCount].setOutlineThickness(0);
			player.colourCount += 1;
			downPressed = down;
		}

		if (!down && downPressed)
		{
			downPressed = false;
		}
		dPadDown = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -m_val;
		if (dPadDown && !dPadDownPress)
		{
			colours[player.colourCount].setOutlineThickness(0);
			player.colourCount += 1;
			dPadDownPress = dPadDown;
		}

		if (!dPadDown && dPadDownPress)
		{
			dPadDownPress = false;
		}

		dPadUp = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < m_val;
		if (dPadUp && !dPadUpPress)
		{
			colours[player.colourCount].setOutlineThickness(0);
			player.colourCount -= 1;
			dPadUpPress = dPadUp;
		}

		if (!dPadUp && dPadUpPress)
		{
			dPadUpPress = false;
		}
		if (player.colourCount <= -1)
		{
			player.colourCount = 4;
		}
		if (player.colourCount <= 4)
		{
			colours[player.colourCount].setOutlineColor(sf::Color::Black);
			colours[player.colourCount].setOutlineThickness(10);
		}

	}
}