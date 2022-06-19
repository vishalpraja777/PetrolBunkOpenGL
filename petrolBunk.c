#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include <unistd.h>
//#include<stdbool.h>

//static GLfloat theta[] = {0.0,0.0,0.0};
//static GLint axis = 2;
static GLdouble viewer[]= {-12.0, 15.0, 50.0};
GLdouble angle[]= {0.0, 10.0, 0.0};



void ground()
{
	glColor3f(0.0,1.0,0.1);
	glPushMatrix();
	glTranslatef(0.0,-1.0,0.0);
	glScalef(2.0,0.005,2.0);
 	glutSolidCube(500.0);
 	glPopMatrix();
}

void road()
{
	glColor3f(0.2,0.2,0.2);
	glPushMatrix();
	glTranslatef(0.0,1.0,26.0);
	glScalef(20.0,0.01,0.4);
 	glutSolidCube(30.0);
 	glPopMatrix();
}

void platform()
{
	glColor3f(0.5,0.5,0.5);
	glPushMatrix();
	glTranslatef(0.0,0.0,0.0);
	glScalef(1.5,0.05,1.0);
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

void car(GLfloat tx,GLfloat ty,GLfloat tz,GLfloat ry,GLfloat pr, GLfloat pg, GLfloat pb)
{

	GLfloat xangle=0.0,yangle=0.0,zangle=0.0,carAngle=0.0; 

	float theta;

	GLfloat r=pr,g=pg,b=pb;
	GLfloat xt=0.0,yt=0.0,zt=0.0,xw=0.0;   
	GLfloat xs=1.0,ys=1.0,zs=1.0;

//GLint light=1;
//int count=1,flg=1;
//int view=0;
int flag1=0,aflag=1;            //to switch car driving mode
int flag2=0,wheelflag=0;   //to switch fog effect
//GLUquadricObj *t;


	GLfloat sx = 10.0,sy = 10.0,sz = 10.0;
	
	
	glScalef(sx,sy,sz);
	glTranslatef(tx,ty,tz);
	
	
	glRotatef(ry,0.0,1.0,0.0);
	
	glPushMatrix();
	
	 	              /* OBJECT MODULE*/
  glBegin(GL_QUADS); 
  /* top of cube*/
  //************************FRONT BODY****************************************
  glColor3f(r,g,b);
  glVertex3f( 0.2, 0.4,0.6);
  glVertex3f(0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);

  /* bottom of cube*/
  glVertex3f( 0.2,0.4,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* front of cube*/
  glVertex3f( 0.2,0.2,0.6);
  glVertex3f(0.2, 0.4,0.6);
  glVertex3f(0.2,0.4,0.2);
  glVertex3f( 0.2,0.2,0.2);

  /* back of cube.*/
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.6,0.5,0.2);
  glVertex3f( 0.6,0.2,0.2);

  /* left of cube*/
  glVertex3f(0.2,0.2,0.6);
  glVertex3f(0.6,0.2,0.6);
  glVertex3f(0.6,0.5,0.6);
  glVertex3f(0.2,0.4,0.6);

  /* Right of cube */
  glVertex3f(0.2,0.2,0.2);
  glVertex3f( 0.6,0.2,0.2);
  glVertex3f( 0.6,0.5,0.2);
  glVertex3f( 0.2,0.4,0.2);

  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(1.7,0.65,0.2);        //top cover
  glVertex3f(1.7,0.65,0.6);
//***************************back guard******************************
  glColor3f(r,g,b);            /* Set The Color To Blue*/
  glVertex3f( 1.8, 0.5,0.6);
  glVertex3f(1.8, 0.5,0.2);
  glVertex3f(2.1, 0.4, 0.2);
  glVertex3f(2.1,0.4,0.6);

  /* bottom of cube*/
  glVertex3f( 2.1,0.2,0.6);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(1.8,0.2,0.6);
  glVertex3f( 1.8,0.2,0.6);

  /* back of cube.*/
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);
  glVertex3f(2.1,0.2,0.6);

  /* left of cube*/
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(2.1,0.4,0.2);
  glVertex3f(2.1,0.2,0.2);

  /* Right of cube */
  glVertex3f(1.8,0.2,0.6);
  glVertex3f(1.8,0.5,0.6);
  glVertex3f(2.1,0.4,0.6);
  glVertex3f(2.1,0.2,0.6);
//******************MIDDLE BODY************************************
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.2,0.6);
  glVertex3f(1.8, 0.2, 0.6);
  glVertex3f(1.8,0.5,0.6);

  /* bottom of cube*/
  glVertex3f( 0.6,0.2,0.6);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f( 1.8,0.2,0.6);

  /* back of cube.*/
  glVertex3f(0.6,0.5,0.2);
  glVertex3f(0.6,0.2,0.2);
  glVertex3f(1.8,0.2,0.2);
  glVertex3f(1.8,0.5,0.2);
//*********************ENTER WINDOW**********************************
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.2);
  glVertex3f(0.75, 0.5,0.2);        //quad front window
  glVertex3f(1.2, 0.5, 0.2);
  glVertex3f( 1.22,0.63,0.2);

  glVertex3f(1.27,0.63,.2);
  glVertex3f(1.25,0.5,0.2);        //quad back window
  glVertex3f(1.65,0.5,0.2);
  glVertex3f(1.67,0.63,0.2);

  glColor3f(r,g,b);
  glVertex3f(0.7,0.65,0.2);
  glVertex3f(0.7,0.5,.2);       //first separation
  glVertex3f(0.75,0.5,0.2);
  glVertex3f(0.77,0.65,0.2);

  glVertex3f(1.2,0.65,0.2);
  glVertex3f(1.2,0.5,.2);       //second separation
  glVertex3f(1.25,0.5,0.2);
  glVertex3f(1.27,0.65,0.2);

  glVertex3f(1.65,0.65,0.2);
  glVertex3f(1.65,0.5,.2);     //3d separation
  glVertex3f(1.7,0.5,0.2);
  glVertex3f(1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.2);
  glVertex3f(0.75, 0.63,0.2);        //line strip
  glVertex3f(1.7, 0.63, 0.2);
  glVertex3f( 1.7,0.65,0.2);

  glVertex3f( 0.75, 0.65,0.6);
  glVertex3f(0.75, 0.63,0.6);        //line strip
  glVertex3f(1.7, 0.63, 0.6);
  glVertex3f( 1.7,0.65,0.6);

  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.77, 0.63,0.6);
  glVertex3f(0.75, 0.5,0.6);        //quad front window
  glVertex3f(1.2, 0.5, 0.6);
  glVertex3f( 1.22,0.63,0.6);

  glVertex3f(1.27,0.63,.6);
  glVertex3f(1.25,0.5,0.6);        //quad back window
  glVertex3f(1.65,0.5,0.6);
  glVertex3f(1.67,0.63,0.6);

  glColor3f(r,g,b);
  glVertex3f(0.7,0.65,0.6);
  glVertex3f(0.7,0.5,.6);       //first separation
  glVertex3f(0.75,0.5,0.6);
  glVertex3f(0.77,0.65,0.6);

  glVertex3f(1.2,0.65,0.6);
  glVertex3f(1.2,0.5,.6);       //second separation
  glVertex3f(1.25,0.5,0.6);
  glVertex3f(1.27,0.65,0.6);

  glVertex3f(1.65,0.65,0.6);
  glVertex3f(1.65,0.5,.6);
  glVertex3f(1.7,0.5,0.6);
  glVertex3f(1.7,0.65,0.6);
  glEnd();


 //**************************************************************
  glBegin(GL_QUADS);

  /* top of cube*/
  glColor3f(0.3,0.3,0.3);
  glVertex3f( 0.6, 0.5,0.6);
  glVertex3f(0.6, 0.5,0.2);        //quad front window
  glVertex3f(0.7, 0.65, 0.2);
  glVertex3f( 0.7,0.65,0.6);

  glVertex3f(1.7,0.65,.6);
  glVertex3f(1.7,0.65,0.2);        //quad back window
  glVertex3f(1.8,0.5,0.2);
  glVertex3f(1.8,0.5,0.6);
glEnd();

//*****************************road and surrounding development***********************************
  if(flag1)
  {
	glPushMatrix();
	glTranslatef(xw,0,0);
  glColor3f(0,1,0);
  glVertex3f(-100,0.1,-100);
  glVertex3f(-100,0.1,0);         //a green surroundings
  glVertex3f(100,0.1,0);
  glVertex3f(100,0.1,-100);

  glColor3f(0.7,0.7,0.7);
  glVertex3f(-100,0.1,0);
  glVertex3f(-100,0.1,0.45);         //a long road
  glVertex3f(100,0.1,0.45);
  glVertex3f(100,0.1,0);

  glColor3f(1.0,0.75,0.0);
  glVertex3f(-100,0.1,0.45);       //a median
  glVertex3f(-100,0.1,0.55);
  glVertex3f(100,0.1,0.55);
  glVertex3f(100,0.1,0.45);

  glColor3f(0.7,0.7,0.7);
  glVertex3f(-100,0.1,0.55);
  glVertex3f(-100,0.1,1);         //a long road
  glVertex3f(100,0.1,1);
  glVertex3f(100,0.1,0.55);

  glColor3f(0,1,0);
  glVertex3f(-100,0.1,1);
  glVertex3f(-100,0.1,100);         //a green surroundings
  glVertex3f(100,0.1,100);
  glVertex3f(100,0.1,1);
    glPopMatrix();
  }
  glEnd();
  
  int i;
  if(wheelflag)
  {
	  glPushMatrix();
	  glTranslatef(xw,0,0);
	  glColor3f(0.5,.2,0.3);
	  glBegin(GL_QUADS);
	  for(i=0;i<200;i+=0.2)
	  {
		  glVertex3f(-100+i,0,1);
		  glVertex3f(-99.9+i,0,1);
		  glVertex3f(-99.9+i,0.2,1);
		  glVertex3f(-100+i,0.2,1);
		  i+=0.5;
	  }
	  for(i=0;i<200;i+=0.2)
	  {
		  glVertex3f(-100+i,0,0);
		  glVertex3f(-99.9+i,0,0);
		  glVertex3f(-99.9+i,0.2,0);
		  glVertex3f(-100+i,0.2,0);
		  i+=0.5;
	  }
	  glEnd();
	  glPopMatrix();
  }
  
  
  
glColor3f(0.7,0.7,0.7);
glPushMatrix();
  glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+40)
	  {
  glVertex3f(0.6,0.2,0.62);
  glVertex3f(0.6+(0.08*(cos(((theta+carAngle)*3.14)/180))),0.2+(0.08*(sin(((theta+carAngle)*3.14)/180))),0.62);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
	  for(theta=0;theta<360;theta=theta+40)
	  {
  glVertex3f(0.6,0.2,0.18);
  glVertex3f(0.6+(0.08*(cos(((theta+carAngle)*3.14)/180))),0.2+(0.08*(sin(((theta+carAngle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(theta=0;theta<360;theta=theta+40)
	  {
  glVertex3f(1.7,0.2,0.18);
  glVertex3f(1.7+(0.08*(cos(((theta+carAngle)*3.14)/180))),0.2+(0.08*(sin(((theta+carAngle)*3.14)/180))),0.18);
	  }
glEnd();

glBegin(GL_LINE_STRIP);
for(theta=0;theta<360;theta=theta+40)
	  {
  glVertex3f(1.7,0.2,0.62);
 glVertex3f(1.7+(0.08*(cos(((theta+carAngle)*3.14)/180))),0.2+(0.08*(sin(((theta+carAngle)*3.14)/180))),0.62);
	  }
glEnd();

glTranslatef(0.6,0.2,0.6);
  glColor3f(0,0,0);
  glutSolidTorus(0.025,0.07,10,25);
  glTranslatef(0,0,-0.4);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(1.1,0,0);
  glutSolidTorus(0.025,0.07,10,25);

  glTranslatef(0,0,0.4);
  glutSolidTorus(0.025,0.07,10,25);
  glPopMatrix();
  glPopMatrix();


}

void car1()
{
	static int flag = 0;
	static GLfloat tx = 20.0,ty = 0.0,tz = 2.2,ry=0.0;
	
	GLfloat ra = 4.0;
	
 	car(tx,ty,tz,ry,0.0,0.0,1.0);
 	if(tx>2.0)
 	{
 		tx-=0.1;
 	}
 	else
 	{
 		if(tz>-0.25 && flag==0)
 		{
 			tz-=0.05;
 			if(ry>-90.0)
 				ry-=ra;
 			
 			
 		}
 		else
 		{
 			flag = 1;
 			if(tx>-2.7)
 			{
 				if(ry<0.0)
 					ry+=ra;
 				if(tx<-1.6&& tx>-1.7) 
 				{
 					sleep(2.0);
 				}
 				tx-=0.1;
 			}
 			else if(tz<2.2)
 			{
 				if(ry<90.0)
 					ry+=ra;
 				tz+=0.05;
 			}
 			else if(tx>-20.0)
 			{
 				if(ry>0.0)
 					ry-=ra;
				tx-=0.1;
			}
 		}		
 	}
}


void car2()
{
	
	static int flag = 0;
	static GLfloat tx = 10.0,ty = 0.0,tz = 2.2,ry=0.0;
	
	GLfloat ra = 4.0;
	
 	car(tx,ty,tz,ry,1.0,0.0,0.0);
 	if(tx>-20.0)
 	{
 		tx-=0.1;
 	}
}

void body(GLfloat tx,GLfloat ty,GLfloat tz)
{

	static int elbow[] = {0, 0};
static int arm[] = {0, 0};
static int armZ[] = {0, 0};
static int legX[] = {0, 0};
static int legZ[] = {0, 0};
static int knee[] = {0, 0};
static int fingers[] = {0, 0};
static int flang[] = {0, 0};

glTranslatef(tx, ty, tz);

	glPushMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)legZ[0], 0.0, 0.0, 1.0);
    glTranslatef(-0.5, 0.0, 0.0);

    glRotatef((GLfloat)legX[0], 1.0, 0.0, 0.0);
    glTranslatef(0.5, -0.5, 0.0);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glScalef (0.5, 1.0, 0.5);
    glutSolidCube (1.0);
    glPopMatrix();

    glTranslatef(0.0, -0.5, 0.0);
    //glRotatef(GLfloat (knee[0]), 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glPushMatrix();
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glScalef (0.5, 1.0, 0.5);
    glutSolidCube (1.0);
    glPopMatrix();

    glTranslatef(0.0, -0.625, 0.0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glScalef (0.75, 0.25, 0.75);
    glutSolidCube (1.0);
    glPopMatrix();

    glPopMatrix();
    // END OF RIGHT LEG


    // START OF LEFT LEG
    glPushMatrix();

    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat)legZ[1], 0.0, 0.0, 1.0);
    glTranslatef(+0.5, 0.0, 0.0);

    glRotatef((GLfloat)legX[1], 1.0, 0.0, 0.0);
    glTranslatef(-0.5, -0.5, 0.0);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glScalef (0.5, 1.0, 0.5);
    glutSolidCube (1.0);
    glPopMatrix();


    glTranslatef(0.0, -0.5, 0.0);
    //glRotatef(GLfloat (knee[1]), 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.5, 0.0);
    glPushMatrix();
    glColor3f(0.71, 0.4, 0.12);
    glScalef (0.5, 1.0, 0.5);
    glutSolidCube (1.0);
    glPopMatrix();

    glTranslatef(0.0, -0.625, 0.0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glScalef (0.75, 0.25, 0.75);
    glutSolidCube (1.0);
    glPopMatrix();

    glPopMatrix();
    // END OF LEFT LEG


    // START OF TRUNK
    glPushMatrix();
    glTranslatef(0.0, 0.25, 0.0);
    glScalef(1.5, 0.5, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
    // END OF TRUNK

    // START OF STOMACH
    glPushMatrix();
    glTranslatef(0.0, 1.25, 0.0);
    glScalef(1.5, 1.5, 0.5);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidCube(1.0);
    glPopMatrix();
    // END OF STOMACH

    // START OF HEAD
    glPushMatrix();
    glTranslatef(0.0, 2.5, 0.0);
    glColor3f(0.71, 0.4, 0.12);
    glutSolidSphere(0.35, 16, 16);
    glPopMatrix();
    // END OF HEAD


    // START OF RIGHT ARM

    glPushMatrix();

    glTranslatef(0.9, 1.5, 0.0);

    //glRotatef((GLfloat)armZ[0], 0.0, 0.0, 0.0);
    glRotatef(-90, 0.0, 0.0, 1.0);


    glTranslatef(-0.375, 0, 0);
    glRotatef(arm[0], 0.0, 0.0, 0.0);
    glTranslatef(0.375, 0, 0);

    // Draw the limb
    // The shoulder is centered in origin and has 1, 1, 1 dimensions
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glScalef (0.75, 0.3, 0.3);
    glutSolidCube (1.0);
    glPopMatrix();

    glTranslatef(0.75, 0, 0);

    glTranslatef(-0.375, 0, 0.0);
    glRotatef((GLfloat)elbow[90], 0.0, 1.0, 1.0);
    glTranslatef(0.375, 0, 0.0);
    glPushMatrix();
    glColor3f(0.71, 0.4, 0.12);
    glScalef (0.75, 0.3, 0.3);
    glutSolidCube (1.0);
    glPopMatrix();

    // START OF FINGER 1
    glPushMatrix();

    glTranslatef(0.475, 0.05, 0.1125);
    glColor3f(1, 0, 0);

    glTranslatef(-0.1 , 0, 0);
    glRotatef(flang[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glRotatef(fingers[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 1


    // START OF FINGER 2
    glPushMatrix();

    glTranslatef(0.475, 0.05, 0.0375);
    glColor3f(1, 0, 0);

    glTranslatef(-0.1 , 0, 0);
    glRotatef(flang[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glRotatef(fingers[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 2

    // START OF FINGER 3
    glPushMatrix();

    glTranslatef(0.475, 0.05, -0.0375);
    glColor3f(1, 0, 0);

    glTranslatef(-0.1 , 0, 0);
    glRotatef(flang[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glRotatef(fingers[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 3


    // START OF FINGER 4
    glPushMatrix();

    glTranslatef(0.475, 0.05, -0.1125);
    glColor3f(1, 0, 0);

    glTranslatef(-0.1 , 0, 0);
    glRotatef(flang[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glRotatef(fingers[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 4


    // START OF FINGER 5
    glPushMatrix();

    glTranslatef(0.475, -0.1, 0);
    glColor3f(1, 0, 0);

    glTranslatef(-0.1 , 0, 0);
    glRotatef(- flang[0], 0, 0, 1);
    glTranslatef(0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.1, 0, 0);
    glTranslatef(-0.05, 0, 0);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glRotatef(-fingers[0], 0, 0, 1);
    glTranslatef(0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 5


    glPopMatrix();


    // END OF RIGHT ARM


    // START OF LEFT ARM

    glPushMatrix();

    //glTranslatef(-1.25, 1.85, 0.3);
    glTranslatef(-0.9, 1.5, 0.0);
    // glRotatef((GLfloat)armZ[1], 1.0, 0.0, 0.0);
    glRotatef(90, 0.0, 0.0, 1.0);
    glTranslatef(0.375, 0, 0);
    glRotatef(arm[1], 0.0, 0.0, 0.0);
    glTranslatef(-0.375, 0, 0);

    // Draw the limb
    // The shoulder is centered in origin and has 1, 1, 1 dimensions
    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glScalef (0.75, 0.3, 0.3);
    glutSolidCube (1.0);
    glPopMatrix();

    glTranslatef(-0.75, 0, 0);

    glTranslatef(0.375, 0, 0.0);
    glRotatef((GLfloat)elbow[1], 0.0, 0.0, 0.0);
    glTranslatef(-0.375, 0, 0.0);
    glPushMatrix();
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glScalef (0.75, 0.3, 0.3);
    glutSolidCube (1.0);
    glPopMatrix();

// START OF FINGER 1
    glPushMatrix();

    glTranslatef(-0.475, 0.05, 0.1125);
    glColor3f(1, 0, 0);

    glTranslatef(0.1 , 0, 0);
    glRotatef(flang[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glRotatef(fingers[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 1


    // START OF FINGER 2
    glPushMatrix();

    glTranslatef(-0.475, 0.05, 0.0375);
    glColor3f(1, 0, 0);

    glTranslatef(0.1 , 0, 0);
    glRotatef(flang[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();


    glPushMatrix();
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(fingers[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 2

    // START OF FINGER 3
    glPushMatrix();

    glTranslatef(-0.475, 0.05, -0.0375);
    glColor3f(1, 0, 0);

    glTranslatef(0.1 , 0, 0);
    glRotatef(flang[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(fingers[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 3


    // START OF FINGER 4
    glPushMatrix();

    glTranslatef(-0.475, 0.05, -0.1125);
    glColor3f(1, 0, 0);

    glTranslatef(0.1 , 0, 0);
    glRotatef(flang[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(fingers[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 4

    // START OF FINGER 5
    glPushMatrix();

    glTranslatef(-0.475, -0.1, 0);
    glColor3f(1, 0, 0);

    glTranslatef(0.1 , 0, 0);
    glRotatef(- flang[1], 0, 0, 1);
    glTranslatef(-0.1, 0, 0);
    glPushMatrix();
    glScalef(0.2, 0.1, 0.05);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.1, 0, 0);
    glTranslatef(0.05, 0, 0);
    glRotatef(-fingers[1], 0, 0, 1);
    glTranslatef(-0.05, 0, 0);
    glScalef(0.1, 0.1, 0.05);
    glColor4f(0.71, 0.4, 0.12, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // END OF FINGER 5

    glPopMatrix();

    // END OF LEFT ARM

    glPopMatrix();
   // glutSwapBuffers();

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
 	//trees
 	//tress(0.0,2.0,20.0);
 	
 	// tress(-40.0,2.0,15.0);	
 	// tress(-50.0,2.0,15.0);	
 	// tress(-70.0,2.0,15.0);	
 	// tress(-30.0,2.0,35.0);
 	// tress(-50.0,2.0,35.0);
 	// tress(-70.0,2.0,35.0);
 	tress(20.0,2.0,40.0);
 	tress(30.0,2.0,20.0);
 	tress(30.0,2.0,10.0);
 	// tress(30.0,2.0,5.0);
 	tress(30.0,2.0,0.0);
 	tress(30.0,2.0,-10.0);
 	tress(30.0,2.0,-20.0);
 	tress(40.0,2.0,10.0);
 	// tress(30.0,2.0,-40.0);
 	// tress(30.0,2.0,-50.0);
 	// tress(30.0,2.0,-60.0);
 	// tress(30.0,2.0,-70.0);
 	// tress(30.0,2.0,-80.0);
 	// tress(30.0,2.0,-90.0);
 	// tress(30.0,2.0,-100.0);
 	// tress(50.0,2.0,-50.0);	
 	// tress(50.0,2.0,-40.0);	
 	// tress(50.0,2.0,-30.0);	
 	// tress(50.0,2.0,-20.0);	
 	// tress(50.0,2.0,-10.0);	
 	// tress(50.0,2.0,0.0);
 	// tress(50.0,2.0,10.0);
 	// tress(50.0,2.0,20.0);
 	// tress(50.0,2.0,-60.0);	
 	// tress(50.0,2.0,-70.0);	
 	// tress(50.0,2.0,-80.0);	
 	// tress(50.0,2.0,-90.0);	
 	// tress(50.0,2.0,-100.0);				
 	// tress(10.0,2.0,-50.0);	
 	// tress(10.0,2.0,-40.0);	
 	// tress(10.0,2.0,-30.0);	
 	tress(10.0,2.0,-20.0);	
 	// tress(10.0,2.0,-60.0);	
 	// tress(10.0,2.0,-70.0);	
 	// tress(10.0,2.0,-80.0);	
 	// tress(10.0,2.0,-90.0);	
 	// tress(10.0,2.0,-100.0);		
 	// tress(-10.0,2.0,-50.0);	
 	// tress(-10.0,2.0,-40.0);	
 	// tress(-10.0,2.0,-30.0);	
 	tress(-10.0,2.0,-20.0);	
 	// tress(-10.0,2.0,-60.0);
 	// tress(-10.0,2.0,-70.0);
 	// tress(-10.0,2.0,-80.0);
 	// tress(-10.0,2.0,-90.0);
 	// tress(-10.0,2.0,-100.0);
 	// tress(-30.0,2.0,-50.0);	
 	// tress(-30.0,2.0,-40.0);	
 	// tress(-30.0,2.0,-30.0);	
 	tress(-30.0,2.0,-20.0);	
 	// tress(-30.0,2.0,-60.0);
 	// tress(-30.0,2.0,-70.0);	
 	// tress(-30.0,2.0,-80.0);	
 	// tress(-30.0,2.0,-90.0);		
 	tress(-45.0,2.0,40.0);
 	tress(-45.0,2.0,20.0);
 	tress(-45.0,2.0,10.0);
 	// tress(-45.0,2.0,5.0);
 	tress(-45.0,2.0,0.0);
 	tress(-45.0,2.0,-10.0);
 	tress(-45.0,2.0,-20.0);
 	tress(-55.0,2.0,5.0);
 	// tress(-45.0,2.0,-40.0);
 	// tress(-45.0,2.0,-50.0);
 	// tress(-45.0,2.0,-60.0);
 	// tress(-45.0,2.0,-70.0);
 	// tress(-45.0,2.0,-80.0);	
 	// tress(-60.0,2.0,30.0);
 	// tress(-60.0,2.0,20.0);
 	// tress(-60.0,2.0,10.0);
 	// tress(-60.0,2.0,5.0);
 	// tress(-60.0,2.0,0.0);
 	// tress(-60.0,2.0,-10.0);
 	// tress(-60.0,2.0,-20.0);
 	// tress(-60.0,2.0,-30.0);
 	// tress(-60.0,2.0,-40.0);	
 	// tress(-60.0,2.0,-50.0);	
 	// tress(-60.0,2.0,-60.0);	
 	// tress(-60.0,2.0,-70.0);	
 	// tress(-60.0,2.0,-80.0);
 	// tress(-60.0,2.0,-90.0);	
 	// tress(-60.0,2.0,-100.0);	
 	// tress(-60.0,2.0,-110.0);		
 	//tress(50.0,2.0,15.0);	
 	//tress(70.0,2.0,15.0);	
 	//tress(30.0,2.0,35.0);
 	// tress(50.0,2.0,35.0);
 	// tress(70.0,2.0,35.0);
 	// tress(70.0,2.0,10.0);
 	// tress(70.0,2.0,20.0);
 	// tress(70.0,2.0,0.0);
 	
 	
  glPushMatrix();
 	body(0.0,2.5,10);
  glPopMatrix();

  glPushMatrix();
 	body(0.0,2.5,-4.0);
  glPopMatrix();
 	
 	//GLfloat tx = 0.0,ty = 0.0,tz = 2.2;
 	//car(tx,ty,tz);
 	
 	glPushMatrix();
 	car1();
 	glPopMatrix();
 	
 	glPushMatrix();
 	car2();
 	glPopMatrix();
 	
 	
 	
 	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
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
   //printf("\n%f %f %f\n",viewer[0],viewer[1],viewer[2]);
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
