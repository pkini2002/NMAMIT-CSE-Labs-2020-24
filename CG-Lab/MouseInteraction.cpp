#include<stdio.h>
#include<GL/glut.h>

void drawline(){
   glColor3f(0,1,0);
   glBegin(GL_LINES);
   glVertex2i(100,100);
   glVertex2i(400,200);
   glEnd();
}

void drawrect(){
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100,100);
    glVertex2i(300,100);
    glVertex2i(300,300);
    glVertex2i(100,300);
    glEnd();
}

void mymouse(int btn,int state,int x,int y){
   if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
     glClearColor(1,1,1,1);
     glClear(GL_COLOR_BUFFER_BIT);
     drawline();
     glFlush();
   }

   if(btn == GLUT_RIGHT_BUTTON && state==GLUT_DOWN){
      glClearColor(1,1,1,1);
      glClear(GL_COLOR_BUFFER_BIT);
      drawrect();
      glFlush();
   }
   if(btn == GLUT_MIDDLE_BUTTON && state==GLUT_DOWN){
      exit(0);
   }
}

void init(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char *argv[]){
    glutInit(&argc,argv);
    glutCreateWindow("Mouse Interaction");
    glutDisplayFunc(init);
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}
