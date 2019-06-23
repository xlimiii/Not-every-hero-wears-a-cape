#include <sstream>
#include "Definitions.h"
#include "GameState.h"
#include "GameOverState.h"
#include "windows.h"
#include <SFML/Audio.hpp>

GameState::GameState(GameDataRef data) : _data(data) {}

void GameState::Init() {
	_data->pictures.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
	_data->pictures.LoadTexture("Brick", BRICK_FILEPATH);
	_data->pictures.LoadTexture("Border", BORDER_FILEPATH);
	_data->pictures.LoadTexture("Flower", FLOWER_FILEPATH);
	_data->pictures.LoadTexture("Bee 1", BEE_1_FILEPATH);
	_data->pictures.LoadTexture("Bee 2", BEE_2_FILEPATH);
	_data->pictures.LoadTexture("Bee 3", BEE_3_FILEPATH);

	PlaySound(TEXT("avengers.wav"), NULL, SND_ASYNC | SND_FILENAME);

	brick = new Brick(_data);
	flowers.push_back(new Flower(_data));
	flowers[flowers.size() - 1]->CreateFlower();
	border = new Border(_data);
	bee = new Bee(_data);
	hud = new Hud(_data);
	_background.setTexture(this->_data->pictures.GetTexture("Game Background"));
	_score = 0;
	hud->UpddateScore(_score);
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
	FLOWER.erase(FLOWER.begin(), FLOWER.end());
for(int i =0;i<flowers.size();i++)
	flowers[i]->MoveFlower(dt);
	brick->MoveBrick(dt);
	int a = 0; int b = 0; int c = 0;;
	c = bee->getPosition();
	if (clock.getElapsedTime().asSeconds() > BRICK_CREATION_FREQUENCY)
	{
		a = brick->RandomiseYBrickCoordinate();
		//TWORZENIE KWIATÓW NIEPOKRYWAJĄCYCH SIĘ Z CEGŁAMI
		flowers.push_back(new Flower(_data));
		do
		{
			b = flowers[flowers.size()-1]->RandomiseYFlowerCoordinate();
		} while (!flowers[flowers.size() - 1]->DoIntersect(a, b));
		flowers[flowers.size() -1] ->CreateFlower();
		brick->CreateBricks();
		clock.restart();
	}
	bee->Animate(dt);
	bee->Fly();
	for (int i =0 ; i < flowers.size(); i++) {

		FLOWER.push_back(flowers[i]->getSprite());
		if (collision.isCollision(bee->getSprite(), FLOWER.at(i)))
		{
			flowers.erase(flowers.begin()+ i );
			_score++;
			hud->UpddateScore(_score);
		}
	}
	

	std::vector<sf::Sprite> BRICK = brick->getSprites();
	for (int i = 0; i < BRICK.size(); i++)
	{
		//koniec gry przy zderzeniu z cegłą
		if (collision.isCollision(bee->getSprite(), BRICK.at(i)))
		{
			sf::sleep(sf::seconds(0.3));
			
			PlaySound(TEXT("silent.wav"), NULL, SND_ASYNC | SND_FILENAME);
			_data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
		}
	}
}

void GameState::Draw(float dt)
{
	_data->window.clear();
	_data->window.draw(_background);
	brick->DrawBricks();
	for(int i=0;i<flowers.size();i++)
	flowers[i]->DrawFlower();
	border->DrawBorder();
	bee->DrawBee();

	hud->Draw();

	_data->window.display();

}
