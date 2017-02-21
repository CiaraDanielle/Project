#include "Player.h"
#include "Include\GameState.h"
#include "Include\Sound.h"

//////////////////////////////////////////////////////////////////////////////////
// Constructor 
//////////////////////////////////////////////////////////////////////////////////
Player::Player()
{

	texture[0].loadFromFile("player1.png");
	texture[1].loadFromFile("player2.png");
	texture[2].loadFromFile("player3.png");
	texture[3].loadFromFile("player4.png");
	texture[4].loadFromFile("player5.png");
	shape.setTexture(texture[0]);
	velocity = sf::Vector2f(0, 10);
	position = sf::Vector2f(200, groundpos);
	gravity= sf::Vector2f(0.0f, 9.8f * pixelToMeters);
	shape.setPosition(position);

}

//////////////////////////////////////////////////////////////////////////////////
// Keyboard input  
//////////////////////////////////////////////////////////////////////////////////
void Player::KeyboardInput(Sound &sound)
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isMoving == false && switchGravity == false) {
		Jump();
		sound.PlayJump();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isMoving == false && switchGravity == true) {
		GravityJump();
		sound.PlayJump();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		Reset();
	}
}

//////////////////////////////////////////////////////////////////////////////////
// The jump method 
//////////////////////////////////////////////////////////////////////////////////
void Player::Jump()
{
	velocity.y = (force * (sinf(angle*0.0175)) * pixelToMeters);
	isMoving = true;
	actualTime = 0;
}

//////////////////////////////////////////////////////////////////////////////////
// The gravity jump method
//////////////////////////////////////////////////////////////////////////////////
void Player::GravityJump()
{
	velocity.y = -(force * (sinf(angle*0.0175)) * pixelToMeters);
	isMoving = true;
	actualTime = 0;
}

//////////////////////////////////////////////////////////////////////////////////
// Reset method  
//////////////////////////////////////////////////////////////////////////////////
void Player::Reset()
{
	position.y = groundpos;
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

//////////////////////////////////////////////////////////////////////////////////
// Update method
//////////////////////////////////////////////////////////////////////////////////
void Player::Update(sf::RenderWindow *window, Sound &sound)
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
	KeyboardInput(sound);
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
		
		if (position.y > groundpos && isMoving == true)
		{
			if (velocity.y < -5) {
				position.y = groundpos;
				isMoving = false;
			}
			else {
				position.y = groundpos;
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


//////////////////////////////////////////////////////////////////////////////////
// Draw method
//////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////
// Destructor 
//////////////////////////////////////////////////////////////////////////////////
Player::~Player()
{
}

//////////////////////////////////////////////////////////////////////////////////
// Get the players x position 
//////////////////////////////////////////////////////////////////////////////////
float Player::X()
{
	return shape.getPosition().x;
}

//////////////////////////////////////////////////////////////////////////////////
// Get the players y position 
//////////////////////////////////////////////////////////////////////////////////
float Player::Y()
{
	return shape.getPosition().y;
}


//////////////////////////////////////////////////////////////////////////////////
// Set the ground position to a certain one 
//////////////////////////////////////////////////////////////////////////////////
void Player::Pos(int x)
{
	pos = x; 
}

//////////////////////////////////////////////////////////////////////////////////
// Get the ground postion
//////////////////////////////////////////////////////////////////////////////////
float Player::GetPos()
{
	return pos;
}

//////////////////////////////////////////////////////////////////////////////////
// Return the rectangle
//////////////////////////////////////////////////////////////////////////////////
sf::Sprite Player::Rect()
{
	return shape;
}

//////////////////////////////////////////////////////////////////////////////////
// Set the position of the player to a certain one 
//////////////////////////////////////////////////////////////////////////////////
void Player::SetPosition(int x, int y)
{
	shape.setPosition(sf::Vector2f(x, y));
}

//////////////////////////////////////////////////////////////////////////////////
// setting the index for the texture array 
//////////////////////////////////////////////////////////////////////////////////
void Player::textCount(int x)
{
	textureCount = x;
	SetText();
}

//////////////////////////////////////////////////////////////////////////////////
// Setting a count for the colors 
//////////////////////////////////////////////////////////////////////////////////
void Player::ColourCount(int y)
{
	colourCount = y;
}

//////////////////////////////////////////////////////////////////////////////////
// Setting the texture
//////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////
// Setting the texture color 
//////////////////////////////////////////////////////////////////////////////////
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