#include "Point.h"
#define PI 3.14159265

Point::Point()
{
    Point::x = 0;
    Point::y = 0;
}
Point::Point(int x, int y)
{
    Point::x = x;
    Point::y = y;
}
void Point::Rotate(float degrees)
{
    float radians = degrees * PI / 180;
    float newX = x * cosf(radians) - y * sinf(radians);
    float newY = x * sinf(radians) + y * cosf(radians);
    x = newX;
    y = newY;
}
Point Point::operator+(const Point &p)
{
    return Point(x + p.x, y + p.y);
}
Point Point::operator-(const Point &p)
{
    return Point(x - p.x, y - p.y);
}
void Point::operator=(const Point &p)
{
    this->x = p.x;
    this->y = p.y;
}