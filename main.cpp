#include <stdio.h>
#include <String>
#include "Display.h"
#include "Img.h"


int main(int argc, char* args[])
{
	Display* display = new Display(600, 600);
	Img* dvd = new Img(100, 100, 0, 0, "images/dvd.bmp");
	
	if (!display->init())
	{
		printf("Unable to initiilize\n");
	}
	else
	{
		bool quit = false;

		SDL_Event e;

		while (!quit)
		{
			if(display->loadMedia(dvd))
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}

				display->output();
			}

		}

	}
	display->close();
	return 0;
}

