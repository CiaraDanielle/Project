#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
class Player
{
public:
	Player();
	~Player();
	void KeyboardInput();
	void Update(sf::RenderWindow *window);
	void Draw(sf::RenderWindow *window, GameStates state);
	float GetPos();
	sf::Sprite Rect();
	float X();
	float Y();  
	void Reset(); 
	sf::Clock clock;
	void Pos(int x);
	float updateSpeed = 4.9f; 
	int textureCount = 1;
	int colourCount = 0;
	void SetPosition(int x, int y);
	void textCount(int x);
	void ColourCount(int x);
	void SetText();
	void SetColour(); 
	sf::Texture texture[5];
	bool isMoving = false;
	double GROUNDPOS = 720;

private: 
	float Maxheight = 0;
	float force = 7;
	//sf::RectangleShape shape;
	float preHeight = 0;
	float preTime = 0;
	float actualTime = 0;
	float actualHeight = 0;
	float actualDistance = 0;
	float preDistance = 0;
	float preTimeX = 0;
	float actualTimeX = 0;
	sf::String heightString;
	float linePosY = 720;
	float linePosX = 200;
	float timer = 0.0f;

	sf::Vector2f acceleration;
	sf::Vector2f temp;

	sf::Vector2f velocity;
	sf::Vector2f position;

	sf::Vector2f unitVector;
	float pixelToMeters = 100.0f;
	sf::Vector2f gravity;

	sf::RectangleShape line;
	
	int pos = 720;
	float distance;
	int angle = 50;
	int count = 0; 
	const float FPS = 60.0f;
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Sprite shape;
};

