#include "Map.h"



Map::Map() : m_ml(""), m_ml2(""), m_ml3("")
{
	m_ml.UpdateQuadTree(sf::FloatRect(0, 0, 1400, 800));
	m_ml.Load("Level1.tmx");
	m_level = LevelStates::Level1;
}


Map::~Map()
{
}


void Map::Update(Player &player, GameStates &state)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
		m_level = LevelStates::Level3;
		CheckState();
	}
	const std::vector<tmx::MapLayer>& layers = m_ml.GetLayers();


	if (m_level == LevelStates::Level1)
	{
		CollisionCheckLevel1(player, state);
	}
	if (m_level == LevelStates::Level2)
	{
		CollisionCheckLevel2(player, state);
	}

	if (m_level == LevelStates::Level3)
	{
		CollisionCheckLevel3(player, state);
	}
}

void Map::CheckState()
{
	if (m_level == LevelStates::Level1)
	{
		m_ml.Load("Level1.tmx");
	}

	if (m_level == LevelStates::Level2)
	{
		m_ml2.Load("Level2.tmx");
	}
	if (m_level == LevelStates::Level3)
	{
		m_ml3.Load("Level3.tmx");
	}
}

void Map::Draw(sf::RenderWindow &window)
{
	if (m_level == LevelStates::Level1)
	{
		window.draw(m_ml);
	}
	if (m_level == LevelStates::Level2)
	{
		window.draw(m_ml2);
	}
	if (m_level == LevelStates::Level3)
	{
		window.draw(m_ml3);
	}
}

void Map::CollisionCheckLevel1(Player &player, GameStates &state)
{
	int count = 0;
	bool collision = false;
	for (auto layer = m_ml.GetLayers().begin(); layer != m_ml.GetLayers().end(); ++layer)
	{
		if (m_level == LevelStates::Level2)
		{
			break;
		}
		if (layer->name == "Triangle Objects")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect triangleRect = object->GetAABB();
				collision = triangleRect.intersects(player.Rect().getGlobalBounds());
				if (collision == true)
				{
					collision = false;
					player.Reset();
				}
			}
		}
		bool secondCollision = false;
		if (layer->name == "Square Objects")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				secondCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (secondCollision == true)
				{
					secondCollision = false;
					player.Reset();
				}
			}
		}

		bool fourthCollision = false;
		if (layer->name == "Finish Line Object")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				fourthCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (fourthCollision == true)
				{
					player.Reset();
					fourthCollision = false;
					m_level = LevelStates::Level2;
					CheckState();
				}
			}
		}

		
	}
	bool thirdCollision = false;
	for (auto layer = m_ml.GetLayers().begin(); layer != m_ml.GetLayers().end(); ++layer)
	{
		if (m_level == LevelStates::Level2)
		{
			break;
		}
		if (layer->name == "Gravity")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				thirdCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (thirdCollision == true)
				{
					float y = squareRect.height;
					player.GROUNDPOS = squareRect.top;
					if (player.X() < object->GetPosition().x + squareRect.width)
					{
						player.isMoving = false;
						count = 0;
					}
				}
			}
		}

		else if (player.GROUNDPOS < 720 && thirdCollision == false && count == 0)
		{
			player.GROUNDPOS = 720;
			player.isMoving = true;
			count = 1;
		}
	}
}

void Map::CollisionCheckLevel2(Player &player, GameStates &state)
{
	int count = 0;
	bool collision = false;
	for (auto layer = m_ml2.GetLayers().begin(); layer != m_ml2.GetLayers().end(); ++layer)
	{
		if (layer->name == "Triangle Objects")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect triangleRect = object->GetAABB();
				collision = triangleRect.intersects(player.Rect().getGlobalBounds());
				if (collision == true)
				{
					collision = false;
					player.Reset();
				}
			}
		}
		bool secondCollision = false;
		if (layer->name == "Square Objects")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				secondCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (secondCollision == true)
				{
					secondCollision = false;
					player.Reset();
				}
			}
		}

		bool fourthCollision = false;
		if (layer->name == "Finish Line Object")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				fourthCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (fourthCollision == true)
				{
					player.Reset();
					fourthCollision = false;
					m_level = LevelStates::Level3;
					CheckState();
				}
			}
		}
	}
	bool thirdCollision = false;
	for (auto layer = m_ml2.GetLayers().begin(); layer != m_ml2.GetLayers().end(); ++layer)
	{
		if (layer->name == "Gravity")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				thirdCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (thirdCollision == true)
				{
					float y = squareRect.height;
					player.GROUNDPOS = squareRect.top;
					if (player.X() < object->GetPosition().x + squareRect.width)
					{
						player.isMoving = false;
						count = 0;
					}
				}
			}
		}

		else if (player.GROUNDPOS < 720 && thirdCollision == false && count == 0)
		{
			player.GROUNDPOS = 720;
			player.isMoving = true;
			count = 1;
		}
	}
}

void Map::CollisionCheckLevel3(Player &player, GameStates &state)
{
	int count = 0;
	bool collision = false;
	for (auto layer = m_ml3.GetLayers().begin(); layer != m_ml3.GetLayers().end(); ++layer)
	{
		if (layer->name == "Triangle Objects")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect triangleRect = object->GetAABB();
				collision = triangleRect.intersects(player.Rect().getGlobalBounds());
				if (collision == true)
				{
					collision = false;
					player.Reset();
				}
			}
		}
		bool secondCollision = false;
		if (layer->name == "Square Objects")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				secondCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (secondCollision == true)
				{
					secondCollision = false;
					player.Reset();
				}
			}
		}

		bool fourthCollision = false;
		if (layer->name == "Finish Line Object")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				fourthCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (fourthCollision == true)
				{
					state = GameStates::GameWin;
				}
			}
		}

		bool fifthCollison = false;
		if (layer->name == "Gravity Up")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				fifthCollison = squareRect.intersects(player.Rect().getGlobalBounds());
				if (fifthCollison == true)
				{
					player.switchGravity = true;
					player.isMoving = true;
				}
			}
		}

		bool sixthCollison = false;
		if (layer->name == "Gravity Down")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				sixthCollison = squareRect.intersects(player.Rect().getGlobalBounds());
				if (sixthCollison == true)
				{
					player.switchGravity = false;
					player.isMoving = true;
				}
			}
		}
	}

	bool thirdCollision = false;
	for (auto layer = m_ml3.GetLayers().begin(); layer != m_ml3.GetLayers().end(); ++layer)
	{
		if (layer->name == "Gravity")
		{
			for (auto object = layer->objects.begin(); object != layer->objects.end(); ++object)
			{
				const sf::FloatRect squareRect = object->GetAABB();
				thirdCollision = squareRect.intersects(player.Rect().getGlobalBounds());
				if (thirdCollision == true)
				{
					float y = squareRect.height;
					player.GROUNDPOS = squareRect.top;
					if (player.X() < object->GetPosition().x + squareRect.width)
					{
						player.isMoving = false;
						count = 0;
					}
				}
			}
		}

		else if (player.GROUNDPOS < 720 && thirdCollision == false && count == 0)
		{
			player.GROUNDPOS = 720;
			player.isMoving = true;
			count = 1;
		}
	}
}