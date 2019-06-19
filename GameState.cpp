
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
		_data->pictures.LoadTexture("Flower", FLOWER_FILEPATH);
		_data->pictures.LoadTexture("Bee 1", BEE_1_FILEPATH);
		_data->pictures.LoadTexture("Bee 2", BEE_2_FILEPATH);
		_data->pictures.LoadTexture("Bee 3", BEE_3_FILEPATH);

		brick = new Brick(_data);
		flower = new Flower(_data);
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
		flower->MoveFlower(dt);
		brick->MoveBrick(dt);
		int a = 0; int b = 0; int c = 0;;
		c = bee->getPosition();
		if (clock.getElapsedTime().asSeconds() > BRICK_CREATION_FREQUENCY)
		{
			a = brick->RandomiseYBrickCoordinate();
			//TWORZENIE KWIATÓW NIEPOKRYWAJ¥CYCH SIÊ Z CEG£AMI 
			do 
			{
				b = flower->RandomiseYFlowerCoordinate();
			} while (!flower->DoIntersect(a, b));
			flower->CreateFlower();
			brick->CreateBricks();
			clock.restart();
		}
		bee->Animate(dt);
		bee->Fly(); 
		//PONIZEJ PRÓBNE ZBIERANIE KWIATKÓW ALE NIE DZIA£A ZA BARDZO HAHAHA 
		if (!flower->DoIntersect(b, c)) {
			_score++;
		}
		std::cout << "SCORE = " << _score;
	}

	void GameState::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(_background);
		brick->DrawBricks();
		flower->DrawFlower();
		border->DrawBorder();
		bee->DrawBee();
		_data->window.display();
	}
