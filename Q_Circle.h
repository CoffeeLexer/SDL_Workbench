#ifndef Q_CIRCLE_H
#define Q_CIRCLE_H

#include <SDL2/SDL.h>
#include <list>

class Q_Circle
{
    public:
        static void Draw(SDL_Renderer *renderer, SDL_Point center, float radius)
        {
            int x = 0;
            int y;
            int r_sq = radius * radius;
            std::list<SDL_Point> points;
            while(x < y)
            {
                y = SDL_sqrtf(r_sq - x * x);
                points.push_back({center.x + x, center.y + y});
                points.push_back({center.x - x, center.y + y});
                points.push_back({center.x + x, center.y - y});
                points.push_back({center.x - x, center.y - y});
                points.push_back({center.x + y, center.y + x});
                points.push_back({center.x - y, center.y + x});
                points.push_back({center.x + y, center.y - x});
                points.push_back({center.x - y, center.y - x});
                x++;
            }
            SDL_Point array[points.size()];
            int i = 0;
            for(SDL_Point &one: points)
            {
                array[i] = one;
                i++;
            }
            SDL_RenderDrawPoints(renderer, array, points.size());
        }
};

#endif