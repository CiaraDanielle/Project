#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Include\Menu.h"
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"

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
	tmx::MapLoader ml("");
	sf::View main(sf::FloatRect(0, 0, 1400, 800));
	ml.UpdateQuadTree(sf::FloatRect(0, 0, 1400, 800));
	ml.Load("test.tmx");
	const std::vector<tmx::MapLayer>& layers = ml.GetLayers();
	sf::Vector2f tmp;
	int count = 0; 

	player.clock.restart();
	tileSizeY = ml.GetTileSize().y;
	tileSizeX = ml.GetTileSize().x; 
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

				}
				break;
			case sf::Event::Closed:
				window->close();
				break;

			}
			if (m_GameStates == GameStates::Play)
			{
				//player.KeyboardInput(event, window);
			}
		}
		menu.CustomizePlayer(m_GameStates, *window,event, player);
		bool collision = false;
		for (auto layer = ml.GetLayers().begin(); layer != ml.GetLayers().end(); ++layer)
		{
			if (layer->name == "Triangle Objects")
			{
				for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
				{
					const sf::FloatRect triangleRect = object->GetAABB();
					collision = triangleRect.intersects(player.Rect().getGlobalBounds());
					if (collision == true)
					{
						attempts++;
						cout << attempts << endl; 
						collision = false;
						player.Reset();
					}				
				}
			}
			bool secondCollision = false;
			for (auto layer = ml.GetLayers().begin(); layer != ml.GetLayers().end(); ++layer)
			{
				if (layer->name == "Square Objects")
				{
					for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
					{
						const sf::FloatRect squareRect = object->GetAABB();
						secondCollision = squareRect.intersects(player.Rect().getGlobalBounds());
						if (secondCollision == true)
						{							
							cout << attempts << endl;
							secondCollision = false;
							player.Reset();
							attempts++;
						}
					}
				}
			}

			bool thirdCollision = false;
			for (auto layer = ml.GetLayers().begin(); layer != ml.GetLayers().end(); ++layer)
			{
				if (layer->name == "Gravity")
				{
					for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
					{
						const sf::FloatRect squareRect = object->GetAABB();
						thirdCollision = squareRect.intersects(player.Rect().getGlobalBounds());
						if (thirdCollision == true)
						{
							float y = squareRect.height;
							player.GROUNDPOS = squareRect.top;
							if (player.X() < object->GetPosition().x + squareRect.width)
							{
								player.isMoving = false;
								count = 0;
							}
						}
						if (thirdCollision != true && count == 0 && player.X() > object->GetPosition().x + squareRect.width)
						{
							player.isMoving = true;
 							count = 1;
						}
					}
				}

				else if(player.GROUNDPOS < 720 && thirdCollision == false)
				{
					player.GROUNDPOS = 720;
				}
			}
		}
		window->clear();
		if (m_GameStates != GameStates::Play)
		{
			menu.ScrollBackGround(m_GameStates, *window);
		}
		window->clear();
		if (m_GameStates == GameStates::Play)
		{
			menu.ScrollBackGround(m_GameStates, *window);
			menu.draw(*window, m_GameStates, player);
			player.Draw(window,m_GameStates);
			player.Update(window);
			main.setCenter(player.X(), 400);
			window->setView(main);
			window->draw(ml);
		}
		if (m_GameStates != GameStates::Play)
		{
			menu.draw(*window, m_GameStates,player);
		}
		window->display();



	}

	return 0;
}

