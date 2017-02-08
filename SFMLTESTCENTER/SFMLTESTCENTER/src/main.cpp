#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Include\Menu.h"
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"
#include "Include\Map.h"
#include "Include\ParticleSystem.h"
#include "Include\AttemptsCount.h"
#include "Include\Boost.h"
#include "Include\CountDown.h"
#include "Include\GameOver.h"
#include "Include\Controller.h"
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
	Boost boost;  
	CountDown countDown;
	AttemptsCount attemptsCount;
	LevelStates level = LevelStates::Level1;
	GameStates m_GameStates = GameStates::MainMenu;
	Menu menu(window->getSize().x, window->getSize().y, m_GameStates);
	window->setFramerateLimit(60); 
	sf::View main(sf::FloatRect(0, 0, 1400, 800));
	Map m;
	ParticleSystem particles(500);
	sf::Clock clock;
	sf::Clock menuClock;
	GameOver gameOver;
	Controller controller;

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
					if (m_GameStates == GameStates::Play && level != LevelStates::Level1)
					{
						boost.CanBoost();
					}
					break;
				case sf::Keyboard::Num1:
					level = LevelStates::Level1;
					m.CheckState(level);
					break;
				case sf::Keyboard::Num2:
					level = LevelStates::Level2;
					m.CheckState(level);
					break;
				case sf::Keyboard::Num3:
					level = LevelStates::Level3;
					m.CheckState(level);
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
				}
				break;
			case sf::Event::Closed:
				window->close();
				break;

			}
		}

		menu.CustomizePlayer(m_GameStates, *window,event, player);
		m.Update(player, m_GameStates, level, attemptsCount, countDown);
		gameOver.Update(m_GameStates, attemptsCount);
		controller.Update(m_GameStates, menu, *window, player,boost,level);
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
			boost.Update(player, moveAmount);
			countDown.Update(player, m_GameStates);
			main.setCenter(player.X(), 400);
			window->setView(main);
			m.Draw(*window, level);
			if (level != LevelStates::Level1)
			{
				boost.Draw(*window, m_GameStates);
			}
			countDown.Draw(*window, m_GameStates);//
			attemptsCount.draw(*window, m_GameStates);//
		}

		if (m_GameStates != GameStates::Play)
		{
			window->setView(sf::View(sf::Vector2f(700,400),sf::Vector2f(1400,800)));
		}
		if (m_GameStates != GameStates::Play)
		{
			menu.draw(*window, m_GameStates,player);
		}
		if (m_GameStates == GameStates::GameLose || m_GameStates == GameStates::GameWin)
		{
			window->setView(sf::View(sf::Vector2f(1400, 400), sf::Vector2f(1400, 800)));
			gameOver.Draw(*window);
		}


		window->display();



	}

	return 0;
}

