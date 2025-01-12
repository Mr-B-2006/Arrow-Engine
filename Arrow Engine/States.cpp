//This states file is default
#include "States.h"

void States::state_manager_event(sf::RenderTexture& rt, sf::RenderWindow& win, sf::View& view, sf::Event& event)
{
	int mode = -1; //if the value of mode does not change and is still -1, we know something's gone wrong
	switch (current_state)
	{

	}
}

void States::state_manager_rt(sf::RenderWindow& win, sf::RenderTexture& rt, sf::View& view)
{
	switch (current_state)
	{

	}
}

int States::get_current_state()
{
	return current_state;
}

void States::set_current_state(int new_state)
{
	current_state = new_state;
}

void States::set_current_bg_colour(sf::Color bg_c)
{
	rt_background_colour = bg_c;
}

sf::Color States::get_current_bg_colour()
{
	return rt_background_colour;
}
