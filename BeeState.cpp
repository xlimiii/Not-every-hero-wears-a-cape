#include "BeeState.h"
#include "Definitions.h"
#include <iostream>
#include "MenuState.h"

BeeState::BeeState(GameDataRef data) : _data(data) {}

void BeeState::Init()
{
	_data->pictures.LoadTexture("Educational Note Background", EDUCATIONAL_NOTE_FILEPATH);
	_data->pictures.LoadTexture("Play Again", PLAY_AGAIN_BUTTON_FILEPATH);
	_data->pictures.LoadTexture("Bee 2", BEE_2_FILEPATH);
	_data->pictures.LoadTexture("Bee Turn", BEE_TURN_FILEPATH);

	_background.setTexture(this->_data->pictures.GetTexture("Educational Note Background"));
	_playAgainButton.setTexture(this->_data->pictures.GetTexture("Play Again"));
	_beeNormal.setTexture(this->_data->pictures.GetTexture("Bee 2"));
	_beeTurn.setTexture(this->_data->pictures.GetTexture("Bee Turn"));
	_playAgainButton.setPosition((SCREEN_WIDTH / 2) - (_playAgainButton.getGlobalBounds().width / 2), ((SCREEN_HEIGHT / 2) + (_playAgainButton.getGlobalBounds().height / 0.65)));
	_beeNormal.setPosition((SCREEN_WIDTH / 2) - (_beeNormal.getGlobalBounds().width / 0.3), ((SCREEN_HEIGHT / 2) + (_beeNormal.getGlobalBounds().height / 0.35)));
	_beeTurn.setPosition((SCREEN_WIDTH / 2) + (_beeTurn.getGlobalBounds().width / 0.425), ((SCREEN_HEIGHT / 2) + (_beeTurn.getGlobalBounds().height / 0.35)));
}
void BeeState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}
		if (_data->input.IsSpriteClicked(_playAgainButton, sf::Mouse::Left, _data->window))
			//po nacisnieciu na przycisk PLAY AGAIN, program zmienia stan, przechodzi do gry
		{
			_data->machine.AddState(StateRef(new MenuState(_data)), true);
		}
	}
}
void BeeState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_playAgainButton);
	_data->window.draw(_beeNormal);
	_data->window.draw(_beeTurn);
	_data->window.display();
}