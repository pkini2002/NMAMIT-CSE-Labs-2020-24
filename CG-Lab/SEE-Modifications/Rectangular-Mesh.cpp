// Change the Color of the mesh to red,green and blue on pressing r,g and b keys

#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

int x0=20,y0=20; //starting points
int xmax=10, ymax=12;// number of points to be plotted on x(10) and y(12) axis
int incx=20,incy=25;
int x[100],y[100];

float red=0.0f;
float green=0.0f;
float blue=0.0f;

void display();

void mykb(unsigned char ch,int x,int y){
   if(ch=='r'){
     red=1; green=0;blue=0;
     display();
   }
   else if(ch=='g'){
     red=0;green=1;blue=0;
     display();
   }
   else if(ch=='b'){
    red=0;green=0;blue=1;
    display();
   }
}

void meshpoints(int x[],int y[]){

   for(int i=0;i<xmax;i++){
        x[i]=x0 + i*incx;
   }
   for(int i=0;i<ymax;i++){
        y[i]=y0 + i*incy;
   }
}

int drawline(int x0,int y0,int x1,int y1,float red,float green,float blue){

   glColor3f(red,green,blue);
   glBegin(GL_LINES);
   glVertex2i(x0,y0);
   glVertex2i(x1,y1);
   glEnd();
}

void drawmesh(int x[],int y[],float red,float green,float blue){

    glColor3f(red,green,blue);
    for(int i=0;i<ymax;i++){

        drawline(x[0],y[i],x[xmax-1],y[i],red,green,blue);
    }
    for(int i=0;i<ymax;i++){

        drawline(x[i],y[0],x[i],y[ymax-1],red,green,blue);
    }
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
  meshpoints(x,y);
  drawmesh(x,y,red,green,blue);
  glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Rectangular Mesh");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(mykb);
    glutMainLoop();
}
