#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;

static GLfloat xRestore = 0.05f;
static GLfloat yRestore = 0.05f;
static GLfloat wobx,woby,wobDecay=0.7;
GLfloat hat[3]={0.8f,0.2f,0.2f},head[3]={1.0f,1.0f,1.0f};
static GLfloat line1 = 0.0f;
static GLfloat line2 = 0.0f;
static GLfloat line3 = 0.0f;

void myinit()
{

		glEnable(GL_DEPTH_TEST);
		glClearColor(0.0f,0.0f,0.0f,0.0f);

}

void myKey(unsigned char key1,int x,int y)
{
		if(key1=='a' || key1=='A')
		line1-=0.5f;
		if(key1=='d'||key1=='D')
		line1+=0.5f;
		if(key1=='w'||key1=='W')
		line3+=0.5f;
		if(key1=='s' || key1=='S')
		line3-=0.5f;
		if(key1=='q' || key1=='Q')
		{
			exit(0);
		}
		if(key1==27)
			exit(0);
		glutPostRedisplay();
}

void myReshape(int w, int h)
{
     GLfloat fAspect;
    if(h == 0)
    	h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w/(GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(35.0f, fAspect, 1.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//HANDLER FOR TILTING USING SPECIAL KEYS
void upKeyControl(int key, int x, int y)
{
      if(key == GLUT_KEY_UP)
      {
            wobx=xRot;
            woby=yRot;
      }
     if(key == GLUT_KEY_DOWN)
     {
            wobx=xRot;
            woby=yRot;
     }
     if(key == GLUT_KEY_LEFT)
     {
            wobx=xRot;
            woby=yRot;
     }
     if(key == GLUT_KEY_RIGHT)
     {
            wobx=xRot;
            woby=yRot;
     }
     glutPostRedisplay();
}

void keyControl(int key, int x, int y)
{
     GLfloat rotLim=85;
     if(key == GLUT_KEY_UP && xRot>-rotLim)
     {
            wobx=woby=0;
            xRot-= 5.0f;
     }
     if(key == GLUT_KEY_DOWN && xRot<rotLim)
     {
            wobx=woby=0;
            xRot+= 5.0f;
     }
     if(key == GLUT_KEY_LEFT && yRot<rotLim)
     {
            wobx=woby=0;
            yRot+= 5.0f;
     }
     if(key == GLUT_KEY_RIGHT && yRot>-rotLim)
     {
            wobx=woby=0;
            yRot-= 5.0f;
     }
     glutPostRedisplay();
}


void idler()
{
		static int xLim,yLim;
    if(wobx!=0 || woby!=0)
    {
    	if(wobx>0)
    	{
    		if(xRot>wobx)
    			wobx=(-1)*(wobDecay)*(wobx);
    		else if(xRot<=wobx)
    			xRot+=xRestore;
    	}
    	else if(wobx<0)
    	{
    		if(xRot<wobx)
    			wobx=(-1)*(wobDecay)*(wobx);
    		else if(xRot>=wobx)
    			xRot-=xRestore;
    	}
    	if(woby>0)
    	{
    		if(yRot>woby)
    			woby=(-1)*(wobDecay)*(woby);
    		else if(yRot<=woby)
    			yRot+=yRestore;
    	}
    	else if(woby<0)
    	{
    		if(yRot<woby)
    			woby=(-1)*(wobDecay)*(woby);
    		else if(yRot>=woby)
    			yRot-=yRestore;
    	}
    }
     glutPostRedisplay();
}

void RenderScene(void)
{
     GLUquadricObj *Obj;
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushMatrix();
                    glTranslatef(0.0f, -0.5f, -5.0f);
                    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
                    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
                    glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);

                    Obj = gluNewQuadric();
                    gluQuadricNormals(Obj, GLU_SMOOTH);

                    glPushMatrix();
                            //head
                            glColor3f(head[0], head[1],head[2]);
                            gluSphere(Obj, 0.24f, 26, 13);

                            // Eyes
                            glPushMatrix();
                                           glColor3f(0.0f, 0.0f, 0.0f);
                                           glTranslatef(0.1f, -0.02f, 0.21f);
                                           gluSphere(Obj, 0.02f, 26, 13);

                                           glTranslatef(-0.2f, 0.0f, 0.0f);
                                           gluSphere(Obj, 0.02f, 26, 13);
                            glPopMatrix();

                            glPushMatrix();
                                           glColor3f(hat[0], hat[1], hat[2]);
                                           glRotatef(-90,1,0,0);
                                           gluCylinder(Obj, 0.3f, 0.0f, 1.0, 26, 2);
                            glPopMatrix();
     glPopMatrix();
     glutSwapBuffers();

}

void display()
{

		glutReshapeFunc(myReshape);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
		 glTranslatef(line1, line2, line3);
     RenderScene();
     glutPostRedisplay();
     glFlush();

}



void change(int m) {
	switch(m)
	{
		case 0:exit(0);
		case 1: head[0]=1.0f;
						head[1]=0.8f;
						head[2]=0.8f;
						break;
		case 2:head[0]=0.7f;
						head[1]=0.4f;
						head[2]=0.15f;
						break;
		case 3:hat[0]=0.0f;
						hat[1]=0.0f;
						hat[2]=1.0f;
						break;
		case 4:hat[0]=1.0f;
						hat[1]=1.0f;
						hat[2]=0.0f;
						break;
		case 5:hat[0]=1.0f;
						hat[1]=0.0f;
						hat[2]=0.0f;
						break;
	}
}


void menu()
{
		int sub_hat,sub_head,sub_size;
		sub_head = glutCreateMenu(change);
		glutAddMenuEntry("Cream",1);
		glutAddMenuEntry("Brown",2);

		sub_hat = glutCreateMenu(change);
		glutAddMenuEntry("Blue",3);
		glutAddMenuEntry("Yellow",4);
		glutAddMenuEntry("Red",5);

		glutCreateMenu(change);
		glutAddSubMenu("Head Color",sub_head);
		glutAddSubMenu("Hat Color",sub_hat);
		glutAddMenuEntry("Exit",0);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char *argv[])
{
	    glutInit(&argc, argv);
	    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	    glutInitWindowSize(800, 800);
	    glutCreateWindow("Centre of Gravity Doll");
	    glutReshapeFunc(myReshape);
	    glutSpecialFunc(keyControl);
	    glutSpecialUpFunc(upKeyControl);
	    glutKeyboardFunc(myKey);
	    glutIdleFunc(idler);
	    glutDisplayFunc(display);
	    myinit();
	    menu();
	    glutMainLoop();
    return 0;
}
