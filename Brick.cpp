#include "Brick.h"
#include "Border.h"
	Brick::Brick(GameDataRef data) : _data(data) 
	{
		_borderHeight = _data->pictures.GetTexture("Border").getSize().y;
		_brickHeight = _data->pictures.GetTexture("Brick").getSize().y;
		_brickYCoordinate = 0;
	}

	void Brick::CreateBricks() 
	{
		sf::Sprite sprite(_data->pictures.GetTexture("Brick"));
		sprite.setPosition(_data->window.getSize().x, _brickYCoordinate);
		brickSprites.push_back(sprite);
	}

	void Brick::MoveBrick(float dt) 
	{
		for (int i = 0; i < brickSprites.size(); i++)
		{
			sf::Vector2f position = brickSprites.at(i).getPosition();
			float motion = BRICK_MOVEMENT_SPEED * dt;
			brickSprites.at(i).move(-motion, 0);
		}
	}
	void Brick::DrawBricks()
	{
		for (int i = 0; i < brickSprites.size(); i++)
		{
			_data->window.draw(brickSprites.at(i));
		}
	}
	int Brick::RandomiseYBrickCoordinate() 
	{
		_brickYCoordinate = (rand() % (_data->window.getSize().y - _borderHeight - _brickHeight) + _borderHeight);
		return _brickYCoordinate;

	}

	
	const std::vector<sf::Sprite>& Brick::getSprites() const
	{
		return brickSprites;

	}
