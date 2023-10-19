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
	showField();
	strcpy(turnName,playerX);
	while(1)
	{
		showField();
		inputMultiPlayer();
		showField();
		isDone();
	}
}
void getNames(void)
{
	printTitle("          Players Names");
	printf("Enter First Player Name: ");
	scanf("%20s",playerX);
	clearBuffer();
	printf("Enter Second Player Name: ");
	scanf("%20s",playerO);
	clearBuffer();
	printLine();
	printf("%s -> X\n%s -> O\n",playerX,playerO);
	printLine();
	pressEnter();
}
void inputMultiPlayer(void)
{
	printf("Choose your position, %s[%c]: ",turnName,choice);
	userTurnInput();
	switchChoice();
	playCounter++;
}