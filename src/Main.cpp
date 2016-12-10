#include <SFML/Graphics.hpp>
#include "Player.h"



using namespace std;


int main()
{
	sf::RenderWindow window(sf::VideoMode(1500, 800), "Project I");
	Player player;

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
					break;
				case sf::Keyboard::Down:
					break;
				case sf::Keyboard::BackSpace:
					break;
				case sf::Keyboard::Return:
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
			player.KeyboardInput(event, window);
		}
		player.Update(window);


		window.clear();
		player.Draw(window);
		window.display();

	}

	return 0;
}

