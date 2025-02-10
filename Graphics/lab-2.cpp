#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<iostream>
using namespace std;

int x,y,x1,x2,y1,y2,dy,dx,pk,step;

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000.0, 0.0, 1000.0, -1.0, 1.0);
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 1 ,0, 0);
    dy = y2-y1;
    dx = x2-x1;
    pk = 2*dy-dx;


         //check loop step
    if (dy>dx)
    {
        step = dy;
    }
    else
    {
        step=dx;
    }

    //main loop
    glBegin(GL_POINTS);
    for (int i=0; i<step; i++)
    {
        if (pk<0)
        {
            x=x+1;
            y=y;
            pk=pk+2*dy;
            glVertex2i(x,y);

        }
        else {
            x=x+1;
            y=y+1;
            pk= pk+2*dy - 2*dx;
            glVertex2i(x,y);
        }
    }
    glEnd();
    glutSwapBuffers();
}

int main(int argc,char **argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    cout<<"start value: "<<endl;
    cin>>x1>>y1;
    cout<<"end value: "<<endl;
    cin>>x2>>y2;
    glutCreateWindow("Lab eval-1");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
