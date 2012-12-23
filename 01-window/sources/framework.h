#ifndef FRAMEWORK_H_
#define FRAMEWORK_H_

#include <stdio.h>
#include "OpenGL.h"
#include "types.h"

class Framework
{
public:
    struct CreateArg
    {
	CreateArg()
	    : argc(0),
	      argv(NULL),
	      width(640),
	      height(480),
	      windowTitle(NULL)
	    {}
	int argc;
	char** argv;
	uint width;
	uint height;
	char* windowTitle;
    };

    Framework(CreateArg* pArg);

    void Run();

    void DisplayFunc();
    void ReshapeFunc(int w, int h);
    void IdleFunc();
};

#endif // FRAMEWORK_H_
