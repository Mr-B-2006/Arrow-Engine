#include "Rect_Button.h"

void AE::Rect_Button::draw(sf::RenderTexture& rt)
 {
	rt.draw(*this);
	button_txt.setPosition(drawable_calculations::center_two_transformables(*this, button_txt) + sf::Vector2f(-3, -3)); //centers text relative to the button shape
	rt.draw(button_txt);
}

int AE::Rect_Button::was_pressed(sf::RenderTexture& rt, sf::RenderWindow& win, sf::Event& event)
{
	int result = drawable_calculations::chk_L_click(rt, win, *this, event, button_colour); //stores whether our button has been clicked, hovered or not interatced with
	if (result == mouse_state::click) //the statements below handle the button's text colouring when hovering, clicking or not hovering over a button, this implementation may need to be different for other styles of button though.
	{
		button_txt.setFillColor(txt_colour);
		return mouse_state::click;
	}
	else if (result != mouse_state::untouched)
	{
		button_txt.setFillColor(button_colour);
		return mouse_state::hovering; //check that this actually works :p
	}
	else
	{
		button_txt.setFillColor(txt_colour);
	}
	return mouse_state::untouched;
}

