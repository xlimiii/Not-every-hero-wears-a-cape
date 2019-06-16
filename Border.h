#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
	class Border {
	public:
		Border(GameDataRef data);
		void DrawBorder();
		
		const std::vector < sf::Sprite > &getSprites() const;
	private:
		GameDataRef _data;
		sf::Sprite _borderSprite1;
		sf::Sprite _borderSprite2;
	};
