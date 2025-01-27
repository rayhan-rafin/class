#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>


void init(void)
{
  glClearColor(1.0,1.0,1.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 300, 0.0, 300.0, -1.0, 1.0);
}


void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 1 ,1, 0);

   glBegin(GL_POLYGON);


   glVertex2i(83,133);  //x
   glVertex2i(100,100);
   glVertex2i(116,133);  //x
   glVertex2i(150,150);
   glVertex2i(116,166);  //x
   glVertex2i(100,200);
   glVertex2i(83,166);  //x
   glVertex2i(50,150);
   glEnd();

   glColor3f( 0 ,1, 0);
   glBegin(GL_POLYGON);
   glVertex2i(183,133);  //x
   glVertex2i(200,100);
   glVertex2i(216,133);  //x
   glVertex2i(250,150);
   glVertex2i(216,166);  //x
   glVertex2i(200,200);
   glVertex2i(183,166);  //x
   glVertex2i(150,150);
   glEnd();

   glColor3f( 1 ,0, 0);
   glBegin(GL_POLYGON);
   glVertex2i(133,183);  //x
   glVertex2i(150,150);
   glVertex2i(166,183);  //x
   glVertex2i(200,200);
   glVertex2i(166,216);  //x
   glVertex2i(150,250);
   glVertex2i(133,216);  //x
   glVertex2i(100,200);
   glEnd();

   glColor3f( 0 ,0, 1);
   glBegin(GL_POLYGON);
   glVertex2i(133,83);  //x
   glVertex2i(150,50);
   glVertex2i(166,83);  //x
   glVertex2i(200,100);
   glVertex2i(166,116);  //x
   glVertex2i(150,150);
   glVertex2i(133,116);  //x
   glVertex2i(100,100);
   glEnd();


glutSwapBuffers();
}

int main(int argc,char **argv){


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
