#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Include\Menu.h"
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"
#include "Include\Map.h"
#include "Include\ParticleSystem.h"

using namespace std;
float tileSizeY;
float tileSizeX;
int attempts = 0; 
int moveAmount = 5; 
int count = 0;


int main()
{	
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1500, 800), "Project I");
	Player player;
	GameStates m_GameStates = GameStates::MainMenu;
	Menu menu(window->getSize().x, window->getSize().y, m_GameStates);
	window->setFramerateLimit(60); 
	sf::View main(sf::FloatRect(0, 0, 1400, 800));
	Map m;
	ParticleSystem particles(500);
	sf::Clock clock;
	sf::Clock menuClock;

	player.clock.restart();

	while (window->isOpen())
	{
		main.move(moveAmount, 0);
		//read keyboard input
		sf::Event event;
		while (window->pollEvent(event))
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

				case sf::Keyboard::Left:
					menu.CustomizePlayer(m_GameStates,*window,event,player);
					break;
				case sf::Keyboard::Right:
					menu.CustomizePlayer(m_GameStates,*window,event,player);
					break;

				case sf::Keyboard::BackSpace:
					m_GameStates = GameStates::MainMenu;
					menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
					break;
				case sf::Keyboard::B:
					if (m_GameStates == GameStates::Play)
					{
						moveAmount = 10;
						player.updateSpeed = 10.0f;
					}
				case sf::Keyboard::Return:
					if (m_GameStates == GameStates::MainMenu)
					{
						switch (menu.getPressedItem())
						{
						case 0:
							m_GameStates = GameStates::Play;
							menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
							break;
						case 1:
							m_GameStates = GameStates::Customise;
							menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
							break;
						case 2:
							m_GameStates = GameStates::GameOptions;
							menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
							break;
						case 3:
							return EXIT_SUCCESS;
							break;
						}
					}
					if (m_GameStates == GameStates::GameWin)
					{
						switch (menu.getPressedItem())
						{
						case 0:
							m_GameStates = GameStates::Play;
						}
					}
				}
				break;
			case sf::Event::Closed:
				window->close();
				break;

			}
		}
		menu.CustomizePlayer(m_GameStates, *window,event, player);
		m.Update(player, m_GameStates);
		sf::Vector2i playerPos;
		if (player.switchGravity == false)
		{
			playerPos = sf::Vector2i((window->getSize().x / 2) + 45, (player.Y() + 45) - 10);
		}
		if (player.switchGravity == true)
		{
			playerPos = sf::Vector2i((window->getSize().x / 2)-30, (player.Y() - 45)+10);
		}
		particles.setEmitter(window->mapPixelToCoords(playerPos));
		sf::Time elapsed = clock.restart();
		particles.update(elapsed);

		if (m_GameStates != GameStates::Play)
		{
			menu.ScrollBackGround(m_GameStates, *window);
		}
		window->clear();
		if (m_GameStates == GameStates::Play)
		{
			menu.ScrollBackGround(m_GameStates, *window);
			menu.draw(*window, m_GameStates, player);
			window->draw(particles);
			player.Draw(window,m_GameStates);
			player.Update(window);
			main.setCenter(player.X(), 400);
			window->setView(main);
			m.Draw(*window);
		}
		if (m_GameStates != GameStates::Play)
		{
			menu.draw(*window, m_GameStates,player);
		}
		if (m_GameStates == GameStates::GameWin)
		{
			menu.draw(*window, GameStates::MainMenu, player);
		}
		if (m_GameStates == GameStates::GameWin)
		{
			menu.draw(*window, GameStates::MainMenu, player);
		}
		window->display();



	}

	return 0;
}

