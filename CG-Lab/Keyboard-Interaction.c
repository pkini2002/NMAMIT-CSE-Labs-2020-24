// Keyboard Interaction

#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

void drawline(){
   glColor3f(1,0,0);
   glBegin(GL_LINES);
   glVertex2i(100,100);
   glVertex2i(400,400);
   glEnd();
}

void drawrectangle(){
   glColor3f(1,0,0);
   glBegin(GL_LINE_LOOP);
   glVertex2i(100,100);
   glVertex2i(300,100);
   glVertex2i(300,300);
   glVertex2i(100,300);
   glEnd();
}


void init()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
}

void mykb(char ch,int x,int y){
    if(ch == 'l' || ch == 'L'){
        glClearColor(1,1,1,1);
        glClear(GL_COLOR_BUFFER_BIT);
        drawline();
        glFlush();
    }
    if(ch == 'r' || ch == 'R'){
        glClearColor(1,1,1,1);
        glClear(GL_COLOR_BUFFER_BIT);
        drawrectangle();
        glFlush();
    }
    if(ch == 'q' || ch == 'Q'){
        exit(0);
    }
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Keyboard Interaction OpenGL");
    init();
    glutKeyboardFunc(mykb);
    glutMainLoop();
    return 0;
}
