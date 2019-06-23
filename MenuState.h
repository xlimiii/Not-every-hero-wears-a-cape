#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

//Klasa odpowiadaj�ca za stan maszyny, gdy wy�wietla si� Menu.

class MenuState : public State
{
public:
	MenuState(GameDataRef data);
	void Init();
	void HandleInput();
	void Draw(float dt);
private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _title;
	sf::Sprite _playButton;

	sf::Sprite _findOut;
	sf::Sprite _hereButton;
};