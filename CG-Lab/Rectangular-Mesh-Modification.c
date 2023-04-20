// Modification: Reshape the size of the window and fit to all dimensions using aspect ratio

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

void init(int width,int height){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    float aspect=(float)width/height;
    glViewport(0,0,width,height);
    glLoadIdentity();
    if(width >= height){
      gluOrtho2D(0*aspect,500*aspect,0,500);  // when width > height value of x axis changes ie; left and right
    }
    else{
       gluOrtho2D(0,500,0/aspect,500/aspect);
    }
}

void display(){
  meshpoints(x,y);
  drawmesh(x,y);
  glFlush();
}

int main(int argc,char *argv)
{
    glutInit(&argc,argv);
    glutCreateWindow("Rectangular Mesh");
    glutReshapeFunc(init);
    glutDisplayFunc(display);
    glutMainLoop();
}
