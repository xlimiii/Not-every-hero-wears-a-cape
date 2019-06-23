#include"Bee.h"
Bee::Bee(GameDataRef data) : _data(data)
{
	_animationIterator = 0;
	_animationFrames.push_back(_data->pictures.GetTexture("Bee 1"));
	_animationFrames.push_back(_data->pictures.GetTexture("Bee 2"));
	_animationFrames.push_back(_data->pictures.GetTexture("Bee 3"));
	_beeSprite.setTexture(_animationFrames.at(_animationIterator));
	_beeSprite.setPosition((_data->window.getSize().x / 4) - (_beeSprite.getGlobalBounds().width / 2), 
		(_data->window.getSize().y / 2) - (_beeSprite.getGlobalBounds().height / 2));
}

void Bee::DrawBee()
{
	_data->window.draw(_beeSprite);
}

void Bee::Animate(float dt)
{
	if (_clock.getElapsedTime().asSeconds() > BEE_ANIMATION_DURATION / _animationFrames.size()) //je�eli min�� czas trwania 1 klatki
	{
		if (_animationIterator < _animationFrames.size() - 1) //je�eli numer klatki jest mniejszy ni� ich rzeczywista il w obrazku
		{
			_animationIterator++; //prze��cz klatk� na kolejn�
		}
		else
		{
			_animationIterator = 0; //zresetuj klatk�, aby obrazek zacz�� animacj� od pocz�tku
		}
		_beeSprite.setTexture(_animationFrames.at(_animationIterator)); //ustalenie tekstury pszczo�y na konkretn� klatk�
		_clock.restart();
	}
}

void Bee::Fly()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->top() > 0) //obs�uga braku mo�liwo�ci wyj�cia poza ekran
	{
		_beeSprite.move(0, -2); //przesuni�cie o wektor
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->bottom() < SCREEN_HEIGHT - 50)
	{
		_beeSprite.move(0, 2);
	}
}

const sf::Sprite& Bee::getSprite() const
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