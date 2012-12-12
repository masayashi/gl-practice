#ifndef VEC3_H_
#define VEC3_H_

#include <math.h>

class Vec3
{
public:
    Vec3(float x_ = 0.f, float y_ = 0.f, float z_ = 0.f)
	: x(x_),  y(y_),  z(z_)
    {}

    void set(float x_, float y_, float z_)
    {
	x = x_;
	y = y_;
	z = z_;
    }

    void set(float v_)
    {
	x = v_;  y = v_;  z = v_;
    }
    
    // 正規化
    Vec3& normalize();
    Vec3 getNormalized() const;

    // 内積
    float dot(const Vec3& vec) const;
    
    // 外積
    Vec3& cross(const Vec3& vec);
    Vec3 getCrossed(const Vec3& vec) const;

    Vec3 operator+(const Vec3& vec) const;
    Vec3 operator-(const Vec3& vec) const;
    Vec3 operator*(const Vec3& vec) const;
    Vec3 operator/(const Vec3& vec) const;
    Vec3 operator-() const;
    Vec3& operator+=(const Vec3& vec);
    Vec3& operator-=(const Vec3& vec);
    Vec3& operator*=(const Vec3& vec);
    Vec3& operator/=(const Vec3& vec);

    union
    {
	struct
	{
	    float x, y, z;
	};
	float m[3];
    };
};

inline Vec3& Vec3::normalize()
{
    float len = sqrt(x*x + y*y + z*z);
    if (len > 0)
    {
	x /= len;
	y /= len;
	z /= len;
    }
}
inline Vec3 Vec3::getNormalized() const
{
    float len = sqrt(x*x + y*y + z*z);
    if (len > 0)
    {
	return Vec3(x/len, y/len, z/len);
    }
    else
    {
	return Vec3();
    }
}

inline float Vec3::dot(const Vec3& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z;
}

inline Vec3& Vec3::cross(const Vec3& vec)
{
    float x_ = y * vec.z - z * vec.y;
    float y_ = z * vec.x - x * vec.z;
    z = x * vec.y - y * vec.x;
    x = x_;
    y = y_;
    return *this;
}
inline Vec3 Vec3::getCrossed(const Vec3& vec) const
{
    return Vec3(y * vec.z - z * vec.y,
		z * vec.x - x * vec.z,
		x * vec.y - y * vec.x);
}

//------------------
// operator 演算子
//------------------
inline Vec3 Vec3::operator+(const Vec3& vec) const
{
    return Vec3(x + vec.x, y + vec.y, z + vec.z);
}
inline Vec3 Vec3::operator-(const Vec3& vec) const
{
    return Vec3(x - vec.x, y - vec.y, z - vec.z);
}
inline Vec3 Vec3::operator*(const Vec3& vec) const
{
    return Vec3(x * vec.x, y * vec.y, z * vec.z);
}
inline Vec3 Vec3::operator/(const Vec3& vec) const
{
    return Vec3(vec.x != 0 ? x / vec.x : x,
		vec.y != 0 ? y / vec.y : y,
		vec.z != 0 ? z / vec.z : z);
}
inline Vec3 Vec3::operator-() const
{
    return Vec3(-x, -y, -z);
}

//------------------
// operator 代入演算子
//------------------
inline Vec3& Vec3::operator+=(const Vec3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}
inline Vec3& Vec3::operator-=(const Vec3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}
inline Vec3& Vec3::operator*=(const Vec3& vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
    return *this;
}
inline Vec3& Vec3::operator/=(const Vec3& vec)
{
    vec.x != 0 ? x /= vec.x : x;
    vec.y != 0 ? y /= vec.y : y;
    vec.z != 0 ? z /= vec.z : z;
    return *this;
}

#endif // VEC3_H_
