#define SDL_MAIN_HANDLED
#define FRAME_RATE 60
#include <SDL2/SDL.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <list>
#include <math.h>
#include <windows.h>
#include <thread>
#include <functional>
#include "Vector3.h"
#include "Shape3.h"
#include "Q_Event.h"
#include "Q_Circle.h"

int main(int argc, const char* argv[])
{
	//Disable console
	//ShowWindow(GetConsoleWindow(), SW_HIDE);

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
	bool windowOpen = true;
	Uint32 t = SDL_GetTicks();

	Shape3 box = Shape3();
	box.Add(Vector3(0,0,0));
	box.Add(Vector3(100,0,0));
	box.Add(Vector3(100,100,0));
	box.Add(Vector3(0,100,0));
	box.Add(Vector3(0,0,0));
	box.Add(Vector3(0,0,100));
	box.Add(Vector3(0,100,100));
	box.Add(Vector3(0,100,0));
	box.Add(Vector3(0,100,100));
	box.Add(Vector3(100,100,100));
	box.Add(Vector3(100,100,0));
	box.Add(Vector3(100,100,100));
	box.Add(Vector3(100,0,100));
	box.Add(Vector3(100,0,0));
	box.Add(Vector3(100,0,100));
	box.Add(Vector3(0,0,100));

	box.position += Vector3(200, 200, 0);

	box.SetPivot(Vector3(50,50,50));
	//box.RotateZ(15);
	Q_Event eventSystem = Q_Event([](SDL_Event){});
	eventSystem.BindEvent(SDL_QUIT, [&windowOpen](SDL_Event){windowOpen = false;});
	while(windowOpen)
	{
		eventSystem.PoolEvents();

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
			//SDL_RenderClear(renderer);

			box.RotateX(1.1);
			box.RotateY(1.2);
			box.RotateZ(1.3);
			
			
			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
			box.Draw(renderer);
			for(int i = 1; i < 100; i++)
			Q_Circle::Draw(renderer, {100, 100}, i);

			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
			SDL_RenderPresent(renderer);
			//SDL_Delay(1000);
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