#include <iostream>
#include <stack>

using namespace std;

struct SmallCube;
struct LargeCube;
struct CubeFace;
struct Move;

CubeFace collectFace(LargeCube cube, int direction, int section);
SmallCube initiateSmallCube(void);
LargeCube initiateLargeCube(void);
SmallCube rotateSmallCube(SmallCube cube, int direction);
LargeCube rotateSide(LargeCube cube, int direction, int section);

/*************

state stores the current moves to be 
played by the animation

*************/
struct state
{
	int direction;
	int section;
};

struct Move
{
	int direction;
	int section;
};
/**********
direction:
1	is the rotate forward
-1	is the rotate backwards
2	is the rotate right
-2	is the rotate left
**********/

/**********
0 = top
1 = front
2 = bottom
3 = back
4 = right
5 = left
***********/
struct SmallCube {int side[6];};


/*****************
Stores the information pertaining to a cube, the first value
is the width, the next value is the height and the last value
is the depth of the cube 
[column][row][layer]
*****************/
struct LargeCube
{
	SmallCube cube[3][3][3];
	stack<Move> moves;
	state NextMove;
	int step, mode, random;
	bool activateRandom, activateSolve, initiate;
};

/******************
CubeFace stores the information pertaining to the values in a face of cubes
it stores either the row information or the column in these respective patterns
[row][layer] or [column][layer]
******************/
struct CubeFace {SmallCube cube[3][3];};

/*************************

function collectCubeFace

inputs: LargeCube cube
		int direction
		int section

outputs: CubeFace face

This function takes a cube and selects an individual
face for rotation. It uses the direction and section to determine
which face to choose and then returns the face

*************************/
CubeFace collectFace(LargeCube cube, int direction, int section)
{
	/*
	direction tells us whether we need to store the row or the column
	Column and row tells us which cubes we need to turn
	*/
	CubeFace face;
	if(direction == 1 || direction == -1)
	{
		if(section == 0) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[0][j][i]; 

		else if(section == 1) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[1][j][i]; 
		
		else if(section == 2) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[2][j][i]; 
	}
	else if(direction == 2 || direction == -2)
	{
		if(section == 0) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[j][0][i]; 
		
		else if(section == 1) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[j][1][i]; 
		
		else if(section == 2) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[j][2][i]; 
	}
	else if(direction == 3 || direction == -3)
	{
		if(section == 0) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[j][i][0]; 
		
		else if(section == 1) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[j][i][1]; 
		
		else if(section == 2) for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) face.cube[i][j] = cube.cube[j][i][2]; 
	}
	return face;
}

/*************************

function initiateSmallCube

inputs: void

outputs: SmallCube

This function initializes an indovidual unit cube to
the up facing position

*************************/
SmallCube initiateSmallCube(void)
{
	SmallCube cube;
	for (int i = 0; i < 6; i++)
	{
		cube.side[i] = i;
	}
	return cube;
}

/**************************

function initiateLargeCube

inputs: void

outputs: LargeCube cube

Generates 27 correctly positioned unit cubes into
a fullsized rubik's cube

**************************/
LargeCube initiateLargeCube(void)
{
	LargeCube cube;
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			for(int k = 0; k<3; k++)
			{
				cube.cube[i][j][k] = initiateSmallCube();
			}
		}
	}
	cube.step = 0;
	cube.NextMove.direction = 0;
	cube.NextMove.section = 0;
	cube.mode = 0;
	cube.activateRandom = false;
	cube.activateSolve = false;
	cube.initiate = false;
	cube.random = 0;
	return cube;
}

/**********
0 = top
1 = front
2 = bottom
3 = back
4 = right
5 = left
***********/
/******************************

function rotateSmallCube

inputs: SmallCube cube, int direction

outputs: SmallCube temp

This function rotates a single unit cube in a single direction

******************************/
SmallCube rotateSmallCube(SmallCube cube, int direction)
{
	SmallCube temp;
	//Left turn
	if(direction == -3)
	{
		/*
		0 - > 5
		5 - > 2
		2 - > 4
		4 - > 0*/
		for (int i = 0; i<6; i++){
			if (i == 0) temp.side[i] = cube.side[5];
			else if (i == 5) temp.side[i] = cube.side[2];
			else if (i == 2) temp.side[i] = cube.side[4];
			else if (i == 4) temp.side[i] = cube.side[0];
			else temp.side[i] = cube.side[i];
		}
	}

	else if(direction == -2)
	{
		for (int i = 0; i<6; i++)
		{
			//front becomes right
			if(i == 1) temp.side[i] = cube.side[4];

			//back becomes left
			else if(i == 3) temp.side[i] = cube.side[5];
			
			
			//right becomes back
			else if(i == 4) temp.side[i] = cube.side[3];

			//left to front
			else if(i == 5) temp.side[i] = cube.side[1];

			//top and bottom stay the same
			else temp.side[i] = cube.side[i];
		}
	}
	//Backward rotate
	else if(direction == -1)
	{
		for (int i = 0; i<6; i++)
		{
			if(i < 3) temp.side[i] = cube.side[i+1];

			else if(i == 3) temp.side[i] = cube.side[0];
			else temp.side[i] = cube.side[i];
		}
	}
	//Forward rotate
	else if(direction == 1)
	{
		for (int i = 0; i<6; i++)
		{
			//top to back
			if (i == 0) temp.side[i] = cube.side[3];

			//front to top
			//back to botom
			//bottom to front
			else if(i <= 3 && i > 0) temp.side[i] = cube.side[i-1];

			//left and right stay the same
			else temp.side[i] = cube.side[i];
		}
	}
	//Right Turn
	else if(direction == 2)
	{
		for (int i = 0; i<6; i++)
		{
			//front becomes left
			if(i == 1) temp.side[i] = cube.side[5];
			
			//back becomes right
			else if(i == 3) temp.side[i] = cube.side[4];
			
			//right becomes front
			else if(i == 4) temp.side[i] = cube.side[1];
			
			//left becomes back
			else if(i == 5) temp.side[i] = cube.side[3];
			
			//top and bottom stay the same
			else temp.side[i] = cube.side[i];
		}
	}

	if(direction == 3)
	{
		/*
		0 - > 5
		5 - > 2
		2 - > 4
		4 - > 0*/
		for (int i = 0; i<6; i++)
		{
			if (i == 0) temp.side[i] = cube.side[4];
			else if (i == 2) temp.side[i] = cube.side[5];
			else if (i == 4) temp.side[i] = cube.side[2];
			else if (i == 5) temp.side[i] = cube.side[0];
			else temp.side[i] = cube.side[i];
		}
	}


	return temp;
}


/****************************

rotateSide rotates a single side or section of the cube and returns the cube

inputs:
	LargeCube cube; The cube being modified
	int direction; The direction that it is being turn
	int row, int column; The row and column information that is required for
						 Knowing which chunk to move
outputs:
	LargeCube cube; The output is the input cube with the single rotated section

****************************/
LargeCube rotateSide(LargeCube cube, int direction, int section)
{
	CubeFace temp;
	temp = collectFace(cube, direction, section);
	for(int i = 0; i<3; i++) 
		for(int j = 0; j<3; j++) temp.cube[i][j] = rotateSmallCube(temp.cube[i][j], direction);
	
	if(direction == -3)
		for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) 
			cube.cube[j][i][section] = temp.cube[2-j][i];

	if(direction == 3)
		for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) 
			cube.cube[j][i][section] = temp.cube[j][2-i];


	if(direction == -2)
			for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) 
				cube.cube[j][section][i] = temp.cube[j][2-i];

	else if(direction == 2)
		for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) 
			cube.cube[j][section][i] = temp.cube[2-j][i];

	else if(direction == -1) 
		for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) 
			cube.cube[section][j][i] = temp.cube[j][2-i];

	else if(direction == 1) 
		for(int i = 0; i<3; i++) for(int j = 0; j<3; j++) 
			cube.cube[section][j][i] = temp.cube[2-j][i];
	
	return cube;
}