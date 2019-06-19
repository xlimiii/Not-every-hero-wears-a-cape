#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

	class MenuState :public State {
	public:
		MenuState(GameDataRef data);
		void Init();
		void HandleInput();
		void Draw(float dt);
	private:
		GameDataRef _data;
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
	};