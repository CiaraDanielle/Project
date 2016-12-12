#include "I:\Project\Include\Menu.h"
#include "I:\Project\Include\Button.h"

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
		buttonText[1].setString("Sound Options");
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 65), height / 4 * 2 - 100));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("Difficulty");
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
	else if (state == GameStates::SoundOptions) //sound options
	{
		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Mute");
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 290, height / 4 * 1));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Volume");
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 2 - 95));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("Change Music");
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 3 - 180));

		//ad if statement later to change this
		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("On");
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1));

		buttonText[4].setFont(buttonFont);
		buttonText[4].setString("5"); //will need change due to sound controller
		buttonText[4].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 2 - 95));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString("Type 1"); //will need change due to sound controller
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

	if (state != GameStates::Play)
	{
		moveX = mainBackground.getPosition().x - 0.1f;
		mainBackground.setPosition(sf::Vector2f(moveX, 0));
		moveTwo = rollingBack.getPosition().x - 0.1f;
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
		if (colorNum == 10005)
		{
			mainBackground.setColor(sf::Color::Red);
			rollingBack.setColor(sf::Color::Red);
		}
		if (colorNum == 20005)
		{
			mainBackground.setColor(sf::Color::Green);
			rollingBack.setColor(sf::Color::Green);
		}
		if (colorNum == 30005)
		{
			mainBackground.setColor(sf::Color::Magenta);
			rollingBack.setColor(sf::Color::Magenta);
		}
		if (colorNum == 40005)
		{
			mainBackground.setColor(sf::Color::Yellow);
			rollingBack.setColor(sf::Color::Yellow);
		}
		if (colorNum == 50005)
		{
			colorNum = 0;
		}
		colorNum++;
	}
}
void Menu::draw(sf::RenderWindow &window, GameStates state) //draw method
{

	window.draw(mainBackground);
	window.draw(rollingBack);

	thisButton.draw(window);

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(buttonText[i]);
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
		buttonText[1].setString("Sound Options");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 65), height / 4 * 2 - 100));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("Difficulty");
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
	else if (state == GameStates::SoundOptions) //sound options
	{
		m_selectedButtonIndex = 0;
		thisButton.m_selectedButtonIndex = 0;

		buttonText[0].setFont(buttonFont);
		buttonText[0].setString("Mute");
		buttonText[0].setCharacterSize(35);
		buttonText[0].setFillColor(sf::Color::Yellow);
		buttonText[0].setPosition(sf::Vector2f(width / 2 - 290, height / 4 * 1));


		buttonText[1].setFont(buttonFont);
		buttonText[1].setString("Volume");
		buttonText[1].setCharacterSize(30);
		buttonText[1].setFillColor(sf::Color::White);
		buttonText[1].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 2 - 95));

		buttonText[2].setFont(buttonFont);
		buttonText[2].setString("Change Music");
		buttonText[2].setCharacterSize(30);
		buttonText[2].setFillColor(sf::Color::White);
		buttonText[2].setPosition(sf::Vector2f((width / 2 - 290), height / 4 * 3 - 180));

		//ad if statement later to change this
		buttonText[3].setFont(buttonFont);
		buttonText[3].setString("On");
		buttonText[3].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 1));

		buttonText[4].setFont(buttonFont);
		buttonText[4].setString("5"); //will need change due to sound controller
		buttonText[4].setPosition(sf::Vector2f(width / 2 + 150, height / 4 * 2 - 95));

		buttonText[5].setFont(buttonFont);
		buttonText[5].setString("Type 1"); //will need change due to sound controller
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

	if (state == GameStates::SoundOptions) //main menu
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

	if (state == GameStates::SoundOptions) //sound options menu
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