#include "Controller.h"


Controller::Controller()
{
	
}

void Controller::Update(GameStates& state, Menu& start, sf::RenderWindow &window, Player &player, Boost &boost, LevelStates &level, Sound &sound)
{
	DPadMoveDown(state, start, sound);
	DPadMoveUp(state, start, sound);
	DPadMoveRight(state, start, sound);
	DPadMoveLeft(state, start, sound);
	APressed(state, player, start, window, sound,level);
	BPressed(state, start, window, sound);
	StartPressed(state,boost,level);
}


void Controller::DPadMoveDown(GameStates &state, Menu& start, Sound &sound)
{
	dPadDown = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -m_val;
	if (dPadDown && !dPadDownPress)
	{
			
		start.MoveDown(state);
		if (state == GameStates::MainMenu || state == GameStates::Customise || state == GameStates::Sound)
		{
			// put in beep sound here
			sound.PlayMenuButton();
		}
		dPadDownPress = dPadDown;
	}

	if (!dPadDown && dPadDownPress)
	{
		dPadDownPress = false;
	}
}

void Controller::DPadMoveUp(GameStates &state, Menu& start, Sound &sound)
{
	dPadUp = sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < m_val;
	if (dPadUp && !dPadUpPress)
	{
		start.MoveUp(state);
		if (state == GameStates::MainMenu || state == GameStates::Customise || state == GameStates::Sound)
		{
			//put in beep sound here
			sound.PlayMenuButton();
		}
		dPadUpPress = dPadUp;
	}

	if (!dPadUp && dPadUpPress)
	{
		dPadUpPress = false;
	}
}

void Controller::DPadMoveRight(GameStates state, Menu& start, Sound &sound)
{
	dPadRight = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < m_val;
	if (dPadRight && !dPadRightPress)
	{ 
		if (state == GameStates::Sound)
		{
			start.MoveRight(state, sound);
		}

		else if (state == GameStates::Sound)
		{
			//sound.changeMusicOption(start.getPressedItem());
		}
		if (state == GameStates::MainMenu || state == GameStates::Customise || state == GameStates::Sound)
		{
			//sound.playEffect();
			sound.PlayMenuButton();
		}
		dPadRightPress = dPadRight;
	}

	if (!dPadRight && dPadRightPress)
	{
		dPadRightPress = false;
	}
}

void Controller::DPadMoveLeft(GameStates state, Menu& start, Sound &sound)
{
	dPadLeft = sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -m_val;
	if (dPadLeft && !dPadleftPress)
	{
		if (state == GameStates::Sound)
		{
			start.MoveLeft(state, sound);
		}

		else if (state == GameStates::Sound)
		{
			//sound.changeVolume(start.getPressedItem());
		}
		if (state == GameStates::MainMenu || state == GameStates::Customise || state == GameStates::Sound)
		{
			sound.PlayMenuButton();
		}
		dPadleftPress = dPadLeft;
	}

	if (!dPadLeft && dPadleftPress)
	{
		dPadleftPress = false;
	}
}


void Controller::APressed(GameStates& state, Player &player,Menu& start, sf::RenderWindow& window, Sound &sound, LevelStates &level)
{
	a = sf::Joystick::isButtonPressed(0, 0);

	if (a && !aPressed)
	{


		if (state == GameStates::MainMenu)
		{
			switch (start.getPressedItem())
			{
			case 0:
				state = GameStates::Play;
				//start.CheckMenuState(window.getSize().x, window.getSize().y, state);
				if (level == LevelStates::Level1)
				{
					sound.PlayLevel1Sound();
				}
				if (level == LevelStates::Level2)
				{
					sound.PlayLevel2Sound();
				}
				if (level == LevelStates::Level3)
				{
					sound.PlayLevel3Sound();
				}
				sound.PlayMenuClick();
				sound.StopMenuBackGround();
				break;
			case 1:
				state = GameStates::Customise;
				start.CheckMenuState(window.getSize().x, window.getSize().y, state);
				break;
			case 2:
				state = GameStates::Sound;
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
				sound.PlayJump();
			}
			else if(player.switchGravity == true && player.isMoving == false)
			{
				player.GravityJump();
				sound.PlayJump();
			}
		}

		if (state != GameStates::Play)
		{
			sound.PlayMenuClick();
		}
		aPressed = a;
	}

	if (!a && aPressed)
	{
		aPressed = false;
	}

}

void Controller::BPressed(GameStates& state, Menu& start, sf::RenderWindow& window, Sound &sound)
{
	b = sf::Joystick::isButtonPressed(0, 1);

	if (b && !bPressed)
	{
		if (state == GameStates::Play)
		{
			state = GameStates::MainMenu;
			start.CheckMenuState(window.getSize().x, window.getSize().y, state);
			sound.PlayMenuClick();
			sound.PlayMenuBackGround();
		}

		state = GameStates::MainMenu;
		start.CheckMenuState(window.getSize().x, window.getSize().y, state);
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

