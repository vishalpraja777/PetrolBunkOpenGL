#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdbool.h>

static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis = 2;
static GLdouble viewer[]= {0.0, 16.0, 30.0};

void display(void)
{

 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glLoadIdentity();
	
	gluLookAt(viewer[0],viewer[1],viewer[2], 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);
	
	//platform
	//glLoadIdentity();
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glScalef(1.0,0.05,1.0);
 	glutSolidCube(30.0);
 	glPopMatrix();
 	
 	//shed
 	glColor3f(1.0,0.5,0.0);
	glPushMatrix();
	glTranslatef(0.0,17.5,0.0);
	glScalef(1.0,0.05,1.0);
 	glutSolidCube(25.0);
 	glPopMatrix();
 	
 	//pumpPlatform
 	//glLoadIdentity();
 	glColor3f(0.3,0.3,0.3);
 	glPushMatrix();
 	glTranslatef(0.0,1.0,-5.0);
 	glScalef(8.0,0.5,2.0);
 	glutSolidCube(2.0);
 	glPopMatrix();
 	
 	//glColor3f(1.0,0.0,0.1);
 	glPushMatrix();
 	glTranslatef(0.0,1.0,5.0);
 	glScalef(8.0,0.5,2.0);
 	glutSolidCube(2.0);
 	glPopMatrix();
 	
 	//pillars
 	GLfloat lx = 5.0;
 	GLfloat ly = 8.0;
 	GLfloat lz = 5.0;
 	
 	GLfloat sx = 0.05;
 	GLfloat sy = 1.0;
 	GLfloat sz = 0.05;
 	
 	

 	glColor3f(0.8,0.8,0.8);
 	glPushMatrix();
 	glTranslatef(lx,ly,lz);
 	glScalef(sx,sy,sz);
 	glutSolidCube(20.0);
 	glPopMatrix();
 	
 	glPushMatrix();
 	glTranslatef(-lx,ly,lz);
 	glScalef(sx,sy,sz);
 	glutSolidCube(20.0);
 	glPopMatrix();
 	
 	glPushMatrix();
 	glTranslatef(lx,ly,-lz);
 	glScalef(sx,sy,sz);
 	glutSolidCube(20.0);
 	glPopMatrix();
 	
 	glPushMatrix();
 	glTranslatef(-lx,ly,-lz);
 	glScalef(sx,sy,sz);
 	glutSolidCube(20.0);
 	glPopMatrix();
 	
 	
 	glFlush();
	glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) viewer[0] = 5;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) viewer[1] = 5;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) viewer[2] = 5;
	theta[axis] += 2.0;
	if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	display();
}

void myReshape(int w, int h)
{

	glClearColor(0.0,0.5,1.0,1.0);
	
	float x=20.0,y=20.0,z=20.0;
	
 	glViewport(0, 0, w, h);

/* Use a perspective view */

 	glMatrixMode(GL_PROJECTION); 
 	glLoadIdentity();
 	gluPerspective(100.0,(GLfloat) w/ (GLfloat) h,0.6,200.0);
/*	if(w<=h) 
		glFrustum(-x, x, -y * (GLfloat) h/ (GLfloat) w, y* (GLfloat) h / (GLfloat) w, 2.0, z);
	else 
		glFrustum(-x * (GLfloat) w/ (GLfloat) h, x* (GLfloat) w / (GLfloat) h,-y ,y, 2.0, z);
*/


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
