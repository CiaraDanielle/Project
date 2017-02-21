#include "Sound.h"


//////////////////////////////////////////////////////////////////////////////////
// Constructor 
//////////////////////////////////////////////////////////////////////////////////
Sound::Sound()
{

	if (!menuBackGroundBuffer.loadFromFile("MainMenumusic.wav"))
	{
		//
	}

	menuBackground.setBuffer(menuBackGroundBuffer);
	menuBackground.setVolume(100);
	menuBackground.play();

	if (!menuScrollingBuffer.loadFromFile("MenuClick.wav"))
	{
		//
	}
	menuScrolling.setBuffer(menuScrollingBuffer);
	menuScrolling.setVolume(100);

	if (!menuConfirmationBuffer.loadFromFile("enterbutton.wav"))
	{
		//
	}
	menuConfirmation.setBuffer(menuConfirmationBuffer);
	menuConfirmation.setVolume(100);

	if (!jumpBuffer.loadFromFile("jump.wav"))
	{
		//
	}
	jump.setBuffer(jumpBuffer);
	jump.setVolume(100);

	if (!deathBuffer.loadFromFile("deathsound.wav"))
	{
		//
	}
	death.setBuffer(deathBuffer);
	death.setVolume(100);

	if (!level1buffer.loadFromFile("level1sound.wav"))
	{
		//
	}
	level1.setBuffer(level1buffer);
	level1.setVolume(50);

	if (!level2buffer.loadFromFile("level2sound.wav"))
	{
		//
	}
	level2.setBuffer(level2buffer);
	level2.setVolume(50);

	if (!level3buffer.loadFromFile("level3sound.wav"))
	{
		//
	}
	level3.setBuffer(level3buffer);
	level3.setVolume(50);
}


//////////////////////////////////////////////////////////////////////////////////
// Play the sound when scrolling through the menu 
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayMenuButton()
{
	if (muteSFX == false)
	{
		menuScrolling.play();
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play sound when clicking on an option in the menu 
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayMenuClick()
{
	if (muteSFX == false)
	{
		menuConfirmation.play();
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play a sound when the player jumps
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayJump()
{
	if (muteSFX == false)
	{
		jump.play();
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play a sound when the player dies 
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayDeath()
{
	if (muteSFX == false)
	{
		death.play();
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play music in the menu 
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayMenuBackGround()
{
	if (muteMusic == false)
	{
		menuMusic = true;
		if (menuMusic == true && menuMusicLoop == false)
		{
			menuBackground.play();
			menuBackground.setLoop(true);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play music in level 1 
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayLevel1Sound()
{
	if (muteMusic == false)
	{
		playLevel1 = true;
		if (playLevel1 == true && loopLevel1 == true)
		{
			level1.play();
			level1.setLoop(true);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play music in level 2
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayLevel2Sound()
{
	if (muteMusic == false)
	{
		playLevel2 = true;
		if (playLevel2 == true && loopLevel2 == true)
		{
			level2.play();
			level2.setLoop(true);
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
// Play music in level 1 
//////////////////////////////////////////////////////////////////////////////////
void Sound::PlayLevel3Sound()
{
	if (muteMusic == false)
	{
		playLevel3 = true;
		if (playLevel3 == true && loopLevel3 == true)
		{
			level3.play();
			level3.setLoop(true);
		}
	}
}


void Sound::StopMenuBackGround()
{
	menuBackground.pause();
}


void Sound::StopLevel1Music()
{
	level1.pause();
}

void Sound::StopLevel2Music()
{
	level2.pause();
}

void Sound::StopLevel3Music()
{
	level3.pause();
}
