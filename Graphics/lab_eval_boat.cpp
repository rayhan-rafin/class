#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include<math.h>>




void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1000, 0.0, 1000.0, -1.0, 1.0);

}
void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
    {

        glBegin(GL_TRIANGLE_FAN);
        glVertex2i(cx,cy);
        for(int i=0 ; i<100 ; i++)
        {
            float angle = 2*3.14 *i/50;
            float x=rx*cosf(angle);
            float y=ry*sinf(angle);
            glVertex2f(x+cx,y+cy);
        }
        glEnd();
    }

void semicircle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
    {

        glBegin(GL_TRIANGLE_FAN);
        glVertex2i(cx,cy);
        for(int i=11 ; i<14 ; i++)
        {
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

    //chimney
    glColor3f( 1,1, 0);
    semicircle(250,250,320,450);
    glColor3f( 1,0, 0);
    semicircle(210,210,320,450);

    glColor3f( 1,1, 0);
    semicircle(250,250,400,430);
    glColor3f( 1,0, 0);
    semicircle(210,210,400,430);

    glColor3f( 1,1, 0);
    semicircle(250,250,480,400);
    glColor3f( 1,0, 0);
    semicircle(210,210,480,400);

    glColor3f( 1,1, 0);
    semicircle(250,250,560,360);
    glColor3f( 1,0, 0);
    semicircle(210,210,560,360);

    //boat er front
    glColor3f( 0,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(200,200);
    glVertex2i(250,200);
    glVertex2i(230,500);
    glVertex2i(180,450);
    glEnd();

    //boat er hull
    glColor3f( 0,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(250,200);
    glVertex2i(600,170);
    glVertex2i(630,370);
    glVertex2i(232,430);
    glEnd();

    //hull er white line
    glColor3f( 1,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(232,430);
    glVertex2i(630,370);
    glVertex2i(632,380);
    glVertex2i(232,440);
    glEnd();

    //face block
    glColor3f( 0,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(260,450);
    glVertex2i(590,400);
    glVertex2i(600,450);
    glVertex2i(360,570);
    glVertex2i(260,560);
    glEnd();

    //hull er yellow line
    glColor3f( 1,1, 0);
    glBegin(GL_POLYGON);
    glVertex2i(232,440);
    glVertex2i(632,380);
    glVertex2i(634,410);
    glVertex2i(230,500);
    glEnd();

    //wave
    glColor3f( 0,1,0);
    circle(45,40,210,190);
    circle(45,40,280,190);
    circle(45,40,340,180);
    circle(45,40,400,200);
    circle(45,40,460,190);
    circle(45,40,510,180);
    circle(60,40,600,180);

    circle(45,40,250,170);

    circle(45,40,380,160);

    circle(45,40,500,170);

    //cloud
    glColor3f( 0,0,1);
    circle(15,15,350,750);
    circle(15,15,360,760);
    circle(15,15,370,780);

    glColor3f( 0,0,1);
    circle(15,15,440,750);
    circle(15,15,450,760);
    circle(15,15,460,780);

    glColor3f( 0,0,1);
    circle(15,15,530,730);
    circle(15,15,540,740);
    circle(15,15,550,760);

    glColor3f( 0,0,1);
    circle(15,15,620,680);
    circle(15,15,630,690);
    circle(15,15,640,710);

    //hull er red circle
    glColor3f( 1,0,0);
    circle(12,15,500,370);
    circle(12,15,530,365);
    circle(12,15,560,360);
    circle(12,15,590,355);

    //face er circle
    glColor3f( 1,0,0);
    circle(11,14,380,540);
    circle(11,14,410,530);
    circle(11,14,440,515);
    circle(11,14,470,500);
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
