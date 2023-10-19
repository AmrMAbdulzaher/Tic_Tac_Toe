#include "singleplayer.h"
#include "../General_Functions/generalfunctions.h"
#include "../Appearance_Functions/appearance.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

extern unsigned char playCounter;
extern char titleText[33];
extern char field[3][3];

void singlePlayerMode(void)
{
	char input;
	while(1)
	{
		printSPMenu();
		scanf("%hhd",&input);
		clearBuffer();
		switch(input)
		{
			case 1:
			{
				strcpy(titleText,"         Easy Mode - SP");
				easyModeSP();
				break;
			}
			case 2:
			{
				strcpy(titleText,"         Normal Mode - SP");
				normalModeSP();
				break;
			}
			case 3:
			{
				strcpy(titleText,"           Hard Mode - SP");
				hardModeSP();
				break;
			}
			case 4: return; break;
			case 5: exit(0);
		}
	}
}
void inputSinglePlayer(void)
{
	playCounter++;
	printf("Choose your position [X]: ");
	userTurnInput();
}

void easyModeSP(void)
{
    showField();
    while (1)
	{
		showField();
		//player move
        inputSinglePlayer();
		showField();
		if(!isDone())
		{
			//computer random move
			printf("Computer's turn...\n");
        	computerEasyMove();
			showField();
			isDone();
		}
    }
}

void computerEasyMove(void)
{
    int avaiablePositions[9];
    int numAvaiablePositions = 0;

    //Find available cells
    for (int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
		{
            if (field[i][j] != 'X' && field[i][j] != 'O')
			{
                avaiablePositions[numAvaiablePositions++] = i * 3 + j;
            }
        }
    }

    //If there are available cells, choose a random one
    if (numAvaiablePositions > 0)
	{
        srand(time(NULL));
        int randomIndex = rand() % numAvaiablePositions;
        int chosenPosition = avaiablePositions[randomIndex];
        int row = chosenPosition / 3;
        int col = chosenPosition % 3;

        field[row][col] = 'O';
        playCounter++;
    }
}

void normalModeSP(void)
{
    showField();
    while (1)
	{
    	showField();
        inputSinglePlayer();
    	showField();
		if(!isDone())
		{
			printf("Computer's turn...\n");
        	computerNormalMove();
    		showField();
			isDone();
		}
    }
}
void computerNormalMove(void)
{
	if(!winMove())
	{
		if(!blockMove())
		{
			computerEasyMove();
		}
	}
}
void hardModeSP(void)
{
    showField();
    while (1)
	{
    	showField();
        inputSinglePlayer();
    	showField();
		if(!isDone())
		{
			printf("Computer's turn...\n");
        	computerHardMove();
    		showField();
			isDone();
		}
    }
}
void computerHardMove(void)
{
    if (1 == playCounter && field[1][1] != 'X')
	{
        field[1][1] = 'O';
        playCounter++;
    }
    else if (winMove())
	{
		playCounter++;
	}
    else if (blockMove())
	{
		playCounter++;
    }
    else if (3 == playCounter && 'O' == field[1][1])
	{
		if('X' == field[1][2])
		{
			field[0][2] = 'O';
		}
		else if('X' == field[1][0])
		{
			field[1][2] = 'O';
		}
		else
		{
        	field[1][1] = 'X';
        	if (isWinDiags())
			{
        	    field[1][2] = 'O';
        	}
        	else if (isWinRows() || isWinCols())
			{
        	    field[0][1] = 'O';
        	}
        	field[1][1] = 'O';
		}
        playCounter++;
    }
    else if (1 == playCounter && 'X' == field[1][1])
	{
        field[0][2] = 'O';
        playCounter++;
    }
    else
	{
        computerEasyMove();
    }
}