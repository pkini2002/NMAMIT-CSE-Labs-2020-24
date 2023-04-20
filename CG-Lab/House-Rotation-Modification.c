// OpenGL House Transformations
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

float xp=100;
float yp=100;

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

void rotateHouse(){
     glPushMatrix();
     glTranslatef(100,100,0);
     glRotatef(30,0,0,1);
     glTranslatef(-100,-100,0);
     drawhouse(houseMatrix);
     glPopMatrix();
}

void changeTranslate(){
   glPushMatrix();
   glTranslatef(50,50,0);
   drawhouse(houseMatrix);
   glPopMatrix();
}

void changeScale(){
   glPushMatrix();
   glScalef(0.5,0.5,0);
   glTranslatef(50,50,0);
   drawhouse(houseMatrix);
   glPopMatrix();
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
     glColor3f(1,0,0);
     drawhouse(houseMatrix);
     //changeTranslate();
     //changeScale();
     rotateHouse();
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
