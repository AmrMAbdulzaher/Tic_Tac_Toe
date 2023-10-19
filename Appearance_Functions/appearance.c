#include "appearance.h"
#include "../General_Functions/generalfunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

extern char field[3][3];
void printMainMenu(void)
{
	system(CLEAR);
	printTitle("       Main Menu");
	printf("[1] Start\n");
	printf("[2] About\n");
	printf("[3] Exit\n");
	printLine();
}
void printModeMenu(void)
{
	system(CLEAR);
	printTitle("      Choose Mode");
	printf("[1] Single-Player Mode\n");
	printf("[2] MultiPlayer Mode\n");
	printf("[3] Back\n");
	printf("[4] Exit\n");
	printLine();
}
void printAboutMenu(void)
{
	system(CLEAR);
	printTitle("         About");
	printf("[1] Program Description\n");
	printf("[2] Program Developer\n");
	printf("[3] Back\n");
	printf("[4] Exit\n");
	printLine();
}
void printDeveloper(void)
{
	printTitle("   Program Developer");
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
	printTitle("  Program Description");
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
	printf("%s\n",text);
	printLine();
}
void printSPMenu(void)
{
	printTitle("  Single-Player Mode");
	printf("   Choose Difficulty\n");
	printLine();
	printf("[1] Easy\n");
	printf("[2] Normal\n");
	printf("[3] Hard\n");
	printf("[3] Back\n");
	printf("[5] Exit\n");
	printLine();
}
void showField(const char* text)
{
	printTitle(text);
	printf("\n");
	printf("        %c | %c | %c ", field[0][0], field[0][1], field[0][2]);
	printf("\n       ---|---|---\n");
	printf("        %c | %c | %c ", field[1][0], field[1][1], field[1][2]);
	printf("\n       ---|---|---\n");
	printf("        %c | %c | %c ", field[2][0], field[2][1], field[2][2]);
	printf("\n\n");
}