#pragma once

struct Vector
{
	int x;
	int y;

	Vector(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vector()
	{
		this->x = 0;
		this->y = 0;
	}

};