#include <time.h>
#include <iostream>

/*****************************

function randomNumberGenerator

inputs: void

outputs: Move

This function generates a random move value
for the graphicalRandomizer as to all for 
a player to have a scrambled cube to play with

*****************************/
Move randomNumberGenerator(void)
{
	srand(time(NULL));
	Move moves;
	int random1 = rand()%100;
	int random2 = rand()%100;
	int temp = random1;
	srand(random1*34 - 100);
	while (random1%7==3)
{
		for (int i = 0; i < 40; i++)
		{
			srand(time(NULL));
			random1 = rand()%100;
			if(random1 % 6 == 0) srand((random1*34 - 100)%10000);
			else if(random1 % 8 == 0) srand((random1*23/27 + 70)%100000);
			else if(random1 % 4 == 0) srand((random1*50 + 90)%100000); 
			else if(random1 % 2 == 0) srand((random1*23/87 + 43)%100000);
			else if(random1 % 3 == 0) srand((random1*100/33 + 7)%100000);
			else if(random1 % 7 == 0) srand((random1 + 9 * 6)%100000);
			else srand(random1*5/6 + 77);

		}
	}
	
	moves.direction = random1%7-3;

	for (int i = 0; i < 40; i++)
	{
		srand(time(NULL));
		random2 = rand()%100;
		if(random2 % 6 == 0) srand((random2*34 - 100)%10000);
		else if(random2 % 8 == 0) srand((random2*23/27 + 70)%100000);
		else if(random2 % 4 == 0) srand((random2*50 + 90)%100000); 
		else if(random2 % 2 == 0) srand((random2*23/87 + 43)%100000);
		else if(random2 % 3 == 0) srand((random2*100/33 + 7)%100000);
		else if(random2 % 7 == 0) srand((random2 + 9 * 6)%100000);
		else srand(random2*5/6 + 77);

	}
	moves.section = random2%3;

	return moves;
}
