
#include <sstream>
#include "WelcomeState.h"
#include "Definitions.h"
#include "MenuState.h"
#include <iostream>

WelcomeState::WelcomeState(GameDataRef data) : _data(data) {}
void WelcomeState::Init()
{
	_data->pictures.LoadTexture("Welcome State Background", WELCOME_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->pictures.GetTexture("Welcome State Background"));
}
void WelcomeState::HandleInput()
{
	sf::Event event;
	while (_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->window.close();
		}
	}
}
void WelcomeState::Update(float dt)
{
	//Po up³ywie czasu ustawionego w WELCOME_STATE_SHOW_TIME, program zmienia stan, przechodzi do stanu menu g³ównego
	if (_clock.getElapsedTime().asSeconds() > WELCOME_STATE_SHOW_TIME)
	{
		_data->machine.AddState(StateRef(new MenuState(_data)), true);
	}
}
void WelcomeState::Draw(float dt) {
	_data->window.clear();
	_data->window.draw(_background);
	_data->window.display();
}
