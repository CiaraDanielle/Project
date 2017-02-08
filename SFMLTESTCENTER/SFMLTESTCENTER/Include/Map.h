#pragma once
#include "Include\GameState.h"
#include "Include\MapLoader.h"
#include "Include\MapObject.h"
#include "SFML\Graphics.hpp"
#include "Player.h"
#include "LevelState.h"
#include "AttemptsCount.h"
#include "CountDown.h"
class Map
{
private:
	Map(Map const & m);
	//Map & operator=(Map const & m);
	tmx::MapLoader m_ml;
	tmx::MapLoader m_ml2;
	tmx::MapLoader m_ml3;

public:
	Map();
	~Map();
	void Draw(sf::RenderWindow &window, LevelStates &level);
	void Update(Player &player, GameStates &level, LevelStates &state, AttemptsCount &count, CountDown &timer);
	void CollisionCheckLevel1(Player &player, GameStates &state, LevelStates &level, AttemptsCount &count, CountDown &timer);
	void CollisionCheckLevel2(Player &player, GameStates &state, LevelStates &level, AttemptsCount &count, CountDown &timer);
	void CollisionCheckLevel3(Player &player, GameStates &state, LevelStates &level, AttemptsCount &count, CountDown &timer);
	void CheckState(LevelStates &level);
};

