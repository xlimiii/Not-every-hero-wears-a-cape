#pragma once
#include <SFML/Graphics.hpp>

//Klasa odpowiadająca za dane wprowadzane przez użytkownika.

	class Input 
	{
	public:
		Input(){}
		~Input() {}
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
