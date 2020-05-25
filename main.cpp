#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "field.h"
#include "rectangle.h"
using namespace std;

//размер пол€
int s=4;
int S=s*s;
int X0=80, Y0=60;

int w=400;
int h=500;

int number1=0;
int number2=0;
int tab=0;
bool start=0;

int wR=50, hR=70, step=10;


vector<Rectangle> Rs;

bool compareRecs(Rectangle R1, Rectangle R2)
{
    return (R1<R2);
}



void setColor()
{
    Rs.resize(16);
    Rs[0].setColor(0.0, 0.0, 1.0);
    Rs[1].setColor(0.33, 0.06, 0.8);
    Rs[2].setColor(0.66, 0.13, 0.6);
    Rs[3].setColor(1.0, 0.2, 0.4);
    Rs[4].setColor(0.16, 0.23, 1.0);
    Rs[5].setColor(0.44, 0.26, 0.81);
    Rs[6].setColor(0.72, 0.29, 0.62);
    Rs[7].setColor(1.0, 0.32, 0.43);
    Rs[8].setColor(0.3, 0.5, 1.0);
    Rs[9].setColor(0.44, 0.44, 0.81);
    Rs[10].setColor(0.72, 0.46, 0.62);
    Rs[11].setColor(1.0, 0.48, 0.43);
    Rs[12].setColor(0.16, 0.70, 1.0);
    Rs[13].setColor(0.44, 0.66, 0.84);
    Rs[14].setColor(0.72, 0.61, 0.68);
    Rs[15].setColor(1.0, 0.57, 0.52);
}

//придавание пр€моугольникам фейковых ид (фейковое id это текущее ид пр€моугольника) но как минимум 4 по углам оставл€ютс€ насто€щие ид, то есть, они закреплены


void renameAll2()
{
    Rs[0].setFid(0);//
    Rs[1].setFid(7);
    Rs[2].setFid(5);
    Rs[3].setFid(3);//
    Rs[4].setFid(9);
    Rs[5].setFid(6);
    Rs[6].setFid(8);
    Rs[7].setFid(1);
    Rs[8].setFid(4);
    Rs[9].setFid(11);
    Rs[10].setFid(10);
    Rs[11].setFid(2);
    Rs[12].setFid(12);//
    Rs[13].setFid(14);
    Rs[14].setFid(13);
    Rs[15].setFid(15);
    sort(Rs.begin(), Rs.end(), compareRecs);
}

//задание координат

void setCoord()
{
    int k=0;
    for(int i=0; i<s; i++)
    {
        for (int j=0; j<s; j++)
        {
            Rs[k].setPosition(X0+j*(wR+step), Y0+i*(hR+step));
            k++;
        }
    }
}

//функци€ замены пр€моугольников

void replaceRecs(int number1, int number2)
{
    Rectangle Temp;
    Temp.setPosition(Rs[number1].getX(), Rs[number1].getY());

    Temp.setFid(Rs[number1].getFid());
    Rs[number1].setPosition(Rs[number2].getX(), Rs[number2].getY());
    Rs[number1].setFid(Rs[number2].getFid());

    Rs[number2].setPosition(Temp.getX(), Temp.getY());
    Rs[number2].setFid(Temp.getFid());

    tab=0;
}


//отрисовка пол€

void drawingField(int wR, int Hr)
{
    for (int i=0; i<S; i++)
    {
        Rs[i].drawingRec(wR, hR);
    }
}


void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, (GLdouble)w, (GLdouble)h, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        if (state == GLUT_DOWN) // && (y>Y0 && y<(Rs[S].getY()+hR)) && (x>X0 && x<Rs[S].getX()+wR))
        {
            for (int k=1; k<S; k++)
            {
                if (k!=s-1 && k!=S-1 && k!=S-s)
                {
                    if(y>Rs[k].getY() && y<(Rs[k].getY()+hR) && x>Rs[k].getX() && x<(Rs[k].getX()+wR))
                    {
                        if(tab==0)
                        {
                            number1=k;
                            tab=1;
                            break;
                        }
                        if(tab==1)
                        {
                            number2=k;
                            tab=2;
                            break;
                        }
                    }
                }
            }
        }
    }
    if(tab==2)
    {
        replaceRecs(number1, number2);
        glutPostRedisplay();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if(start==0)
    {
        setColor();
        renameAll2();
        setCoord();
        start=1;
    }

    drawingField(wR, hR);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Colors");
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMouseFunc(mouseFunc);

    glutMainLoop();

    return 0;
}

