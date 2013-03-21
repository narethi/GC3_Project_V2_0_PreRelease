/*#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

#include <GL/glut.h>

using namespace std;

void display(void);

int WindowHeight = 600;
int WindowWidth = 600;

void printText(int x, int y, string String)
{
//(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WindowWidth, 0, WindowHeight, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (int i=0; i<String.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glEnable(GL_DEPTH_TEST);
	
    char string[64];
    sprintf(string, "Single Player");
    printText(250,390,string);
	sprintf(string, "Computer Modes");
	printText(250,360,string);
	sprintf(string, "Computer Versus");
	printText(250,330,string);
	sprintf(string, "Choose cube color");
	printText(240,300,string);
	sprintf(string, "Choose background");
	printText(240,270,string);


	glutSwapBuffers();
}


int main(int argc, char *argv[])
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WindowWidth, WindowHeight);
	glutInitWindowPosition(0, 0);
	
	glutCreateWindow("OpenGL Text Example");
	
	glutDisplayFunc(display);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 1, 1, 100);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	gluLookAt(2, 2, 10, 2, 0, 0, 0, 1, 0);

	glutMainLoop();
	return 0;
}


	else if(key == '3') 
	{
		CENTER[1] = CENTER[1] - .1;
		EYE[1] = EYE[1] - .1; 
	}
	else if(key == '4') 	
	{
		CENTER[1] = CENTER[1] + .1;
		EYE[1] = EYE[1] + .1; 
	}
	else if(key == '5')
	{
		CENTER[2] = CENTER[2] - .1;
		EYE[2] = EYE[2] - .1; 
	}
	else if(key == '6') 
	{
		CENTER[2] = CENTER[2] + .1;
		EYE[2] = EYE[2] + .1; 
	} 
	else if(key == '7')	
	{
		CENTER[0] = CENTER[0] - .1;
		EYE[0] = EYE[0] - .1; 
	}
	else if(key == '8') 
	{
		CENTER[0] = CENTER[0] + .1;
		EYE[0] = EYE[0] + .1; 
	}
*/
