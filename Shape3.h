#include <SDL2/SDL.h>
#include <list>
#include "Vector3.h"
#ifndef Shape3_H
#define Shape3_H
class Shape3
{
    public:
        Shape3()
        {
            position = Vector3().zero();
        }
        void Add(Vector3 v)
        {
            points.push_back(v);
        }
        void Draw(SDL_Renderer *r)
        {
            switch(points.size())
            {
                case 0:
                    break;
                case 1:
                {
                    Vector3 p = points.front();
                    p += position;
                    SDL_RenderDrawPointF(r, p['x'], p['y']);
                }
                break;
                case 2:
                {
                    Vector3 s = points.front();
                    Vector3 f = points.back();
                    s += position;
                    f += position;
                    SDL_RenderDrawLineF(r, s['x'], s['y'], f['x'], f['y']);
                }
                break;
                default:
                {
                    Vector3 previous;
                    bool flag = true;
                    for(Vector3 one : points)
                    {
                        one += position;
                        if(flag)
                        {
                            flag = false;
                            previous = one;
                            continue;
                        }
                        SDL_RenderDrawLineF(r, previous['x'], previous['y'], one['x'], one['y']);
                        previous = one;
                    }
                    Vector3 first = points.front();
                    first += position;
                    SDL_RenderDrawLineF(r, first['x'], first['y'], previous['x'], previous['y']);
                }
            }
        }
        void RotateX(float d)
        {
            int c = points.size();
            for(int i = 0; i < c; i++)
            {
                Vector3 p = points.front();
                points.pop_front();
                p.RotateX(d);
                points.push_back(p);
            }
        }
        void RotateY(float d)
        {
            int c = points.size();
            for(int i = 0; i < c; i++)
            {
                Vector3 p = points.front();
                points.pop_front();
                p.RotateY(d);
                points.push_back(p);
            }
        }
        void RotateZ(float d)
        {
            int c = points.size();
            for(int i = 0; i < c; i++)
            {
                Vector3 p = points.front();
                points.pop_front();
                p.RotateZ(d);
                points.push_back(p);
            }
        }
        Vector3 position;
    private:
        std::list<Vector3> points;
};
#endif