// game_physic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"main.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	window.clear(sf::Color::Cyan);
	window.display();
	getchar();
}
