#include "Player.h"



Player::Player()
{
	if (!font.loadFromFile("Resource/arial.ttf"))
	{
		std::string s("Error loading font");
		throw std::exception(s.c_str());
	}

	heightString = "height: " + std::to_string(actualHeight) + "\n" + "Distance: " + std::to_string(actualDistance) + "\n" + "Force: " + std::to_string(force) + "\n" + "Angle: " + std::to_string(angle) + "\n" + "Time: " + std::to_string(actualTime);

	text.setString(heightString);

	shape.setPosition(sf::Vector2f(200, 680));
	shape.setSize(sf::Vector2f(20, 20));
	shape.setFillColor(sf::Color::Green);

	acceleration = sf::Vector2f(0.0f, 9.81f);
	temp = sf::Vector2f(0, 45);
	velocity = sf::Vector2f(0, 0);
	position = sf::Vector2f(200, 680);
	unitVector = sf::Vector2f(0.0f, 0.0f);
	gravity= sf::Vector2f(0.0f, 9.8f * pixelToMeters);

	line.setSize(sf::Vector2f(1600, 10));
	line.setFillColor(sf::Color::Blue);
	line.setPosition(0, linePosY);

	text.setFont(font);
//	text.setColor(sf::Color::Red);
	text.setCharacterSize(24);
	text.setPosition(10, 10);
}

void Player::KeyboardInput(sf::Event &event, sf::RenderWindow &window)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isMoving == false) {
		velocity.y = (force * (sinf(angle*0.0175)) * pixelToMeters);
		velocity.x = (force * (cosf(angle*0.0175)) * pixelToMeters);
		isMoving = true;
		actualTime = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		position.y = 680;
		position.x = 200;
		velocity.x = 0;
		velocity.y = 0;
		actualDistance = 0;
		actualHeight = 0;
		actualTime = 0;
		Maxheight = 0;
		distance = 0;
		isMoving = false;
		angle = 50;
		force = 45;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && isMoving == false) {
		angle++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && isMoving == false) {
		angle--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) && isMoving == false) {
		force++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && isMoving == false) {
		force--;
	}
}

void Player::Update(sf::RenderWindow &window)
{
	Maxheight = linePosY - position.y;
	//s = s0 + u*t + 0.5*a*t2.
	distance = position.x - linePosX;

	//get the time since last update and restart the clock
	timeSinceLastUpdate += clock.restart();
	//update every 60th of a second
	if (timeSinceLastUpdate > timePerFrame)
	{

		if (isMoving == true) {

			velocity.y = velocity.y - gravity.y * timeSinceLastUpdate.asSeconds();
			position.y = position.y - (velocity.y * timeSinceLastUpdate.asSeconds()) + 0.5 * gravity.y*(timeSinceLastUpdate.asSeconds()*timeSinceLastUpdate.asSeconds());
			position.x = position.x + (velocity.x * timeSinceLastUpdate.asSeconds()) + 0.5 * acceleration.x*(timeSinceLastUpdate.asSeconds()*timeSinceLastUpdate.asSeconds());

			actualTime += timeSinceLastUpdate.asSeconds();

			while (actualHeight < Maxheight) {
				actualHeight = Maxheight;
			}
			while (actualDistance < distance) {
				actualDistance = distance;

			}
		}

		if (position.y > 680 && isMoving == true)
		{
			if (velocity.y < -5) {
				position.y = 680;
			//	velocity.y = -restitution * velocity.y;
			//velocity.x = velocity.x  * (cosf(angle*0.0175));
				isMoving = false;
			}
			else {
				position.y = 680;
				velocity.y = 0;
				velocity.x = 0;
				isMoving = false;
			}
		}


		window.clear();

		// update position and velocity here using equations in lab sheet using timeChange as  timeSinceLastUpdate.asSeconds().


		//update shape on screen
		shape.setPosition(position);


		window.draw(shape);
		window.draw(line);
		window.draw(text);

		window.display();
		timeSinceLastUpdate = sf::Time::Zero;
	}
}


void Player::Draw(sf::RenderWindow &window)
{
	window.draw(shape);
	window.draw(line);
	window.draw(text);
}


Player::~Player()
{
}
