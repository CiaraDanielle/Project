#include "Include\Menu.h"
#include "Include\Button.h"

Button thisButton(GameStates::MainMenu);

Menu::Menu(float width, float height, GameStates state)
{


	if (!buttonFont.loadFromFile("arial.ttf"))
	{
		////
	}
	MainTexture.loadFromFile("mainMenu.png");
	mainBackground.setTexture(MainTexture);
	MainTexture.loadFromFile("mainMenu.png");
	mainBackground.setTexture(MainTexture);
	mainBackground.setPosition(sf::Vector2f(0, 0));
	rollingTexture.loadFromFile("mainMenu2.png");
	rollingBack.setTexture(rollingTexture);
	rollingBack.setPosition(800, 0);
	rollingBack.setPosition(1495, 0);

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
	else if (state == GameStates::GameOptions) //Game options
	{

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Difficulty");
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 250, height / 4 * 1 + 50));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Number of Waves");
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 2 + 70));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 25), height / 4 * 3 - 180));

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("Medium"); //will change due to difficulty controller later
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1 + 50));


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString("10"); //will need change due to difficulty controller
		buttonText[4].setPosition(sf::Vector2f((width / 2 + 190), height / 4 * 2 + 70));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));

		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);
	}
	else if (state == GameStates::Pause) //pause menu
	{
		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Resume");
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 70, height / 4 * 1 + 100));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Quit");
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 50), height / 4 * 2 + 50));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 25), height / 4 * 3 - 180));

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString(""); //will change due to difficulty controller later
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1 + 50));


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString(""); //will need change due to difficulty controller
		buttonText[4].setPosition(sf::Vector2f((width / 2 + 190), height / 4 * 2 + 70));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));


		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);

	}
	thisButton.m_selectedButtonIndex = 0;
	m_selectedButtonIndex = 0;
}

Menu::~Menu()
{
}

void Menu::ScrollBackGround(GameStates state, sf::RenderWindow &window)
{
		moveX = mainBackground.getPosition().x - 5.0f;
		mainBackground.setPosition(sf::Vector2f(moveX, 0));
		moveTwo = rollingBack.getPosition().x - 5.0f;
		rollingBack.setPosition(sf::Vector2f(moveTwo, 0));
		if (mainBackground.getPosition().x < -1495)
		{
			mainBackground.setPosition(sf::Vector2f(1495, 0));
		}
		if (rollingBack.getPosition().x < -1495)
		{
			rollingBack.setPosition(sf::Vector2f(1495, 0));
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

//void Menu::CustomizePlayer(GameStates state, sf::Event &event)
//{
//	if(state == GameStates::Customise && sf::Event)
//}
void Menu::draw(sf::RenderWindow& window, GameStates state, Player &player) //draw method
{

	window.draw(mainBackground);
	window.draw(rollingBack);

	thisButton.draw(window);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(buttonText[i]);
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
	}
}



void Menu::CheckMenuState(float width, float height, GameStates state) //checks the current state of the game changing to the corrosponding menu
{
	thisButton.setButtonSize(state);
	m_selectedButtonIndex = 0;

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
	else if (state == GameStates::GameOptions) //Game options
	{
		m_selectedButtonIndex = 0;
		thisButton.m_selectedButtonIndex = 0;

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Difficulty");
		buttonText[0].setCharacterSize(35);
		buttonText[0].setFillColor(sf::Color::Yellow);
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 250, height / 4 * 1 + 50));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Number of Waves");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 2 + 70));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 25), height / 4 * 3 - 180));

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("Medium"); //will change due to difficulty controller later
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1 + 50));


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString("10"); //will need change due to difficulty controller
		buttonText[4].setPosition(sf::Vector2f((width / 2 + 190), height / 4 * 2 + 70));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));

		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);
	}
	else if (state == GameStates::Pause) //pause menu
	{
		m_selectedButtonIndex = 0;
		thisButton.m_selectedButtonIndex = 0;

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Resume");
		buttonText[0].setCharacterSize(35);
		buttonText[0].setFillColor(sf::Color::Yellow);
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 70, height / 4 * 1 + 100));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Quit");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 50), height / 4 * 2 + 50));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 25), height / 4 * 3 - 180));

		buttonText[3].setFont(buttonFont);
		buttonText[3].setString(""); //will change due to difficulty controller later
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1 + 50));


		buttonText[4].setFont(buttonFont);
		buttonText[4].setString(""); //will need change due to difficulty controller
		buttonText[4].setPosition(sf::Vector2f((width / 2 + 190), height / 4 * 2 + 70));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString(""); //will need change due to sound controller
		buttonText[5].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 3 - 180));


		//set what position the buttons will be depending on the game state
		thisButton.setButtonPositions(width, height, state);
		thisButton.setButtonSize(state);

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

	if (state == GameStates::Pause) //main menu
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

	if (state == GameStates::GameOptions) //main menu
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

	if (state == GameStates::Pause) //Pause menu
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

	if (state == GameStates::GameOptions) //difficulty menu
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

void Menu::updateSoundOptions(bool &mute, int &volume)
{
	if (mute == true)
	{
		buttonText[3].setString("Off");
	}
	if (mute == false)
	{
		buttonText[3].setString("On");
	}
	buttonText[4].setString(std::to_string(volume));
}

void Menu::updateGameOptions(int lvl, int numberOfWaves)
{
	if (lvl == 1)
	{
		buttonText[3].setString("Easy");
	}
	if (lvl == 2)
	{
		buttonText[3].setString("Medium");
	}
	if (lvl == 3)
	{
		buttonText[3].setString("Hard");
	}
	buttonText[4].setString(std::to_string(numberOfWaves));
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
		for (int i = 0; i < 5; i++)
		{
			colours[i].setSize(sf::Vector2f(45, 45));
		}
		left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		if (left && !leftPressed)
		{
			player.textureCount -= 1;
			leftPressed = left;
		}

		if (!left && leftPressed)
		{
			leftPressed = false;
		}

		right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		if (right && !rightPressed)
		{
			player.textureCount += 1;
			rightPressed = right;
		}

		if (!right && rightPressed)
		{
			rightPressed = false;
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

		if (player.colourCount <= 4)
		{
			colours[player.colourCount].setOutlineColor(sf::Color::Black);
			colours[player.colourCount].setOutlineThickness(10);
		}


	}
}