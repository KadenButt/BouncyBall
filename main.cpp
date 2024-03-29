#include <stdio.h>
#include <String>
#include <chrono>

#include "Display.h"
#include "Img.h"
#include "Sprite.h"


int main(int argc, char* args[])
{
	Display* display = new Display(1920, 1080);

	Sprite* dvd = new Sprite(100, 100, 0, 0, "images/dvd.bmp");
	dvd->setSpeed(Vector(2, 1));

	dvd->setBoundaries(Vector(0, 0), Vector(1920, 1080));

	auto timeSince = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration;

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

				duration = std::chrono::high_resolution_clock::now() - timeSince;
				if (duration.count() > 0.01f)
				{
					display->clearScreen();
					
					dvd->update();
					timeSince = std::chrono::high_resolution_clock::now();
				}
				


				display->output();
				

				
			}

		}

	}
	display->close();
	return 0;
}

