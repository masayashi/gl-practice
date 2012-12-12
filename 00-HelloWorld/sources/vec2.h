#ifndef VEC2_H_
#define VEC2_H_

#include <math.h>

class Vec2
{
public:
    Vec2(float x_ = 0.f, float y_ = 0.f)
	: x(x_),  y(y_)
    {}

    void set(float x_, float y_) {
	x = x_;
	y = y_;
    }
    
    void set(float v) {
	x = v;  y = v;
    }

    float getLength() const {
	float pow = x * x + y * y;
	return pow != 0.f ? sqrt(pow) : 0.f;
    }
    
    // 正規化
    Vec2& normalize();
    Vec2 getNormalized() const;

    // 内積
    float dot(const Vec2& vec) const;
    
    union
    {
	struct
	{
	    float x, y;
	};
	float m[2];
    };
};

inline Vec2& Vec2::normalize()
{
    float len = getLength();
    if (len > 0.f)
    {
	x /= len;
	y /= len;
    }
}

inline Vec2 Vec2::getNormalized() const
{
    float len = getLength();
    if (len > 0.f)
    {
	return Vec2(x/len, y/len);
    }
    else
    {
	return Vec2();
    }
}

inline float Vec2::dot(const Vec2& vec) const
{
    return x * vec.x + y * vec.y;
}

#endif // VEC2_H_
