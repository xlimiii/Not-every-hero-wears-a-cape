#include <sstream>
#include "MenuState.h"
#include "Definitions.h"
#include "GameState.h"
#include <iostream>
#include "RulesState.h"

	MenuState::MenuState(GameDataRef data) : _data(data) {}

	void MenuState::Init()
	{
		_data->pictures.LoadTexture("MainMenu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->pictures.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->pictures.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_data->pictures.LoadTexture("Find Out", FIND_OUT_FILEPATH);
		_data->pictures.LoadTexture("Here", HERE_FILEPATH);

		_background.setTexture(this->_data->pictures.GetTexture("MainMenu Background"));
		_title.setTexture(this->_data->pictures.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->pictures.GetTexture("Play Button"));
		_findOut.setTexture(this->_data->pictures.GetTexture("Find Out"));
		_hereButton.setTexture(this->_data->pictures.GetTexture("Here"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 8);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), ((SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 11.5)));
		_findOut.setPosition((SCREEN_WIDTH / 2) - (_findOut.getGlobalBounds().width / 1.3), ((SCREEN_HEIGHT / 2) + (_findOut.getGlobalBounds().height / 0.25)));
		_hereButton.setPosition((SCREEN_WIDTH / 2) + (_hereButton.getGlobalBounds().width / 1.2), ((SCREEN_HEIGHT / 2) + (_hereButton.getGlobalBounds().height / 0.255)));
	}

	void MenuState::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}

			//Przejście do głównej części gry
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true);
			}

			//Przejście do zasad gry
			if (_data->input.IsSpriteClicked(_hereButton, sf::Mouse::Left, _data->window))
			{
				_data->machine.AddState(StateRef(new RulesState(_data)), true);
			}
		}
	}

	void MenuState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.draw(_findOut);
		_data->window.draw(_hereButton);
		_data->window.display();
	}