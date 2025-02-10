#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<iostream>
using namespace std;


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
    glBegin(GL_LINES);
    glVertex2i(100,100);
    glVertex2i(600,100);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(600,100);
    glVertex2i(600,600);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(600,600);
    glVertex2i(100,600);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(100,600);
    glVertex2i(100,100);
    glEnd();
    glutSwapBuffers();
}

int main(int argc,char **argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab eval-1");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
