#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"
#include "Brick.h"
class Flower{
public:
	Flower(GameDataRef data);
	void CreateFlower();
	void DrawFlower();
	void MoveFlower(float dt);
	int RandomiseYFlowerCoordinate();
	bool DoIntersect(int, int);
	std::vector<sf::Sprite>& getSprites();
private:
	GameDataRef _data;
	std::vector<sf::Sprite> flowerSprites;
	int _borderHeight;
	int _flowerHeight;
	int _flowerYCoordinate;
};