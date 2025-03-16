#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float y=20;

void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 100, 0.0, 100.0, -1.0, 1.0);
}


void Draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
   glColor3f( 0 ,0, 1);

   if (y<=120){                     //120 to make it look like its going up
   y=y+0.01;                       // for speed comntrol and smoothness
   }
   else{
   y=0;                           // to make it look like its coming from bottom
   }                              // Note: both y=120 and y=-20 are out of bounds (intentionally)

   glutPostRedisplay();

   glBegin(GL_QUADS);            //clockwise
   glVertex2f(40,y);
   glVertex2f(50,y);
   glVertex2f(50,y-20);
   glVertex2f(40,y-20);

   glEnd();

glutSwapBuffers();
}

int main(int argc,char **argv){


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
