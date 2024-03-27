#include "Sprite.h"
#include <String>
#include <chrono>
#include <iostream>



Sprite::Sprite(int h, int w, int x, int y, std::string p) : Img(h, w, x, y, p) 
{
	
}

void Sprite::setSpeed(Vector v)
{
	speed = v;
}

void Sprite::update()
{

	printf("X: %d Y: %d \n", this->getPosition().x, this->getPosition().y);


	duration = std::chrono::high_resolution_clock::now() - timeSince;


	this->setPosition(Vector(this->getPosition().x + speed.x, this->getPosition().y + speed.y));
	//printf("done\n");

	if(activeBoundary && duration.count() > 2 )
	{
		if (this->getPosition().y < topLeftBoundary.y || this->getPosition().y > bottomRightBoundary.y - this->getHeight())
		{
			speed.y *= -1;
			timeSince = std::chrono::high_resolution_clock::now();
		}

		if (this->getPosition().x < topLeftBoundary.x || this->getPosition().x > bottomRightBoundary.x - this->getWidth())
		{
			speed.x *= -1;
			timeSince = std::chrono::high_resolution_clock::now();
		}


	}

}

void Sprite::setBoundaries(Vector tlb, Vector brb)
{
	topLeftBoundary = tlb;
	bottomRightBoundary = brb;
	activeBoundary = true;
}