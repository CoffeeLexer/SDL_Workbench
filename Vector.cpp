#include "Vector.h"

Vector::Vector(void)
{
    Vector::_x = 0;
    Vector::_y = 0;
}
Vector::Vector(float x, float y)
{
    Vector::_x = x;
    Vector::_y = y;
}
Vector::~Vector(void)
{
}
void Vector::Rotate(float degrees)
{
    float radians = degrees * PI / 180;
    float newX = Vector::_x * cosf(radians) - Vector::_y * sinf(radians);
    float newY = Vector::_x * sinf(radians) + Vector::_y * cosf(radians);
    Vector::_x = newX;
    Vector::_y = newY;
}