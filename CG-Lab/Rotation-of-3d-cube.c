#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// because 3D cube has 8 vertices and 3 dimensions
int cube[8][3]={
      {-1,-1,-1},
      {1,-1,-1},
      {1,1,-1},
      {-1,1,-1},
      {-1,-1,1},
      {1,-1,1},
      {1,1,1},
      {-1,1,1}
};

int axis=0;
int theta[3]={0,0,0};


void spin(){
     theta[axis]=theta[axis]+1;
     if(theta[axis]>360){
        theta[axis]=0;
     }
     display();
}

// used to render 1 surface of a cube (which needs 4 vertices)
void polygon(int a,int b,int c,int d){
   glBegin(GL_POLYGON);
   glVertex3iv(cube[a]);
   glVertex3iv(cube[b]);
   glVertex3iv(cube[c]);
   glVertex3iv(cube[d]);
   glEnd();
}

void changeaxis(char ch,int x,int y){
     if(ch=='x'){
        axis=1;
     }
     if(ch=='y'){
        axis=2;
     }
     if(ch=='z'){
        axis=0;
     }
}

void drawCube(){
    glColor3f(1,0,0);
    polygon(0,1,2,3);
    glColor3f(0,1,0);
    polygon(4,5,6,7);
    glColor3f(0,0,1);
    polygon(0,3,7,4);
    glColor3f(0,1,1);
    polygon(1,2,6,5);
    glColor3f(1,0,1);
    polygon(0,1,5,4);
    glColor3f(1,1,0);
    polygon(2,3,7,6);
}

void rotate(){
    glPushMatrix();
    glRotatef(theta[0],1,0,0);
    glRotatef(theta[1],0,1,0);
    glRotatef(theta[2],0,0,1);
    drawCube();
    glPopMatrix();
}

void init(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glOrtho(-2,2,-2,2,2,-2);
}

void display(){
     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     rotate();
     glutSwapBuffers(); // It will swap the required buffer and will use the right buffer for rendering. glFlush() is inherently built inside this
}

int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Cube");
    init();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST); // closer will be enabled and the back will be hidden
    glutIdleFunc(spin);
    glutKeyboardFunc(changeaxis);
    glutMainLoop();
    return 0;
}
