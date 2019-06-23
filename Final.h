#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Definitions.h"
class Final
{
public:
	Final(GameDataRef data);

	void Draw();
	void UpddateScore(int score);

private:
	GameDataRef _data;
	sf::Font font;
	sf::Text _scoreText;
	sf::Text _wordScore;
};

