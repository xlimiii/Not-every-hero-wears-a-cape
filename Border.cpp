#include "Border.h"
#include "Definitions.h"

Border::Border(GameDataRef data) : _data(data)
{
	_data->pictures.LoadTexture("Border", BORDER_FILEPATH);
	_borderSprite1.setTexture(this->_data->pictures.GetTexture("Border"));
	_borderSprite2.setTexture(this->_data->pictures.GetTexture("Border"));
	_borderSprite1.setPosition(0, _data->window.getSize().y - _borderSprite1.getGlobalBounds().height);
	_borderSprite2.setPosition(0, 0);
}
void Border::DrawBorder()
{
	_data->window.draw(_borderSprite1);
	_data->window.draw(_borderSprite2);
}

const std::vector<sf::Sprite>& Border::getSprites() const
{
	std::vector<sf::Sprite> _borderSprites;
	_borderSprites.push_back(_borderSprite1);
	_borderSprites.push_back(_borderSprite2);

	return _borderSprites;
}