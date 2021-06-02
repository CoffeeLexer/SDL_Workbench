#define SDL_MAIN_HANDLED
#define FRAME_RATE 60
#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <list>
#include "Box.h"
#include "Vector.h"
#include "Shape.h"

int main(int argc, const char* argv[])
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}
	SDL_Window *window = SDL_CreateWindow(
		"SDL",
		0,
		28,
		500,
		500,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if(window == NULL)
	{
		SDL_Log("Unable to create window SDL: %s", SDL_GetError());
	}
	
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event event;
	bool windowOpen = true;

	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_TARGET, 200, 200);
	Uint32 t = SDL_GetTicks();
	Shape shape = Shape();
	shape.Add(0, 0);
	shape.Add(0, 100);
	shape.Add(5, 95);
	shape.Add(95, 95);
	shape.Add(100, 100);
	shape.Add(100, 0);
	shape.Add(95, 5);
	shape.Add(5, 5);
	shape.Add(5, 95);
	shape.Add(0, 100);
	shape.Add(100, 100);
	shape.Add(95, 95);
	shape.Add(95, 5);
	shape.Add(100, 0);
	shape.Add(0, 0);
	shape.Add(5, 5);


	
	shape.SetPivot(50, 50);
	while(windowOpen)
	{
		while(SDL_PollEvent(&event) > 0)
		{
			switch(event.type)
			{
				case SDL_QUIT:
					windowOpen = false;
					break;
				case SDL_KEYDOWN:
					printf("Key down\n");
					break;
			}
		}
		if(SDL_GetTicks() > t + 1000 / FRAME_RATE)
		{
			t = SDL_GetTicks();
			SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x10);
			SDL_Rect rect;
			rect.x = 0;
			rect.y = 0;
			rect.w = 400;
			rect.h = 400;
			SDL_RenderFillRect(renderer, &rect);
			SDL_RenderClear(renderer);

			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
			shape.Rotate(1);
			shape.Draw(renderer, Point(100, 100));
			SDL_RenderPresent(renderer);
		}
		else
		{
			SDL_Delay(1);
			//SDL_Delay(1000 / FRAME_RATE - 4);
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}