#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Brick.h"
#include "Border.h"
#include "Bee.h"
#include "Flower.h"
#include "Collision.h"

#include "Hud.h"

class GameState :public State {
public:
	GameState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);
	int _score;
	int k = 0;

private:
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _background;
	Brick* brick;
	Flower* flower;
	std::vector<Flower*> flowers;
	std::vector<sf::Sprite> FLOWER;
	Border* border;
	Bee* bee;
	Collision collision;
	sf::Clock clock;
	Hud* hud;

};
