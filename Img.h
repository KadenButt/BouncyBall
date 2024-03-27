#pragma once


#include <string>

class Img
{
private:
	int h;
	int w;
	int x;
	int y;
	int speed = 0;

	std::string path;

public:
	Img(int h, int w, int x, int y, std::string p);

	void setHeight(int h);
	void setWidth(int w);
	void setXPosition(int x);
	void setYPosition(int y);
	void setSpeed(int speed);
	void update();

	int getHeight();
	int getWidth();
	int getXPosition();
	int getYPosition();

	
	std::string getPath();
};

