#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Include\Menu.h"
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"

using namespace std;
float tileSizeY;
float tileSizeX;
int attempts = 1; 
int moveAmount = 5; 
int count = 0;

//////////////////Boost Additions///////////////////////////////
const int maxBoost = 16;
const int minBoost = 0;
int boost = 0;
bool canBoost = false;
bool go = false;



//////////////////Timer Additions//////////////////////////////
int attemptMove = 0;
int remaining = 0;
int counter = 310;
sf::Clock timer;
sf::Time elapsed;
sf::String text;
sf::Font font;
sf::Text theText;
sf::Text attemptText;
sf::String attemptString;
////////////////////////////////////////////////////////////////

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

	////////////Boost Meter/////////////////////////////////////////////////////////////////////////////
	int increase = 1;
	sf::RectangleShape boostBar(sf::Vector2f(160, 40));
	boostBar.setFillColor(sf::Color::Transparent);
	boostBar.setOutlineColor(sf::Color::Green);
	boostBar.setOutlineThickness(4);
	boostBar.setPosition(player.X() - 40, 60);


	sf::RectangleShape innerBoost(sf::Vector2f(10,40));
	innerBoost.setFillColor(sf::Color::Red);
	innerBoost.setPosition(player.X() - 40, 40);

	/////////////////////////Don't forget to get the font from the resource file///////////////////////////////////
	if (!font.loadFromFile("DESIB___.TTF"))
	{

	}

	text = to_string(counter) + ": Seconds";
	int textX = 200;
	theText.setCharacterSize(50);
	theText.setFillColor(sf::Color::Yellow);
	theText.setFont(font);
	theText.setString(text);

	attemptString = to_string(attempts) + ": Attempts";
	attemptText.setCharacterSize(50);
	attemptText.setFillColor(sf::Color::White);
	attemptText.setFont(font);
	attemptText.setString(attemptString);
	//////////////////////////////////////////////////////////

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
					if (m_GameStates == GameStates::Play) 
					{
						if (canBoost == true)
						{
							go = true;
						}
					}
					break;

				case sf::Keyboard::BackSpace:
					m_GameStates = GameStates::MainMenu;
					menu.CheckMenuState(window->getSize().x, window->getSize().y, m_GameStates);
					break;
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
		//////////////////////////////Changed the collisions////////////////////////////////////////////////////////////////
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
						player.Reset();
						attempts++;
						collision = false;

						attemptString = "Attempt: " + to_string(attempts);
						attemptText.setString(attemptString);
						attemptText.setPosition(40, 40);
					}				
				}
			}
			bool secondCollision = false;
				if (layer->name == "Square Objects")
				{
					for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
					{
						const sf::FloatRect squareRect = object->GetAABB();
						secondCollision = squareRect.intersects(player.Rect().getGlobalBounds());
						if (secondCollision == true)
						{		
							player.Reset();
							attempts++;
						    secondCollision = false;

							attemptString = "Attempt: " + to_string(attempts);
							attemptText.setString(attemptString);
							attemptText.setPosition(40, 40);
						}
					}
				}


				//////////////////////////////////////////////////////////////////////////////////////
				bool thirdCollision = false;
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
			

				if(player.GROUNDPOS < 720 && thirdCollision == false)
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
			///////////////////////////////////////////////////////////////////////
			boostBar.setPosition(player.X() - 600, 60);
			innerBoost.setPosition(player.X() - 600, 60);
			innerBoost.setScale(increase, 1);

			main.setCenter(player.X(), 400);
			window->setView(main);
			window->draw(ml);
			window->draw(boostBar); //
			window->draw(innerBoost); //
		
			////////////////////////////////////////////////////////////////////////////
			attemptString = "Attempt: " + to_string(attempts);

			if (attemptMove < 100) // moving the text
			{
				attemptMove++;
				attemptText.setPosition(player.X() - 40, 40);
				attemptText.setString(attemptString);
			}
			else if (attemptMove < 200)
			{
				attemptMove++;
				attemptText.setPosition(500, 40);
				attemptText.setString(attemptString);	
			}
			window->draw(attemptText);

			//Countdown timer
			elapsed = timer.getElapsedTime();  // start the timer
			remaining = elapsed.asSeconds();
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
				if (boost == maxBoost)
				{
					canBoost = true;
				}
				if (boost > minBoost && canBoost == true && go == true)
				{
					if (increase > 0)
					{
						increase -= 4;
					}
					boost -= 4;
					moveAmount = 9;
					player.updateSpeed = 9.0f;
				}
				if (boost == minBoost)
				{
					increase = 0;
					go = false;
					canBoost = false;
					moveAmount = 5;
					player.updateSpeed = 4.9f;
				}
				counter = counter - remaining;  // counter is time remaining, remaining is at max 1
				if (counter > 120)
				{
					text = to_string(counter / 60) + ": Minutes";
				}
				else if (counter >= 60 && counter <= 119)
				{
					text = to_string(counter / 60) + ": Minute";
				}
				else if (counter < 60)
				{
					text = to_string(counter) + ": Seconds";
				}
					timer.restart();
				
			}
			textX = player.X() + 330;
			theText.setPosition(textX, 40);
			theText.setString(text);
			window->draw(theText);
			if (counter <= 0)
			{
				//gameover
				m_GameStates == GameStates::GameLose;
			}
			////////////////////////////////////////////////////////////////////////////////////
		}
		if (m_GameStates != GameStates::Play)
		{
			menu.draw(*window, m_GameStates,player);
		}
		window->display();
	}

	return 0;
}

