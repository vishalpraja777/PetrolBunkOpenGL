#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
//#include<stdbool.h>

//static GLfloat theta[] = {0.0,0.0,0.0};
//static GLint axis = 2;
static GLdouble viewer[]= {30.0, 15.0, 30.0};
GLdouble angle[]= {0.0, 10.0, 0.0};

void ground()
{
	glColor3f(0.0,1.0,0.1);
	glPushMatrix();
	glTranslatef(0.0,-1.0,0.0);
	glScalef(1.0,0.005,1.0);
 	glutSolidCube(500.0);
 	glPopMatrix();
}

void road()
{
	glColor3f(0.2,0.2,0.2);
	glPushMatrix();
	glTranslatef(0.0,1.0,26.0);
	glScalef(100.0,0.05,0.4);
 	glutSolidCube(30.0);
 	glPopMatrix();
}

void platform()
{
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glScalef(1.0,0.05,1.0);
 	glutSolidCube(40.0);
 	glPopMatrix();
}

void shed()
{

	//shedBlue
 	glColor3f(0.0,0.0,0.5);
	glPushMatrix();
	glTranslatef(0.0,18.4,0.0);
	glScalef(1.0,0.02,1.0);
 	glutSolidCube(26.1);
 	glPopMatrix();
 	
	//shedOrange
 	glColor3f(1.0,0.4,0.0);
	glPushMatrix();
	glTranslatef(0.0,17.5,0.0);
	glScalef(1.0,0.05,1.0);
 	glutSolidCube(26.0);
 	glPopMatrix();
 	
 	//shedWhite
 	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
	glTranslatef(0.0,17.4,0.0);
	glScalef(1.0,0.05,1.0);
 	glutSolidCube(25.0);
 	glPopMatrix();	
}

void pumpPlatform(GLfloat lz)
{
	glColor3f(0.3,0.3,0.3);
 	glPushMatrix();
 	glTranslatef(0.0,1.0,-lz);
 	glScalef(8.5,0.5,2.0);
 	glutSolidCube(2.0);
 	glPopMatrix();
 	
 	//glColor3f(1.0,0.0,0.1);
 	glPushMatrix();
 	glTranslatef(0.0,1.0,lz);
 	glScalef(8.5,0.5,2.0);
 	glutSolidCube(2.0);
 	glPopMatrix();
}

void pillars(GLfloat lx,GLfloat ly,GLfloat lz,GLfloat sx,GLfloat sy,GLfloat sz)
{
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
}

void pumps(GLfloat lz)
{
	glColor3f(0.9,0.9,0.9);
	
	glPushMatrix();
	glTranslatef(0.0,2.0,lz);
	glScalef(1.0,2.5,0.5);
 	glutSolidCube(3.0);
 	glPopMatrix();
 	
 	glPushMatrix();
	glTranslatef(1.35,6.5,lz);
	glScalef(0.1,0.5,0.45);
 	glutSolidCube(3.0);
 	glPopMatrix();
 	
 	glPushMatrix();
	glTranslatef(-1.35,6.5,lz);
	glScalef(0.07,0.5,0.45);
 	glutSolidCube(3.0);
 	glPopMatrix();
 	
	glPushMatrix();
	glTranslatef(0.0,7.5,lz);
	glScalef(1.0,0.2,0.5);
 	glutSolidCube(3.0);
 	glPopMatrix();
 	
}

void tress(GLfloat lx, GLfloat ly, GLfloat lz)
{	
	//steam
	glColor3f(0.5,0.2,0.0);
 	glPushMatrix();
 	glTranslatef(lx,ly,lz);
 	glScalef(0.05,1.0,0.05);
 	glutSolidCube(22.0);
 	glPopMatrix();
 	
 	//leaves
 	glColor3f(0.0,0.6,0.0);
 	glPushMatrix();
 	glTranslatef(lx-2.0,ly+10.0,lz-2.0);
 	glutSolidSphere(3.0,100.0,100.0);
 	glPopMatrix();
 	
 	glColor3f(0.0,0.6,0.0);
 	glPushMatrix();
 	glTranslatef(lx+2.0,ly+10.0,lz+2.0);
 	glutSolidSphere(3.0,100.0,100.0);
 	glPopMatrix();
 	
 	glColor3f(0.0,0.6,0.0);
 	glPushMatrix();
 	glTranslatef(lx,ly+14.0,lz);
 	glutSolidSphere(3.0,100.0,100.0);
 	glPopMatrix();
}

void display(void)
{

 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	gluLookAt(viewer[0],viewer[1],viewer[2], angle[0],angle[1],angle[2], 0.0, 1.0, 0.0);
	
	ground();
 	
 	road();
 	
	platform();
	
 	shed(); 	
 	
 	GLfloat lx = 5.0;
 	GLfloat ly = 8.0;
 	GLfloat lz = 7.0;
 	
 	GLfloat sx = 0.05;
 	GLfloat sy = 1.0;
 	GLfloat sz = 0.05;
 	
 	pumpPlatform(lz);
 	
 	pillars(lx,ly,lz,sx,sy,sz);
 	
 	pumps(lz);
 	pumps(-lz);
 	
 	//trees
 	//tress(0.0,2.0,20.0);
 	
 	tress(-30.0,2.0,15.0);	
 	tress(-50.0,2.0,15.0);	
 	tress(-70.0,2.0,15.0);	
 	tress(-30.0,2.0,35.0);
 	tress(-50.0,2.0,35.0);
 	tress(-70.0,2.0,35.0);
 	tress(30.0,2.0,15.0);	
 	tress(50.0,2.0,15.0);	
 	tress(70.0,2.0,15.0);	
 	tress(30.0,2.0,35.0);
 	tress(50.0,2.0,35.0);
 	tress(70.0,2.0,35.0);
 	
 	
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
 	gluPerspective(100.0,(GLfloat) w/ (GLfloat) h,0.6,200.0);
/*	if(w<=h) 
		glFrustum(-x, x, -y * (GLfloat) h/ (GLfloat) w, y* (GLfloat) h / (GLfloat) w, 2.0, z);
	else 
		glFrustum(-x * (GLfloat) w/ (GLfloat) h, x* (GLfloat) w / (GLfloat) h,-y ,y, 2.0, z);
*/


 glMatrixMode(GL_MODELVIEW);
}

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) angle[1] += 1.0;
	if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) viewer[1] = 15;
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) angle[1] -= 1.0;
	//theta[axis] += 2.0;
	//if( theta[axis] > 360.0 ) theta[axis] -= 360.0;
	display();
}

void keys(unsigned char key, int x, int y)
{

/* Use x, X, y, Y, z, and Z keys to move viewer */

   if(key == 'x') viewer[0]-= 1.0;
   if(key == 'X') viewer[0]+= 1.0;
   if(key == 'y') viewer[1]-= 1.0;
   if(key == 'Y') viewer[1]+= 1.0;
   if(key == 'z') viewer[2]-= 1.0;
   if(key == 'Z') viewer[2]+= 1.0;
   display();
}

void  main(int argc, char **argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(700, 700);
 glutCreateWindow("Petrol Bunk");
 glutReshapeFunc(myReshape);
 glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
 glutMainLoop();
}
