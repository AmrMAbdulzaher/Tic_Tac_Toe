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

void drawFreePalestine(void)
{
	textNormal_B();
	printf("\n\n");
	printf("\t\t\t\t\t######   ######    ######   ######\n");
    printf("\t\t\t\t\t#        #    ##   #        #     \n");
    printf("\t\t\t\t\t######   ######    ######   ######\n");
    printf("\t\t\t\t\t#        #     #   #        #     \n");
    printf("\t\t\t\t\t#        #     #   ######   ######\n\n");	
	textRed_B();
	printf("\t\t#####     #      ");
	textBlack_B();
	printf("#       ######   ######   #######   #####   #    #   ######\n");
	textRed_B();
	printf("\t\t#   ##   # #     ");
	textBlack_B();
    printf("#       #        #           #        #     ##   #   #     \n");
	textRed_B();
	printf("\t\t#####   #####    #       ");
	textWhite_B();
    printf("######   ######      #        #     # #  #   ######\n");
	textRed_B();
	printf("\t\t#      #     #   ");
	textGreen_B();
    printf("#       #             #      #        #     #  # #   #     \n");
	textRed_B();
	printf("\t\t#     #       #  ");
	textGreen_B();
    printf("######  ######   ######      #      #####   #    #   ######\n\n");
	textWhite_B();
	printf("\t\t\t\t\t    From The River to The Sea\n\n\t\t\t\t\t     ");
	textReset();
}
void printMainMenu(void)
{
	system(CLEAR);
	printTitle("            Main Menu");
	printf("[1] Start\n");
	printf("[2] About\n");
	printf("[3] Exit\n");
	printLine();
}
void printModeMenu(void)
{
	system(CLEAR);
	printTitle("           Choose Mode");
	printf("[1] Single-Player Mode\n");
	printf("[2] MultiPlayer Mode\n");
	printLine();
	printf("[3] Back\n");
	printf("[4] Exit\n");
	printLine();
}
void printAboutMenu(void)
{
	system(CLEAR);
	printTitle("              About");
	printf("[1] Program Description\n");
	printf("[2] Program Developer\n");
	printLine();
	printf("[3] Back\n");
	printf("[4] Exit\n");
	printLine();
}
void printDeveloper(void)
{
	printTitle("        Program Developer");
	printf("Name: ");
	printAnimatedText(devName,devTextTime);
	printf("Email: ");
	printAnimatedText(devEmail,devTextTime);
	printf("Linkedin: ");
	printAnimatedText(devLinkedin,devTextTime);
	printf("GitHub: ");
	printAnimatedText(devGitHub,devTextTime);
	printLine();
	pressEnter();

}
void printDescription(void)
{
	printTitle("       Program Description");
	printAnimatedText(programDscrp,dscrpTextTime);
	printLine();
	pressEnter();
}
void pressEnter(void)
{
	printf("Press ENTER to continue.");
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
	printf("%s\n",text);
	textReset();
	printLine();
}
void printSPMenu(void)
{
	printTitle("       Single-Player Mode");
	printf("        Choose Difficulty\n");
	printLine();
	printf("[1] Easy\n");
	printf("[2] Normal\n");
	printf("[3] Hard\n");
	printLine();
	printf("[4] Back\n");
	printf("[5] Exit\n");
	printLine();
}
void showField(void)
{
	printTitle(titleText);
	printf("           ScoreBoard\n           ==========\n");
	printf("           %s: %hhu\n           %s: %hhu\n",playerX,playerXCounter,playerO,playerOCounter);
	printLine();
	printf("\n");
	printf("            %c | %c | %c ", field[0][0], field[0][1], field[0][2]);
	printf("\n           ---|---|---\n");
	printf("            %c | %c | %c ", field[1][0], field[1][1], field[1][2]);
	printf("\n           ---|---|---\n");
	printf("            %c | %c | %c ", field[2][0], field[2][1], field[2][2]);
	printf("\n\n");
	printLine();
}