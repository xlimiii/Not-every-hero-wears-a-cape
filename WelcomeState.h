#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

//Klasa odpowiadaj�ca za stan maszyny, gdy wy�wietlaj� si� tw�rcy gry.

	class WelcomeState :public State 
	{
	public:
		WelcomeState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
	private:
		GameDataRef _data;
		sf::Clock _clock;	
		sf::Sprite _background;
	};