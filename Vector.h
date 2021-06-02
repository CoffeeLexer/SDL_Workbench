#define PROPERTY(t,n)  __declspec( property ( put = property__set_##n, get = property__get_##n ) ) t n;\
	typedef t property__tmp_type_##n
#define READONLY_PROPERTY(t,n) __declspec( property (get = property__get_##n) ) t n;\
	typedef t property__tmp_type_##n
#define WRITEONLY_PROPERTY(t,n) __declspec( property (put = property__set_##n) ) t n;\
	typedef t property__tmp_type_##n
#define GET(n) property__tmp_type_##n property__get_##n() 
#define SET(n) void property__set_##n(const property__tmp_type_##n& value)   
#define PI 3.14159265


#include <stdio.h>
#include <math.h>

class Vector
{
    public:
        READONLY_PROPERTY(int, X);
        READONLY_PROPERTY(int, Y);
        READONLY_PROPERTY(int, Z);
        GET(X) { return _x; }
        GET(Y) { return _y; }
        GET(Z) { return _z; }
        Vector(void);
        Vector(float, float);
        ~Vector(void);
        void Rotate(float);
    private:
        float _x;
        float _y;
        float _z;
};