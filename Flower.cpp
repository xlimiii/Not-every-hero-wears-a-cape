#include"Flower.h"

Flower::Flower(GameDataRef data) : _data(data)
{
		_borderHeight = _data->pictures.GetTexture("Border").getSize().y;
		_flowerHeight = _data->pictures.GetTexture("Flower").getSize().y;
		_flowerYCoordinate = 0;
		_data->pictures.LoadTexture("Flower", FLOWER_FILEPATH);
		_flowerSprite.setTexture(this->_data->pictures.GetTexture("Flower"));
}

//Tworzenie kwiatków
void Flower::CreateFlower()
{
	sf::Sprite sprite(_data->pictures.GetTexture("Flower"));
	sprite.setPosition(_data->window.getSize().x, _flowerYCoordinate);
	_flowerSprite = sprite;
}

//Poruszanie siê kwiatków
void Flower::MoveFlower(float dt)
{
		sf::Vector2f position = _flowerSprite.getPosition();
		float motion = BRICK_MOVEMENT_SPEED * dt;
		_flowerSprite.move(-motion, 0);
}

void Flower::DrawFlower( )
{
		_data->window.draw(_flowerSprite);
}

//Losowe wybranie gdzie pojawi siê kwiatek
int Flower::RandomiseYFlowerCoordinate()
{
	_flowerYCoordinate = (rand() % (_data->window.getSize().y - _borderHeight - _flowerHeight) + _borderHeight-10);
	return _flowerYCoordinate;
}

bool Flower::DoIntersect(int y1, int y2)
{
	if ((y1 + 47 < y2) || (y1 - 47 > y2))
		return true;
	else
		return false;
}

 sf::Sprite Flower::getSprite()
 {
	 return _flowerSprite;
 }