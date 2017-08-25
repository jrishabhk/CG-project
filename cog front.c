#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void strokeString(float x,float y,float sx,float sy,char *string,int width)
{
	char *c;
	glLineWidth(width);
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(sx,sy,0);
	for (c=string; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void title()
{       glClearColor(0.1,0.1,0.1,0.1);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0,1000.0,0.0,1000.0,0.0,1000.0);
	      glColor3f(0.3,0.3,1.0);
        strokeString(30,850,0.35,0.35,"BANGALORE INSTITUTE OF TECHNOLOGY",2);
        glColor3f(0,1,0);
        strokeString(100,750,0.3,0.3,"DEPARTMENT OF COMPUTER SCIENCE",2);
        strokeString(300,670,0.3,0.3,"AND ENGINEERING",2);
        strokeString(200,500,0.3,0.3,"AN OPENGL MINI PROJECT ON",1);
        glColor3f(0.5,0.5,1);
        strokeString(40,420,0.4,0.4,"3D FIGURE with Centre Of Gravity",3);
        glColor3f(0.5,0.5,1);

        strokeString(50,100,0.17,0.17,"1. Use right button of the mouse for menu options ",1);
        strokeString(50,50,0.17,0.17,"2. Press (q) to start the simulation",1);
        strokeString(650,200,0.15,0.15,"By:",1);
        glColor3f(0,0.5,1);
        strokeString(650,160,0.18,0.18,"J RISHABH KUAMR",1);
        strokeString(650,30,0.2,0.2,"D.R NAGAMANI",1);
        strokeString(650,0,0.2,0.2,"BHAVANA K V",1);
        glColor3f(1,0,0);
        strokeString(650,120,0.18,0.18,"1BI14CS059",1);
        strokeString(650,60,0.15,0.15,"Under the guidance of.",1);

	glutSwapBuffers();



}

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     glClearColor(0.8, 0.9, 0.7, 1.0);
     gluOrtho2D(0.0,800.0,0.0,800.0);
    glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key,int x,int y)
{
  if(key=='q')
    exit(0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Centre of gravity Doll front page");
  glutDisplayFunc(title);
	init();
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  	return 0;
  }
