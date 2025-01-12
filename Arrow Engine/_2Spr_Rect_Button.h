#pragma once
#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H
#endif
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Arrow Engine/Drawable_calculations.h>
#include <Arrow Engine/Buttons/Rect_Button.h>	

namespace AE //make it so the textures arent passed thru the constructor, but rather a seperate function like with sf::Sprite (alternatively, create an alternate constructor which only asks for the bare minimum parameters maybe)
{
	// : Base_Button(size_x, size_y, colour, fnt, button_str_param, txt_colour_param) //when an abscissa or ordinate of Button, is negative, they will default to scaling based on the size of the text 
		
	class _2Spr_Rect_Button : public AE::Rect_Button
	{
	private:
		enum button_parts
		{
			beginning = 0, end = 1
		};
		sf::Sprite button_sprites[2];
	public:
		_2Spr_Rect_Button(int size_x, int size_y, sf::Font& fnt, std::string button_str_param, sf::Color txt_colour_param) : AE::Rect_Button(size_x, size_y, fnt, button_str_param, txt_colour_param) 
		{
			button_sprites[end].setScale(-1, 1);
		} 
		void setTextures(sf::Texture& sides, sf::Texture& mid);
		sf::Vector2f getButtonPosition();
		void setButtonPosition(int x, int y); //this function sets the position of the button and it's sprite components, 

		//templated funcs
		template <class T>
		void draw(T &rt) 
		{
			rt.draw(button_sprites[beginning]);
			rt.draw(*this);
			rt.draw(button_sprites[end]);
			rt.draw(button_txt);

		}
		int was_pressed();
	};
}

//template <class T>
//void AE::_2Spr_Rect_Button::render_button(sf::RenderTexture &rt)

