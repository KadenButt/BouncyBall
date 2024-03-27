#include "Img.h"
#include <string>

Img::Img(int h, int w, int x, int y, std::string p)
{
	this->h = h;
	this->w = w;
	this->x = x;
	this->y = y;
	this->path = p;
}

void Img::setHeight(int h)
{
	this->h = h;
}

void Img::setWidth(int w)
{
	this->w = w;
}

void Img::setXPosition(int x)
{
	this->x = x;
}

void Img::setYPosition(int y)
{
	this->y = y;
}

void Img::setSpeed(int speed)
{
	this->speed = speed;
}

void Img::update()
{
	setXPosition(x + speed);
}

int Img::getHeight()
{
	return h;
}

int Img::getWidth()
{
	return w;
}


int Img::getXPosition()
{
	return x;
}

int Img::getYPosition()
{
	return y;
}

std::string Img::getPath()
{
	return path;
}