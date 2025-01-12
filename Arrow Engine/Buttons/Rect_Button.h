#pragma once
#ifndef RECT_BUTTON_H
#define RECT_BUTTON_H
#endif
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Arrow Engine/Buttons/Base_Button.h>

namespace AE
{
	class Rect_Button : public Base_Button, public sf::RectangleShape
	{
	private:

	public:
		Rect_Button(int size_x, int size_y, sf::Font& fnt, std::string button_str_param, sf::Color txt_colour_param) : AE::Base_Button(size_x, size_y, fnt, button_str_param, txt_colour_param) //when an abscissa or ordinate of Button, is negative, they will default to scaling based on the size of the text 
		{
			if (size_x < 0) //if no specified size is given, we will just give the button similar dimensions to the text
			{
				size_x = button_txt.getGlobalBounds().width;
			}
			if (size_y < 0)
			{
				std::cout << button_txt.getGlobalBounds().height << "\n";
				size_y = button_txt.getGlobalBounds().height;
			}
			this->setSize(sf::Vector2f(size_x + 6, size_y));
		}
		void draw(sf::RenderTexture& rt);/* {
			rt.draw(*this);
			button_txt.setPosition(drawable_calculations::center_two_transformables(*this, button_txt) + sf::Vector2f(-3, -3)); //centers text relative to the button shape
			rt.draw(button_txt);
		}*/

		int was_pressed(sf::RenderTexture& rt, sf::RenderWindow& win, sf::Event& event);
	};
}
