// On 1st keyboard press draw polygon and on 2nd keyboard key press fill polygon

//Modification:  Fill the polygon on keyboard key press

#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

int a[2]={200, 200};
int b[2]={100, 300};
int c[2]={200, 400};
int d[2]={300, 300};
int le[500];
int re[500];
int polygonDrawn=0;

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

void display(){
    glColor3f(1, 0, 0);
    if(polygonDrawn){
    drawpolygon(a, b, c, d);
    }
    glFlush();
}

void mykb(unsigned char ch,int x,int y){
   if(ch>='a' && ch<='z'){
       if (!polygonDrawn) {
            polygonDrawn = 1;
            display();
        } else {
            polyfill(a, b, c, d);
        }
   }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Polygon");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(mykb);
    glutMainLoop();
    return 0;
}
