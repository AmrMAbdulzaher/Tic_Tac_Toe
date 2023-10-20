/**
 * @file generalfunctions.c
 * @brief General utility functions for the Tic-Tac-Toe game.
 * 
 * This file contains functions that provide general utility and game logic for the
 * Tic-Tac-Toe game, including handling player input, game state, and checking for a winner.
 * 
 * @author Amr Mohamed Abdulzaher (amrnassareng@gmail.com)
 * @date 21-10-2023
 */

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

/**
 * @brief Display the welcome screen with a title and press Enter prompt.
 */
void welcomeScreen(void)
{
	system(CLEAR);
	drawFreePalestine();
	pressEnter();
	mainMenu();
}
/**
 * @brief Toggle the player's choice between 'X' and 'O'.
 */
void switchChoice(void)
{
	//switch turn character
	choice = (choice == 'X') ? 'O' : 'X';
	//swtich the turn name
	if(strcmp(playerX,turnName) == 0)
	{
		strcpy(turnName,playerO);
	}
	else
	{
		strcpy(turnName,playerX);
	}
}
/**
 * @brief Display the main menu and handle user input.
 */
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
/**
 * @brief Display the mode selection menu and handle user input.
 */
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
/**
 * @brief Display the about menu and handle user input.
 */
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
			case 2: printSPDescription(); break;
			case 3: printMPDescription(); break;
			case 4: printDeveloper(); break;
			case 5: return;
			case 6: exitGame();
		}
	}
}
/**
 * @brief Handle user input for the player's turn and update the game state.
 *
 * @return 1 if the user's input is valid, 0 otherwise.
 */
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
			resetGameStat();
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
/**
 * @brief Get the game state to check for a winner or a draw.
 *
 * @return 0 if the game is not over, 1 if there's a winner, 2 if it's a draw.
 */
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
				resetGameStat();
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
/**
 * @brief Reset the game field and play counter to start a new game.
 */
void resetField(void)
{
	//reset play counter
	playCounter=0;
	//reset the turn character
	choice='X';
	//reset the turn name
	strcpy(turnName,playerX);
	//reset the positions
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
/**
 * @brief Reset the game ,including the field, player names, and players counters.
 */
void resetGameStat(void)
{
	resetField();
	strcpy(playerX,"You");
	strcpy(playerO,"Computer");
	playerXCounter=0;
	playerOCounter=0;
}
/**
 * @brief Check if the game has ended due to a winner or a draw.
 *
 * @return 1 if the game has ended, 0 otherwise.
 */
unsigned char isEnd(void)
{
	char winner=winnerChar();
	unsigned char isEndState=1;
	if('X' == winner)
	{
		playerXCounter++;
		showField();
		textGreen_B();
		printf("\t\t\t\t\t\t     %s %s the winner.\n",playerX,strcmp(playerX,"You")==0?"are":"is");
		textReset();
		printLine();
		pressEnter();
	}
	else if('O' == winner)
	{
		playerOCounter++;
		showField();
		strcmp(playerX,"Computer")==0?textRed_B():textGreen_B();
		printf("\t\t\t\t\t\t     %s is the winner.\n",playerO);
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
/**
 * @brief Get the character of the winner ('X', 'O', or 'F' for no winner).
 *
 * @return The winning character ('X', 'O', or 'F').
 */
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
/**
 * @brief Check if there's a win in any of the rows.
 *
 * @return 1 if there's a win in the rows, 0 otherwise.
 */
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
/**
 * @brief Check if there's a win in any of the columns.
 *
 * @return 1 if there's a win in the columns, 0 otherwise.
 */
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
/**
 * @brief Check if there's a win in any of the diagonals.
 *
 * @return 1 if there's a win in the diagonals, 0 otherwise.
 */
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
/**
 * @brief Exit the game with a confirmation prompt.
 */
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
