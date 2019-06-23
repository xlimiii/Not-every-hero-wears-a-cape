#include "RulesState.h"
#include "MenuState.h"
#include "Definitions.h"

RulesState::RulesState(GameDataRef data) :_data(data) {}

void RulesState::Init()
{
	_data->pictures.LoadTexture("Rules", RULES_FILEPATH);
	_data->pictures.LoadTexture("Return Button", RETURN_BUTTON_FILEPATH);
	_background.setTexture(this->_data->pictures.GetTexture("Rules"));
	_returnButton.setTexture(this->_data->pictures.GetTexture("Return Button"));
	_returnButton.setPosition((SCREEN_WIDTH / 2) - (_returnButton.getGlobalBounds().width / 2), ((SCREEN_HEIGHT / 2) + (_returnButton.getGlobalBounds().height / 0.99)));
}

void RulesState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}

		//Przejœcie do stanu maszyny z Menu
		if (_data->input.IsSpriteClicked(_returnButton, sf::Mouse::Left, _data->window))
		{
			_data->machine.AddState(StateRef(new MenuState(_data)), true);
		}
	}
}
void RulesState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.draw(_returnButton);
	_data->window.display();
}