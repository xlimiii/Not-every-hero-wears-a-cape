
#include <sstream>
#include "Definitions.h"
#include "GameState.h"
#include "GameOverState.h"
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
			const std::vector<sf::Sprite> FLOWER = flower->getSprites();
			brick->CreateBricks();
			clock.restart();
		}
		bee->Animate(dt);
		bee->Fly();
		std::vector<sf::Sprite> FLOWER = flower->getSprites();
		for (int i = 0; i < FLOWER.size(); i++) {
			bool deleteSprite = false;
			//PUNKTY W MIARE DZIALAJA(NABIJA SIE 22, ALE TO DLATEGO, ¯E NIE DZIALA ZNIKANIE JESZCZE I PSZCZO£A PRZEZ D£UGI CZAS JEST W KONTAKCIE Z KWIATKIEM)
			if (collision.isCollision(bee->getSprite(), FLOWER.at(i)))
			{
				_score++;
				std::cout << "PUNKTY - " << _score << std::endl;
			}
		}
		std::vector<sf::Sprite> BRICK = brick->getSprites();
		for (int i = 0; i < BRICK.size(); i++)
		{
			//koniec gry przy zderzeniu z ceg³¹. Dzia³a, ale chcê poprawiæ ekran GAMEOVER
			if (collision.isCollision(bee->getSprite(), BRICK.at(i)))
			{	
				_data->machine.AddState(StateRef(new GameOverState(_data)), true);
			}
		}
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
