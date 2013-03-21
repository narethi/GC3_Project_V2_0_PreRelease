#include <math.h>

/************************

function drawAxis

drawAxis is a program used for debugging that draws an axis in the X,Y, and Z
used debugging, and setting up the camera, and aligning the cube

************************/
void drawAxis()
{
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex3f(0,0,0);
	glVertex3f(10,0,0);
	
	glColor3f(1,1,0);
	glVertex3f(-10,0,0);
	glVertex3f(0,0,0);

	glColor3f(0,1,0);
	glVertex3f(0,0,0);
	glVertex3f(0,10,0);

	glColor3f(0,0,1);
	glVertex3f(0,0,-10);
	glVertex3f(0,0,0);

	glColor3f(1,0,1);
	glVertex3f(0,0,10);
	glVertex3f(0,0,0);

	glColor3fv(BLACK);
	glVertex3f(1.5,-.2,0);
	glVertex3f(1.5,.2,0);

	glColor3f(1,0,1);
	glVertex3f(-1.6,-.2,0);
	glVertex3f(-1.6,.2,0);
	glEnd();
	
	
}

/*********************

function setColor

inputs: int side

outputs: void

This function generates a color using the 
RED, GREEN, BLUE constants to correspond to
the side of the cube being drawn

*********************/
void setColor(int side)
{
	switch(side)
	{
	case 0:
		RED = 1.0;
		GREEN = 1.0;
		BLUE = 1.0;
		break;
	case 1:
		RED = 1.0;
		GREEN = 0.0;
		BLUE = 0.0;
		break;
	case 2:
		RED = 1.0;
		GREEN = 1.0;
		BLUE = 0.0;
		break;
	case 3:
		RED = 1.0;
		GREEN = 0.5;
		BLUE = 0.0;
		break;
	case 4:
		RED = 0.0;
		GREEN = 0.0;
		BLUE = 1.0;
		break;
	case 5:
		RED = 0.0;
		GREEN = 1.0;
		BLUE = 0.0;
		break;
	default:
		RED = 0.0;
		GREEN = 0.0;
		BLUE = 0.0;
		break;
	}

}

/**********************

function animateSectionRotate

inputs: LargeCube cube

outputs: void

This function adds the rotation animations to the 
cube when a side is rotated

**********************/
void animateSectionRotate(LargeCube cube)
{
	//glTranslatef(-1.5,-1.4,-1.5);
	glTranslatef(-HEIGHT/WIDTH - .5,-HEIGHT/WIDTH - .4,-HEIGHT/WIDTH -.5);
	if(cube.NextMove.direction == 2 || cube.NextMove.direction == -2)
	{
		if(cube.NextMove.direction == -2) cube.step = cube.step*-1;
		if(cube.NextMove.section == 0)
		{
			glPushMatrix();
			glTranslatef((HEIGHT/WIDTH)+.5,0,(HEIGHT/WIDTH)+.5);
			glRotatef(cube.step,0,1,0);
			glTranslatef(-((HEIGHT/WIDTH)+.5),0,-((HEIGHT/WIDTH)+.5));

			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (1)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (1)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 1.005+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 1.005+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 1.005+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 1.005+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (1)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (1)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
		
			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();

			for(int j = 0; j<3; j++)
			{
				for (int k = 0; k<3; k++)
				{

					//draw the top face
					glBegin(GL_QUADS);
					setColor(cube.cube[k][0][j].side[0]);
					glColor3f(RED, GREEN, BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH) ,   (j-1+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH) , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH) , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH) , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

					glEnd();

					if(j<1)
					{

						glBegin(GL_QUADS);

						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED, GREEN, BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED, GREEN, BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
							
						glEnd();
					}
					if(k<1)
					{
						glBegin(GL_QUADS);
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED, GREEN, BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED, GREEN, BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glEnd();
					}
				}		
			}
			
			glPopMatrix();
			glPushMatrix();
			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, .995+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, .995+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , .995+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , .995+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (.995)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH), -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (.995)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (.995)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (.995)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
		
			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.995)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.995)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-1.11)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-1.11)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (.995)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.995)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-1.11)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-1.11)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();
			for(int j = 0; j<3; j++)
			{
				for(int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					//draw the bottom face
					setColor(cube.cube[k][2][j].side[2]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					
					if(j > 0)
					{
						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						
						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					}
					if (k > 0)
					{
						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
								
					}
					glEnd();
				}
					glPopMatrix();
			}
		}

		else if(cube.NextMove.section == 1)
		{
			glPushMatrix();
			glTranslatef((HEIGHT/WIDTH)+.5,0,(HEIGHT/WIDTH)+.5);
			glRotatef(cube.step,0,1,0);
			glTranslatef(-((HEIGHT/WIDTH)+.5),0,-((HEIGHT/WIDTH)+.5));
			int j = 1;
			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (1)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-0.05)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-0.05)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (1)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.05+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.05+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.05+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.05+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (1)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-0.05)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-0.05)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (1)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
		
			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();

			for (int k = 0; k<3; k++)
			{
			glBegin(GL_QUADS);
			//back face
			setColor(cube.cube[k][j][2].side[3]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

			//Front colored face
			setColor(cube.cube[k][j][0].side[1]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glEnd();
			
			}
			int k = 1;
			for (int j = 0; j<3; j++)
			{
				//right face
				glBegin(GL_QUADS);
				setColor(cube.cube[2][k][j].side[4]);
				glColor3f(RED,GREEN,BLUE);
				glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));


				//left face
				setColor(cube.cube[0][k][j].side[5]);
				glColor3f(RED,GREEN,BLUE);
				glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				
				glEnd();
			}	
			glPopMatrix();
			glPushMatrix();

			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top bottom face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			
			//top fill
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.105+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.105+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//bottom top face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.045+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.045+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.045+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.045+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (1)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (1)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
		
			//top right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//top left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (1)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

				
			//bottom back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.105)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-0.05)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-0.05)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.105)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			//top front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.105)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-0.05)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-0.05)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.105)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
		
			//top right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (-1.06)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (2.06)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-1.105)+(HEIGHT/WIDTH)  , 2.06+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-1.105)+(HEIGHT/WIDTH)  , -1.06+(HEIGHT/WIDTH));

			//top left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-1.105)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-1.105)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

				
			//top back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (1)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (1)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			glEnd();
		
			for(int j = 0; j<3; j++)
			{
				for(int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					//draw the bottom face
					setColor(cube.cube[k][2][j].side[2]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.11+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.11+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.11+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.11+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
				
					//top colored face
					setColor(cube.cube[k][0][j].side[0]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						

			
					if(j != 1)
					{
						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					}
					if (k != 1)
					{
						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
								
					}
					glEnd();
				}
				glPopMatrix();
			}
		}

		else if(cube.NextMove.section == 2)
		{
			glPushMatrix();
			glTranslatef((HEIGHT/WIDTH)+.5,0,(HEIGHT/WIDTH)+.5);
			glRotatef(cube.step,0,1,0);
			glTranslatef(-((HEIGHT/WIDTH)+.5),0,-((HEIGHT/WIDTH)+.5));

			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.055+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.055+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.055+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.055+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-0.055)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.1)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.1)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-0.055)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-0.055)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.1)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.1)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-0.055)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
		
			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-1.1)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-1.1)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.055)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.055)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (-1.1)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-1.1)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.055)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.055)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();

			for (int k = 0; k<3; k++)
			{
				for(int j = 0; j<3; j++)
				{
					glBegin(GL_QUADS);
					//draw the bottom face
					setColor(cube.cube[k][2][j].side[2]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

					if(j == 2)
					{
						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
		
						glEnd();
					}
				}
			}
			int k = 2;
			for (int j = 0; j<3; j++)
			{
				//right face
				glBegin(GL_QUADS);
				setColor(cube.cube[2][k][j].side[4]);
				glColor3f(RED,GREEN,BLUE);
				glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));


				//left face
				setColor(cube.cube[0][k][j].side[5]);
				glColor3f(RED,GREEN,BLUE);
				glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
				glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				glEnd();
			}	
			glPopMatrix();
			glPushMatrix();

			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-0.05)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-0.05)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.05+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -0.05+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.05+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -0.05+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-0.05)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-0.05)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
		
			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (-0.05)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();
		
			for(int j = 0; j<3; j++)
			{
				for(int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					//top colored face
					setColor(cube.cube[k][0][j].side[0]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
					
					if(j != 2)
					{
						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					}
					if (k != 2)
					{
						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
								
					}
					glEnd();
				}
				glPopMatrix();
			}

		}
	}
	else if(cube.NextMove.direction == -1 || cube.NextMove.direction == 1)
	{
		if(cube.NextMove.direction == -1) cube.step = cube.step*-1;
		if(cube.NextMove.section == 0)
		{
			glPushMatrix();
			glTranslatef(0,(HEIGHT/WIDTH)+.5,(HEIGHT/WIDTH)+.5);
			glRotatef(cube.step,-1,0,0);
			glTranslatef(0,-((HEIGHT/WIDTH)+.5),-((HEIGHT/WIDTH)+.5));

			glBegin(GL_QUADS);
			glColor3fv(BLACK);
			//left side left
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			
			//left side right
			glVertex3f(.99+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top face
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			glEnd();
			//draw the left face
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					setColor(cube.cube[0][k][j].side[5]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					if(k  == 0)
					{
						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

					}
					glEnd();

				}
			}


			glPopMatrix();
			glPushMatrix();

			glBegin(GL_QUADS);
			glColor3fv(BLACK);

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH)	, (.94-2.045)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH)	, (.94-2.045)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			
			//left side inside
			glVertex3f(.985+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)			, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(.985+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)			, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.985+(HEIGHT/WIDTH)		, (.94-2.045)+(HEIGHT/WIDTH)	, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.985+(HEIGHT/WIDTH)		, (.94-2.045)+(HEIGHT/WIDTH)	, (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((.985)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)			,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)			,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)			,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)			,   (-1.045)+(HEIGHT/WIDTH));
				
			//top face
			glVertex3f((.985)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)			,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)			,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)			,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)			,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));

			glEnd();

			for(int j = 0; j<3; j++)
			{
				for (int k = 0; k<3; k++)
				{

					glBegin(GL_QUADS);
					if (k > 0)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					}
					//right face
					setColor(cube.cube[2][k][j].side[4]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						
					glColor3f(0.0,0.0,0.0);
					glVertex3f(-1.055+(HEIGHT/WIDTH), (2-k)+(HEIGHT/WIDTH)  , (j-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.055+(HEIGHT/WIDTH), (1-k)+(HEIGHT/WIDTH)  , (j-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.055+(HEIGHT/WIDTH), (1-k)+(HEIGHT/WIDTH)  , j+(HEIGHT/WIDTH));
					glVertex3f(-1.055+(HEIGHT/WIDTH), (2-k)+(HEIGHT/WIDTH)  , j+(HEIGHT/WIDTH));
					glEnd();
				}
			}
			glPopMatrix();
		}
		else if(cube.NextMove.section == 1)
		{
			glPushMatrix();
			glTranslatef(0,(HEIGHT/WIDTH)+.5,(HEIGHT/WIDTH)+.5);
			glRotatef(cube.step,-1,0,0);
			glTranslatef(0,-((HEIGHT/WIDTH)+.5),-((HEIGHT/WIDTH)+.5));
			int k = 1;
			//left side left
			glBegin(GL_QUADS);
			glColor3fv(BLACK);
			glVertex3f(.985+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(.985+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.985+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.985+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			
			//left side right
			glVertex3f(.99+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((.985)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top face
			glVertex3f((.985)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.985)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			glEnd();
			//draw the left face
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					if(k  == 1)
					{
						glBegin(GL_QUADS);
						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

					}
					glEnd();

				}
			}


			glPopMatrix();
			glPushMatrix();

			glBegin(GL_QUADS);
			glColor3fv(BLACK);
			//left side left
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			
			//left side right
			glVertex3f(.99+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(.99+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top face
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.99)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			//left side left
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			
			//left side right
			glVertex3f(-0.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-0.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-0.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-0.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-1.1)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			glEnd();

			for(int j = 0; j<3; j++)
			{
				for (int k = 0; k<3; k++)
				{

					glBegin(GL_QUADS);
					if (k == 0 || k == 2)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					}
					//right face
					setColor(cube.cube[2][k][j].side[4]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
				
					//left face
					setColor(cube.cube[0][k][j].side[5]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					glEnd();
				}
			}
			glPopMatrix();
		}
		else if(cube.NextMove.section == 2)
		{
			glPushMatrix();
			glTranslatef(0,(HEIGHT/WIDTH)+.5,(HEIGHT/WIDTH)+.5);
			glRotatef(cube.step,-1,0,0);
			glTranslatef(0,-((HEIGHT/WIDTH)+.5),-((HEIGHT/WIDTH)+.5));
			int k = 2;

			//draw the left face
			glBegin(GL_QUADS);
			glColor3fv(BLACK);

			//left side left
			glVertex3f(-0.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-0.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-0.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-0.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			
			//left side right
			glVertex3f(-1.1+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.1+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.1+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.1+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-1.105)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			glEnd();
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					//right face
					setColor(cube.cube[2][k][j].side[4]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f(-1.105+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.105+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(-1.105+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f(-1.105+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					if(k  == 2)
					{
						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

					}
					glEnd();

				}
			}


			glPopMatrix();
			glPushMatrix();

			//draw the left face
			glBegin(GL_QUADS);
			glColor3fv(BLACK);

			//left side left
			glVertex3f(-0.045+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-0.045+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-0.045+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-0.045+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			
			//left side right
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//front side
			glVertex3f((-0.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((-0.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
				
			//bottom face
			glVertex3f((-0.045)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((-0.045)+(HEIGHT/WIDTH)	, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//top face
			glVertex3f((-0.045)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((-0.045)+(HEIGHT/WIDTH)	, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, 2.04+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//back face
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((-0.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			for(int j = 0; j<3; j++)
			{
				for (int k = 0; k<3; k++)
				{

					glBegin(GL_QUADS);
					if (k < 2)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//Front colored face
						setColor(cube.cube[k][j][0].side[1]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));


						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//back face
						setColor(cube.cube[k][j][2].side[3]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					}
					
					//draw left face
					setColor(cube.cube[0][k][j].side[5]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					glEnd();
				}
			}
			glPopMatrix();
		}
	}
	else if(cube.NextMove.direction == 3 || cube.NextMove.direction == -3)
	{
		if(cube.NextMove.direction == -3) cube.step = cube.step*-1;
		if (cube.NextMove.section == 0)
		{
			glPushMatrix();
			glTranslatef((HEIGHT/WIDTH)+.5,(HEIGHT/WIDTH)+.5,0);
			glRotatef(cube.step,0,0,-1);
			glTranslatef(-((HEIGHT/WIDTH)+.5),-((HEIGHT/WIDTH)+.5),0);

			glBegin(GL_QUADS);
			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)    , 2.040+(HEIGHT/WIDTH)  ,		(-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)    , 2.040+(HEIGHT/WIDTH)  ,		(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			//front face back
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, (HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, (HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, (HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, (HEIGHT/WIDTH));


			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		 , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , (HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		,	(-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		,	(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();

			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					//Front colored face
					setColor(cube.cube[k][j][0].side[1]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

					glEnd();
					
					glBegin(GL_QUADS);
					if(j  == 0)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					}
					glEnd();

					//needed for initial roatation
				}
			}
			glPopMatrix();
			glPushMatrix();
			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   0.05+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   0.05+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 0.05+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 0.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 0.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 0.05+(HEIGHT/WIDTH));

			//back face
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (0.05)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 0.05+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (0.05)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (0.05)+(HEIGHT/WIDTH));

			glEnd();
			for (int j = 0; j<3; j++)
			{
				for(int k = 0; k< 3; k++)
				{
					glBegin(GL_QUADS);
					//back face
					setColor(cube.cube[k][j][2].side[3]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));						
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					if(j > 0)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					}
					glEnd();
				}
			}
			glPopMatrix();
			
		}
		else if(cube.NextMove.section == 1)
		{
			glPushMatrix();
			glTranslatef((HEIGHT/WIDTH)+.5,(HEIGHT/WIDTH)+.5,0);
			glRotatef(cube.step,0,0,-1);
			glTranslatef(-((HEIGHT/WIDTH)+.5),-((HEIGHT/WIDTH)+.5),0);

			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)	,  (0.05)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)	,   (1.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (1.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 0.05+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 0.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 0.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 0.05+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (1.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (1.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 1.05+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 1.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 1.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 1.05+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)			, (1.05)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)			, (0.05)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)	, 0.05+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)	, 1.05+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (1.05)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		, (0.05)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (0.05)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (1.05)+(HEIGHT/WIDTH));

			glEnd();

			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					
					glBegin(GL_QUADS);
					if(j  == 1)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
					}
					glEnd();

					//needed for initial roatation
				}
			}
			glPopMatrix();
			glPushMatrix();

			glBegin(GL_QUADS);

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//front face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)			, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (0.05)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 1.015+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 1.015+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 1.015+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 1.015+(HEIGHT/WIDTH));
			
			//front face back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)		, 0.05+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)			, 0.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, 0.05+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, 0.05+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , 0.05+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 0.05+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (0.05)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (0.05)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			//top face
			glColor3fv(BLACK);
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));


			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , 1.015+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 1.015+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (1.015)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (1.015)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));

			glEnd();

			for (int j = 0; j<3; j++)
			{
				for(int k = 0; k< 3; k++)
				{
					glBegin(GL_QUADS);
					//back face
					setColor(cube.cube[k][j][2].side[3]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));						
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

					//Front colored face
					setColor(cube.cube[k][j][0].side[1]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

					if(j != 1)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						
					}
					glEnd();
				}
			}
			glPopMatrix();
		}
		else if(cube.NextMove.section == 2)
		{
			glPushMatrix();
			glTranslatef((HEIGHT/WIDTH)+.5,(HEIGHT/WIDTH)+.5,0);
			glRotatef(cube.step,0,0,-1);
			glTranslatef(-((HEIGHT/WIDTH)+.5),-((HEIGHT/WIDTH)+.5),0);
			glBegin(GL_QUADS);

			glColor3fv(BLACK);
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

			
			//front face back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)		, 1.015+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)			, 1.015+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, 1.015+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, 1.015+(HEIGHT/WIDTH));

			//top face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));


			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , 1.015+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 1.015+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (1.015)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (1.015)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));

			glEnd();
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k<3; k++)
				{
					glBegin(GL_QUADS);
					//back face
					setColor(cube.cube[k][j][2].side[3]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));						
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
					
					if(j  == 2)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

					}
					glEnd();

					//needed for initial roatation
				}
			}
			glPopMatrix();
			glPushMatrix();

			glBegin(GL_QUADS);

			glColor3fv(BLACK);
			//back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, -1.045+(HEIGHT/WIDTH));

			
			//front face back face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)		, 1.015+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)			, 1.015+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)			, 1.015+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, 1.015+(HEIGHT/WIDTH));

			//top face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, 2.040+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//bottom face
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
			glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (1.015)+(HEIGHT/WIDTH));
			glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

			//right face
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , -1.045+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)		  , 1.015+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 1.015+(HEIGHT/WIDTH));
			glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

			//left face
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (1.015)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (1.015)+(HEIGHT/WIDTH));
			glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

			glEnd();
			for (int j = 0; j<3; j++)
			{
				for(int k = 0; k< 3; k++)
				{
					glBegin(GL_QUADS);
					//Front colored face
					setColor(cube.cube[k][j][0].side[1]);
					glColor3f(RED,GREEN,BLUE);
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
					glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

					if(j < 2)
					{
						//top colored face
						setColor(cube.cube[k][0][j].side[0]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//draw the bottom face
						setColor(cube.cube[k][2][j].side[2]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

						//right face
						setColor(cube.cube[2][k][j].side[4]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

						//left face
						setColor(cube.cube[0][k][j].side[5]);
						glColor3f(RED,GREEN,BLUE);
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
						
					}
					glEnd();
				}
			}
			glPopMatrix();
		}
	}
}

/**************************

function draw3DCube

inputs: LargeCube cube

outputs: void

This function draws the base cube of 27 unit cubes

**************************/
void draw3DCube(LargeCube cube)
{
	glTranslatef(-HEIGHT/WIDTH-.5,-HEIGHT/WIDTH - .4,-HEIGHT/WIDTH - .5);
	glBegin(GL_QUADS);

	//top face
	glColor3fv(BLACK);
	glVertex3f((2.045)+(HEIGHT/WIDTH)    , 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));		
	glVertex3f((2.045)+(HEIGHT/WIDTH)    , 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
	glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
	glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , 2.040+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));

	//front face
	glVertex3f((2.05)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
	glVertex3f((2.05)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
	glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));
	glVertex3f((.94-2.05)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)		, -1.045+(HEIGHT/WIDTH));

	//bottom face
	glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	glVertex3f((2.045)+(HEIGHT/WIDTH)		, -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
	glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (2.095)+(HEIGHT/WIDTH));
	glVertex3f((.94-2.045)+(HEIGHT/WIDTH)   , -1.1+(HEIGHT/WIDTH)  ,   (-1.045)+(HEIGHT/WIDTH));
	
	//back face
	glVertex3f((2.045)+(HEIGHT/WIDTH)		, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));
	glVertex3f((2.045)+(HEIGHT/WIDTH)		, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
	glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (2.04)+(HEIGHT/WIDTH)		, 2.095+(HEIGHT/WIDTH));
	glVertex3f((.94-2.045)+(HEIGHT/WIDTH)	, (-1.11)+(HEIGHT/WIDTH)	, 2.095+(HEIGHT/WIDTH));

	//right face
	glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
	glVertex3f(-1.105+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
	glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , 2.095+(HEIGHT/WIDTH));
	glVertex3f(-1.105+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , -1.045+(HEIGHT/WIDTH));

	//left face
	glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));
	glVertex3f(2.05+(HEIGHT/WIDTH), (2.04)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
	glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (2.095)+(HEIGHT/WIDTH));
	glVertex3f(2.05+(HEIGHT/WIDTH), (.94-2.045)+(HEIGHT/WIDTH)  , (-1.045)+(HEIGHT/WIDTH));

	glEnd();
	
	for(int j = 0; j<3; j++)
		{
			for (int k = 0; k<3; k++)
			{
				

			glBegin(GL_QUADS);

			//top colored face
			setColor(cube.cube[k][0][j].side[0]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j-1+j*.03)+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , 2.045+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

			//Front colored face
			setColor(cube.cube[k][j][0].side[1]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , -1.05+(HEIGHT/WIDTH));

			//draw the bottom face
			setColor(cube.cube[k][2][j].side[2]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03-1)+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));
			glVertex3f((2-k*.03-k)+(HEIGHT/WIDTH)   , -1.105+(HEIGHT/WIDTH)  ,   (j+j*.03)+(HEIGHT/WIDTH));

			//back face
			setColor(cube.cube[k][j][2].side[3]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (2-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
			glVertex3f((1-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));
			glVertex3f((2-k-k*.03)+(HEIGHT/WIDTH)  , (1-j-j*.03)+(HEIGHT/WIDTH) , 2.1+(HEIGHT/WIDTH));

			//right face
			setColor(cube.cube[2][k][j].side[4]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
			glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
			glVertex3f(-1.11+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
			glVertex3f(-1.11+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

			//left face
			setColor(cube.cube[0][k][j].side[5]);
			glColor3f(RED,GREEN,BLUE);
			glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
			glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03-1)+(HEIGHT/WIDTH));
			glVertex3f(2.055+(HEIGHT/WIDTH), (1-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));
			glVertex3f(2.055+(HEIGHT/WIDTH), (2-k-k*.03)+(HEIGHT/WIDTH)  , (j+j*.03)+(HEIGHT/WIDTH));

			glEnd();
		}
	}

}