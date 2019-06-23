#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

//Klasa odpowiadaj�ca za stan maszyny, gdzie pojawia si� notka o pszczo�ach.

class BeeState : public State
{
public:
	BeeState(GameDataRef data);
	void Init();
	void HandleInput();
	void Draw(float dt);
private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _playAgainButton;
	sf::Sprite _beeNormal;
	sf::Sprite _beeTurn;
};
