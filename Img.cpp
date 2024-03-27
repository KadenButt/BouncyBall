#include "Img.h"
#include <string>
#include "Vector.h"

Img::Img(int h, int w, int x, int y, std::string p)
{
	this->h = h;
	this->w = w;
	position.x = x;
	position.y = y;
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

void Img::setPosition(Vector v)
{
	position = v;
}

int Img::getHeight()
{
	return h;
}

int Img::getWidth()
{
	return w;
}

Vector Img::getPosition()
{
	return position;
}

std::string Img::getPath()
{
	return path;
}