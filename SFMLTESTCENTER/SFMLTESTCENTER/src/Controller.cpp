#include "Controller.h"


Controller::Controller()
{
	
}

void Controller::Update(GameStates& state, Menu& start, sf::RenderWindow &window, Player &player, Boost &boost, LevelStates &level)
{
	DPadMoveDown(state, start);
	DPadMoveUp(state, start);
	DPadMoveRight(state, start);
	DPadMoveLeft(state, start);
	APressed(state, player, start, window);
	BPressed(state, start, window);
	StartPressed(state,boost,level);
}


void Controller::DPadMoveDown(GameStates &state, Menu& start)
{
	dPadDown = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -m_val;
	if (dPadDown && !dPadDownPress)
	{
			
		start.MoveDown(state);
		if (state == GameStates::MainMenu || state == GameStates::Pause || state == GameStates::GameOptions || state == GameStates::GameOptions)
		{
			// put in beep sound here
		}
		dPadDownPress = dPadDown;
	}

	if (!dPadDown && dPadDownPress)
	{
		dPadDownPress = false;
	}
}

void Controller::DPadMoveUp(GameStates &state, Menu& start)
{
	dPadUp = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < m_val;
	if (dPadUp && !dPadUpPress)
	{
		start.MoveUp(state);
		if (state == GameStates::MainMenu || state == GameStates::Pause || state == GameStates::GameOptions || state == GameStates::GameOptions)
		{
			//put in beep sound here
		}
		dPadUpPress = dPadUp;
	}

	if (!dPadUp && dPadUpPress)
	{
		dPadUpPress = false;
	}
}

void Controller::DPadMoveRight(GameStates state, Menu& start)
{
	dPadRight = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < m_val;
	if (dPadRight && !dPadRightPress)
	{ 
		if (state == GameStates::GameOptions)
		{
			//manager.changeOptionRight(start.getPressedItem());
		}

		else if (state == GameStates::GameOptions)
		{
			//sound.changeMusicOption(start.getPressedItem());
		}
		if (state == GameStates::MainMenu || state == GameStates::Pause || state == GameStates::GameOptions || state == GameStates::GameOptions)
		{
			//sound.playEffect();
		}
		dPadRightPress = dPadRight;
	}

	if (!dPadRight && dPadRightPress)
	{
		dPadRightPress = false;
	}
}

void Controller::DPadMoveLeft(GameStates state, Menu& start)
{
	dPadLeft = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -m_val;
	if (dPadLeft && !dPadleftPress)
	{
		if (state == GameStates::GameOptions)
		{
			//manager.changeOptionLeft(start.getPressedItem());
		}

		else if (state == GameStates::GameOptions)
		{
			//sound.changeVolume(start.getPressedItem());
		}
		if (state == GameStates::MainMenu || state == GameStates::Pause || state == GameStates::GameOptions || state == GameStates::GameOptions)
		{
			//sound.playEffect();
		}
		dPadleftPress = dPadLeft;
	}

	if (!dPadLeft && dPadleftPress)
	{
		dPadleftPress = false;
	}
}


void Controller::APressed(GameStates& state, Player &player,Menu& start, sf::RenderWindow& window)
{
	a = sf::Joystick::isButtonPressed(0, 0);

	if (a && !aPressed)
	{

		if (state == GameStates::Pause)
		{
			switch (start.getPressedItem())
			{
			case 0:
				state = GameStates::Play;
				break;
			case 1:
				return window.close();
				break;
			}
		}
		if (state == GameStates::MainMenu)
		{
			switch (start.getPressedItem())
			{
			case 0:
				state = GameStates::Play;
				//start.CheckMenuState(window.getSize().x, window.getSize().y, state);
				break;
			case 1:
				state = GameStates::Customise;
				start.CheckMenuState(window.getSize().x, window.getSize().y, state);
				break;
			case 2:
				state = GameStates::GameOptions;
				start.CheckMenuState(window.getSize().x, window.getSize().y, state);
				break;
			case 3:
				return window.close();
				break;
			}
		}

		if (state == GameStates::Play)
		{
			if (player.switchGravity == false && player.isMoving == false)
			{
				player.Jump();
			}
			else if(player.switchGravity == true && player.isMoving == false)
			{
				player.GravityJump();
			}
		}
		aPressed = a;
	}

	if (!a && aPressed)
	{
		aPressed = false;
	}

}

void Controller::BPressed(GameStates& state, Menu& start, sf::RenderWindow& window)
{
	b = sf::Joystick::isButtonPressed(0, 1);

	if (b && !bPressed)
	{
		if (state == GameStates::Customise || state == GameStates::GameOptions || state == GameStates::Play)
		{
			state = GameStates::MainMenu;
			start.CheckMenuState(window.getSize().x, window.getSize().y, state);
		}

		bPressed = b;
	}

	else if (!b && bPressed)
	{
		bPressed = false; 
	}
}

void Controller::StartPressed(GameStates& state, Boost &boost, LevelStates &level)
{
	start = sf::Joystick::isButtonPressed(0, 7);

	if (start && !startPressed)
	{
		if (state == GameStates::Play && level != LevelStates::Level1)
		{
			boost.CanBoost();
		}

		startPressed = start;
	}

	else if (!start && startPressed)
	{
		startPressed = false;
	}


}

