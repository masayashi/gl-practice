
#include <stdio.h>
#include "framework.h"

int main()
{
    Framework::CreateArg arg;
    Framework fw(&arg);

    fw.Run();

    return 0;
}

