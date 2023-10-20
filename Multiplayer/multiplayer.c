/**
 * @file multiplayer.c
 * @brief Functions for handling the multiplayer game mode.
 *
 * This file contains functions for managing the multiplayer game mode, including
 * handling player names, user input, and game state updates for two players taking turns.
 *
 * @author Amr Mohamed Abdulzaher (amrnassareng@gmail.com)
 * @date 21-10-2023
 */

#include "multiplayer.h"
#include "../General_Functions/generalfunctions.h"
#include "../Appearance_Functions/appearance.h"
#include <stdio.h>
#include <string.h>

extern char choice;
extern unsigned char playCounter;
extern char playerX[21];
extern char playerO[21];
extern char turnName[21];

/**
 * @brief Handle the multiplayer game mode, allowing two players to take turns playing the game.
 */
void multiPlayerMode(void)
{
	getNames();
	strcpy(turnName,playerX);
	while(1)
	{
		showField();
		if(!inputMultiPlayer())
		{
			break;
		}
		showField();
		if(2 == getGameStat())
		{
			return;
		}
	}
}
/**
 * @brief Handle user input and update the game state for multiplayer mode.
 *
 * @return 1 if the user's input is valid, 0 otherwise.
 */
unsigned char inputMultiPlayer(void)
{
	unsigned char state=0;
	printf("\t\t\t\t\t     Choose your position, %s[%c]: ",turnName,choice);
	if(userTurnInput())
	{
		state=1;
		switchChoice();
		playCounter++;
	}
	return state;
}
/**
 * @brief Get player names from the users and ensure they are not the same.
 */
void getNames(void)
{
	printTitle("            Players Names");
	printf("\t\t\t\t\t     Enter Name of Player 1: ");
	scanf("%20s",playerX);
	clearBuffer();
	printf("\t\t\t\t\t     Enter Name of Player 2: ");
	scanf("%20s",playerO);
	clearBuffer();
	while(1)
	{
		if(strcmp(playerX,playerO)==0)
		{
			printf("\t\t\t\t\t     Identical Names! Enter Player 2 Name: ");
			scanf("%20s",playerO);
			clearBuffer();
		}
		else
		{
			break;
		}
	}
	printLine();
	printf("\t\t\t\t\t     %s -> X\n\t\t\t\t\t     %s -> O\n",playerX,playerO);
	printLine();
	pressEnter();
}