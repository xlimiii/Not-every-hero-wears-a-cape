#include <sstream>
#include "MenuState.h"
#include "Definitions.h"
#include "GameState.h"
#include <iostream>

	MenuState::MenuState(GameDataRef data) : _data(data) {}
	
	void MenuState::Init() 
	{
		_data->pictures.LoadTexture("MainMenu Background", MAIN_MENU_BACKGROUND_FILEPATH);
		_data->pictures.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
		_data->pictures.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);
		_background.setTexture(this->_data->pictures.GetTexture("MainMenu Background"));
		_title.setTexture(this->_data->pictures.GetTexture("Game Title"));
		_playButton.setTexture(this->_data->pictures.GetTexture("Play Button"));

		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), _title.getGlobalBounds().height / 8);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2), ((SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 11.5)));
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
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) 
				//po naciœniêciu na przycisk PLAY, program zmienia stan, przechodzi do gry
			{
				_data->machine.AddState(StateRef(new GameState(_data)), true); 
			}
		}
	}
	
	void MenuState::Draw(float dt) 
	{
		_data->window.clear();
		_data->window.draw(_background);
		_data->window.draw(_title);
		_data->window.draw(_playButton);
		_data->window.display();
	}
