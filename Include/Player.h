#pragma once
#include <SFML/Graphics.hpp>
class Player
{
public:
	Player();
	~Player();
	void KeyboardInput(sf::Event &event, sf::RenderWindow &window);
	void Update(sf::RenderWindow &window);
	void Draw(sf::RenderWindow &window);
	void UpdatePosition(); 
	void ResetTime(); 

	sf::Clock clock;


private: 
	float Maxheight = 0;
	bool isMoving = false;
	int force = 10;
	sf::RectangleShape shape;
	float preHeight = 0;
	float preTime = 0;
	float actualTime = 0;
	float actualHeight = 0;
	float actualDistance = 0;
	float preDistance = 0;
	float preTimeX = 0;
	float actualTimeX = 0;
	sf::String heightString;
	float linePosY = 700;
	float linePosX = 200;
	float timer = 0.0f;
	bool isMovingX = false;
	float friction = 2.0f;
	sf::Vector2f acceleration;
	sf::Vector2f temp;

	sf::Vector2f velocity;
	sf::Vector2f position;

	sf::Vector2f unitVector;
	float pixelToMeters = 30.0f;
	sf::Vector2f gravity;

	sf::RectangleShape line;
	

	sf::Text text;

	float distance;
	int angle = 50;
	sf::Font font;
	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

};

