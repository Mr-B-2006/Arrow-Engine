#pragma once
#ifndef STATES_H
#define STATES_H
#endif
#include <iostream>
#include <SFML/Graphics.hpp>

enum state_keys //these enums tell us what state the program is in
{
	default_state = 0
};

class States
{
private:
	int current_state = state_keys::default_state;
	sf::Color rt_background_colour;
public:
	States()	{	}
	void state_manager_event(sf::RenderTexture& rt, sf::RenderWindow& win, sf::View& view, sf::Event& event);
	void state_manager_rt(sf::RenderWindow& win, sf::RenderTexture& rt, sf::View& view);
	int get_current_state();
	void set_current_state(int new_state);
	void set_current_bg_colour(sf::Color bg_c);
	sf::Color get_current_bg_colour();

};