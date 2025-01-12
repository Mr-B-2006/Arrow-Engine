//This project config is default
#pragma once
#ifndef PROJECT_CONFIG_H
#define PROJECT_CONFIG_H
#endif
#include <iostream>
#include <SFML/Graphics.hpp>

namespace AE
{
	const sf::Vector2f initial_win_size = sf::Vector2f(620, 440);
	const sf::Vector2f initial_win_center = sf::Vector2f(initial_win_size / 2.f);
	const sf::Vector2f initial_view_size = sf::Vector2f(310, 220);
}