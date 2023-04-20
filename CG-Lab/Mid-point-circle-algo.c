#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int R; // R is a radius

void midpointCircle(int R){
    // Calculation of initial decision
    double d=5.0/4.0-R;
    int x=0;
    int y=R;
    circlePoints(x,y);

    while(x<y){
        if(d<0){
            //Choose pixel E
            d=d+2*x+3;
            x=x+1;
        }
        else{
            // Choose pixel SE
            d=d+2*(x-y)+5;
            x=x+1;
            y=y-1;
        }
        circlePoints(x,y);
    }
}

void circlePoints(int x,int y){
    plot(x,y);
    plot(x,-y);
    plot(-x,y);
    plot(-x,-y);
    plot(y,x);
    plot(-y,x);
    plot(y,-x);
    plot(-y,-x);
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
   gluOrtho2D(-100,100,-100,100);
}

void display(){
   midpointCircle(R);
   glFlush();
}

int main(int argc,char *argv[])
{
    printf("Enter the radius: \n");
    scanf("%d",&R);
    glutInit(&argc,argv);
    glutCreateWindow("Mid Point Circle algorithm");
    init();
    display();
    glutMainLoop();
    return 0;
}
