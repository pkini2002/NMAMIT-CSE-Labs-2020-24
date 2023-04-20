#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

int a[2]={200, 200};
int b[2]={100, 300};
int c[2]={200, 400};
int d[2]={300, 300};
int le[500];
int re[500];

void arrayinit(int le[],int re[]){
     int i;
     for(i=0;i<500;i++){
        le[i]=999;
        re[i]=0;
     }
}

void edgedetect(int v0[],int v1[]){
     double xmin,ymin,xmax,ymax,x,m; // double is used to avoid divide by 0
     int y;
     if(v0[1]<v1[1]){
        ymin=v0[1];
        xmin=v0[0];
        ymax=v1[1];
        xmax=v1[0];

     }
     else{
        ymin=v1[1];
        xmin=v1[0];
        xmax=v0[0];
        ymax=v0[1];
     }

     m=(ymax-ymin)/(xmax-xmin);
     x=xmin;

     for(y=ymin;y<=ymax;y++){
        if(x<le[y]){
            le[y]=x;
        }
        if(x>re[y]){
            re[y]=x;
        }
        x=x+(1/m);
     }
}

void fillpixel(int le[],int re[]){
    int i,j;
    for(int i=0;i<500;i++){
       if(le[i]<=re[i]){
        for(j=le[i];j<=re[i];j++){
            glColor3f(1,0,0);
            glBegin(GL_POINTS);
            glVertex2i(j,i);
            glEnd();
            glFlush();
        }
       }
    }
}

void drawpolygon(int a[], int b[], int c[], int d[]){
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2iv(a);
    glVertex2iv(b);
    glVertex2iv(c);
    glVertex2iv(d);
    glEnd();
}

void polyfill(int a[],int b[],int c[],int d[]){
       arrayinit(le,re);
       edgedetect(a,b);
       edgedetect(b,c);
       edgedetect(c,d);
       edgedetect(d,a);
       fillpixel(le,re);
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 500, 0, 500);
}

void mymouse(int btn,int state,int x,int y){
    if(btn  == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        polyfill(a,b,c,d);
        glFlush();
    }
    if(btn == GLUT_RIGHT_BUTTON && state ==  GLUT_DOWN){
        exit(0);
    }
}

void display(){
    glColor3f(1, 0, 0);
    drawpolygon(a, b, c, d);
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Polygon");
    init();
    display();
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}
