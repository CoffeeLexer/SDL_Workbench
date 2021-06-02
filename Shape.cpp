#include "Shape.h"
Shape::Shape()
{
    pivot = Point(0, 0);
}
void Shape::Add(Point p)
{
    p.x -= pivot.x;
    p.y -= pivot.y;
    points.push_back(p);
}
void Shape::Add(int x, int y)
{
    points.push_back(Point(x - pivot.x, y - pivot.y));
}
void Shape::Draw(SDL_Renderer *r)
{
    Draw(r, Point(0, 0));
}
void Shape::Draw(SDL_Renderer *r, Point position)
{
    switch(points.size())
    {
        case 0:
            break;
        case 1:
        {
            Point p = points.front();
            p = p + position;
            SDL_RenderDrawPointF(r, p.x, p.y);
        }
        break;
        case 2:
        {
            Point s = points.front();
            Point f = points.back();
            s = s + position;
            f = f + position;
            SDL_RenderDrawLineF(r, s.x, s.y, f.x, f.y);
        }
        break;
        default:
        {
            Point previous;
            bool flag = true;
            for(Point one : points)
            {
                one = one + position;
                if(flag)
                {
                    flag = false;
                    previous = one;
                    continue;
                }
                SDL_RenderDrawLineF(r, previous.x, previous.y, one.x, one.y);
                previous = one;
            }
            Point first = points.front();
            first = first + position;
            SDL_RenderDrawLineF(r, first.x, first.y, previous.x, previous.y);
        }
    }
}
void Shape::Rotate(float degrees)
{
    int c = points.size();
    for(int i = 0; i < c; i++)
    {
        Point p = points.front();
        points.pop_front();
        p.Rotate(degrees);
        points.push_back(p);
    }
}
void Shape::SetPivot(float x, float y)
{
    SetPivot(Point(x, y));
}
void Shape::SetPivot(Point p)
{
    Point dif = pivot - p;
    int c = points.size();
    for(int i = 0; i < c; i++)
    {
        Point p = points.front();
        points.pop_front();
        p = p + dif;
        points.push_back(p);
    }
    pivot = p;
}