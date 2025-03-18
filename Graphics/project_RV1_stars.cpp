#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

float starSize=20;
bool starStatus=1;
float starBorderY=700;


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1600.0, 0.0, 900.0, -1.0, 1.0);
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

void drawStars(float centerX, float centerY, float size, bool status)
{
    if (status==1)
    {
        glColor3f( 1,1,1);
    }
    else
    {
        glColor3f( 0,0,0);
    }

    glBegin(GL_POLYGON);
    float deduct = size/5;
    glVertex2f(centerX-deduct,centerY-deduct);
    glVertex2f(centerX,centerY-size);  //axis
    glVertex2f(centerX+deduct,centerY-deduct);
    glVertex2f(centerX+size,centerY);    //axis
    glVertex2f(centerX+deduct,centerY+deduct);
    glVertex2f(centerX,centerY+size);    //axis
    glVertex2f(centerX-deduct,centerY+deduct);
    glVertex2f(centerX-size,centerY);    //axis
    glEnd();
    Sleep(100);

}

void Draw()
{

    glClear(GL_COLOR_BUFFER_BIT);
    //scaling
    glColor3f(1,0,0);
    for(int i=0; i<=900; i+=100)
    {
        glBegin(GL_LINES);
        glVertex2f(0,i);
        glVertex2f(20,i);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(1600,i);
        glVertex2f(1580,i);
        glEnd();
    }
    for(int i=0; i<=1600; i+=100)
    {
        glBegin(GL_LINES);
        glVertex2f(i,900);
        glVertex2f(i,880);
        glEnd();
        glBegin(GL_LINES);
        glVertex2f(i,0);
        glVertex2f(i,20);
        glEnd();
    }

    drawStars(100, starBorderY + 100, starSize, starStatus); // 1
    drawStars(150, starBorderY + 90, starSize, !starStatus); // 2
    drawStars(220, starBorderY + 80, starSize, !starStatus); // 3
    drawStars(350, starBorderY + 100, starSize, starStatus); // 4
    drawStars(400, starBorderY - 20, starSize, !starStatus); // 5
    drawStars(500, starBorderY + 70, starSize, !starStatus); // 6
    drawStars(550, starBorderY + 100, starSize - 7, starStatus); // 7
    drawStars(650, starBorderY + 80, starSize - 7, starStatus); // 8
    drawStars(700, starBorderY + 120, starSize - 7, starStatus); // 9
    drawStars(730, starBorderY + 90, starSize - 6, !starStatus); // 10
    drawStars(800, starBorderY + 60, starSize + 5, starStatus); // 11
    drawStars(850, starBorderY + 85, starSize, !starStatus); // 12
    drawStars(900, starBorderY + 75, starSize - 5, !starStatus); // 13
    drawStars(1000, starBorderY - 30, starSize + 2, starStatus); // 14
    drawStars(1050, starBorderY + 70, starSize - 4, !starStatus); // 15
    drawStars(1100, starBorderY - 50, starSize + 10, starStatus); // 16
    drawStars(150, starBorderY + 65, starSize - 3, !starStatus); // 17
    drawStars(250, starBorderY + 90, starSize, starStatus); // 18
    drawStars(300, starBorderY + 50, starSize + 4, !starStatus); // 19
    drawStars(400, starBorderY + 40, starSize - 2, starStatus); // 20
    starStatus = !starStatus;

    glColor3f( 1,1,1);
    circle (30,30,1450,750);
    glutPostRedisplay();    // Request redisplay
    glutSwapBuffers();      // Swap buffers for smooth animation
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1600, 900);
    glutCreateWindow("Project_UFO");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
