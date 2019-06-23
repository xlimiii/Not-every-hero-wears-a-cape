#include "Hud.h"
#include <string>

Hud::Hud(GameDataRef data) : _data(data) {
	font.loadFromFile(SCORE_FONT);
	_scoreText.setFont(font);
	_scoreText.setString("0");
	_scoreText.setCharacterSize(30);

	_scoreText.setFillColor(sf::Color::Red);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2.f, _scoreText.getGlobalBounds().height / 2.f);
	_scoreText.setPosition(_data->window.getSize().x / 1.07, _data->window.getSize().y / 13);

	_wordScore.setFont(font);
	_wordScore.setString("SCORE: ");
	_wordScore.setFillColor(sf::Color::Black);
	_wordScore.setOrigin(_wordScore.getGlobalBounds().width / 2.f, _wordScore.getGlobalBounds().height / 2.f);
	_wordScore.setPosition(_data->window.getSize().x / 1.2, _data->window.getSize().y / 13);
}

void Hud::Draw()
{
	_data->window.draw(_scoreText);
	_data->window.draw(_wordScore);
}
void Hud::UpddateScore(int score) {
	_scoreText.setString(std::to_string(score));
}
