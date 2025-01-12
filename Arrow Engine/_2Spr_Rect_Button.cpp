#include "_2Spr_Rect_Button.h"

void AE::_2Spr_Rect_Button::setTextures(sf::Texture& sides, sf::Texture& mid)
{
	button_sprites[button_parts::beginning].setTexture(sides);
	this->setTexture(&mid);
	button_sprites[button_parts::end].setTexture(sides);
	button_sprites[end].setOrigin(sf::Vector2f(button_sprites[end].getGlobalBounds().width, 0)); //Origin resets when a new texture is set
	button_sprites[button_parts::beginning].setPosition(AE::drawable_calculations::get_spr_topright(button_sprites[button_parts::beginning]));
	button_txt.setOrigin(button_txt.getLocalBounds().left, button_txt.getLocalBounds().top);
}

sf::Vector2f AE::_2Spr_Rect_Button::getButtonPosition()
{
	return button_sprites[beginning].getPosition();
}

void AE::_2Spr_Rect_Button::setButtonPosition(int x, int y)
{
	button_sprites[beginning].setPosition(x, y);
	this->setPosition(AE::drawable_calculations::get_spr_topright(button_sprites[button_parts::beginning]));
	button_sprites[end].setPosition(AE::drawable_calculations::get_shape_topright(*this));
	button_txt.setPosition(AE::drawable_calculations::vectorf_components_to_int(AE::drawable_calculations::center_two_transformables(*this, button_txt) + sf::Vector2f(0, button_txt.getLineSpacing())));
}

int AE::_2Spr_Rect_Button::was_pressed()
{
	return 0;
}
