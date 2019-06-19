#include "Collision.h"
#include <iostream>


bool Collision::isCollision(sf::Sprite s1, sf::Sprite s2)
{
	sf::Rect<float> rect1 = s1.getGlobalBounds();
	sf::Rect<float> rect2 = s2.getGlobalBounds();
	if (rect1.intersects(rect2))
		return true;
	else
		return false;
}