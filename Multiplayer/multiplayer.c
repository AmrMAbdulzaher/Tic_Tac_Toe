#include "multiplayer.h"
#include "../General_Functions/generalfunctions.h"
#include "../Appearance_Functions/appearance.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

extern char choice;
extern unsigned char playCounter;

void multiPlayerMode(void)
{
	showField("   MultiPlayer Mode");
	while(1)
	{
		showField("   MultiPlayer Mode");
		inputMultiPlayer();
		showField("   MultiPlayer Mode");
		isDone();
	}
}
void inputMultiPlayer(void)
{
	printf("Choose your position, Player %c: ",choice);
	userTurnInput();
	switchChoice();
	playCounter++;
}