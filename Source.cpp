float WIDTH = 500;
float HEIGHT = 500;
int cameraDirection = 1;
float RED,BLUE,GREEN;
int cameraRotate = 0;
float BLACK[3] = {0.0,0.0,0.0}; 
float WHITE[3] = {1.0,1.0,1.0};

#include <stdlib.h>
#include <Windows.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <gl/glut.h>
#include <gl/GL.h>
#include <fstream>
#include "cubeStructures.h"

bool previousWindow = false;
bool initiateSolve = false;
bool pause = false;
bool voidKeys = false;
LargeCube solver(LargeCube cube);
LargeCube randomize(LargeCube cube);
LargeCube graphicalRandomizer(LargeCube cube);
LargeCube graphicalSolve(LargeCube cube);
GLuint	texture[3];			// Storage For One Texture ( NEW )

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

#include "textControls.h"
#include "3DLibrary.h"
#include "randomNumberGenerator.h"
#include "GameModes.h"
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

void drawCubeNet(LargeCube cube);
void display(void);
void display3DFront(void);
void displayMainMenu(void);
void displayMain(void);
void display3DBack(void);
void display(void);
void playerOneDisplay(void);
void playerOneDisplayBack(void);
void playerTwoDisplay(void);
void playerTwoDisplayBack(void);
void idleFunc3d(void);
void openMainMenu(void);
void versusIdleFunction(void);
LargeCube executePlayerMove(LargeCube cube, int direction, int section);
void voidWindow(void);
void rotateCube(unsigned char key, int x, int y);
void voidKeyBoard(unsigned char key, int x, int y);
char selectChar(int value);
void initiateClock(void);
void parseTime(int seconds, int minute);
void voidWindow(void);
bool checkSolve(LargeCube cube);
void basicKeyboard();
void activateKeyboard();
LargeCube solver(LargeCube cube);
LargeCube randomize(LargeCube cube);

int ROOF = 1;
float radius;
double cameraAngle = 3.14;
double cameraCount = 0;
float verticalAngle = 1.57;
float EYE[3] = {0,0,-8};
float CENTER[3] = {0,0,0};
int ANGLE = 50;
int MAIN_WINDOW, BACK_WINDOW, FRONT_WINDOW, SECOND_BACK_WINDOW, SECOND_FRONT_WINDOW;
bool isOpen = false;

/*********************
Player One is the cube that will be manipulated by the player
*********************/
LargeCube PLAYER_ONE;

/****************************

function setKeyboard 

This function monitors whether or not to void the keyboard
when functions such as rotation requires the keyboard to be
voided they set keyboardVoid to true and the keyboard is 
then voided

****************************/
void setKeyboardfunc(void)
{
	if(keyboardVoid == true)
	{
		glutSetWindow(MAIN_WINDOW);
		glutKeyboardFunc(voidKeyBoard);
	}
	else
	{
		glutSetWindow(MAIN_WINDOW);
		glutKeyboardFunc(rotateCube);
	}
}

/***********************************

function graphicalRandomizer

inputs: LargeCube cube

outputs: LargeCube cube

This function takes a cube and randomizes it through
the rotation statemachine by setting a random 
direction and section into the next move section of the 
cube class and setting the step to zero activating the inital
rotation step

***********************************/
LargeCube graphicalRandomizer(LargeCube cube)
{
	Move temp;
	if(cube.activateRandom == true)
	{
		cube.activateSolve = false;
		clockCycles = 0;
		keyboardVoid = true;
		if(cube.step == 0 && cube.random < 41)
		{
			temp = randomNumberGenerator();
			cube.NextMove.direction = temp.direction;
			cube.NextMove.section = temp.section;
			cube.step = 10;
			cube.random++;
			if(PLAYER_TWO.mode != 3) Sleep(50);
			else Sleep(20);
		}
		else if(cube.random == 41) 
		{
			cube.random = 0;
			temp.direction = cube.NextMove.direction;
			temp.section = cube.NextMove.section;
			cube.moves.push(temp);
			cube.activateRandom = false;
			keyboardVoid = false;
			if(cube.initiate == true) cube.initiate = false;
		}
	}
	return cube;
}

/***************************

function graphicalSolver

inputs: LargeCube cube

outputs: LargeCube cube

This fuction works the same way as the randomizer
however instead it uses a stack and works the moves backwards
until the cube is solved

***************************/
LargeCube graphicalSolve(LargeCube cube)
{
	if(cube.activateSolve == true && cube.step == 0) 
	{
		cube.activateRandom = false;
		if(checkSolve(cube)) 
		{
			cube.activateSolve = false;
			//cube.initiate = true;
			keyboardVoid = false;
		}
		else if(cube.activateSolve == true)
		{
			cube = solver(cube);
			Sleep(20);
			keyboardVoid = true;
		}
	}
	return cube;
}

/**************************

function modelSingleCube

Expressly for testing purposes, this function draws an
individual unit cube in three space, designed to allow
rotation tests

**************************/
void modelSingleCube(int x, int y, int z, SmallCube cube)
{

	glBegin(GL_QUADS);
	glVertex3i(50 - x*10, 50 - y*10, z);
	glVertex3i(110+x*10, 110+y*10, z);
	glVertex3i(100+x*10, 100+y*10, z);
	glVertex3i(100+x*10, 100+y*10, z);
	glEnd();

}

/****************************

function voidMouse

This function voids the mouse function in the currently
selected window

****************************/
void voidMouse(int button, int state, int x, int y)
{
}


/*************************

function cameraRotationStateMachine

inputs: void

This function keeps track of the camera
and icrements its location so that the camera has
a smooth animation when moving

*************************/
void cameraRotationStateMachine(void)
{
	if(cameraRotate > 0 && cameraRotate < 159 || cameraRotate < 0 && cameraRotate > -159)
	{
		if(cameraDirection == 1)
		{
			cameraAngle -= 0.005;
			if(cameraAngle < 0.005) cameraAngle = 6.28;
			else if(cameraAngle > 6.28) cameraAngle = .005;
			if(cameraRotate%8 == 0)
			{
				EYE[0] = 8*sin(cameraAngle);
				EYE[2] = 8*cos(cameraAngle);
			}
			cameraRotate--;
		}
		else if(cameraDirection == -1)
		{
			cameraAngle += 0.005;
			if(cameraAngle < 0.005) cameraAngle = 6.28;
			else if(cameraAngle > 6.28) cameraAngle = 0.005;
			if(cameraRotate % 8)
			{
				EYE[0] = 8*sin(cameraAngle);
				EYE[2] = 8*cos(cameraAngle);
			}
			cameraRotate++;
			
		}
		else if(cameraDirection == 2)
		{
			verticalAngle -= .005;
			if(verticalAngle > 2.355) verticalAngle -= 3.14;
			else if(verticalAngle < .785) 
			{
				verticalAngle = .785;
				cameraRotate = 0;
			}
			EYE[0] = 8*sin(cameraAngle);
			EYE[1] = 8*cos(verticalAngle);
			cameraRotate--;
		}
		else if(cameraDirection == -2)
		{
			verticalAngle += .005;
			if(verticalAngle < -2.355) verticalAngle += 3.14;
			else if(verticalAngle > 2.355) 
			{
				verticalAngle = 2.355;
				cameraRotate = 0;
			}
			EYE[0] = 8*sin(cameraAngle);
			EYE[1] = 8*cos(verticalAngle);
			cameraRotate++;
		}
	}
	if(cameraRotate == 158 || cameraRotate == -158) cameraRotate = 0;
}

/******************

function stateCamera

inputs: int button
		int state
		int x
		int y

outputs: void

This function is a standard mouse function
it determines where the user clicks and then 
rotates the camera using the statemachine 
depending on where the user clicks

******************/
void stateCamera(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN && x < (WIDTH/2)-120*(WIDTH/HEIGHT) && 
		y < (HEIGHT/2)+120*(WIDTH/HEIGHT)  && y > (HEIGHT/2)-120*(WIDTH/HEIGHT))
	{
		if(cameraRotate == 0) cameraRotate = 1;
		cameraDirection = -1;
	}
	else if(state == GLUT_DOWN && x > (WIDTH/2)+120*(WIDTH/HEIGHT) &&
		y < (HEIGHT/2)+120*(WIDTH/HEIGHT)  && y > (HEIGHT/2)-120*(WIDTH/HEIGHT))
	{
	if(cameraRotate == 0) cameraRotate = -1;
	cameraDirection = 1;
	}
	else if(state == GLUT_DOWN && x < (WIDTH/2)+120*(WIDTH/HEIGHT) &&
		x > (HEIGHT/2)-120*(WIDTH/HEIGHT)  &&  y < (HEIGHT/2)-120*(WIDTH/HEIGHT))
	{
		if(cameraRotate == 0) cameraRotate = -1;
		cameraDirection = 2;
	}
	else if(state == GLUT_DOWN && x < (WIDTH/2)+120*(WIDTH/HEIGHT) &&
		x > (HEIGHT/2)-120*(WIDTH/HEIGHT)  &&  y > (HEIGHT/2)+120*(WIDTH/HEIGHT))
	{
		if(cameraRotate == 0) cameraRotate = 1;
		cameraDirection = -2;
	}
}

/******************

function activeCamera

inputs: int button
		int state
		int x
		int y

outputs: void

This function is a standard mouse function
it determines where the user clicks and then 
rotates the camera using a basic incremented
camera system depending on where the user clicks

******************/
void activeCamera(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN && x < (WIDTH/2)-120*(WIDTH/HEIGHT) && 
		y < (HEIGHT/2)+120*(WIDTH/HEIGHT)  && y > (HEIGHT/2)-120*(WIDTH/HEIGHT))
	{
	cameraAngle += 0.785;
	if(cameraAngle > 6.28) cameraAngle = .785;
	EYE[0] = 8*sin(cameraAngle);
	EYE[2] = 8*cos(cameraAngle);
	if(cameraAngle > 6.28) cameraAngle = 0;
	}
	else if(state == GLUT_DOWN && x > (WIDTH/2)+120*(WIDTH/HEIGHT) &&
		y < (HEIGHT/2)+120*(WIDTH/HEIGHT)  && y > (HEIGHT/2)-120*(WIDTH/HEIGHT))
	{
	cameraAngle -= 0.785;
	if(cameraAngle < 0) cameraAngle = 6.28;
	else if(cameraAngle > 6.28) cameraAngle = .785;
	EYE[0] = 8*sin(cameraAngle);
	EYE[2] = 8*cos(cameraAngle);
	}
	else if(state == GLUT_DOWN && x < (WIDTH/2)+120*(WIDTH/HEIGHT) &&
		x > (HEIGHT/2)-120*(WIDTH/HEIGHT)  &&  y < (HEIGHT/2)-120*(WIDTH/HEIGHT))
	{
		verticalAngle -= .785;
		if(verticalAngle > 2.355) verticalAngle -= 3.14;
		else if(verticalAngle < .785) 
		{
			verticalAngle = .785;
		}
		EYE[0] = 8*sin(cameraAngle);
		EYE[1] = 8*cos(verticalAngle);
	}
	else if(state == GLUT_DOWN && x < (WIDTH/2)+120*(WIDTH/HEIGHT) &&
		x > (HEIGHT/2)-120*(WIDTH/HEIGHT)  &&  y > (HEIGHT/2)+120*(WIDTH/HEIGHT))
	{
		verticalAngle += .785;
		if(verticalAngle < -2.355) verticalAngle += 3.14;
		else if(verticalAngle > 2.355) 
		{
			verticalAngle = 2.355;
		}
		EYE[0] = 8*sin(cameraAngle);
		EYE[1] = 8*cos(verticalAngle);
	}
}

/******************

function mouse

inputs: int button
		int state
		int x
		int y

outputs: void

This is the funciton that controls the menu
it detects where the mouse clicks and then allows
chooses the game mode

******************/
void mouse(int button, int state, int x, int y)
{
	if(state == GLUT_DOWN && x > (WIDTH/2) - 20 && x < (WIDTH/2) + 76 && y > (3*HEIGHT/8)-20 && y < (3*HEIGHT/8)+10)
	{
		if(previousWindow == true) 
		{
			WIDTH /= 2; 
			previousWindow = false;
		}
		glutIdleFunc(idleFunc3d);
		glutSetWindow(MAIN_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		glutSetWindow(FRONT_WINDOW);
		glutDisplayFunc(display3DFront);
		glutMouseFunc(stateCamera);
		glutSetWindow(BACK_WINDOW);
		glutDisplayFunc(display3DBack);
		glutMouseFunc(voidMouse);
		PLAYER_ONE.initiate = true;
		PLAYER_ONE.mode = 0;
		PLAYER_TWO.mode = 0;
	}
	else if(state == GLUT_DOWN && x > (WIDTH/2) - 20 && x < (WIDTH/2) + 76 && y > (3*HEIGHT/8) + 10 && y < (3*HEIGHT/8)+40)
	{
		if(previousWindow == true) 
		{
			WIDTH /= 2; 
			previousWindow = false;
		}
		glutIdleFunc(idleFunc3d);
		glutSetWindow(MAIN_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		glutSetWindow(FRONT_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		glutDisplayFunc(display3DFront);
		glutMouseFunc(stateCamera);
		glutSetWindow(BACK_WINDOW);
		glutDisplayFunc(display3DBack);
		PLAYER_ONE.initiate = true;
		PLAYER_ONE.mode = 1;
		PLAYER_TWO.mode = 0;
	}
	else if(state == GLUT_DOWN && x > (WIDTH/2) - 20 && x < (WIDTH/2) + 76 && y > (3*HEIGHT/8) + 40 && y < (3*HEIGHT/8) + 70)
	{
		if(previousWindow == true) 
		{
			WIDTH /= 2; 
			previousWindow = false;
		}
		glutIdleFunc(idleFunc3d);
		glutSetWindow(MAIN_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		glutSetWindow(FRONT_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		glutDisplayFunc(display3DFront);
		glutMouseFunc(stateCamera);
		glutSetWindow(BACK_WINDOW);
		glutDisplayFunc(display3DBack);
		PLAYER_ONE.initiate = true;
		PLAYER_ONE.mode = 2;
		PLAYER_TWO.mode = 0;
	}
	else if(state == GLUT_DOWN && x > (WIDTH/2) - 20 && x < (WIDTH/2) + 76 && y > (3*HEIGHT/8) + 70 && y < (3*HEIGHT/8) + 110)
	{
		if(previousWindow == false) 
		{
			WIDTH *= 2;
			previousWindow = true;
			glutSetWindow(MAIN_WINDOW);
			glutReshapeWindow(WIDTH, HEIGHT);
			glutMouseFunc(stateCamera);
		}
		else
		{
		glutSetWindow(MAIN_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		}
		glutIdleFunc(versusIdleFunction);
		
		glutSetWindow(FRONT_WINDOW);
		glutDisplayFunc(playerOneDisplay);
		glutMouseFunc(stateCamera);

		glutSetWindow(BACK_WINDOW);
		glutDisplayFunc(playerOneDisplayBack);
		
		glutSetWindow(SECOND_FRONT_WINDOW);
		glutMouseFunc(stateCamera);
		glutDisplayFunc(playerTwoDisplay);
		
		glutSetWindow(SECOND_BACK_WINDOW);
		glutDisplayFunc(playerTwoDisplayBack);
		
		PLAYER_TWO.initiate = true;
		PLAYER_ONE.initiate = true;
		PLAYER_ONE.mode = 0;
		PLAYER_TWO.mode = 3;
		PLAYER_ONE.activateRandom = true;
	}
	else if(state == GLUT_DOWN && x > (WIDTH/2) - 20 && x < (WIDTH/2) + 76 && y > (3*HEIGHT/8) + 90 && y < (3*HEIGHT/8) + 120)
	{
		exit(0);
	}
}

/*******************

function changeSize

inputs: int w
		int h

outputs: void

This is the resize function, it resizes
all the windows when they are needed.

*******************/
void changeSize(int w, int h)
{
	float ratio;
	WIDTH = w;
	HEIGHT = h;

	if (h == 0) h = 1;

	ratio =  w / h;

	glLoadIdentity();

	glViewport(0, 0, WIDTH, HEIGHT);

	glMatrixMode(GL_MODELVIEW);

	if(PLAYER_TWO.mode == 3)
	{
	glutSetWindow(BACK_WINDOW);
	glutPositionWindow(3*WIDTH/8, 0);
	glutReshapeWindow(WIDTH/8, WIDTH/8);

	glutSetWindow(FRONT_WINDOW);
	glutReshapeWindow(WIDTH/4, HEIGHT);
	glutMouseFunc(stateCamera);
	glutPositionWindow(0, 0);

	glutSetWindow(SECOND_BACK_WINDOW);
	glutPositionWindow(7*WIDTH/8, 0);
	glutReshapeWindow(WIDTH/8, WIDTH/8);

	glutSetWindow(SECOND_FRONT_WINDOW);
	glutReshapeWindow(WIDTH/4, HEIGHT);
	glutMouseFunc(stateCamera);
	glutPositionWindow(WIDTH/2, 0);
	glutSetWindow(MAIN_WINDOW);
	glutMouseFunc(stateCamera);
	}
	else
	{
	glutSetWindow(BACK_WINDOW);
	glutPositionWindow(3*WIDTH/4, 0);
	glutReshapeWindow(WIDTH/4, WIDTH/4);
	glutSetWindow(FRONT_WINDOW);
	glutPositionWindow(0, 0);
	glutReshapeWindow(WIDTH, HEIGHT);
	glutSetWindow(MAIN_WINDOW);
	}


}

/*******************

function display3DFront

display3DFront is the main display function
for the main game window.

*******************/
void display3DFront(void)
{
	glCullFace(GL_BACK);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH, HEIGHT);
	gluPerspective(ANGLE,WIDTH/HEIGHT,1,100);
	glutSetWindow(FRONT_WINDOW);
	glutMouseFunc(stateCamera);
	glOrtho(-1,1,-1,1,1,-1);
	gluLookAt(EYE[0],EYE[1],EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	PLAYER_ONE = rotationStateMachine(PLAYER_ONE);
	if(PLAYER_ONE.mode == 1) printText(WIDTH/2,8*HEIGHT/9,parsedTime, 5, BLACK);
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();

}

//The following are the four display functions for the 4 windows
//needed to run the display for the competitive mode

/*******************

function playerOneDisplay

playerOneDisplay is designed for the four display mode
(computer verus) it is the player's display

*******************/
void playerOneDisplay(void)
{
	glCullFace(GL_BACK);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH/2, HEIGHT);
	glutMouseFunc(stateCamera);
	gluPerspective(ANGLE,(WIDTH/2)/HEIGHT,1,100);

	glOrtho(-1,1,-1,1,1,-1);
	gluLookAt(EYE[0],EYE[1],EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	PLAYER_ONE = rotationStateMachine(PLAYER_ONE);
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();
}

/*******************

function playerOneDisplayBack

playerOneDisplayBack is designed for the four display mode
(computer verus) it is the player's back display. 

*******************/
void playerOneDisplayBack(void)
{
	glCullFace(GL_FRONT);
	glutInitDisplayMode(GL_DOUBLE| GLUT_RGBA | GLUT_DEPTH);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH/8, WIDTH/8);
	glOrtho(-1,1,-1,1,1,-1);
	gluPerspective(ANGLE,1,1 ,100);
	gluLookAt(-EYE[0],-EYE[1],-EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	rotationStateMachine(PLAYER_ONE);
	glutPostRedisplay();
}

/***************************

function versusIdleFunction

This is the idle function that keeps track of the
player and computer moves in computer versus

***************************/
void versusIdleFunction(void)
{
	PLAYER_ONE = selectGameMode(PLAYER_ONE);
	PLAYER_TWO = selectGameMode(PLAYER_TWO);
	if(goBackToMenu == true) openMainMenu();
	if(voidKeys == true) basicKeyboard();
	else activateKeyboard();
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();

}

/*******************

function playerTwoDisplay

playerTwoDisplayBack is designed for the four display mode
(computer verus) it is the computer's display. 

*******************/
void playerTwoDisplay(void)
{
	glCullFace(GL_BACK);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH/2, HEIGHT);
	
	gluPerspective(ANGLE,(WIDTH/2)/HEIGHT,1,100);

	glOrtho(-1,1,-1,1,1,-1);
	gluLookAt(EYE[0],EYE[1],EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	PLAYER_TWO = rotationStateMachine(PLAYER_TWO);
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();
}

/*******************

function playerTwoDisplayBack

playerTwoDisplayBack is designed for the four display mode
(computer verus) it is the computer's back display. 

*******************/
void playerTwoDisplayBack(void)
{
	glCullFace(GL_FRONT);
	glutInitDisplayMode(GL_DOUBLE| GLUT_RGBA | GLUT_DEPTH);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH/8, WIDTH/8);
	glOrtho(-1,1,-1,1,1,-1);
	gluPerspective(ANGLE,1,1 ,100);
	gluLookAt(-EYE[0],-EYE[1],-EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	rotationStateMachine(PLAYER_TWO);
	glutPostRedisplay();
}

/*********************

function displayMainMenu

This function draws the mainMenu

*********************/
void displayMainMenu(void)
{
	glCullFace(GL_BACK);
	glClearColor(0,0,0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, image);
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH, HEIGHT);
	gluPerspective(ANGLE,WIDTH/HEIGHT,1,100);
	glOrtho(0,WIDTH,0,HEIGHT,0,400);
	gluLookAt(EYE[0],EYE[1],EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	
	glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); 
		glTexCoord2f(WIDTH, 0.0f); 
		glTexCoord2f(WIDTH, HEIGHT); 
		glTexCoord2f(0.0f, HEIGHT); 

	glEnd();
    char string[64];
    sprintf(string, "Free Play");
	printText(WIDTH/2,5*HEIGHT/8,string, 9, WHITE);
	sprintf(string, "Single Player");
	printText((WIDTH/2)-10,(5*HEIGHT/8)-30,string, 13, WHITE);
	sprintf(string, "Computer Mode");
	printText((WIDTH/2)-25,(5*HEIGHT/8)-60,string, 13, WHITE);
	sprintf(string, "Computer Versus");
	printText((WIDTH/2)-30,(5*HEIGHT/8)-90,string, 15, WHITE);
	sprintf(string, "Exit");
	printText((WIDTH/2)+30,(5*HEIGHT/8)-120,string, 5, WHITE);


	glutSwapBuffers();
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();

}

/*********************

function displayMain

This is the display function that runs the window
that encompasses all the other windows

*********************/
void displayMain(void)
{
	glCullFace(GL_BACK);
	glutInitDisplayMode(GL_DOUBLE| GLUT_RGBA | GLUT_DEPTH);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	gluPerspective(ANGLE,WIDTH/HEIGHT,1,100);

	glOrtho(-1,1,-1,1,1,-1);
	gluLookAt(EYE[0],EYE[1],EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);

}

/************************

function display3DBack

This is the function draws to the back window
during the single player games
************************/
void display3DBack(void)
{
	glCullFace(GL_FRONT);
	
	glutInitDisplayMode(GL_DOUBLE| GLUT_RGBA | GLUT_DEPTH);
	glClearColor(0.5,0.5,0.5, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glutReshapeWindow(WIDTH/4, WIDTH/4);
	glOrtho(-1,1,-1,1,1,-1);
	gluPerspective(ANGLE,1,1 ,100);
	gluLookAt(-EYE[0],-EYE[1],-EYE[2], CENTER[0],CENTER[1],CENTER[2],0,ROOF,0);
	PLAYER_ONE = rotationStateMachine(PLAYER_ONE);
	glutPostRedisplay();

}

/*****************

function basicKeyboard

This function sets the keyboard to void when
it is not needed

*****************/
void basicKeyboard(void)
{
	glutSetWindow(MAIN_WINDOW);
	glutKeyboardFunc(voidKeyBoard);
	glutSetWindow(FRONT_WINDOW);
	glutKeyboardFunc(voidKeyBoard);
	glutSetWindow(SECOND_FRONT_WINDOW);
	glutKeyboardFunc(voidKeyBoard);
	glutSetWindow(SECOND_BACK_WINDOW);
	glutKeyboardFunc(voidKeyBoard);
}

/*********************

function activateKeyboard

Sets the keyboards to active so that the 
player can use the keyboard in play

*********************/
void activateKeyboard(void)
{
	glutSetWindow(MAIN_WINDOW);
	glutKeyboardFunc(rotateCube);
	glutSetWindow(FRONT_WINDOW);
	glutKeyboardFunc(rotateCube);
	glutSetWindow(SECOND_FRONT_WINDOW);
	glutKeyboardFunc(rotateCube);
	glutSetWindow(SECOND_BACK_WINDOW);
	glutKeyboardFunc(rotateCube);
}

/*****************************

function idleFunc3d

This function runs the single display game modes

*****************************/
void idleFunc3d(void)
{
	setKeyboardfunc();
	if(goBackToMenu == true) openMainMenu();
	if(voidKeys == true) basicKeyboard();
	else activateKeyboard();
	cameraRotationStateMachine();
	PLAYER_ONE = selectGameMode(PLAYER_ONE);
	glutSwapBuffers();
	glFlush();
	glutPostRedisplay();
}

/****************************

0 - Top		- Black
1 - Front	- Red
2 - Bottom	- Green
3 - Back	- Blue
4 - Right	- Orange
5 - Left	- Yellow
default - default - Black

****************************/
void drawCubeNet(LargeCube cube)
{
	int number;
	for (int i = 0; i<6; i++)
	{
		for(int j = 0; j<3; j++)
		{
			for (int k = 0; k<3; k++)
			{
				if(i == 0) number = cube.cube[k][0][j].side[0];
				if(i == 1) number = cube.cube[k][j][0].side[1];
				if(i == 2) number = cube.cube[k][2][j].side[2];
				if(i == 3) number = cube.cube[k][j][2].side[3];
				if(i == 4) number = cube.cube[2][k][j].side[4];
				if(i == 5) number = cube.cube[0][k][j].side[5];
				switch(number)
				{
				case 0:
					glColor3f(0.0,0.0,0.0);
					break;
				case 1:
					glColor3f(1.0,0.0,0.0);
					break;
				case 2:
					glColor3f(1.0,1.0,0.0);
					break;
				case 3:
					glColor3f(1.0,0.5,0.0);
					break;
				case 4:
					glColor3f(0.0,0.0,1.0);
					break;
				case 5:
					glColor3f(0.0,1.0,0.0);
					break;
				default:
					glColor3f(0.0,0.0,0.0);
					break;
				}
				glPointSize(40);
				glBegin(GL_POINTS);

				//draw the top face
				if(i == 0) glVertex2i(k*45+200, ((i)*200+140) - j*55);
				
				//draw the front face
				if(i == 1) glVertex2i(k*45+200, ((i)*200)+30 + (j*55));
				
				//draw the bottom face
				if(i == 2) glVertex2i(k*45+200, ((i)*200)+30 + (j*55));
				
				//the back face
				if(i == 3) 
				{
					glVertex2i(k*45+200, ((i)*200+140) - j*55);
					glVertex2i(600- k*45, (j*55)+230);
				}
				
				//the left face
				if(i == 4) glVertex2i(j*45+350, (k*55)+230);
				
				//the right face
				if(i == 5) glVertex2i(130 -(j*45), k*55 + 230);
				glEnd();

			}
		}
	}

}

/**********************

function circularCameraControl

circularCameraControl is a keyboard based camera
that allows spherical motion (this is camera revision 2 leading
to the animated camera)

**********************/
void circularCameraControl(unsigned char key, int x, int y)
{
	if(key == '1')
	{
		cameraAngle += .01;
		radius = sqrt((EYE[0]*EYE[0])+(EYE[2]*EYE[2]));
		EYE[0] = 8*sin(cameraAngle);
		EYE[2] = 8*cos(cameraAngle);
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '2')
	{
		cameraAngle -= .01;
		radius = sqrt((EYE[0]*EYE[0])+(EYE[2]*EYE[2]));
		EYE[0] = 8*sin(cameraAngle);
		EYE[2] = 8*cos(cameraAngle);
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '3')
	{
		verticalAngle -= .01;
		if(verticalAngle > 0) verticalAngle -= 6.28;
		if(verticalAngle >-3.14) ROOF = 1;
		else if(verticalAngle < -6.28) 
		{
			ROOF = 1;
			verticalAngle = 0;
		}
		else if(verticalAngle < -3.14) ROOF = -1;
		EYE[0] = 8*sin(verticalAngle);
		EYE[1] = 8*cos(verticalAngle);
		EYE[2] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '4')
	{
		verticalAngle += .01;
		if(verticalAngle < 0) verticalAngle += 6.28;
		if(verticalAngle > 6.28) 
		{
			ROOF = -1;
			verticalAngle = 0;
		}
		else if(verticalAngle > 3.14) ROOF = 1;
		EYE[0] = 8*sin(verticalAngle);
		EYE[1] = 8*cos(verticalAngle);
		EYE[2] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '5')
	{
		//front
		cameraAngle = 3.14;
		EYE[0] = 8*sin(cameraAngle);
		EYE[2] = 8*cos(cameraAngle);
		EYE[1] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '%')
	{
		//left
		cameraAngle = 1.57;
		EYE[0] = 8*sin(cameraAngle);
		EYE[2] = 8*cos(cameraAngle);
		EYE[1] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '6')
	{
		//back
		cameraAngle = 0;
		EYE[0] = 8*sin(cameraAngle);
		EYE[2] = 8*cos(cameraAngle);
		EYE[1] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '7')
	{
		//right
		cameraAngle = -1.57;
		EYE[0] = 8*sin(cameraAngle);
		EYE[2] = 8*cos(cameraAngle);
		EYE[1] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '&')
	{
		//top
		verticalAngle = 0.001;
		ROOF = 1;
		EYE[0] = 8*sin(verticalAngle);
		EYE[1] = 8*cos(verticalAngle);
		EYE[2] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
	else if(key == '8')
	{
		//top
		verticalAngle = -3.14;
		ROOF = -1;
		EYE[0] = 8*sin(verticalAngle);
		EYE[1] = 8*cos(verticalAngle);
		EYE[2] = 0;
		CENTER[0] = 0;
		CENTER[1] = 0;
		CENTER[2] = 0;
	}
}

/**********************

function cameraControl

this is the first version of the
current cameraControl structure
this camera is a basic keyboard
based camera control structure

**********************/
void cameraControl(unsigned char key, int x, int y)
{
	if(key == '1')
	{
		EYE[0] = 1;
		EYE[1] = 1.45;
		EYE[2] = -5.9;
		CENTER[0] = 1;
		CENTER[1] = 1.45;
		CENTER[2] = -0.9;
		cout<<"front"<< endl;
	}
	//Back face
	else if(key == '2')
	{
		EYE[0] = 1.95;
		EYE[1] = 1.45;
		EYE[2] = 8.95;
		CENTER[0] = 1.95;
		CENTER[1] = 1.45;
		CENTER[2] = -0.85;
		cout<<"Back"<< endl;
	}
	//Top face
	else if(key == '3')
	{
		EYE[0] = 1.6;
		EYE[1] = 9;
		EYE[2] = 0.95;
		CENTER[0] = 1.599999;
		CENTER[1] = -0.6;
		CENTER[2] = 0.95;
		cout<<"top"<< endl;
	}
	//Bottom face
	else if(key == '4')
	{
		EYE[0] = 1;
		EYE[1] = -10;
		EYE[2] = 2;
		CENTER[0] = 0.999;
		CENTER[1] = 0;
		CENTER[2] = 2;
		cout<<"bottom"<< endl;
	}
	//Right face
	else if(key == '5')
	{
		EYE[0] = 10;
		EYE[1] = 2;
		EYE[2] = 2;
		CENTER[0] = 0;
		CENTER[1] = 2;
		CENTER[2] = 2;
		cout<<"right"<< endl;
	}
	//Left face
	else if(key == '6')
	{
		EYE[0] = -10;
		EYE[1] = 2;
		EYE[2] = 2;
		CENTER[0] = 0;
		CENTER[1] = 2;
		CENTER[2] = 2;
		cout<<"left"<< endl;
	}
}

void voidKeyBoard(unsigned char key, int x, int y)
{
	if(key == 'p' || key == 'P')
	{
		if(pause == false) pause = true;
		else if(pause == true) pause = false;
		cout << "Pause..." << endl;
	}
	else if(key == 'z' || key == 'Z')
	{
		openMainMenu();
	}
}

/**************

function openMainMenu

This function is the function that
changes the display functions so that
the menu can be displayed

**************/
void openMainMenu(void)
{
		PLAYER_ONE.activateRandom = false;
		PLAYER_ONE.activateSolve = false;
		PLAYER_TWO.activateRandom = false;
		PLAYER_TWO.activateSolve = false;
		PLAYER_TWO.mode = 0;
		PLAYER_ONE.mode = 0;
		if(previousWindow == true) 
		{
			WIDTH /= 2; 
			previousWindow = false;
		}
		clockCycles = 0;
		initiateClock();
		PLAYER_ONE = initiateLargeCube();
		glutSetWindow(MAIN_WINDOW);
		glutReshapeWindow(WIDTH, HEIGHT);
		glutSetWindow(FRONT_WINDOW);
		glutDisplayFunc(displayMainMenu);
		glutMouseFunc(mouse);
		glutSetWindow(BACK_WINDOW);
		glutDisplayFunc(voidWindow);
		goBackToMenu = false;
}

/******************

function rotateCube

This is the function that runs the keyboard in the game modes
this keyboard is synced to the camera, when the angle of the 
camera changes so do the controls. The controls are kept constant
for easier control

******************/
void rotateCube(unsigned char key, int x, int y)
{
	if(key == 'z' || key == 'Z')
	{
		openMainMenu();
	}
	if (key == 'q' || key == 'Q')
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,0);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,0);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,2);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,2);
	}
	else if(key == 'w' || key == 'W') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,1);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,1);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,1);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,1);
	}
	else if(key == 'e' || key == 'E') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,2);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,2);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,0);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,0);
	}
	else if(key == 'a' || key == 'A') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,0);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,0);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,2);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,2);
	}
	else if(key == 's' || key == 'S') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,1);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,1);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,1);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,1);
	}
	else if(key == 'd' || key == 'D') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,0);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,0);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,2);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,2);
	}

	else if(key == 't' || key == 'T')
	{
		PLAYER_ONE = executePlayerMove(PLAYER_ONE, 2,0);
	}
	else if(key == 'g' || key == 'G') 
	{
		PLAYER_ONE = executePlayerMove(PLAYER_ONE, 2,1);
	}
	else if(key == 'b' || key == 'B')
	{
		PLAYER_ONE = executePlayerMove(PLAYER_ONE, 2,2);
	}
	else if(key == 'r' || key == 'R')
	{
		PLAYER_ONE = executePlayerMove(PLAYER_ONE, -2,0);
	}
	else if(key == 'f' || key == 'F') 
	{
		PLAYER_ONE = executePlayerMove(PLAYER_ONE, -2,1);
	}
	else if(key == 'v' || key == 'V') 
	{
		PLAYER_ONE = executePlayerMove(PLAYER_ONE, -2,2);
	}

	else if(key == 'y' || key == 'Y')
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,0);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,2);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,2);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,0);
	}
	else if(key == 'h' || key == 'H') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,1);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,1);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,1);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,1);
	}
	else if(key == 'n' || key == 'N') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,2);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,0);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,0);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,2);
	}
	else if(key == 'u' || key == 'U')
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,0);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,2);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,2);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,0);
	}
	else if(key == 'j' || key == 'J')
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,1);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,1);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,1);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,1);
	}
	else if(key == 'm' || key == 'M') 
	{
		if(cameraAngle > 2.356 && cameraAngle < 3.926)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -3,2);
		else if(cameraAngle > 3.926 && cameraAngle < 5.496)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, -1,0);
		else if(cameraAngle > 5.496 || cameraAngle < .786)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 3,0);
		else if(cameraAngle > .786 || cameraAngle < 2.356)
			PLAYER_ONE = executePlayerMove(PLAYER_ONE, 1,2);
	}
	else if(key == 'c') initiateSolve= true;
	else if(key == 'p' || key == 'P')
	{
		if(pause == false) pause = true;
		else if(pause == true) pause = false;
		cout << "Pause..." << endl;
	}
	else;
}

/**************

function solver

inputs: LargeCube cube

outputs: LargeCube cube

This function takes a large cube and solves it

**************/
LargeCube solver(LargeCube cube)
{
	
	if(cube.moves.empty() != true && cube.activateSolve == true)
	{
		if(cube.step == 0)
		{
			Move temp;
			temp = cube.moves.top();
			cube.NextMove.section = temp.section;
			cube.NextMove.direction = -temp.direction;
			cube.moves.pop();
			cube.step = 10;
			if(cube.moves.empty()) cube.activateSolve = false;
		}
	}
	else if(pause == false) cout<<"CRASHED"<< endl;
	return cube;
}

/************

function voidWindow

voidWindow voids windows by reducing the 
size to 1x1 pixel

************/
void voidWindow(void)
{
	glClearColor(0.5,0.5,0.5,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluPerspective(ANGLE,WIDTH/HEIGHT,1,0);
	glutReshapeWindow(1,1);
	gluLookAt(EYE[0],EYE[1],EYE[2], 0, 1.0,  4.0, 0.0,1.0,0.0);
	glutPostRedisplay();
}
/*************

function main

This is the main function of the program

*************/
int main(int argc, char **argv)
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_ALPHA_TEST);
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(20,20);
	MAIN_WINDOW = glutCreateWindow("CUBEZ");
	BACK_WINDOW = glutCreateSubWindow(MAIN_WINDOW, 0,0,0,0);
	FRONT_WINDOW = glutCreateSubWindow(MAIN_WINDOW, 0, 0,0,0);
	SECOND_BACK_WINDOW = glutCreateSubWindow(MAIN_WINDOW,0,0,0,0);
	SECOND_FRONT_WINDOW = glutCreateSubWindow(MAIN_WINDOW,0,0,0,0);
	glutSetWindow(SECOND_BACK_WINDOW);
	glutDisplayFunc(voidWindow);

	glutSetWindow(SECOND_FRONT_WINDOW);
	glutDisplayFunc(voidWindow);

	glutSetWindow(FRONT_WINDOW);
	glutDisplayFunc(displayMainMenu);
	glutKeyboardFunc(rotateCube);
	glutMouseFunc(mouse);

	glutSetWindow(BACK_WINDOW);
	glutDisplayFunc(voidWindow);

	glutSetWindow(MAIN_WINDOW);
	glutDisplayFunc(displayMain);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(rotateCube);
	
	glutIdleFunc(idleFunc3d);

	glutMainLoop();
	return 0;
}