#include"Coin.h"

Flower::Flower(GameDataRef data) : _data(data)
{
		_borderHeight = _data->pictures.GetTexture("Border").getSize().y;
		_flowerHeight = _data->pictures.GetTexture("Flower").getSize().y;
		_flowerYCoordinate = 0;
}

void Flower::CreateFlower()
{
	sf::Sprite sprite(_data->pictures.GetTexture("Flower"));
	sprite.setPosition(_data->window.getSize().x, _flowerYCoordinate);
	flowerSprites.push_back(sprite);
}

void Flower::MoveFlower(float dt)
{
	for (int i = 0; i < flowerSprites.size(); i++)
	{
		sf::Vector2f position = flowerSprites.at(i).getPosition();
		float motion = BRICK_MOVEMENT_SPEED * dt;
		flowerSprites.at(i).move(-motion, 0);
	}
}
void Flower::DrawFlower()
{
	for (int i = 0; i < flowerSprites.size(); i++)
	{
		_data->window.draw(flowerSprites.at(i));
	}
}
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

 std::vector<sf::Sprite>& Flower::getSprites() 
{
	return flowerSprites;

}
