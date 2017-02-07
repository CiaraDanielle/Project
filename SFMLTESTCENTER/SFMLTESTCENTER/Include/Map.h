#pragma once
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "LevelState.h"
class Map
{
private:
	Map(Map const & m);
	//Map & operator=(Map const & m);
	tmx::MapLoader m_ml;
	tmx::MapLoader m_ml2;
	tmx::MapLoader m_ml3;
	LevelStates m_level;

public:
	Map();
	~Map();
	void Draw(sf::RenderWindow &window); 
	void Update(Player &player, GameStates &state);
	void CollisionCheckLevel1(Player &player, GameStates &state);
	void CollisionCheckLevel2(Player &player, GameStates &state);
	void CollisionCheckLevel3(Player &player, GameStates &state);
	void CheckState();
};

