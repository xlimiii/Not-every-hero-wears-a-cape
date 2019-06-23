#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Definitions.h"
class Hud
{
public:
	Hud(GameDataRef data);

	void Draw();
	void UpddateScore(int score);
	//void DrawWordScore(std::string word);

private:
	GameDataRef _data;
	sf::Font font;
	sf::Text _scoreText;
	sf::Text _wordScore;
};
