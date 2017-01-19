#include <SFML\Graphics.hpp>
#include "Include\GameState.h"

class Button
{
public:
	
	Button(GameStates state);
	~Button();
	void setButtonSize(GameStates state);
	void setButtonPositions(float width, float height, GameStates state);
	void draw(sf::RenderWindow &window, GameStates state);
	void ButtonScaleUp(GameStates state);
	void ButtonScaleDown(GameStates state);
	void setButtonScaleUp(GameStates state);
	void setButtonScaleDown(GameStates state);
	int m_selectedButtonIndex;

private:

	sf::Texture m_buttonTexture;
	sf::Sprite buttons[4];
};


