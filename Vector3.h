//Implementing method name/functionality target
//https://docs.unity3d.com/ScriptReference/Vector3.html
#include <math.h>

#define PI 3.14159265

#ifndef Vector3_H
#define Vector3_H

class Vector3
{
    public:
        static Vector3 back() { return Vector3(0, 0, -1); }
        static Vector3 down() { return Vector3(0, -1, 0); }
        static Vector3 forward() { return Vector3(0, 0, 1); }
        static Vector3 left() { return Vector3(-1, 0, 0); }
        static Vector3 negativeInfinity() { return Vector3(-INFINITY, -INFINITY, -INFINITY); }
        static Vector3 one() { return Vector3(1, 1, 1); }
        static Vector3 positiveInfinity() { return Vector3(INFINITY, INFINITY, INFINITY); }
        static Vector3 right() { return Vector3(1, 0, 0); }
        static Vector3 up() { return Vector3(0, 1, 0); }
        static Vector3 zero() { return Vector3(0, 0, 0); }

        float magnitude() { return sqrtf(_x * _x + _y * _y + _z * _z); }
        Vector3 normalized() 
        {
            float magnitude = this->magnitude();
            return Vector3(_x / magnitude, _y / magnitude, _z / magnitude);
        }
        float sqrMagnitude() { return _x * _x + _y * _y + _z * _z; }

        float& operator [] (int i)
        {
            switch (i)
            {
            case 0:
                return _x;
                break;
            case 1:
                return _y;
                break;
            case 2:
                return _z;
                break;
            default:
                break;
            }
        }
        float& operator [] (char c)
        {
            switch (c)
            {
            case 'x':
            case 'X':
                return _x;
                break;
            case 'y':
            case 'Y':
                return _y;
                break;
            case 'z':
            case 'Z':
                return _z;
                break;
            default:

                break;
            }
        }
        Vector3(void)
        {
            _x = 0;
            _y = 0;
            _z = 0;
        }
        Vector3(float x, float y, float z)
        {
            _x = x;
            _y = y;
            _z = z;
        }
        void RotateX(float degrees) 
        {
            float d = degrees * PI / 180;
            float y = _y * cosf(d) - _z * sinf(d);
            float z = _y * sinf(d) + _z * cosf(d);
            _y = y;
            _z = z;
        }
        void RotateY(float degrees)
        {
            float d = degrees * PI / 180;
            float x = _x * cosf(d) + _z * sinf(d);
            float z = - _x * sinf(d) + _z * cosf(d);
            _x = x;
            _z = z;  
        }
        void RotateZ(float degrees)
        {
            float d = degrees * PI / 180;
            float x = _x * cosf(d) - _y * sinf(d);
            float y = _x * sinf(d) + _y * cosf(d);
            _x = x;
            _y = y;
        }
        void operator +=(const Vector3& other)
        {
            _x += other._x;
            _y += other._y;
            _z += other._z;
        }
        void operator -=(const Vector3& other)
        {
            _x -= other._x;
            _y -= other._y;
            _z -= other._z;
        }
    private:
        float _x;
        float _y;
        float _z;
};

#endif