// game_physic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"main.h"
#include"../game_physic/include/Player.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");


int main()
{
	window.clear(sf::Color::Black);

	point2D pos{ 20,20 };
	Player myPlayer(pos, sf::Lines);

	myPlayer.draw();

	//// Drawing lines
	//sf::Vertex line[] =
	//{
	//	sf::Vertex(sf::Vector2f(10, 10)),
	//	sf::Vertex(sf::Vector2f(150, 150))
	//};
	//window.draw(line, 2, sf::Lines);

	window.display();

	getchar();
}
