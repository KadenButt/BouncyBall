#include "Display.h"
#include <SDL.h>
#include <string>
#include "Img.h"

Display::Display(int h, int w)
{
	screenWidth = w;
	screenHeight = h;
}

bool Display::init()
{

	if (SDL_Init(SDL_INIT_VIDEO < 0))
	{
		printf("Unable to init, SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("Bouncy Ball", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Unable to create window, SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}

	return true;
}

SDL_Surface* Display::loadSurface(Img* img)
{
	SDL_Surface* optimized = NULL;

	SDL_Surface* loaded = SDL_LoadBMP(img->getPath().c_str());
	if (loaded == NULL)
	{
		printf("Unable to load image, SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		optimized = SDL_ConvertSurface(loaded, gScreenSurface->format, 0);
		if (optimized == NULL)
		{
			printf("Error unable to convert image, SDL Error: %s\n", SDL_GetError());
		}
		SDL_FreeSurface(loaded);
	}

	return optimized;

}

bool Display::loadMedia(Img* img)
{
	gStretchedSurface = loadSurface(img);
	if (gStretchedSurface == NULL)
	{
		printf("Unable to load image, SDL Error: %s\n", SDL_GetError());
		return false;
	}
	currentImg = img;
	return true;
}

void Display::output()
{
	SDL_Rect stretchRect;
	stretchRect.x = currentImg->getXPosition();
	stretchRect.y = currentImg->getYPosition();
	stretchRect.w =	currentImg->getWidth();
	stretchRect.h = currentImg->getHeight();
	SDL_BlitScaled(gStretchedSurface, NULL, gScreenSurface, &stretchRect);

	//update window
	SDL_UpdateWindowSurface(gWindow);
}

void Display::clearScreen()
{
	SDL_FillRect(gScreenSurface, NULL, 0x000000);
}

void Display::close()
{
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}
