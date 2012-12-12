#include "mtx44.h"

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "types.h"
#include "Vec3.h"
#include "Vec4.h"

Mtx44::Mtx44()
{
    memset(m, 0, sizeof(m));
}

void Mtx44::ortho(
    float left, float right,
    float bottom, float top,
    float near, float far)
{
    float tx = right - left;
    float ty = top - bottom;
    float tz = far - near;
    setRow(0, 2.f / tx, 0, 0, 0);
    setRow(1, 0, 2.f / ty, 0, 0);
    setRow(2, 0, 0, -2.f / tz, 0);
    setRow(3, -(right + left) / tx, -(top + bottom) / ty, -(far + near) / tz, 1);
}

void Mtx44::frustum(
    float left, float right,
    float bottom, float top,
    float near, float far)
{
    if (near == 0) printf("frustum can't near = 0\n");
    float w = right - left;
    float h = top - bottom;
    float d = far - near;
    setRow(0, (2 * near) / w, 0, 0, 0);
    setRow(1, 0, (2 * near) / h, 0, 0);
    setRow(2, (right + left) / w, (top + bottom) / h,  -(far + near) / d, -1);
    setRow(3, 0, 0,  -(2 * far * near) / d, 0);
}

void Mtx44::perspective(
    float fovy, float aspectRate,
    float near, float far)
{
    float tan_fovy = tan(DEG_TO_RAD(fovy * 0.5f));
    float right    = tan_fovy * aspectRate * near;
    float left     = -right;
    float top      = tan_fovy * near;
    float bottom = -top;
    frustum(left, right, bottom, top, near, far);
/*    double tan_fovy = tan(fovy*0.5*DEG_TO_RAD);
    double right  =  tan_fovy * aspectRatio * zNear;
    double left   = -right;
    double top    =  tan_fovy * zNear;
    double bottom =  -top;
    makeFrustumMatrix(left,right,bottom,top,zNear,zFar);*/

}

void Mtx44::lookat(
    float ex, float ey, float ez,
    float tx, float ty, float tz,
    float ux, float uy, float uz)
{
    Vec3 eye(ex, ey, ez);
    Vec3 target(tx, ty, tz);
    Vec3 up(ux, uy, uz);
    lookat(eye, target, up);
}

void Mtx44::lookat(const Vec3& eye, const Vec3& target, const Vec3& up)
{
    /*
      [note] z軸はカメラ位置から視線方向へのベクトル。
       x軸はz軸と上方向に垂直なので両者の外積。
       y軸はz軸とx軸に垂直なので両者の外積。
       平行移動成分は各軸に対してカメラ位置に合うように移動。
    */
    Vec3 zaxis = (eye - target).getNormalized();
    Vec3 xaxis = up.getCrossed(zaxis).getNormalized();
    Vec3 yaxis = zaxis.getCrossed(xaxis);
    setRow(0, xaxis.x, yaxis.x, zaxis.x, 0);
    setRow(1, xaxis.y, yaxis.y, zaxis.y, 0);
    setRow(2, xaxis.z, yaxis.z, zaxis.z, 0);
    setRow(3, -xaxis.dot(eye), -yaxis.dot(eye), -zaxis.dot(eye), 1);
}

Mtx44& Mtx44::identity()
{
    setRow(0, 1, 0, 0, 0);
    setRow(1, 0, 1, 0, 0);
    setRow(2, 0, 0, 1, 0);
    setRow(3, 0, 0, 0, 1);
    return *this;
}

void Mtx44::dump()
{
    printf("%f\t%f\t%f\t%f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
    printf("%f\t%f\t%f\t%f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
    printf("%f\t%f\t%f\t%f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
    printf("%f\t%f\t%f\t%f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
}

Mtx44 Mtx44::operator * (const Mtx44 &mtx)
{
    Mtx44 r;
    for(int i=0; i<4; i++){
	for(int j=0; j<4; j++){
	    for(int k=0; k<4; k++){
		r.m[i][j] += m[i][k] * mtx.m[k][j];
	    }
	}
    }
    return r;
}

Vec4 Mtx44::operator * (const Vec4 &v)
{
    Vec4 ret;
    ret.x = x0 * v.x + x1 * v.y + x2 * v.z + x3 * v.w;
    ret.y = y0 * v.y + y1 * v.y + y2 * v.z + y3 * v.w;
    ret.z = z0 * v.z + z1 * v.y + z2 * v.z + z3 * v.w;
    ret.w = w0 * v.w + w1 * v.y + w2 * v.z + w3 * v.w;
    return ret;
}

