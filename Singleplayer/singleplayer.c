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
		showSPMenu();
		shiftTextLeft();
		scanf("%hhd",&input);
		clearBuffer();
		if(1 == input)
		{
			strcpy(titleText,"            Easy Mode - SP");
			easyModeSP();
			break;
		}
		else if(2 == input)
		{
			strcpy(titleText,"           Normal Mode - SP");
			normalModeSP();
			break;
		}
		else if(3 == input)
		{
			strcpy(titleText,"            Hard Mode - SP");
			hardModeSP();
			break;
		}
		else if(4 == input)
		{
			return;
		}
		else if(5 == input)
		{
			exitGame();
		}
	}
}
unsigned char inputSinglePlayer(void)
{
	unsigned char state=0;
	playCounter++;
	printf("\t\t\t\t\t     Choose your position [X]: ");
	if(!userTurnInput())
	{
		state=1;
	}
	return state;
}

void easyModeSP(void)
{
	char decisionState=0;
    while (1)
	{
    	showField();
		if(inputSinglePlayer())
		{
			return;
		}
    	showField();
		decisionState= getGameStat();
		if(2 == decisionState)
		{
			return;
		}
		else if(0 == decisionState)
		{
			printf("\t\t\t\t\t     Computer's turn...\n");
        	computerEasyMove();
    		showField();
			getGameStat();
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
	char decisionState=0;
    while (1)
	{
    	showField();
        inputSinglePlayer();
    	showField();
		decisionState= getGameStat();
		if(2 == decisionState)
		{
			return;
		}
		else if(0 == decisionState)
		{
			printf("\t\t\t\t\t     Computer's turn...\n");
        	computerNormalMove();
    		showField();
			getGameStat();
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
	char decisionState=0;
    while (1)
	{
    	showField();
        inputSinglePlayer();
    	showField();
		decisionState= getGameStat();
		if(2 == decisionState)
		{
			return;
		}
		else if(0 == decisionState)
		{
			printf("\t\t\t\t\t     Computer's turn...\n");
        	computerHardMove();
    		showField();
			getGameStat();
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
unsigned char winMove(void)
{
	char temp;
	//win if possible
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] != 'X' && field[i][j] != 'O')
            {
                temp = field[i][j];
                field[i][j] = 'O';
                if ('O' == winnerChar())
                {
                    return 1;
                }
                field[i][j] = temp;
            }
        }
    }
	
	return 0;
}
unsigned char blockMove(void)
{
	char temp;
	//block if possible
	for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] != 'X' && field[i][j] != 'O')
            {
                temp = field[i][j];
                field[i][j] = 'X';
                if ('X' == winnerChar())
                {
                    field[i][j] = 'O';
                    return 1;
                }
                field[i][j] = temp;
            }
        }
    }
	return 0;
}