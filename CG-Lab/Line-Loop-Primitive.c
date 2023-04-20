#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void drawShape(){
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    // glBegin(GL_LINE_LOOP);
    glVertex2i(100,100);
    glVertex2i(150,100);
    glVertex2i(150,50);
    glEnd();
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,300,0,300);
}

void display(){
    drawShape();
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Mid Point line algorithm");
    init();
    display();
    glutMainLoop();
    return 0;
}
