#pragma once


#include <string>
#include "Vector.h"
class Img
{
private:
	int h;
	int w;
	//int x;
	//int y;
	Vector position;
	std::string path;

public:
	Img(int h, int w, int x, int y, std::string p);

	void setHeight(int h);
	void setWidth(int w);
	void setPosition(Vector v);


	int getHeight();
	int getWidth();
	Vector getPosition();

	
	std::string getPath();
};

