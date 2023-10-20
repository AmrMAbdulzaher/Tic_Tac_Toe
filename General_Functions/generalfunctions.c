#include "generalfunctions.h"
#include "../Appearance_Functions/appearance.h"
#include "../Singleplayer/singleplayer.h"
#include "../Multiplayer/multiplayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char field[3][3] = {{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};
char choice= 'X';
unsigned char playCounter=0;
static char winnerCharacter;
unsigned char playerXCounter=0;
unsigned char playerOCounter=0;
char playerX[21]="You";
char playerO[21]="Computer";
char turnName[21];
char titleText[33];

void welcomeScreen(void)
{
	system(CLEAR);
	drawFreePalestine();
	pressEnter();
	mainMenu();
}
void switchChoice(void)
{
	choice = (choice == 'X') ? 'O' : 'X';
	if(strcmp(playerX,turnName) == 0)
	{
		strcpy(turnName,playerO);
	}
	else
	{
		strcpy(turnName,playerX);
	}
}
void mainMenu(void)
{
	char input;
	while(1)
	{
		showMainMenu();
		shiftTextLeft();
		scanf("%hhd",&input);
		clearBuffer();
		switch(input)
		{
			case 1: chooseMode(); break;
			case 2: aboutMenu(); break;
			case 3: exitGame();
		}
	}
}
void chooseMode(void)
{
	char input;
	while(1)
	{
		showModeMenu();
		shiftTextLeft();
		scanf("%hhd",&input);
		clearBuffer();
		if(1 == input)
		{
			singlePlayerMode();
			break;
		}
		else if(2== input)
		{
			strcpy(titleText,"           MultiPlayer Mode");
			multiPlayerMode();
			break;
		}
		else if(3==input)
		{
			return;
		}
		else if(4==input)
		{
			exitGame();
		}
	}
}
void aboutMenu(void)
{
	char input;
	while(1)
	{
		showAboutMenu();
		shiftTextLeft();
		scanf("%hhd",&input);
		clearBuffer();
		switch(input)
		{
			case 1: printDescription(); break;
			case 2: printDeveloper(); break;
			case 3: return;
			case 4: exitGame();
		}
	}
}
unsigned char userTurnInput(void)
{
	char position;
	unsigned char state=1;
	unsigned char scanReturn;
	unsigned char row;
	unsigned char col;
	
	while(1)
	{
		scanReturn= scanf("%hhd",&position);
		clearBuffer();
		row = (position - 1) / 3;
		col = (position - 1) % 3;
		if (isAvailablePosition)
		{
			field[row][col] = choice;
			break;
		}
		else if(isUsedPosition)
		{
			printf("\t\t\t\t\t     Used Position! Choose another position: ");
		}
		else if(1 == scanReturn && 0 == position)
		{
			resetField();
			strcpy(playerX,"You");
			strcpy(playerO,"Computer");
			state=0;
			break;
		}
		else if(1 == scanReturn && -1 == position)
		{
			exit(0);
		}
		else
		{
			printf("\t\t\t\t\t     Invalid Position! Choose another position: ");
		}
	}
	return state;
}

unsigned char getGameStat(void)
{
	unsigned char state=0;
	if(isEnd())
	{
		char input;
		while(1)
		{
			showWhatNext();
			shiftTextLeft();
			scanf("%hhd",&input);
			clearBuffer();
			if(1==input)
			{
				state=1;
				resetField();
				break;
			}
			else if(2==input)
			{
				state=2;
				playerXCounter=0;
				playerOCounter=0;
				resetField();
				break;
			}
			else if(3==input)
			{
				exitGame();
			}
		}
	}
	return state;
}
void resetField(void)
{
	playCounter=0;
	choice='X';
	strcpy(turnName,playerX);
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
unsigned char isEnd(void)
{
	char winner=winnerChar();
	unsigned char isEndState=1;
	if('X' == winner)
	{
		playerXCounter++;
		showField();
		textGreen_B();
		printf("\t\t\t\t\t\t           %s %s the winner.\n",playerX,strcmp(playerX,"You")==0?"are":"is");
		textReset();
		printLine();
		pressEnter();
	}
	else if('O' == winner)
	{
		playerOCounter++;
		showField();
		strcmp(playerX,"Computer")==0?textRed_B():textGreen_B();
		printf("\t\t\t\t\t\t           %s is the winner.\n",playerO);
		textReset();
		printLine();
		pressEnter();
	}
	else if(POSTIONS_NUM == playCounter)
	{
		showField();
		textNormal_B();
		printf("\t\t\t\t\t\t             Draw!\n");
		textReset();
		printLine();
		pressEnter();
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
void exitGame(void)
{
	char input=0;
	while(1)
	{
		showExitMenu();
		shiftTextLeft();
		scanf("%hhd",&input);
		if(1==input)
		{
			textReset();
			exit(0);
		}
		else if(2==input)
		{
			return;
		}
	}
}
