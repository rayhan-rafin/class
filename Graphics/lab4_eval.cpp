#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>>

void init(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500.0, 500.0, -500.0, 500.0, -1.0, 1.0);
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
	glColor3f( 0 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-500,-500);
    glVertex2i(500,-500);
    glVertex2i(500,-210);
    glVertex2i(-500,-210);
    glEnd();


    circle(120,60,-400,-210);
    circle(120,60,-200,-210);
    circle(120,60,400,-210);
    circle(120,60,200,-210);

    //boat
    glColor3f( 1 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-100,-210);
    glVertex2i(100,-210);
    glVertex2i(200,-100);
    glVertex2i(-200,-100);
    glEnd();

    //3 columns
    glColor3f( 1 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(-150,-100);
    glVertex2i(-100,-100);
    glVertex2i(-100,150);
    glVertex2i(-150,150);
    glEnd();

    glColor3f( 0 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(-100,-100);
    glVertex2i(-50,-100);
    glVertex2i(-50,120);
    glVertex2i(-100,120);
    glEnd();

    glColor3f( 0 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(-50,-100);
    glVertex2i(100,-100);
    glVertex2i(-50,70);
    glEnd();

    //pole
    glColor3f( 0 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(150,-100);
    glVertex2i(160,-100);
    glVertex2i(160,150);
    glVertex2i(150,150);
    glEnd();

    //flag
    glColor3f( 0 ,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(160,30);
    glVertex2i(350,30);
    glVertex2i(350,150);
    glVertex2i(160,150);
    glEnd();

    glColor3f( 1 ,0, 0);
    circle(50,50,250,90);

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
