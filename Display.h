#pragma once
#include <SDL.h>
#include <string>
#include "Img.h"


class Display
{
private:
	int screenWidth;
	int screenHeight;

	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gStretchedSurface = NULL;
	
	Img* currentImg = NULL ;

	SDL_Surface* loadSurface(Img* img);

	


public:
	Display(int w, int h);
	bool init();
	bool loadMedia(Img* img);
	void output();
	void clearScreen();
	void close();



};

