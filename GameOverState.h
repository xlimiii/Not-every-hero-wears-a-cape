#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Final.h"
#include "GameState.h"
class GameOverState :public State {
public:
	GameOverState(GameDataRef data, int score);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
private:
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _background;
	Final* final;
	sf::Sprite _clickToProtect;
	int _score;
};
