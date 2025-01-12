#pragma once
#ifndef SCENE_TEXTURE_MANAGER_H
#define SCENE_TEXTURE_MANAGER_H
#endif
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Arrow Engine/Drawable_calculations.h>
#include "Scene_Texture_Manager.h"

namespace AE
{ //it is reccomended that you create enums to identify each element in the texture manager
	class Scene_Texture_Manager : public std::vector<sf::Texture>
	{
	private:

	public:
		Scene_Texture_Manager(std::string* texture_dirs, int arr_size)
		{
			load_texture_dirs(texture_dirs, arr_size);
		}
		Scene_Texture_Manager()		{		}
		void load_texture_dirs(std::string* texture_dirs, int arr_size);

		//load texture dirs free mem

		void load_texture_dirs_free_mem(std::string* texture_dirs, int arr_size); //frees the memory used by texture_dirs by calling shrink_to_fit()
		AE::Scene_Texture_Manager operator+(std::string texture_dir)
		{
			sf::Texture* buffer = new sf::Texture;
			buffer->loadFromFile(texture_dir);
			this->push_back(*buffer);
			delete buffer;
		}
	};
}
