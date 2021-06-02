#include "Box.h"

Box::Box(SDL_Renderer *r)
{
    Box::renderer = r;
}
void Box::draw(int x, int y, int w, int h)
{
    SDL_Rect rectangle;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_RenderDrawRect(Box::renderer, &rectangle);
    SDL_free(&rectangle);
}