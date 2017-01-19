#include "Player.h"
#include "Include\GameState.h"


Player::Player()
{

	optionOne.loadFromFile("player1.png");
	optionTwo.loadFromFile("player2.png");
	optionThree.loadFromFile("player3.png");
	optionFour.loadFromFile("player4.png");
	optionFive.loadFromFile("player5.png");
	shape.setTexture(optionOne);
	shape.setPosition(sf::Vector2f(100, pos));
	temp = sf::Vector2f(0, 45);
	velocity = sf::Vector2f(0, 10);
	position = sf::Vector2f(100, pos);
	unitVector = sf::Vector2f(0.0f, 0.0f);
	gravity= sf::Vector2f(0.0f, 9.8f * pixelToMeters);

}

void Player::KeyboardInput(sf::Event &event, sf::RenderWindow *window)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isMoving == false) {
		velocity.y = (force * (sinf(angle*0.0175)) * pixelToMeters);
		isMoving = true;
		actualTime = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		position.y = pos;
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
		force = 7;
	}
}

void Player::Reset()
{
	position.y = pos;
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
	force = 7;
}

void Player::Update(sf::RenderWindow *window)
{
	Maxheight = linePosY - position.y;
	//s = s0 + u*t + 0.5*a*t2.
	distance = position.x - linePosX;
	position.x+=updateSpeed;

	//get the time since last update and restart the clock
	timeSinceLastUpdate += clock.restart();
	//update every 60th of a second
	if (timeSinceLastUpdate > timePerFrame)
	{

		if (isMoving == true) {

			velocity.y = velocity.y - gravity.y * timeSinceLastUpdate.asSeconds();
			position.y = position.y - (velocity.y * timeSinceLastUpdate.asSeconds()) + 0.5 * gravity.y*(timeSinceLastUpdate.asSeconds()*timeSinceLastUpdate.asSeconds());

			actualTime += timeSinceLastUpdate.asSeconds();

			while (actualHeight < Maxheight) {
				actualHeight = Maxheight;
			}
			while (actualDistance < distance) {
				actualDistance = distance;

			}
		}

		if (position.y > pos && isMoving == true)
		{
			if (velocity.y < -5) {
				position.y = pos;
				isMoving = false;
			}
			else {
				position.y = pos;
				velocity.y = 0;
				velocity.x = 0;
				isMoving = false;
			}
		}

		//update shape on screen
		shape.setPosition(position);

		timeSinceLastUpdate = sf::Time::Zero;
	}
}


void Player::Draw(sf::RenderWindow *window, GameStates state)
{
	SetColour();
	SetText();
	if (state == GameStates::Customise)
	{
		window->draw(shape);
	}
	else
	{
		window->clear();
		window->draw(shape);
	}
}


Player::~Player()
{
}

float Player::X()
{
	return shape.getPosition().x;
}

float Player::Y()
{
	return shape.getPosition().y;
}

void Player::Pos(int x)
{
	pos = x; 
}

sf::Sprite Player::Rect()
{
	return shape;
}

void Player::SetPosition(int x, int y)
{
	shape.setPosition(sf::Vector2f(x, y));
}

void Player::textCount(int x)
{
	textureCount = x;
	SetText();
}

void Player::ColourCount(int y)
{
	colourCount = y;
}

void Player::SetText()
{
	if (textureCount == 0)
	{
		shape.setTexture(optionOne);
	}

	if (textureCount == 1)
	{
		shape.setTexture(optionTwo);
	}
	if (textureCount == 2)
	{
		shape.setTexture(optionThree);
	}
	if (textureCount == 4)
	{
		shape.setTexture(optionFour);
	}
	if (textureCount == 5)
	{
		shape.setTexture(optionFive);
	}

	if (textureCount <= -1)
	{
		textureCount = 5;
	}
	if (textureCount >= 6)
	{
		textureCount = 0;
	}
	SetColour();
}

void Player::SetColour()
{
	if (colourCount == 0)
	{
		shape.setColor(sf::Color::Magenta);
	}
	
	if (colourCount == 1)
	{
		shape.setColor(sf::Color::Red);
	}
	if (colourCount == 2)
	{
		shape.setColor(sf::Color::Cyan);
	}
	if (colourCount == 3)
	{
		shape.setColor(sf::Color::Green);
	}
	if (colourCount == 4)
	{
		shape.setColor(sf::Color::Yellow);
	}

	if (colourCount == -1)
	{
		colourCount = 4;
	}
	if (colourCount == 5)
	{
		colourCount = 0;
	}
}