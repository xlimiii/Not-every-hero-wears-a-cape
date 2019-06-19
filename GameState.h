#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Brick.h"
#include "Border.h"
#include "Bee.h"
#include "Coin.h"
#include "Collision.h"
	class GameState :public State {
	public:
		GameState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;
		sf::Clock _clock;
		sf::Sprite _background;
		Brick* brick;
		Flower* flower;
		Border* border;
		Bee* bee;
		Collision collision;
		sf::Clock clock;
		int _gameState;
		int _score=0;
	};