char selectChar(int value);
void parseTime(int seconds, int minute);
void printText(int x, int y, char word[], int wordLength);

char parsedTime[5] = {'0', '0', ':' ,'0', '0'};

/********************************

function printText

inputs: int x
		int y
		char word[]
		int wordLength

outputs: void

This function takes the location and word and prints it to the screen

********************************/
void printText(int x, int y, char word[], int wordLength, float color[])
{
	//(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -2.0f, 5.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
	glColor3fv(color);
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (unsigned int i = 0; i <  wordLength; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, word[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

/******************************

function parseTime

inputs: int seconds
		int minute

outputs: void

This function takes the time arguments and parses the integer
information into a string of chars for write to screen

******************************/
void parseTime(int seconds, int minute)
{
	int ones, tens, minutesOnes, minutesTens;
	minutesOnes = minute%10;
	minutesTens = minute/10;
	ones = seconds%10;
	tens = seconds/10;
	if(minutesTens == 0) parsedTime[0] = ' ';
	else parsedTime[0] = selectChar(minutesTens);
	parsedTime[4] = selectChar(ones);
	parsedTime[3] = selectChar(tens);
	parsedTime[2] = ':';
	parsedTime[1] = selectChar(minutesOnes);
}

/********************************

funtion selectChar

inputs: int value

outputs: char

This function takes an integer multiple of 1 and returns
the char representation

********************************/
char selectChar(int value)
{
	switch(value)
	{
	case 0: return '0';
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	default: return '0';
	}
}