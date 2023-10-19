#include "generalfunctions.h"
#include "../Appearance_Functions/appearance.h"
#include "../Singleplayer/singleplayer.h"
#include "../Multiplayer/multiplayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

char field[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
char choice= 'X';
unsigned char playCounter=0;
static char winnerCharacter;

void chooseMode(void)
{
	char input;
	while(1)
	{
		printModeMenu();
		scanf("%hhd",&input);
		clearBuffer();
		switch(input)
		{
			case 1: singlePlayerMode(); break;
			case 2: multiPlayerMode(); break;
			case 3: return;
			case 4: exit(0);
		}
	}
}
void aboutMenu(void)
{
	char input;
	while(1)
	{
		printAboutMenu();
		scanf("%hhd",&input);
		clearBuffer();
		switch(input)
		{
			case 1: printDescription(); break;
			case 2: printDeveloper(); break;
			case 3: return;
			case 4: exit(0);
		}
	}
}
unsigned char isEnd(void)
{
	char winner=winnerChar();
	unsigned char isEndState=1;
	if('X' == winner)
	{
		printf("Player X is the winner.\n");
	}
	else if('O' == winner)
	{
		printf("Player O is the winner.\n");
	}
	else if(POSTIONS_NUM == playCounter)
	{
		printf("Draw!\n");
	}
	else
	{
		isEndState=0;
	}
	return isEndState;
}
char winnerChar(void)
{	
	if(!isWinRows())
	{
		if(!isWinCols())
		{
			if(!isWinDiags())
			{
				winnerCharacter='F';
			}
		}
	}
	return winnerCharacter;
}
unsigned char isWinRows(void)
{
	unsigned char isWinState=0;
	for (int i = 0; i < 3; i++)
	{
		if ((field[i][0] == field[i][1]) && (field[i][1] == field[i][2])) 
		{
			isWinState=1;
			winnerCharacter= field[i][0];
		}
	}
	return isWinState;
}
unsigned char isWinCols(void)
{
	unsigned char isWinState=0;
	if ((field[0][0] == field[1][1] && field[1][1] == field[2][2]) || (field[0][2] == field[1][1] && field[1][1] == field[2][0]))
	{
		isWinState=1;
        winnerCharacter= field[1][1];
    }
	return isWinState;
}
unsigned char isWinDiags(void)
{
	unsigned char isWinState=0;
	for (int i = 0; i < 3; i++)
	{
	  if ((field[0][i] == field[1][i]) && (field[1][i] == field[2][i]))
	  {
		  isWinState=1;
		  winnerCharacter= field[0][i];
	  }
	}
	return isWinState;
}
void userTurnInput(void)
{
	char position;
	unsigned char scanReturn;
	unsigned char row;
	unsigned char col;
	scanReturn= scanf("%hhd",&position);
	clearBuffer();
	if (position >= 1 && position <= POSTIONS_NUM && scanReturn == 1)
	{
		row = (position - 1) / 3;
		col = (position - 1) % 3;
		while(1)
		{
			if (field[row][col] == 'X' || field[row][col] == 'O')
			{
				printf("Used Position! Choose another position: ");
				scanf("%hhd",&position);
				clearBuffer();
				row = (position - 1) / 3;
				col = (position - 1) % 3;
			}
			else
			{
				break;
			}
		}
		field[row][col] = choice;
	}
	else
	{
		while(1)
		{
			printf("Invalid Position! Choose another position: ");
			scanReturn= scanf("%hhd",&position);
			clearBuffer();
			if(position >= 1 && position <= POSTIONS_NUM && scanReturn == 1)
			{
				row = (position - 1) / 3;
				col = (position - 1) % 3;
				field[row][col] = choice;
				break;
			}
		}
	}
}


unsigned char isDone(void)
{
	unsigned char state=0;
	if(isEnd())
	{
		char inputChar;
		printf("Enter [y] to Play Again: ");
		inputChar= getchar();
		clearBuffer();
		inputChar=tolower(inputChar);
		switch(inputChar)
		{
			case 'y': resetField(); state=1; break;
			default: exit(0);
		}
	}
	return state;
}
void resetField(void)
{
	playCounter=0;
	choice='X';
	char num='1';
	int i, j;
	for (i = 0; i < 3; i++)
	{
    	for (j = 0; j < 3; j++)
		{
      		field[i][j]=num;;
			num++;
		}
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