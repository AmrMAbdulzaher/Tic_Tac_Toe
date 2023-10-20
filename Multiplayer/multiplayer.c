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
void getNames(void)
{
	printTitle("            Players Names");
	printf("\t\t\t\t\t     Enter First Player Name: ");
	scanf("%20s",playerX);
	clearBuffer();
	printf("\t\t\t\t\t     Enter Second Player Name: ");
	scanf("%20s",playerO);
	clearBuffer();
	printLine();
	printf("\t\t\t\t\t     %s -> X\n\t\t\t\t\t     %s -> O\n",playerX,playerO);
	printLine();
	pressEnter();
}