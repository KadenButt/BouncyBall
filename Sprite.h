#pragma once
#include "Vector.h"
#include "Img.h"
#include <String>
#include <chrono>


class Sprite : public Img
{
private:
	Vector speed;
	//point from left centre  
	Vector topLeftBoundary;
	Vector bottomRightBoundary;
	
	bool activeBoundary = false;

	std::chrono::steady_clock::time_point timeSince = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration;


public:
	Sprite(int h, int w, int x, int y, std::string p);
	void setSpeed(Vector v);
	void update();
	void setBoundaries(Vector tlb, Vector brb);

};

