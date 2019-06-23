#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Final.h"
#include "GameState.h"

//Klasa odpowiadaj¹ca za stan maszyny, kiedy gracz przegra.

class GameOverState :public State 
{
public:
	GameOverState(GameDataRef data, int score);
	void Init();
	void HandleInput();
	void Draw(float dt);
private:
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _background;
	Final* final;
	sf::Sprite _clickToProtect;
	int _score;
};