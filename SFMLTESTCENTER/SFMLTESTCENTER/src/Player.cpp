#include "Player.h"
#include "Include\GameState.h"


Player::Player()
{

	texture[0].loadFromFile("player1.png");
	texture[1].loadFromFile("player2.png");
	texture[2].loadFromFile("player3.png");
	texture[3].loadFromFile("player4.png");
	texture[4].loadFromFile("player5.png");
	shape.setTexture(texture[0]);
	velocity = sf::Vector2f(0, 10);
	position = sf::Vector2f(200, pos);
	gravity= sf::Vector2f(0.0f, 9.8f * pixelToMeters);
	shape.setPosition(position);

}

void Player::KeyboardInput()
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isMoving == false && switchGravity == false) {
		velocity.y = (force * (sinf(angle*0.0175)) * pixelToMeters);
 		isMoving = true;
		actualTime = 0;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isMoving == false && switchGravity == true) {
		velocity.y = -(force * (sinf(angle*0.0175)) * pixelToMeters);
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
		isMoving = false;
		angle = 50;
		switchGravity = false;
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
	isMoving = false;
	angle = 50;
	switchGravity = false;
}

void Player::Update(sf::RenderWindow *window)
{
	if (switchGravity == true)
	{
		gravity = sf::Vector2f(0.0f, -9.8f * pixelToMeters);
		shape.setRotation(180);
	}
	else if (switchGravity == false)
	{
		gravity = sf::Vector2f(0.0f, 9.8f * pixelToMeters);
		shape.setRotation(0);
	}
	KeyboardInput();
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
float Player::GetPos()
{
	return pos;
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
		shape.setTexture(texture[0]);
	}

	if (textureCount == 1)
	{
		shape.setTexture(texture[1]);
	}
	if (textureCount == 2)
	{
		shape.setTexture(texture[2]);
	}
	if (textureCount == 3)
	{
		shape.setTexture(texture[3]);
	}
	if (textureCount == 4)
	{
		shape.setTexture(texture[4]);
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