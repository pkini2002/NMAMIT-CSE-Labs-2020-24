#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int A[2]={100,100};
int B[2]={300,100};
int C[2]={300,300};
int D[2]={100,300};

void draw(){
   glColor3f(0,1,0);
   glBegin(GL_LINE_LOOP);
   glVertex2iv(A);
   glVertex2iv(B);
   glVertex2iv(C);
   glVertex2iv(D);
   glEnd();
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
   draw();
   glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Vertex 1-d array");
    init();
    display();
    glutMainLoop();
    return 0;
}
