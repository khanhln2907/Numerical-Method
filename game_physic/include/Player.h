#pragma once
#include "..\main.h"
struct point2D;

class Player
{
private:
	point2D pos;
	sf::PrimitiveType type;
	
public:
	Player(point2D pos, sf::PrimitiveType type);
	point2D getPosition();
	void setPosition(point2D pos);
	void draw();
	~Player();
};

