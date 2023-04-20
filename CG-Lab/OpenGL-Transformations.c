#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int rect[4][2]={
  {100,100},{300,100},{300,300},{100,300}
};

void drawrect(){
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2iv(rect[0]);
    glVertex2iv(rect[1]);
    glVertex2iv(rect[2]);
    glVertex2iv(rect[3]);
    glEnd();
}

// Translation
void change(){
   glPushMatrix();
   glTranslatef(50,50,0);
   drawrect();
   glPopMatrix();
}

// Scaling
void changeScale(){
   glPushMatrix();
   glScalef(0.5,0.5,0);
   glTranslatef(50,50,0);
   drawrect();
   glPopMatrix();
}

// Rotation
void changeRotate(){
  glPushMatrix();
  glTranslatef(100,100,0);
  glRotatef(30,0,0,1);
  glTranslatef(-100,-100,0);
  drawrect();
  glPopMatrix();
}

void init(){
   glClearColor(1,1,1,1);
   glClear(GL_COLOR_BUFFER_BIT);
   gluOrtho2D(0,500,0,500);
}

void display(){
    drawrect();
    //change();
    // changeScale();
    changeRotate();
    glFlush();
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutCreateWindow("Transformation");
    init();
    display();
    glutMainLoop();
    return 0;
}
