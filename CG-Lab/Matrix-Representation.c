#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int rect[4][2]={{100,100},{300,100},{300,300},{100,300}};


void drawrect(){
   glColor3f(1,0,0);
   glBegin(GL_LINE_LOOP);
   glVertex2iv(rect[0]);
   glVertex2iv(rect[1]);
   glVertex2iv(rect[2]);
   glVertex2iv(rect[3]);
   glEnd();
}

void display(){
    glColor3f(1, 0, 0);
    drawrect();
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc,char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("2-D Array Matrix form");
    init();
    display();
    glutMainLoop();
    return 0;
}
