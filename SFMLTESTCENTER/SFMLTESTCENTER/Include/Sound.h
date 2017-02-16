#pragma once
#include "SFML\Audio.hpp"
#include "GameState.h"
class Sound
{
public:
	Sound();
	~Sound();
	void Update();
	//Play the sound methods
	void PlayMenuButton();
	void PlayMenuClick(); 
	void PlayJump();
	void PlayDeath(); 
	void PlayLevel1Sound(); 
	void PlayLevel2Sound();
	void PlayLevel3Sound();
	void PlayMenuBackGround();

	//Stop sounds 
	void StopMenuBackGround();
	void StopLevel1Music();
	void StopLevel2Music(); 
	void StopLevel3Music();
	
	//to mute 
	bool muteMusic = false;
	bool muteSFX = false;

private:

	//Sound Buffers 
	sf::SoundBuffer menuBackGroundBuffer;
	sf::SoundBuffer menuScrollingBuffer;
	sf::SoundBuffer menuConfirmationBuffer;
	sf::SoundBuffer jumpBuffer; 
	sf::SoundBuffer deathBuffer; 
	sf::SoundBuffer level1buffer; 
	sf::SoundBuffer level2buffer;
	sf::SoundBuffer level3buffer;


	//Sounds
	sf::Sound menuBackground;
	sf::Sound menuScrolling;
	sf::Sound menuConfirmation;
	sf::Sound jump;
	sf::Sound death;
	sf::Sound level1;
	sf::Sound level2;
	sf::Sound level3;


	bool menuMusic = false;
	bool menuMusicLoop = false;

	bool playLevel1 = false;
	bool loopLevel1 = true;

	bool playLevel2 = false;
	bool loopLevel2 = true;

	bool playLevel3 = false;
	bool loopLevel3 = true;
};

