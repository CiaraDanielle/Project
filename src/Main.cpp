#include <SFML/Graphics.hpp>
#include "Player.h"
#include "I:\Project\Include\Menu.h"
#include "I:\Project\Include\GameState.h"


using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Project I");
	Player player;
	GameStates m_GameStates = GameStates::MainMenu;
	Menu menu(window.getSize().x, window.getSize().y, m_GameStates);

	player.clock.restart();

	while (window.isOpen())
	{

		//read keyboard input
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp(m_GameStates);
					break;
				case sf::Keyboard::Down:
					menu.MoveDown(m_GameStates);
					break;
				case sf::Keyboard::BackSpace:
					m_GameStates = GameStates::MainMenu;
					menu.CheckMenuState(window.getSize().x, window.getSize().y, m_GameStates);
					break;
				case sf::Keyboard::Return:
					if (m_GameStates == GameStates::MainMenu)
					{
						switch (menu.getPressedItem())
						{
						case 0:
							m_GameStates = GameStates::Play;
							menu.CheckMenuState(window.getSize().x, window.getSize().y, m_GameStates);
							break;
						case 1:
							m_GameStates = GameStates::SoundOptions;
							menu.CheckMenuState(window.getSize().x, window.getSize().y, m_GameStates);
							break;
						case 2:
							m_GameStates = GameStates::GameOptions;
							menu.CheckMenuState(window.getSize().x, window.getSize().y, m_GameStates);
							break;
						case 3:
							return EXIT_SUCCESS;
							break;
						}
					}
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;

			}
			if (m_GameStates == GameStates::Play)
			{
				player.KeyboardInput(event, window);
			}
		}

		if (m_GameStates == GameStates::Play)
		{
			player.Update(window);
		}
		if (m_GameStates != GameStates::Play)
		{
			menu.ScrollBackGround(m_GameStates, window);
		}

		window.clear();
		if (m_GameStates == GameStates::Play)
		{
			player.Draw(window);
		}
		if (m_GameStates != GameStates::Play)
		{
			menu.draw(window, m_GameStates);
		}
		window.display();



	}

	return 0;
}

