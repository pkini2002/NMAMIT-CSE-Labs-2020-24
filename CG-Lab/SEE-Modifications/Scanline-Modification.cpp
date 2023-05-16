// Clip 2 lines drawn on rectangle

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define top 8
#define bottom 4
#define right 2
#define left 1
#define true 1
#define false 0

int xmin=50;
int ymin=50;
int xmax=200;
int ymax=200;
double x0=70;
double y0=30;
double x1=70;
double y1=250;

double x2=150;
double y2=30;
double x3=150;
double y3=250;


void drawRectangle(int xmin,int ymin,int xmax,int ymax){
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();
}

void drawline(double x0,double y0,double x1,double y1){
     glColor3f(0,0,1);
     glBegin(GL_LINES);
     glVertex2d(x0,y0);
     glVertex2d(x1,y1);
     glEnd();
}

int computeCode(double x,double y,int xmin,int ymin,int xmax,int ymax){
    int code=0; // Binary: 0000
    if(y>ymax){
        code=code|top;
    }
    if(y<ymin){
        code=code|bottom;
    }
    if(x>xmax){
        code=code|right;
    }
    if(x<xmin){
        code=code|left;
    }
    return code;
}

void cohenClip(double x0,double y0,double x1,double y1,int xmin,int ymin,int xmax,int ymax){
   int outcode0,outcode1,outcode;
   int accept=false;
   int done=false;
   double x,y; //Used for calculating intersecting values
   outcode0=computeCode(x0,y0,xmin,ymin,xmax,ymax);
   outcode1=computeCode(x1,y1,xmin,ymin,xmax,ymax);
   do{
     // Test 1
     if((outcode0 | outcode1)==0){
        accept=true;
        done=true;
     }
     // Test 2
     else if((outcode0 & outcode1)!=0){
        done=true;
     }
     // Clipping Operation
     else{
        if(outcode0){
            outcode=outcode0;
        }
        else{
            outcode=outcode1;
        }

        // Top Clip
        if(outcode & top){
            y=ymax;
            x=x0+(x1-x0)*(y-y0)/(y1-y0);
        }
        // Bottom Clip
        else if(outcode & bottom){
            y=ymin;
            x=x0+(x1-x0)*(y-y0)/(y1-y0);
        }
        // Right clip
        else if(outcode & right){
            x=xmax;
            y=y0+(y1-y0)*(x-x0)/(x1-x0);
        }
        // Left clip
        else{
            x=xmin;
            y=y0+(y1-y0)*(x-x0)/(x1-x0);
        }

        if(outcode = outcode0){
            x0=x;
            y0=y;
            outcode0=computeCode(x0,y0,xmin,ymin,xmax,ymax);
        }
        else{
            x1=x;
            y1=y;
            outcode1=computeCode(x1,y1,xmin,ymin,xmax,ymax);
        }
     }
   }while(!done);

   drawRectangle(xmin+200,ymin,xmax+200,ymax);
   if(accept){
       drawline(x0+200,y0,x1+200,y1);
   }
}


void cohenClip1(double x2,double y2,double x3,double y3,int xmin,int ymin,int xmax,int ymax){
   int outcode0,outcode1,outcode;
   int accept=false;
   int done=false;
   double x,y; //Used for calculating intersecting values
   outcode0=computeCode(x2,y2,xmin,ymin,xmax,ymax);
   outcode1=computeCode(x3,y3,xmin,ymin,xmax,ymax);
   do{
     // Test 1
     if((outcode0 | outcode1)==0){
        accept=true;
        done=true;
     }
     // Test 2
     else if((outcode0 & outcode1)!=0){
        done=true;
     }
     // Clipping Operation
     else{
        if(outcode0){
            outcode=outcode0;
        }
        else{
            outcode=outcode1;
        }

        // Top Clip
        if(outcode & top){
            y=ymax;
            x=x2+(x3-x2)*(y-y2)/(y3-y2);
        }
        // Bottom Clip
        else if(outcode & bottom){
            y=ymin;
             x=x2+(x3-x2)*(y-y2)/(y3-y2);
        }
        // Right clip
        else if(outcode & right){
            x=xmax;
            y=y2+(y3-y2)*(x-x2)/(x3-x2);
        }
        // Left clip
        else{
            x=xmin;
            y=y2+(y3-y2)*(x-x2)/(x3-x2);
        }

        if(outcode = outcode0){
            x2=x;
            y2=y;
            outcode0=computeCode(x2,y2,xmin,ymin,xmax,ymax);
        }
        else{
            x3=x;
            y3=y;
            outcode1=computeCode(x3,y3,xmin,ymin,xmax,ymax);
        }
     }
   }while(!done);

   drawRectangle(xmin+200,ymin,xmax+200,ymax);
   if(accept){
       drawline(x2+200,y2,x3+200,y3);
   }
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
   glColor3f(1,0,0);
   drawRectangle(xmin,ymin,xmax,ymax);
   drawline(x0,y0,x1,y1);
   drawline(x2,y2,x3,y3);
   glColor3f(0,1,0);
   cohenClip(x0,y0,x1,y1,xmin,ymin,xmax,ymax);
   cohenClip(x2,y2,x3,y3,xmin,ymin,xmax,ymax);
   glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Cohen Sutherland");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
