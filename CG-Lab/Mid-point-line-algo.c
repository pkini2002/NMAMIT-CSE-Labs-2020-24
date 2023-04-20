#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int x0=50;
int y0=50;
int x1=200;
int y1=200;

void midpointline(int x0,int y0,int x1,int y1){
    int dx=x1-x0;
    int dy=y1-y0;
    int incE=dy;
    int incNE=dy-dx;

    //Calculate initial decision
    int d=2*dy-dx;
    int x=x0;
    int y=y0;
    plot(x,y);

    while(x<x1){
        if(d<=0){
            // Choose pixel E
            d=d+2*incE;
            x=x+1;
        }
        else{
            // Choose pixel NE
            d=d+2*incE;
            x=x+1;
            y=y+1;
        }
        plot(x,y);
    }
}

void plot(int x,int y){
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,300,0,300);
}

void display(){
    midpointline(x0,y0,x1,y1);
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
