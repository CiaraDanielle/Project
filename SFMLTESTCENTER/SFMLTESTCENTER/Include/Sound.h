#pragma once
#include "SFML\Audio.hpp"
#include "GameState.h"
class Sound
{
public:
	////////////////////////////////////////////////////////////
	/// \brief Default Constructor
	///
	/// \param None
	////////////////////////////////////////////////////////////
	Sound();
	
	////////////////////////////////////////////////////////////
	/// \brief Play the menu button so when moving through the menu it plays a sound 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayMenuButton();

	////////////////////////////////////////////////////////////
	/// \brief Play a sound when you click into a button on the menu
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayMenuClick(); 

	////////////////////////////////////////////////////////////
	/// \brief Play a sound when the player jumps
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayJump();

	////////////////////////////////////////////////////////////
	/// \brief Play a sound when the player dies
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayDeath(); 

	////////////////////////////////////////////////////////////
	/// \brief Play level 1 song 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayLevel1Sound(); 

	////////////////////////////////////////////////////////////
	/// \brief Play level 2 song
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayLevel2Sound();

	////////////////////////////////////////////////////////////
	/// \brief Play level 3 song 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayLevel3Sound();

	////////////////////////////////////////////////////////////
	/// \brief Play the main menu theme song 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void PlayMenuBackGround();

	////////////////////////////////////////////////////////////
	/// \brief Stop playing the menu theme
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void StopMenuBackGround();

	////////////////////////////////////////////////////////////
	/// \brief Stop level 1 music 
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void StopLevel1Music();

	////////////////////////////////////////////////////////////
	/// \brief Stop level 2 music
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void StopLevel2Music(); 

	////////////////////////////////////////////////////////////
	/// \brief Stop level 3 music
	///
	/// \param None
	////////////////////////////////////////////////////////////
	void StopLevel3Music();
	
	///Bool used to mute the music 
	bool muteMusic = false;

	///Bool used to mute the sound effects e.g. jump
	bool muteSFX = false;

private:

	/// Sound buffer for the background music 
	sf::SoundBuffer menuBackGroundBuffer;

	///Sound buffer for scrolling through the options in the menu 
	sf::SoundBuffer menuScrollingBuffer;

	/// Sound buffer for when clicking into a option in the options 
	sf::SoundBuffer menuConfirmationBuffer;

	/// Sound buffer for jump 
	sf::SoundBuffer jumpBuffer; 

	/// Sound buffer for death 
	sf::SoundBuffer deathBuffer; 

	/// Sound buffer for level 1 music 
	sf::SoundBuffer level1buffer; 

	/// Sound Buffer for level 2 music
	sf::SoundBuffer level2buffer;

	/// Sound buffer for level 3 music 
	sf::SoundBuffer level3buffer;


	/// Sound for the background music 
	sf::Sound menuBackground;

	///Sound for scrolling through the options in the menu 
	sf::Sound menuScrolling;

	/// Sound for when clicking into a option in the options 
	sf::Sound menuConfirmation;

	/// Sound for jump 
	sf::Sound jump;

	/// Sound for death 
	sf::Sound death;

	/// Sound for level 1 music 
	sf::Sound level1;

	/// Sound for level 2 music 
	sf::Sound level2;

	/// Sound for level 3 music 
	sf::Sound level3;

	/// Used to play the music 
	bool menuMusic = false;

	/// bool to set a loop for the music 
	bool menuMusicLoop = false;

	/// bool to play the music 
	bool playLevel1 = false;

	/// bool to set a loop for the music 
	bool loopLevel1 = true;

	/// bool to play the music 
	bool playLevel2 = false;

	/// bool to set a loop for the music 
	bool loopLevel2 = true;

	/// bool to play the music 
	bool playLevel3 = false;

	/// bool to set a loop for the music
	bool loopLevel3 = true;
};

