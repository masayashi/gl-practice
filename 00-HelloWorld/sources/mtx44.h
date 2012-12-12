#ifndef MTX44_H_
#define MTX44_H_

#include <math.h>
#include "vec3.h"
#include "vec4.h"

class Mtx44
{
public:

    Mtx44();

    //--- 行、列の設定
    void setRow(int index, float m0, float m1, float m2, float m3) {
	m[index][0] = m0;
	m[index][1] = m1;
	m[index][2] = m2;
	m[index][3] = m3;
    }
    void setRow(int index, const Vec4& v) {
	m[index][0] = v.x;
	m[index][1] = v.y;
	m[index][2] = v.z;
	m[index][3] = v.w;
    }
    void setColumn(int index, float m0, float m1, float m2, float m3) {
	m[0][index] = m0;
	m[1][index] = m1;
	m[2][index] = m2;
	m[3][index] = m3;
    }
    void setColumn(int index, const Vec4& v) {
	m[0][index] = v.x;
	m[1][index] = v.y;
	m[2][index] = v.z;
	m[3][index] = v.w;
    }

    //--- 行列変換系の変数設定
    void setScale(float s) {
	m[0][0] *= s;
	m[1][1] *= s;
	m[2][2] *= s;
    }
    void translate(const Vec3& v) {
	m[3][0] = v.x;
	m[3][1] = v.y;
	m[3][2] = v.z;
    }
    
    //--- カメラ行列系
    void ortho(
	float left, float right,
	float bottom, float top,
	float near, float far);
    
    void frustum(
	float left, float right,
	float bottom, float top,
	float near, float far);

    void perspective(
	float fovy, float aspectRate,
	float near, float far);
    
    void lookat(
	float ex, float ey, float ez,
	float tx, float ty, float tz,
	float ux, float uy, float uz);

    void lookat(const Vec3& eye, const Vec3& target, const Vec3& up);

    Mtx44& identity();

    float* getArray() {
	return reinterpret_cast<float*>(m);
    }

    void dump();

    Mtx44 operator * (const Mtx44 &mtx);
    Vec4 operator * (const Vec4 &vec);

    union
    {
	struct
	{
	    float x0, x1, x2, x3;
	    float y0, y1, y2, y3;
	    float z0, z1, z2, z3;
	    float w0, w1, w2, w3;
	};
	float m[4][4];
    };

protected:

};


#endif // MTX44_H_
