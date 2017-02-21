#include "GameOver.h"


//////////////////////////////////////////////////////////////////////////////////
// Constructor 
//////////////////////////////////////////////////////////////////////////////////
GameOver::GameOver()
{
	if (!font.loadFromFile("DESIB___.TTF"))
	{

	}
	texture.loadFromFile("scrollbackground.png");
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(400, 0));
	texture2.loadFromFile("scrollbackground2.png");
	sprite2.setTexture(texture2);
	sprite2.setPosition(sf::Vector2f(16000, 0));
}

//////////////////////////////////////////////////////////////////////////////////
// Scrolling background method 
//////////////////////////////////////////////////////////////////////////////////
void GameOver::scrollBackground(GameStates &state, sf::RenderWindow &window)
{
	moveX = sprite.getPosition().x - speed;
	sprite.setPosition(sf::Vector2f(moveX, 0));
	moveTwo = sprite2.getPosition().x - speed;
	sprite2.setPosition(sf::Vector2f(moveTwo, 0));
	if (sprite.getPosition().x <= -15000)
	{
		sprite.setPosition(sf::Vector2f(15000, 0));
	}
	if (sprite2.getPosition().x <= -15000)
	{
		sprite2.setPosition(sf::Vector2f(15000, 0));
	}
	if (colorNum == 0)
	{
		sprite.setColor(sf::Color::Blue);
		sprite2.setColor(sf::Color::Blue);
	}
	if (colorNum == 105)
	{
		sprite.setColor(sf::Color::Red);
		sprite2.setColor(sf::Color::Red);
	}
	if (colorNum == 205)
	{
		sprite.setColor(sf::Color::Green);
		sprite2.setColor(sf::Color::Green);
	}
	if (colorNum == 305)
	{
		sprite.setColor(sf::Color::Magenta);
		sprite2.setColor(sf::Color::Magenta);
	}
	if (colorNum == 405)
	{
		sprite.setColor(sf::Color::Yellow);
		sprite2.setColor(sf::Color::Yellow);
	}
	if (colorNum == 505)
	{
		colorNum = 0;
	}
	colorNum++;
}

//////////////////////////////////////////////////////////////////////////////////
// Destructor 
//////////////////////////////////////////////////////////////////////////////////
GameOver::~GameOver()
{
}

//////////////////////////////////////////////////////////////////////////////////
// Update method 
//////////////////////////////////////////////////////////////////////////////////
void GameOver::Update(GameStates &state, AttemptsCount &count)
{
	string = std::to_string(count.attempts) + ": Attempts";
	text.setCharacterSize(50);
	if (count.attempts > 10)
	{
		text.setFillColor(sf::Color::Red);
		text2.setFillColor(sf::Color::Red);
	}
	if (count.attempts < 10)
	{
		text.setFillColor(sf::Color::Green);
		text2.setFillColor(sf::Color::Green);
	}
	text.setFont(font);
	text.setString(string);
	text.setPosition(1400, 300);

	if (state == GameStates::GameWin)
	{
		string2 = "You won! \n It took you ";
		text2.setCharacterSize(50);
		text2.setFont(font);
		text2.setString(string2);
		text2.setPosition(1000, 300);
		timerString = "It took you " + std::to_string(time) + " Minutes";
		timerText.setCharacterSize(50);
		timerText.setFillColor(sf::Color::Yellow);
		timerText.setFont(font);
		timerText.setString(timerString);
		timerText.setPosition(1000, 500);
	}

	if (state == GameStates::GameLose)
	{
		string2 = "You Lost! \n It took you ";
		text2.setCharacterSize(50);
		text2.setFillColor(sf::Color::Red);
		text2.setFont(font);
		text2.setString(string2);
		text2.setPosition(1000, 300);
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Draw method 
//////////////////////////////////////////////////////////////////////////////////
void GameOver::Draw(sf::RenderWindow &window)
{
	window.draw(sprite);
	window.draw(sprite2);
	window.draw(text);
	window.draw(text2);
	window.draw(timerText);
}

//////////////////////////////////////////////////////////////////////////////////
// Get the over all time taken method 
//////////////////////////////////////////////////////////////////////////////////
void GameOver::OverAllTime(int timer)
{
	time += timer;
	time /= 60;
}