#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

int x0=20,y0=20; //starting points
int xmax=10, ymax=12;// number of points to be plotted on x(10) and y(12) axis
int incx=20,incy=25;
int x[100],y[100];

void meshpoints(int x[],int y[]){

   for(int i=0;i<xmax;i++){
        x[i]=x0 + i*incx;
   }
   for(int i=0;i<ymax;i++){
        y[i]=y0 + i*incy;
   }
}

int drawline(int x0,int y0,int x1,int y1){

   glColor3f(1,0,0);
   glBegin(GL_LINES);
   glVertex2i(x0,y0);
   glVertex2i(x1,y1);
   glEnd();
}

void drawmesh(int x[],int y[]){

    glColor3f(1,0,0);
    for(int i=0;i<ymax;i++){

        drawline(x[0],y[i],x[xmax-1],y[i]);
    }
    for(int i=0;i<ymax;i++){

        drawline(x[i],y[0],x[i],y[ymax-1]);
    }
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
  meshpoints(x,y);
  drawmesh(x,y);
  glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Rectangular Mesh");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
