#include"Bee.h"
Bee::Bee(GameDataRef data) : _data(data)
{
	_animationIterator = 0;
	_animationFrames.push_back(_data->pictures.GetTexture("Bee 1"));
	_animationFrames.push_back(_data->pictures.GetTexture("Bee 2"));
	_animationFrames.push_back(_data->pictures.GetTexture("Bee 3"));
	_beeSprite.setTexture(_animationFrames.at(_animationIterator));
	_beeSprite.setPosition((_data->window.getSize().x / 4) - (_beeSprite.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) - (_beeSprite.getGlobalBounds().height / 2));
}

void Bee::DrawBee()
{
	_data->window.draw(_beeSprite);
}

void Bee::Animate(float dt) 
{
	if (_clock.getElapsedTime().asSeconds() > BEE_ANIMATION_DURATION / _animationFrames.size()) 
	{
		if (_animationIterator < _animationFrames.size() - 1) 
		{
			_animationIterator++;
		}
		else
		{
			_animationIterator = 0;
		}
		_beeSprite.setTexture(_animationFrames.at(_animationIterator));
		_clock.restart();
	}
}

void Bee::Fly()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_beeSprite.move(0, -2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
	{
		_beeSprite.move(0, 2);
	}
}

const sf::Sprite &Bee::getSprite() const
{
	return _beeSprite;
}