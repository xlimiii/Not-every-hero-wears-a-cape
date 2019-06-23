#include "Pictures.h"

    //Funkcja odpowiadaj�ca za wczytanie tekstury z pliku
	void Pictures::LoadTexture(std::string name, std::string fileName) 
	{
		sf::Texture texture;
		if (texture.loadFromFile(fileName)) 
		{
			this->_textures[name] = texture;
		}
	}

	sf::Texture &Pictures::GetTexture(std::string name)
	{
		return this->_textures.at(name);
	}