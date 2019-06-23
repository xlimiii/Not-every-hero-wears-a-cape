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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->top() > 0) //T
	{
		_beeSprite.move(0, -3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->bottom() < 490) //tutaj trzeba aktualizowaæ wysokoœæ ekranu T
	{
		_beeSprite.move(0, 3);
	}
}

const sf::Sprite &Bee::getSprite() const
{
	return _beeSprite;
}

int Bee::getPosition()
{
	return _beeSprite.getPosition().y;
}

//T
float Bee::top()
{
	return this->_beeSprite.getPosition().y - _beeSprite.getTextureRect().height / 2.f;
}

float Bee::bottom()
{
	return this->_beeSprite.getPosition().y + _beeSprite.getTextureRect().height / 2.f;
}