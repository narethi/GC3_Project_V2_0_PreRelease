char selectChar(int value);
void parseTime(int seconds, int minute);
void printText(int x, int y, string String);

char parsedTime[5] = {'0', '0', ':' ,'0', '0'};

void printText(int x, int y, string String)
{
//(x,y) is from the bottom left of the window
	parseTime(seconds, minutes);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -2.0f, 5.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
	glColor3fv(BLACK);
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (unsigned int i = 0; i <  5; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, parsedTime[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

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