#include "Vector.h"
#define PI 3.14159265

Vector::Vector(void)
{
    Vector::x = 0;
    Vector::y = 0;
}
Vector::Vector(float x, float y)
{
    Vector::x = x;
    Vector::y = y;
}
Vector::~Vector(void)
{
}
void Vector::Rotate(float degrees)
{
    float radians = degrees * PI / 180;
    float newX = Vector::x * cosf(radians) - Vector::y * sinf(radians);
    float newY = Vector::x * sinf(radians) + Vector::y * cosf(radians);
    Vector::x = newX;
    Vector::y = newY;
}
float Vector::getX()
{
    return Vector::x;
}
float Vector::getY()
{
    return Vector::y;
}