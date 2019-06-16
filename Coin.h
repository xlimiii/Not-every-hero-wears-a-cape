#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"
class Coin {
public:
	Coin(GameDataRef data);
	void DrawCoin();
private:
	GameDataRef _data;
	sf::Sprite _coinSprite;
};