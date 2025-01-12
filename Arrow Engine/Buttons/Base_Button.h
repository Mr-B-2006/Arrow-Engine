#pragma once
#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H
#endif
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Arrow Engine/Drawable_calculations.h>

namespace AE
{
	class Base_Button
	{
	protected:
		sf::Text button_txt;
		sf::Color button_colour;
		sf::Color txt_colour; //we dont need size for Base_Button's constructor as it has no shape applied to it yet
		//also consider getting rid of "button_colour" and "txt_colour" as these are stored in each button type's parent already, also we are never going to apply colours or whatever in Base_Button anyway ¯\_(ツ)_/¯
		//CHAR SIZE PARAMETER NEEDS TO BE ADDED ASAP
		//different fonts can be weirdly positioned due to size differences, it may be worth given option for user defined offsets?
		Base_Button(int size_x, int size_y, sf::Color colour, sf::Font& fnt, std::string button_str_param, sf::Color txt_colour_param)
		{
			drawable_calculations::initialise_sftext(button_txt, fnt, 8, button_str_param);
			button_txt.setFillColor(txt_colour_param);
			txt_colour = txt_colour_param;
			
			button_colour = colour;
			button_txt.setString(button_str_param);
		}
		Base_Button(int size_x, int size_y, sf::Font& fnt, std::string button_str_param, sf::Color txt_colour_param) //no colour tint or outline
		{
			drawable_calculations::initialise_sftext(button_txt, fnt, 8, button_str_param);
			button_txt.setFillColor(txt_colour_param);
			txt_colour = txt_colour_param;
			button_txt.setString(button_str_param);
		}
	public:
		//virtual void draw(sf::RenderTexture& rt) = 0;
		virtual int was_pressed(sf::RenderTexture& rt, sf::RenderWindow& win, sf::Event& event) = 0;
		/* {
			int result = drawable_calculations::chk_L_click(rt, win, *this, event, this->getFillColor()); //stores whether our button has been clicked, hovered or not interatced with
			if (result == mouse_state::click) //the statements below handle the button's text colouring when hovering, clicking or not hovering over a button, this implementation may need to be different for other styles of button though.
			{
				button_txt.setFillColor(txt_colour);
				return true;
			}
			else if (result != mouse_state::untouched)
			{
				button_txt.setFillColor(button_colour);
			}
			else
			{
				button_txt.setFillColor(txt_colour);
			}
			return false;
		}*/
	};
}
