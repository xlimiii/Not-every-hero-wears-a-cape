#include <sstream>
#include "Definitions.h"
#include "GameOverState.h"
#include "BeeState.h"
#include <iostream>
#include "GameState.h"



GameOverState::GameOverState(GameDataRef data, int score) : _data(data), _score(score)
{

}
void GameOverState::Init()
{
	std::cout << "WYNIK TO: " << _score;
	_data->pictures.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
	_data->pictures.LoadTexture("Click To Find Out About Bees", PROTECTING_BEES_FILEPATH);
	_background.setTexture(this->_data->pictures.GetTexture("Game Over Background"));

	_clickToProtect.setTexture(this->_data->pictures.GetTexture("Click To Find Out About Bees"));
	_clickToProtect.setPosition((SCREEN_WIDTH / 2) - (_clickToProtect.getGlobalBounds().width / 2), 
		((SCREEN_HEIGHT / 2) + (_clickToProtect.getGlobalBounds().height / 1.45)));
	final = new Final(_data);
	final->UpddateScore(_score);
}
void GameOverState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}
		if (_data->input.IsSpriteClicked(_clickToProtect, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new BeeState(_data)), true);
		}


	}
}
void GameOverState::Update(float dt)
{

}
void GameOverState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_clickToProtect);
	final->Draw();
	_data->window.display();
}
