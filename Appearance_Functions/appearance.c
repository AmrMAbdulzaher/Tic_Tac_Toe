#include "appearance.h"
#include "../General_Functions/generalfunctions.h"
#include <stdio.h>
#include <stdlib.h>

extern char field[3][3];
extern unsigned char playerXCounter;
extern unsigned char playerOCounter;
extern char titleText[33];
extern char playerX[21];
extern char playerO[21];
extern unsigned char playCounter;

void drawFreePalestine(void)
{
	textNormal_B();
	printf("\n\n");
	
	printf("\t\t\t\t\t\t######   ######    ######   ######\n");
    printf("\t\t\t\t\t\t#        #    ##   #        #     \n");
    printf("\t\t\t\t\t\t######   ######    ######   ######\n");
    printf("\t\t\t\t\t\t#        #     #   #        #     \n");
    printf("\t\t\t\t\t\t#        #     #   ######   ######\n\n");	
	textRed_B();
	printf("\t\t\t#####     #      ");
	textBlack_B();
	printf("#       ######   ######   #######   #####   #    #   ######\n");
	textRed_B();
	printf("\t\t\t#   ##   # #     ");
	textBlack_B();
    printf("#       #        #           #        #     ##   #   #     \n");
	textRed_B();
	printf("\t\t\t#####   #####    #       ");
	textWhite_B();
    printf("######   ######      #        #     # #  #   ######\n");
	textRed_B();
	printf("\t\t\t#      #     #   ");
	textGreen_B();
    printf("#       #             #      #        #     #  # #   #     \n");
	textRed_B();
	printf("\t\t\t#     #       #  ");
	textGreen_B();
    printf("######  ######   ######      #      #####   #    #   ######\n\n");
	textWhite_B();
	printf("\t\t\t\t\t\t   From The River to The Sea\n\n");
	textReset();
}
void showMainMenu(void)
{
	system(CLEAR);
	printTitle("              Main Menu");
	printf("\t\t\t\t\t     [1] Start\n");
	printf("\t\t\t\t\t     [2] About\n");
	printf("\t\t\t\t\t     [3] Exit\n");
	printLine();
}
void showModeMenu(void)
{
	system(CLEAR);
	printTitle("             Choose Mode");
	printf("\t\t\t\t\t     [1] Single-Player Mode\n");
	printf("\t\t\t\t\t     [2] MultiPlayer Mode\n");
	printLine();
	printf("\t\t\t\t\t     [3] Back\n");
	printf("\t\t\t\t\t     [4] Exit\n");
	printLine();
}
void showAboutMenu(void)
{
	system(CLEAR);
	printTitle("                About");
	printf("\t\t\t\t\t     [1] Program Description\n");
	printf("\t\t\t\t\t     [2] Program Developer\n");
	printLine();
	printf("\t\t\t\t\t     [3] Back\n");
	printf("\t\t\t\t\t     [4] Exit\n");
	printLine();
}
void printDeveloper(void)
{
	printTitle("          Program Developer");
	printf("\t\t\t\t\t     Name: ");
	printAnimatedText(devName,devTextTime);
	printf("\t\t\t\t\t     Email: ");
	printAnimatedText(devEmail,devTextTime);
	printf("\t\t\t\t\t     Linkedin: ");
	printAnimatedText(devLinkedin,devTextTime);
	printf("\t\t\t\t\t     GitHub: ");
	printAnimatedText(devGitHub,devTextTime);
	printLine();
	pressEnter();

}
void printDescription(void)
{
	printTitle("         Program Description");
	shiftTextLeft();
	printAnimatedText("Console based Tic-Tac-Toe  Game  that",dscrpTextTime);
	shiftTextLeft();
	printAnimatedText("offers both singleplayer & multiplayer",dscrpTextTime);
	shiftTextLeft();
	printAnimatedText("modes.It has multiple dificulty levels",dscrpTextTime);
	shiftTextLeft();
	printAnimatedText("for singleplayer mode,allowing players",dscrpTextTime);
	shiftTextLeft();
	printAnimatedText("to challenge against computer opponent",dscrpTextTime);
	shiftTextLeft();
	printAnimatedText("In multiplayer mode,  two players can",dscrpTextTime);
	shiftTextLeft();
	printAnimatedText("take turns playing against each other.",dscrpTextTime);
	printLine();
	pressEnter();
}
void pressEnter(void)
{
	printf("\t\t\t\t\t            Press ENTER to continue.");
	getchar();
}
void printAnimatedText(const char* text,const unsigned int time_ms)
{
	for (int i = 0; text[i] != '\0'; i++)
    {
        putchar(text[i]);
        fflush(stdout);
        sleep(time_ms);
    }
	printf("\n");
}
void printTitle(const char* text)
{
	system(CLEAR);
	printLine();
	textNormal_B();
	printf("\t\t\t\t\t                Tic-Tac-Toe Game\n");
	textReset();
	printLine();
	textNormal_B();
	printf("\t\t\t\t\t     %s\n",text);
	textReset();
	printLine();
}
void showSPMenu(void)
{
	printTitle("          Single-Player Mode");
	printf("\t\t\t\t\t               Choose Difficulty\n");
	printLine();
	printf("\t\t\t\t\t     [1] Easy\n");
	printf("\t\t\t\t\t     [2] Normal\n");
	printf("\t\t\t\t\t     [3] Hard\n");
	printLine();
	printf("\t\t\t\t\t     [4] Back\n");
	printf("\t\t\t\t\t     [5] Exit\n");
	printLine();
}
void showField(void)
{
	printTitle(titleText);
	printf("\t\t\t\t\t                   ScoreBoard\n\t\t\t\t\t                   ==========\n");
	printf("\t\t\t\t\t                   %s: %hhu\n\t\t\t\t\t                   %s: %hhu\n",playerX,playerXCounter,playerO,playerOCounter);
	printLine();
	printf("\n");
	textNormal_B();
	printf("\t\t\t\t\t                   %c | %c | %c ", field[0][0], field[0][1], field[0][2]);
	printf("\n\t\t\t\t\t                  ---|---|---\n");
	printf("\t\t\t\t\t                   %c | %c | %c ", field[1][0], field[1][1], field[1][2]);
	printf("\n\t\t\t\t\t                  ---|---|---\n");
	printf("\t\t\t\t\t                   %c | %c | %c ", field[2][0], field[2][1], field[2][2]);
	textReset();
	printf("\n\n");
	printLine();
	printf("\t\t\t\t\t     [0] Back to Main Menu\n");
	printf("\t\t\t\t\t     [-1] Exit Game\n");
	printLine();
}
void showWhatNext(void)
{
	printTitle(titleText);
	printTitle("              What Next?");
	printf("\t\t\t\t\t     [1] Play Again\n");
	printf("\t\t\t\t\t     [2] Back to Main Menu\n");
	printf("\t\t\t\t\t     [3] Exit Game\n");
	printLine();
}
void showExitMenu(void)
{
	system(CLEAR);
	printTitle("    Are you sure you want to Exit?");
	printf("\t\t\t\t\t     [1] Yes\n");
	printf("\t\t\t\t\t     [2] No\n");
	printLine();
}