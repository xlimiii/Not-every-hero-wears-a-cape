#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include<vector>
#include "Definitions.h"
#include "Flower.h"

	class Brick {
	public:
		Brick(GameDataRef data);
		void CreateBricks();
		void DrawBricks();
		void MoveBrick(float dt);
		int RandomiseYBrickCoordinate();
		const std::vector<sf::Sprite>& getSprites() const;
	private:
		GameDataRef _data;
		std::vector<sf::Sprite> brickSprites;
		int _borderHeight;
		int _brickHeight;
		int _brickYCoordinate;
	};