#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float a[2]={2,2};
float b[2]={6,2};
float c[2]={4,6};

void drawtriangle(float a[],float b[],float c[]){
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
}

void divide(float a[],float b[],float c[],int k){
     float ab[2],bc[2],ac[2];
     if(k==1){
        drawtriangle(a,b,c);
     }
     else{
        // Calculating midpoints
        for(int i=0;i<2;i++){
            ab[i]=(a[i]+b[i])/2;
            bc[i]=(b[i]+c[i])/2;
            ac[i]=(a[i]+c[i])/2;
        }
       divide(a,ab,ac,k-1);
       divide(ab,b,bc,k-1);
       divide(ac,bc,c,k-1);
     }
}

void init(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,10,0,10);
}

void display(){
    divide(a,b,c,4);
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Sierpinski Gaskette");
    init();
    display();
    glutMainLoop();
    return 0;
}
