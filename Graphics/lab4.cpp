#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;

int x=0;
int y,pk,r;

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}


void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f( 1 ,0, 0);
	glBegin(GL_POINTS);
	pk=1-r;
	while (x<=y){
        if (pk<0){
            x=x+1;
            y=y;
            pk= pk+2*x+1;
        }
        else{
            x=x+1;
            y=y-1;
            pk=pk+2*x+1-2*y;
        }
        glVertex2i(x,y);
        glVertex2i(y,x);
        glVertex2i(-x,y);
        glVertex2i(-y,x);
        glVertex2i(-x,-y);
        glVertex2i(-y,-x);
        glVertex2i(x,-y);
        glVertex2i(y,-x);

	}
	glEnd();
	glutSwapBuffers();
}

int main(int argc,char **argv)
{

    cin>>r;
	y=r;

	glutInit(&argc,argv);
	glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("Lab Final");
	init();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
