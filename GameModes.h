bool keyboardVoid = false;
bool activateSolve = false;
bool initiate = true;
bool goBackToMenu = false;
int seconds;
int minutes;
int clockCycles = 0;

LargeCube selectGameMode(LargeCube player);
void initiateClock(void);
void countDownTimer(void);
LargeCube timeModeStateMachine(LargeCube cube);
LargeCube versusModeStateMachine(LargeCube cube);
LargeCube freePlayStateMachine(LargeCube cube);
LargeCube computerModeStateMachine(LargeCube cube);
LargeCube rotationStateMachine(LargeCube cube);
LargeCube executePlayerMove(LargeCube cube, int direction, int section);
bool checkSolve(LargeCube cube);
//int mode = 0;
LargeCube PLAYER_TWO;

/******************************

function selectGameMode

inputs: LargeCube player

outputs: LargeCube player

selectGameMode looks at the mode selection value and
choose to run the corresponding state machines.

the state machines are as follows:
	
	0: freeplay
	1: time challenge
	2: computer demo mode
	3: computer versus mode

******************************/
LargeCube selectGameMode(LargeCube player)
{
	int temp = player.mode;
	bool tempRandom = player.activateRandom;
	bool tempSolve = player.activateSolve;
	bool tempInitiate = player.initiate;
	if(player.initiate == true && player.activateRandom == false || player.initiate == true && player.mode == 0)
	{
		clockCycles = 0;
		player.random = 0;
		initiateClock();
		player = initiateLargeCube();
		player.activateRandom = false;
		keyboardVoid = false;
	}
	player.mode = temp;
	player.activateSolve = tempSolve;
	player.activateRandom = tempRandom;
	player.initiate = tempInitiate;
	switch(player.mode)
	{
	case 0:	if(player.initiate == true) player.initiate = false;
			player = graphicalSolve(player);
			player = graphicalRandomizer(player);
			break;
	case 1: if(player.initiate == true) player.activateRandom = true;
			else if(player.initiate == false && !checkSolve(player) && initiateSolve == true) 
			{
				player.activateSolve = true;
				player.activateRandom = false; 
			}
			player = graphicalSolve(player);
			player = graphicalRandomizer(player);
			player = timeModeStateMachine(player);
			printText(WIDTH/2,8*HEIGHT/9,parsedTime, 5, BLACK);
			if(checkSolve(player) && !player.initiate) 
			{
				goBackToMenu = true;
			}
			else if(seconds == 0 && minutes == 0)
			{
				goBackToMenu = true;
			}
			break;
	case 2: if(player.initiate == true && player.activateSolve == false) 
				player.activateRandom = true;
			else if(player.initiate == false && !checkSolve(player)) 
			{
				player.activateSolve = true;
				player.activateRandom = false; 
			}
			else if(player.initiate == false && checkSolve(player))
			{
				player.initiate = true;
				Sleep(1000);
			}
			player = graphicalSolve(player);
			player = graphicalRandomizer(player);
			player = freePlayStateMachine(player);
			break;
	case 3: if(player.initiate == true && player.activateSolve == false) 
			{
				player.activateRandom = true;
			}
			else if(player.initiate == false && !checkSolve(player)) 
			{
				player.activateSolve = true;
				player.activateRandom = false;
			}
			if(checkSolve(player) && !player.initiate) 
			{
				goBackToMenu = true;
			}
			glPushMatrix();
			glTranslatef(10, 0, 10);
			player = graphicalRandomizer(player);
			player = graphicalSolve(player);
			player = freePlayStateMachine(player);
			glPopMatrix();
			break;
	default: break;
	}
	return player;
}

/***************************

function checkSolve checks if a cube is solved

inputs: LargeCube cube

outputs: bool

if the cube is solved true is returned 
otherwise false is returned

***************************/
bool checkSolve(LargeCube cube)
{
	int temp;
	temp = cube.cube[0][0][0].side[0];
	int lPrevious = 0;
	for(int l = 0; l < 6; l++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				for(int i = 0; i < 3; i++)
				{
					if(l > lPrevious) lPrevious = 1;
					else if(cube.cube[i][j][k].side[l] == temp);
					else return false;
					temp = cube.cube[i][j][k].side[l];
				}
			}
		}
	}
	return true;
}


/************************

function countDownTimer

inputs: LargeCube cube

This function keeps track of the current clock
every 25 cycles it decrements the clock by 1 second

************************/
void countDownTimer(LargeCube cube)
{
	clockCycles++;
	if(clockCycles == 15)
	{
		clockCycles = 0;
		seconds = seconds - 1;
		if (seconds < 1) 
		{
			seconds = 59;
			minutes = minutes - 1;
			if(minutes < 0) 
			{
				minutes = 0;
				seconds = 0;
			}
		}
	}
	Sleep(1);
	if(checkSolve(cube)) clockCycles = 0;
}

/*************************

function initiateClock

initiateClock sets the global clock
time to 3:00 at the beginning of the
countdown phase

*************************/
void initiateClock(void)
{
	seconds = 0;
	minutes = 3;
}

/***********************

function executrPlayerMove

inputs: LargeCube cube
		int direction
		int section

outputs: LargeCube cube

this function takes a cube and sets the next move that the
cube will make and returns the cube with the information on
how the cube will function in the next stage of the state
machine.

***********************/
LargeCube executePlayerMove(LargeCube cube, int direction, int section)
{
	cube.step = 10;
	cube.NextMove.section = section;
	cube.NextMove.direction = direction;
	return cube;
}

/************************

function timeModeStateMachine

inputs: LargeCube cube

outputs: LargeCube cube

This function runs the countdown timer
and draws the timer while running the 
statemachine that increments the cube
rotation animations

************************/
LargeCube timeModeStateMachine(LargeCube cube)
{
	parseTime(seconds, minutes);
	countDownTimer(cube);
	return cube;
}

/************************************

function freePlayStateMachine

inputs: LargeCube cube

outputs: LargeCube cube

This function runs the animation statemachine
without any extra functions, therefore no timer
and no opponent

***********************************/
LargeCube freePlayStateMachine(LargeCube cube)
{
	return cube;
}

/*********************************

funciton rotationStateMAchine

inputs: LargeCube cube

outputs: LargeCube cube

Takes a cube and checks if it has been prepped to start rotating
if is ready for rotation the statemachine then sets up a stage for each
degree of rotation until a rotation of 90 degrees is obtained

*********************************/
LargeCube rotationStateMachine(LargeCube cube)
{
	Move moves;
	moves.direction = cube.NextMove.direction;
	moves.section = cube.NextMove.section;
	if(cube.mode == 1 && cube.activateRandom) Sleep(1);
	if(cube.step < 90 && cube.step > 0)
	{
		if(cube.mode != 3) voidKeys= true;
		animateSectionRotate(cube);
		cube.step = cube.step + 1;
	}
	else if(cube.step == 90)
	{
		cube.step = 0;
		cube = rotateSide(cube, cube.NextMove.direction, cube.NextMove.section);
		animateSectionRotate(cube);
		if(cube.activateSolve == false) cube.moves.push(moves);
		if(cube.mode != 3) voidKeys= false;
	}
	else draw3DCube(cube);
	return cube;
}