
#pragma once
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Game.h"
#include <vector>
class Bee {
public:
	Bee(GameDataRef data); //konstruktor
	void DrawBee();  //
	void Animate(float dt);
	void Fly();
	const sf::Sprite& getSprite() const;
	int getPosition();
	float top(); //T
	float bottom(); //T
private:
	GameDataRef _data;
	sf::Sprite _beeSprite;
	std::vector<sf::Texture> _animationFrames;
	unsigned int _animationIterator;
	sf::Clock _clock;
};

