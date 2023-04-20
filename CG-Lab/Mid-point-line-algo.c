#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,300,0,300);
}

void draw(){
   glColor3f(1,0,0);
   glBegin(GL_LINES);
   glVertex2i(0,0);
   glVertex2i(100,100);
   glEnd();
}

void display(){
    draw();
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Plotting Line");
    init();
    display();
    glutMainLoop();
    return 0;
}
