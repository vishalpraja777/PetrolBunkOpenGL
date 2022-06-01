#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdbool.h>

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
static GLdouble viewer[]= {10.0, 10.0, 10.0};

void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();
	
	gluLookAt(viewer[0],viewer[1],viewer[2], 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	
	//glLoadIdentity();
	glColor3f(0.0,1.0,0.1);
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glScalef(50.0,1.0,50.0);
 	glutSolidCube(1.0);
 	glPopMatrix();
 	
 	//glLoadIdentity();
 	glColor3f(1.0,0.0,0.1);
 	glPushMatrix();
 	glTranslatef(10.0,0.0,0.0);
 	//glutSolidCube(5.0);
 	glPopMatrix();
 	
 	glFlush();
	glutSwapBuffers();
}

void myReshape(int w, int h)
{

	glClearColor(0.0,0.5,1.0,1.0);
	
	float x=20.0,y=20.0,z=20.0;
 	glViewport(0, 0, w, h);

/* Use a perspective view */

 	glMatrixMode(GL_PROJECTION); 
 	glLoadIdentity();
	if(w<=h) 
		glFrustum(-x, x, -y * (GLfloat) h/ (GLfloat) w, y* (GLfloat) h / (GLfloat) w, 2.0, z);
	else 
		glFrustum(-x * (GLfloat) w/ (GLfloat) h, x* (GLfloat) w / (GLfloat) h,-y ,y, 2.0, z);



 glMatrixMode(GL_MODELVIEW);
}

void  main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(700, 700);
 glutCreateWindow("Petrol Bunk");
 glutReshapeFunc(myReshape);
 glutDisplayFunc(display);
	//glutMouseFunc(mouse);
	//glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
 glutMainLoop();
}
