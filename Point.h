#include <math.h>
class Point
{
    public:
        Point operator+(const Point &);
        Point operator-(const Point &);
        void operator=(const Point &);
        Point(void);
        Point(int, int);
        void Rotate(float);
        float x;
        float y;
};