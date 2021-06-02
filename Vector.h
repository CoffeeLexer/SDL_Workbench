#include <stdio.h>
#include <math.h>

class Vector
{
    public:
        Vector(void);
        Vector(float, float);
        ~Vector(void);
        void Rotate(float);
        float getX();
        float getY();
    private:
        float x;
        float y;
};