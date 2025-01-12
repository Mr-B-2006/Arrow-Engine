#include "Scene_Texture_Manager.h"

void AE::Scene_Texture_Manager::load_texture_dirs(std::string* texture_dirs, int arr_size)
{
	this->clear();
	for (int i = 0; i != arr_size; i++)
	{
		sf::Texture texture_buffer;
		texture_buffer.loadFromFile(*(texture_dirs + i));
		this->push_back(texture_buffer);
	}
}

void AE::Scene_Texture_Manager::load_texture_dirs_free_mem(std::string* texture_dirs, int arr_size)
{
	this->clear();
	for (int i = 0; i != arr_size; i++)
	{
		sf::Texture texture_buffer;
		this->push_back(texture_buffer);
		this->at(i).loadFromFile(*(texture_dirs + i));
	}
	this->shrink_to_fit();
}