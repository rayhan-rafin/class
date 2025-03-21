#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <cmath>
#include <stdio.h>


#define HORIZON_DISTANCE 400


//global variables
//stars
float starSize=15;
bool starStatus=1;
float starBorderY=700;
float lastStarDrawTime=0;
//sheeps
//sheep1
bool sheep1Right = true;
int sheep1Dir = -1, sheep1Pause = 0;
float sheep1x = 100;
//sheep2
bool sheep2Right = false;
int sheep2Dir = 1, sheep2Pause = 0;
float sheep2x = 250;
//flowers
bool flowerRight = false;
float flowerx = 1400, flowery = 40;
float flowerDir = 1;
float flowerBottom = flowerx;
float grassStart = flowerx;
float grassStart2 = grassStart+100;
//cloud
float cloudx=0, cloudy = 720;
//UFO
float ufoSize = 10;
float ufoPosx = 1600;
float ufoPosy = 780;

//functions
void moveUFO(int value);
void moveUFO1 (int value);
void moveUFO2 (int value);
void moveUFO3 (int value);
void drawUFOLight();


void init(void)
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1600, 0, 900, -1.0, 1.0);
    //for opacity control
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}



void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(cx,cy);
    int division = 1;
    for(int i=0 ; i<=60 ; i++)
    {
        float angle = 2*3.14 *i/50;
        float x=rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}

void halfCircle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(cx,cy);
    for(int i=0 ; i<=25 ; i++)
    {
        float angle = 2*3.14 *i/50;
        float x=rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}

void inverseHalfCircle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=70 ; i<=80 ; i++)
    {
        float angle = 2*3.14 *i/100;
        float x=rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}



void drawStars(float centerX, float centerY, float size, bool status)
{
    if (status)
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
}


void drawAllStars()
{
    drawStars(100, starBorderY + 100, starSize, starStatus); // 1
    drawStars(150, starBorderY + 90, starSize, starStatus); // 2
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
    drawStars(170, starBorderY + 65, starSize - 3, !starStatus); // 17
    drawStars(250, starBorderY + 90, starSize, starStatus); // 18
    drawStars(300, starBorderY + 50, starSize + 4, !starStatus); // 19
    drawStars(400, starBorderY + 40, starSize - 2, starStatus); // 20
}

void blinkStars(int value)
{
    starStatus = !starStatus;
    glutPostRedisplay();
    glutTimerFunc(1000, blinkStars, 0);
}


void drawMoon()
{
    for (int i=0; i<=50; i++)
    {
        float p = i/100.0;
        glColor3f(1*p, 1*p, 1*p);
        circle(35+50-i,35+50-i,1450,750);
    }
    glColor3f( 1,1,1);
    circle (35,35,1450,750);
}

void drawHill(GLfloat rx, GLfloat ry, GLfloat cx)
{
    float cy = HORIZON_DISTANCE;
    glColor3f(0.4, 0.2, 0.0); //brown
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(cx,cy);
    for(int i=0 ; i<=25 ; i++)
    {
        float angle = 2*3.14 *i/50;
        float x=rx*cosf(angle);
        float y=ry*sinf(angle);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}


void drawAllHills()
{
    drawHill(90, 130, 90);
    drawHill(70, 90, 230);
    drawHill(70, 70, 360);
    drawHill(100, 150, 490);
    drawHill(80, 120, 650);
    drawHill(70, 80, 760);
    drawHill(90, 100, 870);
    drawHill(90, 130, 1010);
    drawHill(100, 150, 1180);
    drawHill(70, 90, 1320);
    drawHill(70, 120, 1430);
    drawHill(80, 90, 1520);
}


void drawTree(float x)
{
    float y = HORIZON_DISTANCE;

    // Draw trunk
    glColor3f(0.2, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(x - 1, y);
    glVertex2f(x + 1, y);
    glVertex2f(x + 1, y + 30);
    glVertex2f(x - 1, y + 30);
    glEnd();

    // Draw leaves
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 10, y + 20);
    glVertex2f(x + 10, y + 20);
    glVertex2f(x, y + 40);
    glEnd();
}

void drawAllTrees()
{
    drawTree(50);
    drawTree(300);
    drawTree(430);
    drawTree(610);
    drawTree(750);
    drawTree(1080);
    drawTree(1200);
    drawTree(1500);
}


void drawField()
{
    glBegin(GL_QUADS);
    glColor3f(0.1f, 0.5f, 0.1f); // Dark green (bottom)
    glVertex2f(0, 0);
    glVertex2f(1600, 0);

    glColor3f(0.6f, 0.6f, 0.3f); // Light green (top near horizon)
    glVertex2f(1600, HORIZON_DISTANCE);
    glVertex2f(0, HORIZON_DISTANCE);
    glEnd();
}


void drawFencePillar(float x, float y)
{
    glLineWidth(3);
    glColor3f(0.6, 0.5, 0.0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y+30);
    glEnd();
}


void drawFence()
{
    //fence pillars
    for(int i=0; i<=900; i+=10)
    {
        drawFencePillar(i,300);
    }
    for(float i=0,j=700; i<=300; i+=10)
    {
        j+=(200/30.0);
        drawFencePillar(j, i);
    }

    //fence horizontal lines
    glLineWidth(3);
    glColor3f(0.6, 0.5, 0.0);
    glBegin(GL_LINES);
    glVertex2f(0, 310);
    glVertex2f(910, 310);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0, 320);
    glVertex2f(910, 320);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(700, 0);
    glVertex2f(910, 310);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(700, 10);
    glVertex2f(910, 320);
    glEnd();
}


void drawGrass(float x, float y)
{
    glLineWidth(3);
    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x, y+=10);
    glEnd();
}


void drawAllGrass()
{
    float grassEnd = 700;
    for(int j=0; j<=280; j+=60)
    {
        for(int i=0; i<=grassEnd; i+=60)
        {
            drawGrass(i,j);
        }
        grassEnd+=35;
    }
    grassEnd = 700;
    for(int j=30; j<=280; j+=60)
    {
        for(int i=30; i<=grassEnd; i+=60)
        {
            drawGrass(i,j);
        }
        grassEnd+=35;
    }
}


void drawSheep(float x, float y, int direction)
{
    //direction = 1 (facing left)
    //direction = -1 (facing right)

    glColor3f(0,0,0);       //black color
    circle(10,10,x-(35*direction),y);   //head
    circle(30,20,x,y);      //body background
    circle(5,5,x+(32*direction),y+5);   //tail

    //legs
    glBegin(GL_LINES);
    glVertex2f(x-10, y);
    glVertex2f(x-10, y-25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x-15, y);
    glVertex2f(x-15, y-25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x+10, y);
    glVertex2f(x+10, y-25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x+15, y);
    glVertex2f(x+15, y-25);
    glEnd();

    glColor3f(1,1,1);       //white color
    circle(28,18,x,y);      //body
    circle(2,2,x-(40*direction),y+2);   //eye

}


void drawTargetSheep(float x, float y)
{
    glColor3f(0,0,0);       //black color
    circle(10,10,x+33,y-8);   //head
    circle(30,20,x,y);      //body background
    circle(5,5,x-32,y+5);   //tail

    //legs
    glBegin(GL_LINES);
    glVertex2f(x-10, y);
    glVertex2f(x-10, y-25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x-15, y);
    glVertex2f(x-15, y-25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x+10, y);
    glVertex2f(x+10, y-25);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x+15, y);
    glVertex2f(x+15, y-25);
    glEnd();

    glColor3f(1,1,1);       //white color
    circle(28,18,x,y);      //body
    circle(2,2,x+37,y-12);   //eye
}



void moveSheep1(int value)
{
    if(sheep1Pause>0)
    {
        sheep1Pause-=10;
    }
    else if(sheep1Right)
    {
        sheep1Dir = -1;
        sheep1x += 0.7;
        if(sheep1x >= 300)
        {
            sheep1Right = false;
            sheep1Pause = 1000;
        }
    }
    else
    {
        sheep1x -= 0.7;
        sheep1Dir = 1;
        if(sheep1x <= 100)
        {
            sheep1Right = true;
            sheep1Pause = 1000;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, moveSheep1, 0);
}


void moveSheep2(int value)
{
    if(sheep2Pause>0)
    {
        sheep2Pause-=10;
    }
    else if(sheep2Right)
    {
        sheep2Dir = -1;
        sheep2x += 0.5;
        if(sheep2x >= 250)
        {
            sheep2Right = false;
            sheep2Pause = 1000;
        }
    }
    else
    {
        sheep2x -= 0.5;
        sheep2Dir = 1;
        if(sheep2x <= 150)
        {
            sheep2Right = true;
            sheep2Pause = 1000;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, moveSheep2, 0);
}


void drawAllSheeps()
{
    drawSheep(sheep1x,100,sheep1Dir);
    drawSheep(sheep2x,150,sheep2Dir);
    drawTargetSheep(500,100);
}


void graph(int n)
{
    //graph
    glColor3f(1,0,0);
    for(int i=0; i<=900; i+=n)
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
    for(int i=0; i<=1600; i+=n)
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

}

void drawBarn()
{
    //front
    glColor3f(0.671f, 0.208f, 0.141f);
    glBegin(GL_POLYGON);
    glVertex2f(1100,200);
    glVertex2f(1400,175);
    glVertex2f(1400,475);
    glVertex2f(1257,607);
    glVertex2f(1100,500);
    glEnd();

    //side
    glColor3f(0.6f, 0.18f, 0.12f);
    glBegin(GL_POLYGON);
    glVertex2f(1400,175);
    glVertex2f(1600,195);
    glVertex2f(1600,475);
    glVertex2f(1400,475);
    glEnd();


    //shade
    glColor3f(0.139f, 0.131f, 0.175f);
    glBegin(GL_POLYGON);
    glVertex2f(1070,490);
    glVertex2f(1100,490);
    glVertex2f(1256,606);
    glVertex2f(1240,620);
    glEnd();

    //roof
    glColor3f(0.137f, 0.114f, 0.129f);
    glBegin(GL_POLYGON);
    glVertex2f(1415,460);
    glVertex2f(1600,465);
    glVertex2f(1600,570);
    glVertex2f(1240,620);
    glEnd();
}



void drawDoor()
{
    glBegin(GL_QUADS);
    glColor3f(0.67f, 0.39f, 0.11f);
    glVertex2f(1190, 192);
    glVertex2f(1290, 184);
    glColor3f(0, 0, 0);
    glVertex2f(1290, 345);
    glVertex2f(1190, 350);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.25f, 0.1f);
    glVertex2f(1255, 192);
    glVertex2f(1290, 184);
    glVertex2f(1290, 345);
    glVertex2f(1255, 342);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.25f, 0.1f);
    glVertex2f(1255, 192);
    glVertex2f(1290, 184);
    glVertex2f(1290, 345);
    glVertex2f(1255, 342);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.25f, 0.1f);
    glVertex2f(1190, 192);
    glVertex2f(1225, 192);
    glVertex2f(1225, 342);
    glVertex2f(1190, 350);
    glEnd();
}


void drawWindow()
{
    glBegin(GL_QUADS);
    glColor3f(0.647f, 0.824f, 1.0f);
    glVertex2f(1205, 421);
    glVertex2f(1275, 420);
    glVertex2f(1275, 480);
    glVertex2f(1205, 479);
    glEnd();
    glColor3f(1,1,1);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2f(1205, 422);
    glVertex2f(1275, 421);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(1273, 420);
    glVertex2f(1273, 480);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(1275, 479);
    glVertex2f(1205, 478);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(1208, 479);
    glVertex2f(1208, 421);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(1240, 479);
    glVertex2f(1240, 421);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(1205, 451);
    glVertex2f(1275, 451);
    glEnd();
}



void drawLightBulb()
{
    //bulb
    glColor3f(1,1,0);
    circle(8,8,1240,400);

    //cover
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(1240, 415);
    glColor3f(0.5,0.5,0);
    glVertex2f(1225, 395);
    glVertex2f(1255, 395);
    glEnd();

    //light
    glColor4f(1,1,0,0.3);
    glBegin(GL_POLYGON);
    glVertex2f(1085, 170);
    glVertex2f(1395, 170);
    glVertex2f(1255, 395);
    glVertex2f(1225, 395);
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(1240,170);
    for(int i=25 ; i<=50 ; i++)
    {
        float angle = 2*3.14 *i/50;
        float x=155*cosf(angle);
        float y=30*sinf(angle);
        glVertex2f(x+1240,y+170);
    }
    glEnd();
}



void drawFlowers()
{
    //flower set1
    //flower1
    glLineWidth(2);
    glColor3f(0,0.3,0);
    glBegin(GL_LINES);
    glVertex2f(flowerx, flowery);
    glVertex2f(flowerBottom, flowery-40);
    glEnd();
    glColor3f(0.2, 0.1, 0.1);
    circle(5, 5, flowerx, flowery);
    glColor3f(1,1,0);
    circle(5, 5, flowerx+10, flowery);
    circle(5, 5, flowerx-10, flowery);
    circle(5, 5, flowerx, flowery+10);
    circle(5, 5, flowerx, flowery-10);
    //flower2
    glColor3f(0,0.3,0);
    glBegin(GL_LINES);
    glVertex2f(flowerx+30, flowery+20);
    glVertex2f(flowerBottom+30,flowery-40);
    glEnd();
    glColor3f(0.2, 0.1, 0.1);
    circle(5, 5, flowerx+30, flowery+20);
    glColor3f(1,1,0);
    circle(5, 5, flowerx+40, flowery+20);
    circle(5, 5, flowerx+20, flowery+20);
    circle(5, 5, flowerx+30, flowery+30);
    circle(5, 5, flowerx+30, flowery+10);



    float flowerx2 = flowerx + 100;
    float flowerBottom2 = flowerBottom +100;
    //set2
    glLineWidth(2);
    glColor3f(0,0.3,0);
    glBegin(GL_LINES);
    glVertex2f(flowerx2, flowery);
    glVertex2f(flowerBottom2, flowery-40);
    glEnd();
    glColor3f(0.2, 0.1, 0.1);
    circle(5, 5, flowerx2, flowery);
    glColor3f(1,1,0);
    circle(5, 5, flowerx2+10, flowery);
    circle(5, 5, flowerx2-10, flowery);
    circle(5, 5, flowerx2, flowery+10);
    circle(5, 5, flowerx2, flowery-10);
    //flower2
    glColor3f(0,0.3,0);
    glBegin(GL_LINES);
    glVertex2f(flowerx2+30, flowery+20);
    glVertex2f(flowerBottom2+30,flowery-40);
    glEnd();
    glColor3f(0.2, 0.1, 0.1);
    circle(5, 5, flowerx2+30, flowery+20);
    glColor3f(1,1,0);
    circle(5, 5, flowerx2+40, flowery+20);
    circle(5, 5, flowerx2+20, flowery+20);
    circle(5, 5, flowerx2+30, flowery+30);
    circle(5, 5, flowerx2+30, flowery+10);


    //flowergrass
    glColor3f(0,0.3,0);
    glBegin(GL_POLYGON);
    glVertex2f(grassStart, 0);
    glVertex2f(grassStart+30, 0);
    glVertex2f(grassStart+50, 20);
    glVertex2f(grassStart+20, 10);
    glVertex2f(grassStart+15, 20);
    glVertex2f(grassStart+10, 10);
    glVertex2f(grassStart-20, 20);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(grassStart2, 0);
    glVertex2f(grassStart2+30, 0);
    glVertex2f(grassStart2+50, 20);
    glVertex2f(grassStart2+20, 10);
    glVertex2f(grassStart2+15, 20);
    glVertex2f(grassStart2+10, 10);
    glVertex2f(grassStart2-20, 20);
    glEnd();
}



void moveFlowers(int value)
{
    if(flowerRight)
    {
        flowerDir = -1;
        flowerx += 0.05;
        if(flowerx>=1400)
        {
            flowery-=0.01;
        }
        else
        {
            flowery+=0.01;
        }
        if(flowerx >= 1402)
        {
            flowerRight = false;
        }
    }
    else
    {
        flowerx -= 0.05;
        flowerDir = 1;
        if(flowerx>=1400)
        {
            flowery+=0.01;
        }
        else
        {
            flowery-=0.01;
        }
        if(flowerx <= 1398)
        {
            flowerRight = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(10, moveFlowers, 0);
}

void drawCloud(float x)
{
    glColor4f(0.078f, 0.12f, 0.150f, 0.97);
    halfCircle(150, 10, x+150, cloudy);
    halfCircle(30, 10, x+50, cloudy);
    halfCircle(40, 20, x+80, cloudy);
    halfCircle(40, 30, x+130, cloudy);
    halfCircle(50, 50, x+180, cloudy);
    halfCircle(50, 35, x+220, cloudy);
    halfCircle(30, 10, x+270, cloudy);

    halfCircle(200, 20, x+550, cloudy);
    halfCircle(20, 10, x+400, cloudy);
    halfCircle(40, 20, x+450, cloudy);
    halfCircle(50, 40, x+500, cloudy);
    halfCircle(70, 50, x+570, cloudy);
    halfCircle(50, 40, x+640, cloudy);
    halfCircle(40, 20, x+680, cloudy);
}

void drawCloudSet1()
{
    drawCloud(cloudx);
    drawCloud(cloudx+800);
}
void drawCloudSet2()
{
    float cloudx2;
    if(cloudx<0) cloudx2 = cloudx+1600;
    else cloudx2 = cloudx-1600;

    drawCloud(cloudx2);
    drawCloud(cloudx2+800);
}

void moveCloud(int value)
{
    cloudx -= 2.0;
    if (cloudx < -1600)
    {
        cloudx = 1600;
    }
    glutPostRedisplay();
    glutTimerFunc(30, moveCloud, 0);
}

void drawAllClouds()
{
    drawCloudSet1();
    drawCloudSet2();
}
void drawUFO()
{
    glColor3f(1,1,1);                           //dome
    circle(ufoSize,ufoSize,ufoPosx,ufoPosy);
    glColor3f(0,0,1);                           //body
    circle (ufoSize*3,ufoSize,ufoPosx,(ufoPosy-ufoSize));
    glutPostRedisplay;
}



void moveUFO1(int value){
    if (ufoPosx>1000)
    {
        ufoPosx-=1;
        drawUFO();
        glutTimerFunc(10, moveUFO1, 0);
    }
    else{
        glutTimerFunc(1000, moveUFO2, 0);
    }
}

void moveUFO2 (int value){
    if (ufoPosx>=500){
        ufoPosy =  sqrt(288.8*ufoPosx-144400)+400;                             //288.8x = (y-400)^2 + 144400, check dc
        ufoSize = -(3*ufoPosy/38)+71.579;                            //goes through (780,10) and (400,40) point
        drawUFO();
        glutTimerFunc(5, moveUFO2, 0);
        ufoPosx-=1;
    }
    else {
        glutPostRedisplay();
        glutTimerFunc(3000, moveUFO3, 0);
    }
}

void moveUFO3 (int value){
    if(ufoPosy<900){
        ufoPosy+=1;
        ufoSize = -(3*ufoPosy/38)+71.579;
        drawUFO();
        glutTimerFunc(5, moveUFO3, 0);
    }
    else {
        ufoPosx = 1600;
        ufoPosy = 780;
        ufoSize = 10;
        moveUFO(0);
    }
}

void moveUFO(int value)
{
    //float initialPosx = ufoPosx;
    glutPostRedisplay();

    moveUFO1(0);

}
void drawUFOLight(){
    glColor3f(1,1,0);
    circle (ufoSize/2,ufoSize/3,ufoPosx,(ufoPosy-ufoSize));

    for (int i=0; i<300;i++){
        glColor4f(1,1,0,0.3);
        inverseHalfCircle(i,i,ufoPosx,(ufoPosy-ufoSize));
    }
    glutPostRedisplay();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAllStars();
    drawMoon();
    drawAllHills();
    drawAllTrees();
    drawField();
    drawFence();
    drawAllGrass();
    drawAllSheeps();
    drawBarn();
    drawDoor();
    drawWindow();
    drawLightBulb();
    drawFlowers();
    drawAllClouds();
    drawUFO();
    //drawUFOLight();

    if (ufoPosx==499 && ufoPosy==400){
        drawUFOLight();
    }

    //drawing now-------------------------------------------------------------------------------------------------

    //------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    graph(100);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1600, 900);
    glutCreateWindow("Alien Invasion");
    init();
    glutDisplayFunc(Draw);
    blinkStars(0);
    moveSheep1 (0);
    moveSheep2 (0);
    moveFlowers (0);
    moveCloud (0);
    moveUFO(0);
    glutMainLoop();
    return 0;
}
