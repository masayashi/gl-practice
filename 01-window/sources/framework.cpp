#include "framework.h"
#include "macro.h"

Framework* gpFw;


void DisplayFunc_Static()
{
    gpFw->DisplayFunc();
}
void ReshapeFunc_Static(int w, int h)
{
    gpFw->ReshapeFunc(w, h);
}
void IdleFunc_Static()
{
    gpFw->IdleFunc();
}

//------------------------------------------------------------------------------
Framework::Framework(CreateArg* pArg)
{
    if ( pArg == NULL ) { return; }

    LOG("\n=== START APP ================================================================\n\n");

    glutInit(&pArg->argc, pArg->argv);
    glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
    glutInitWindowSize(pArg->width, pArg->height);
    glutCreateWindow(pArg->windowTitle);

    glutDisplayFunc(DisplayFunc_Static);
    glutReshapeFunc(ReshapeFunc_Static);
    glutIdleFunc(IdleFunc_Static);

    gpFw = this;
}

//------------------------------------------------------------------------------
void Framework::Run()
{
    glutMainLoop();
}

//------------------------------------------------------------------------------
void Framework::DisplayFunc()
{
}

//------------------------------------------------------------------------------
void Framework::ReshapeFunc(int w, int h)
{
}

//------------------------------------------------------------------------------
void Framework::IdleFunc()
{
}

