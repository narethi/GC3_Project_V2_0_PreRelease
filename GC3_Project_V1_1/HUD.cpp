#include "../stdafx.h"

#include "HUD.h"

	int screen_width,screen_height;
	int screenh,screenw;
	std::vector<unsigned char> crosshair;
	unsigned width, height;
	size_t u2,v2;
	double u3,v3;
    char buffer [10];

void HUD::init(){
	
	crosshair = draw("images/TankCrosshair.png");
}
void HUD::operate(int kill,int remaining) {
	
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_ALPHA_TEST);

	glClear(GL_DEPTH_BUFFER_BIT);
  
	glViewport(0, 0, screen_width, screen_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, screen_width, screen_height, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &crosshair[0]);
	glColor4ub(255, 255, 255, 255);
	int offsetW = screen_width/2;
	int offsetH = screen_height/2;	
	 glBegin(GL_QUADS);
	 glTexCoord2d( 0,  0); glVertex2f(offsetW - width/2,offsetH - height/2);
	 glTexCoord2d(u3,  0); glVertex2f(offsetW + width/2,offsetH - height/2);
	 glTexCoord2d(u3, v3); glVertex2f(offsetW + width/2,offsetH + height/2);
	 glTexCoord2d( 0, v3); glVertex2f(offsetW - width/2, offsetH + height/2);
	 glEnd();
	 glDisable(GL_TEXTURE_2D);

	 glutPrint(0, 18,combineChar("Kill Count",itoa(kill,buffer,10)), 0.0f, 1.0f, 0.0f, 1.0f);
	 glutPrint(0, 36,itoa(remaining,buffer,10), 0.0f, 1.0f, 0.0f, 1.0f);

	glViewport(0, 0, screen_width, screen_height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, GLdouble (screen_width), 0, GLdouble (screen_height));
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glDisable(GL_BLEND);
		
}

void HUD::getWindowSize(int width, int height){
	screen_width = width;
	screen_height = height;
}

std::vector<unsigned char> HUD::draw(char* dir){
	 
	std::vector<unsigned char> image;
	unsigned error = lodepng::decode(image, width, height, dir);
	screenw = width;
	if(screenw > 1024) 
		screenw = 1024;
	screenh = height;
	if(screenh > 768) 
		screenw = 768;
	u2 = 1;while(u2 < width) u2 *= 2;
	v2 = 1; while(v2 < height) v2 *= 2;
	u3 = (double)width / u2;
	v3 = (double)height / v2;
	std::vector<unsigned char> image2(u2 * v2 * 4);
	for(size_t y = 0; y < height; y++)
		for(size_t x = 0; x < width; x++)
			for(size_t c = 0; c < 4; c++)
				image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];

return image2;
}


void HUD::glutPrint(float x, float y, char* text, float r, float g, float b, float a)
{
	glDisable(GL_LIGHTING); 
    if(!text || !strlen(text)) return;
    bool blending = false;
    if(glIsEnabled(GL_BLEND)) blending = true;
    glEnable(GL_BLEND);
    glColor4f(r,g,b,a);
    glRasterPos2f(x,y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
    glDisable(GL_BLEND);
	glEnable(GL_LIGHTING); 
}  

char* HUD::combineChar(char* a, char* b)
{
	char* c = ' ';

	for(int i= 0;i<sizeof(a)+sizeof(b)+1;i++)
	{
		if(i<sizeof(a))
			c+=a[i];
		else if(i==sizeof(a))
			c+=' ';
		else
			c+=b[i];
	}
	
	return c;
}