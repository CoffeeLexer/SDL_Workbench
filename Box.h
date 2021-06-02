#include <stdio.h>
#include <SDL2/SDL.h>
class Box
{
    public:
        Box(SDL_Renderer *r);
        void draw(int x, int y, int w, int h);
    private:
        SDL_Renderer *renderer;
};