#include "Player.h"
#include "..\include\Player.h"

Player::Player(point2D pos, sf::PrimitiveType type)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	this->type = type; // shape of player
}

point2D Player::getPosition()
{
	point2D pnt;
	pnt.x = this->pos.x;
	pnt.y = this->pos.y;
	return pnt;
}

void Player::setPosition(point2D newPos)
{
	this->pos.x = newPos.x;
	this->pos.y = newPos.y;
}

void Player::draw()
{
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(this->pos.x, this->pos.y)),
		sf::Vertex(sf::Vector2f(this->pos.x + 100, this->pos.y + 100))
	};
	window.draw(line, 2, this->type);
}

Player::~Player()
{
	;
}
