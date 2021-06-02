#include <list>
#include <SDL2/SDL.h>
#include "Point.h"
class Shape {
    public:
        Shape();
        void Add(Point);
        void Add(int, int);
        void Draw(SDL_Renderer *);
        void Draw(SDL_Renderer *, Point);
        void Rotate(float);
        void SetPivot(Point);
        void SetPivot(float, float);
    private:
        std::list<Point> points;
        Point pivot;
};