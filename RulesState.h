#pragma once
#include "State.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

//Klasa odpowiadaj¹ca za stan maszyny, gdy wyœwietlaj¹ siê zasady.

class RulesState : public State
{
public:
	RulesState(GameDataRef data);
	void Init();
	void HandleInput();
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _returnButton;
};
