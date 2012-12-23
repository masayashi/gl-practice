#ifndef GL_H_
#define GL_H_

#ifdef WIN32
    #include <windows.h>
#endif

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
    #include <OpenGL/glext.h>
#elif WIN32
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif

#endif
