#pragma once
#include<map>
#include <SFML/Graphics.hpp>

//Klasa odpowiadaj¹ca za obrazki.

	class Pictures 
	{
	public:
		Pictures() {}
		~Pictures() {}
		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name);
		
	private:
		std::map<std::string, sf::Texture> _textures;
	};