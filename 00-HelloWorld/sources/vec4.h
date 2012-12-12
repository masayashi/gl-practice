#ifndef VEC4_H_
#define VEC4_H_

class Vec4
{
public:

    Vec4()
	: x(0.f), y(0.f), z(0.f), w(0.f)
    {}
    
    Vec4(float x_, float y_, float z_, float w_)
	: x(x_), y(y_), z(z_), w(w_)
    {}

    void set(float x_, float y_, float z_, float w_)
    {
	x = x_;  y = y_;  z = z_;  w = w_;
    }

    void set(float v)
    {
	x = v;  y = v;  z = v;  w = v;
    }
    
    union
    {
	struct
	{
	    float x, y, z, w;
	};
	float m[4];
    };
};

#endif // VEC4_H_
