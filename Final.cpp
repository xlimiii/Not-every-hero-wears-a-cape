#include "Final.h"
#include <string>

Final::Final(GameDataRef data) : _data(data) {
	font.loadFromFile(SCORE_FONT);
	_scoreText.setFont(font);
	_scoreText.setString("0");
	_scoreText.setCharacterSize(70);

	_scoreText.setFillColor(sf::Color::Black);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2.f, _scoreText.getGlobalBounds().height / 2.f);
	_scoreText.setPosition(_data->window.getSize().x / 1.5, _data->window.getSize().y / 2);
}

void Final::Draw()
{
	_data->window.draw(_scoreText);
	_data->window.draw(_wordScore);
}
void Final::UpddateScore(int score) {
	_scoreText.setString(std::to_string(score));
}
