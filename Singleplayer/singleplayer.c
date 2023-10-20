/**
 * @file singleplayer.c
 * @brief Functions related to the single-player game mode.
 *
 * This file contains functions for handling the single-player game mode,
 * including different difficulty levels (easy, normal, and hard), user input,
 * and computer move strategies.
 *
 * @author Amr Mohamed Abdulzaher (amrnassareng@gmail.com)
 * @date 21-10-2023
 */

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

/**
 * @brief Handle the single-player game mode selection and execute the chosen mode.
 */
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
/**
 * @brief Handle user input for the player's turn and update the game state.
 *
 * @return 1 if the user's input is valid, 0 otherwise.
 */
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

/**
 * @brief Execute the easy mode of the single-player game.
 */
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
			decisionState= getGameStat();
			if(2 == decisionState)
			{
				return;
			}
		}
    }
}
/**
 * @brief Let the computer make a random move in the easy mode.
 */
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
/**
 * @brief Execute the normal mode of the single-player game.
 */
void normalModeSP(void)
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
        	computerNormalMove();
    		showField();
			decisionState= getGameStat();
			if(2 == decisionState)
			{
				return;
			}
		}
    }
}
/**
 * @brief Let the computer make moves in the normal mode using strategy.
 */
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
/**
 * @brief Execute the hard mode of the single-player game.
 */
void hardModeSP(void)
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
        	computerHardMove();
    		showField();
			decisionState= getGameStat();
			if(2 == decisionState)
			{
				return;
			}
		}
    }
}
/**
 * @brief Let the computer make moves in the hard mode using advanced strategies.
 */
void computerHardMove(void)
{
    // Check if it's the first move and the center position is not occupied by the player
    if (1 == playCounter && field[1][1] != 'X')
    {
        field[1][1] = 'O';  // Place 'O' in the center
        playCounter++;
    }
    // Check if a winning move is possible
    else if (winMove())
    {
    }
    // Check if a blocking move is possible
    else if (blockMove())
    {
    }
    // Check for a specific situation at the third move
    else if (3 == playCounter && 'O' == field[1][1])
    {
        if ('X' == field[1][2])
        {
            field[0][2] = 'O';  // Block a potential win by the player
        }
        else if ('X' == field[1][0])
        {
            field[1][2] = 'O';  // Block a potential win by the player
        }
        else
        {
            field[1][1] = 'X';  // Temporarily place 'X' for strategy evaluation
            if (isWinDiags())
            {
                field[1][2] = 'O';  // Block a diagonal win by the player
            }
            else if (isWinRows() || isWinCols())
            {
                field[0][1] = 'O';  // Block a row or column win by the player
            }
            field[1][1] = 'O';  // Restore 'O' for this position
        }
        playCounter++;
    }
    // Check for a specific situation at the first move when the center position is occupied by the player
    else if (1 == playCounter && 'X' == field[1][1])
    {
        field[0][2] = 'O';  // Make a strategic move to take control of the board
        playCounter++;
    }
    else
    {
        computerEasyMove();  // If no specific situation, make a random move
    }
}

/**
 * @brief Check if the computer can make a winning move and execute it.
 *
 * @return 1 if a winning move is made, 0 otherwise.
 */
unsigned char winMove(void)
{
    char temp;
    // Check if the computer can make a winning move
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] != 'X' && field[i][j] != 'O')
            {
                temp = field[i][j];
                field[i][j] = 'O';  // Temporarily place 'O' in an empty slot to check for a winning move
                if ('O' == winnerChar())  // Check if 'O' wins after this move
                {
                    playCounter++;
                    return 1;  // A winning move is made
                }
                field[i][j] = temp;  // Restore the original state of the slot
            }
        }
    }

    return 0;  // No winning move is possible
}
/**
 * @brief Check if the computer can block the player from winning and execute it.
 *
 * @return 1 if a blocking move is made, 0 otherwise.
 */
unsigned char blockMove(void)
{
    char temp;
    // Check if the computer can make a blocking move to prevent the player from winning
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] != 'X' && field[i][j] != 'O')
            {
                temp = field[i][j];
                field[i][j] = 'X';  // Temporarily place 'X' in an empty slot to check for a blocking move
                if ('X' == winnerChar())  // Check if 'X' wins after this move (player's potential winning move)
                {
                    field[i][j] = 'O';  // Block the player by placing 'O' in the slot
                    playCounter++;
                    return 1;  // A blocking move is made
                }
                field[i][j] = temp;  // Restore the original state of the slot
            }
        }
    }
    return 0;  // No blocking move is possible
}
