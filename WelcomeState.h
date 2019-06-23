#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

//Klasa odpowiadaj¹ca za stan maszyny, gdy wyœwietlaj¹ siê twórcy gry.

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