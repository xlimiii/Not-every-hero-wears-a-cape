
#include <sstream>
#include "Definitions.h"
#include "GameState.h"
#include <iostream>

	GameState::GameState(GameDataRef data) : _data(data) {}

	void GameState::Init() {
		std::cout << "Game State\n";
		_data->pictures.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_data->pictures.LoadTexture("Brick", BRICK_FILEPATH);
		_data->pictures.LoadTexture("Border", BORDER_FILEPATH);
		_data->pictures.LoadTexture("Bee 1", BEE_1_FILEPATH);
		_data->pictures.LoadTexture("Bee 2", BEE_2_FILEPATH);
		_data->pictures.LoadTexture("Bee 3", BEE_3_FILEPATH);

		brick = new Brick(_data);
		border = new Border(_data);
		bee = new Bee(_data);

		_background.setTexture(this->_data->pictures.GetTexture("Game Background"));
	}

	void GameState::HandleInput() 
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

	void GameState::Update(float dt) 
	{
		brick->MoveBrick(dt);
		if (clock.getElapsedTime().asSeconds() > BRICK_CREATION_FREQUENCY)
		{
			brick->RandomiseYBrickCoordinate();
			brick->CreateBricks();
			clock.restart();
		}
		bee->Animate(dt);
		bee->Fly();

	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		brick->DrawBricks();
		border->DrawBorder();
		bee->DrawBee();
		_data->window.display();
	}
