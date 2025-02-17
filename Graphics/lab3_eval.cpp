#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>>

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy){

    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(cx,cy);
    for(int i=0 ; i<100 ; i++){
        float angle = 2*3.14 *i/50;
        float x=rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f( 1 ,0, 0);
	circle(9,9,32,20);
	circle(9,9,20,25);
	circle(9,9,20,12);
	circle(9,9,10,23);
	circle(9,9,3,19);
	circle(7,7,-5,12);
	circle(9,9,5,10);
	glutSwapBuffers();
}

int main(int argc,char **argv)
{

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
