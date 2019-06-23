#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"
#include "Brick.h"

class Flower {
public:
	Flower(GameDataRef data);
	void CreateFlower();
	void DrawFlower();
	void MoveFlower(float dt);
	int RandomiseYFlowerCoordinate();
	bool DoIntersect(int, int);
	sf::Sprite getSprite();
	std::vector<Flower*> flowers;
	
	
private:
	GameDataRef _data;
	sf::Sprite _flowerSprite;
	int _borderHeight;
	int _flowerHeight;
	int _flowerYCoordinate;
	Flower* flower;

};