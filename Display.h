#pragma once
#include <SDL.h>
#include <string>

class Display
{
private:
	int screenWidth;
	int screenHeight;

	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gStretchedSurface = NULL;

	SDL_Rect stretchRect;


	SDL_Surface* loadSurface(std::string path);


public:
	Display(int w, int h);
	bool init();
	bool loadMedia(std::string path);
	void output();
	void close();


};

