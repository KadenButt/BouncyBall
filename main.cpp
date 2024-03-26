#include <stdio.h>
#include <String>
#include "Display.h"





int main(int argc, char* args[])
{
	Display* display = new Display(600, 600);
	
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
			if(display->loadMedia("stretch.bmp"))
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
				}
			}

			display->output();
		}

	}
	display->close();
	return 0;
}

