#pragma once
#include <SFML/Graphics.hpp>
	class Input {
	public:
		Input(){}
		~Input() {}
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
