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
#include "Include\Sound.h"

using namespace std;
int moveAmount = 5; 


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
	Sound sound;
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
					sound.PlayMenuButton();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown(m_GameStates);
					sound.PlayMenuButton();
					break;

				case sf::Keyboard::Left:
					menu.CustomizePlayer(m_GameStates,*window,event,player);
					menu.MoveLeft(m_GameStates, sound);
					sound.PlayMenuButton();
					break;
				case sf::Keyboard::Right:
					if (m_GameStates == GameStates::Customise)
					{
						menu.CustomizePlayer(m_GameStates, *window, event, player);
					}
					if (m_GameStates == GameStates::Play && level != LevelStates::Level1)
					{
						boost.CanBoost();
					}
					if (m_GameStates == GameStates::Sound)
					{
						sound.PlayMenuButton();
						menu.MoveRight(m_GameStates, sound);
					}
					break;
				case sf::Keyboard::Num1:
					level = LevelStates::Level1;
					m.CheckState(level);
					sound.PlayLevel1Sound();
					sound.StopLevel2Music();
					sound.StopLevel3Music();
					sound.StopMenuBackGround();
					break;
				case sf::Keyboard::Num2:
					level = LevelStates::Level2;
					m.CheckState(level);
					sound.PlayLevel2Sound();
					sound.StopLevel1Music();
					sound.StopLevel3Music();
					sound.StopMenuBackGround();
					break;
				case sf::Keyboard::Num3:
					level = LevelStates::Level3;
					m.CheckState(level);
					sound.PlayLevel3Sound();
					sound.StopLevel2Music();
					sound.StopLevel1Music();
					sound.StopMenuBackGround();
					break;
				case sf::Keyboard::BackSpace:					
					if (m_GameStates == GameStates::Play)
					{
						sound.PlayMenuBackGround();
					}
					m_GameStates = GameStates::MainMenu;
					menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
					sound.PlayMenuButton();
					break;
				case sf::Keyboard::Y:
					sound.muteMusic = true;
					sound.muteSFX = true; 
					sound.StopMenuBackGround();
				case sf::Keyboard::Return:
					if (m_GameStates == GameStates::MainMenu)
					{
						switch (menu.getPressedItem())
						{
						case 0:
							m_GameStates = GameStates::Play;
							menu.speed = 2.5f;
							menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
							if (level == LevelStates::Level1)
							{
								sound.PlayLevel1Sound();
							}
							if (level == LevelStates::Level2)
							{
								sound.PlayLevel2Sound();
							}
							if (level == LevelStates::Level3)
							{
								sound.PlayLevel3Sound();
							}
							sound.PlayMenuClick();
							sound.StopMenuBackGround();
							break;
						case 1:
							m_GameStates = GameStates::Customise;
							menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
							sound.PlayMenuClick();
							break;
						case 2:
							m_GameStates = GameStates::Sound;
							menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
							sound.PlayMenuClick();
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
		m.Update(player, m_GameStates, level, attemptsCount, countDown,sound,gameOver);
		gameOver.Update(m_GameStates, attemptsCount);
		controller.Update(m_GameStates, menu, *window, player,boost,level,sound);
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
			sound.StopLevel1Music();
			sound.StopLevel2Music();
			sound.StopLevel3Music();
		}
		window->clear();
		if (m_GameStates == GameStates::Play)
		{
			menu.ScrollBackGround(m_GameStates, *window);
			menu.draw(*window, m_GameStates, player);
			window->draw(particles);
			player.Draw(window,m_GameStates);
			player.Update(window,sound);
			if (level != LevelStates::Level1)
			{
				boost.Update(player, moveAmount, m_GameStates);
			}
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
			gameOver.scrollBackground(m_GameStates, *window);
			gameOver.Draw(*window);
		}


		window->display();



	}

	return 0;
}

