#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char   uchar;
typedef unsigned int    uint;

#ifndef PI
#define PI 3.14159265258979
#endif

#ifndef DEG_TO_RAD
#define DEG_TO_RAD(x)  ((x * PI) / 180.f)
#endif

#ifndef RAD_TO_DEG
#define RAD_TO_DEG(x)  ((x * 180.f) / PI)
#endif

#endif//TYPES_H_
