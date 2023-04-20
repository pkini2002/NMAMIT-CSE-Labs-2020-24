// House rotation about an arbitrary point (Xp,Yp)

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float houseMatrix[9][3]={
    {100,100,1},
    {300,100,1},
    {300,300,1},
    {100,300,1},
    {200,400,1},
    {175,100,1},
    {175,200,1},
    {225,200,1},
    {225,100,1}
};

float result[9][3];
float xp=100;
float yp=100;
int degree=30;

void drawhouse(float mat[9][3]){
     glColor3f(1,0,0);
     glBegin(GL_LINE_LOOP);
     glVertex2fv(mat[0]);
     glVertex2fv(mat[1]);
     glVertex2fv(mat[2]);
     glVertex2fv(mat[3]);
     glEnd();

     glBegin(GL_LINE_STRIP);
     glVertex2fv(mat[2]);
     glVertex2fv(mat[4]);
     glVertex2fv(mat[3]);
     glEnd();

     glBegin(GL_LINE_STRIP);
     glVertex2fv(mat[5]);
     glVertex2fv(mat[6]);
     glVertex2fv(mat[7]);
     glVertex2fv(mat[8]);
     glEnd();
}

void rotateHouse(float mat[9][3]){
    float theta=3.142/180*degree;
    float Ra[3][3]={
        {
            cos(theta),sin(theta),0
        },
        {
            -sin(theta),cos(theta),0
        },
        {
            -xp*cos(theta)+yp*sin(theta)+xp,
            -xp*sin(theta)-yp*cos(theta)+yp,
            1
        }
    };

    for(int i=0;i<9;i++){
        for(int j=0;j<3;j++){
            result[i][j]=0;
            for(int k=0;k<3;k++){
                result[i][j]+=houseMatrix[i][k]*Ra[k][j];
            }
        }
    }
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
     glColor3f(1,0,0);
     drawhouse(houseMatrix);
     rotateHouse(houseMatrix);
     drawhouse(result);
     glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Rotation of house about arbitrary point");
    init();
    display();
    glutMainLoop();
    return 0;
}
