#pragma once
#include<SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"

//Klasa odpowiadaj¹ca za kolizje.

class Collision 
{
public:
	Collision() {}
	bool isCollision(sf::Sprite sprite_1, sf::Sprite sprite_2);
};