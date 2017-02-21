#pragma once
#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Sound.h"
class Player
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Default Constructor
	///
	/// \param None
	////////////////////////////////////////////////////////////
	Player();

	////////////////////////////////////////////////////////////
	/// \brief Destructor
	///
	/// \param None
	////////////////////////////////////////////////////////////
	~Player();

	////////////////////////////////////////////////////////////
	/// \brief Handling keyboard input
	///
	/// \param Sound to play a sound when the player jumps
	////////////////////////////////////////////////////////////
	void KeyboardInput(Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Update the players position and also update via gravity
	///
	/// \param The render window and sound 
	////////////////////////////////////////////////////////////
	void Update(sf::RenderWindow *window, Sound &sound);

	////////////////////////////////////////////////////////////
	/// \brief Draw the player 
	///
	/// \param Render window and the game state 
	////////////////////////////////////////////////////////////
	void Draw(sf::RenderWindow *window, GameStates state);

	////////////////////////////////////////////////////////////
	/// \brief Updating variables to jump
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void Jump();

	////////////////////////////////////////////////////////////
	/// \brief Updating variables to jump upside down for when gravity switch is enabled
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void GravityJump();

	////////////////////////////////////////////////////////////
	/// \brief Get the players position
	///
	/// \param None
	////////////////////////////////////////////////////////////
	float GetPos();

	////////////////////////////////////////////////////////////
	/// \brief Return a sprite attributes i.e. width, height.. etc
	///
	/// \param None
	////////////////////////////////////////////////////////////
	sf::Sprite Rect();

	////////////////////////////////////////////////////////////
	/// \brief Get the players x position
	///
	/// \param None
	////////////////////////////////////////////////////////////
	float X();

	////////////////////////////////////////////////////////////
	/// \brief Get the players y position
	///
	/// \param None
	////////////////////////////////////////////////////////////
	float Y();

	////////////////////////////////////////////////////////////
	/// \brief Reset the players position
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void Reset(); 

	/// A clock to update the time for gravity 
	sf::Clock clock;

	////////////////////////////////////////////////////////////
	/// \brief Set the ground position to a certain place
	///
	/// \param int x 
	////////////////////////////////////////////////////////////
	void Pos(int x);

	///brief update speed on the x axis for the player
	float updateSpeed = 4.9f; 

	/// the count for textures 
	int textureCount = 1;

	///count for the colours 
	int colourCount = 0;

	////////////////////////////////////////////////////////////
	/// \brief Set the players position 
	///
	/// \param int x, and y 
	////////////////////////////////////////////////////////////
	void SetPosition(int x, int y);

	////////////////////////////////////////////////////////////
	/// \brief Texture count, so set the players texture to a certain one
	///
	/// \param an int 
	////////////////////////////////////////////////////////////
	void textCount(int x);

	////////////////////////////////////////////////////////////
	/// \brief Set the players colour to a certain one 
	///
	/// \param an int 
	////////////////////////////////////////////////////////////
	void ColourCount(int x);

	////////////////////////////////////////////////////////////
	/// \brief Set the texture to a certain one 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void SetText();

	////////////////////////////////////////////////////////////
	/// \brief Set the colour to a certain one 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void SetColour(); 

	/// an array of textures for the player 
	sf::Texture texture[5];

	/// can the player jump so they can't double jump
	bool isMoving = false;

	/// The players ground position 
	double pos = 720;

	/// Is gravity switch enabled 
	bool switchGravity = false;

private: 
	///The max height the player can reach 
	float Maxheight = 0;

	///The force used to jump 
	float force = 7;

	/// The actual time it takes to jump 
	float actualTime = 0;

	///The actual height it took to jump
	float actualHeight = 0;

	/// the actual distance the player moved on the x axis whilst jumping 
	float actualDistance = 0;

	/// The line for the ground (not drawn)
	float linePosY = 720;

	/// The line for the ground (not drawn)
	float linePosX = 200;

	/// The velocity the player uses to jump 
	sf::Vector2f velocity;

	/// The players position 
	sf::Vector2f position;

	/// A number to move the player faste whilst jumping 
	float pixelToMeters = 100.0f;

	/// A vector contain gravity 
	sf::Vector2f gravity;

	/// The ground position of the player 
	int groundpos = 720;

	/// the distance moved
	float distance;

	/// The angle to jump at 
	int angle = 50;

	/// Update it at a certain frame per seconds
	const float FPS = 60.0f;

	/// Time used to jump 
	const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	/// The time it took since the last update 
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	/// The sprite used for the player 
	sf::Sprite shape;

};

