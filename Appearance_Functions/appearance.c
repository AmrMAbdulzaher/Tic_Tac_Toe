/**
 * @file appearance.c
 * @brief Functions for managing the visual appearance of the Tic-Tac-Toe game.
 *
 * This file contains functions for displaying the game's title, menus, the game board, and various
 * visual elements to enhance the user experience. It also includes functions to print descriptions
 * of the game, single-player modes, multiplayer mode, and information about the developer.
 *
 * @author Amr Mohamed Abdulzaher (amrnassareng@gmail.com)
 * @date 21-10-2023
 */

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

/**
 * @brief Draw the title and the message "Free Palestine."
 */
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
/**
 * @brief Display the main menu options.
 */
void showMainMenu(void)
{
	system(CLEAR);
	printTitle("              Main Menu");
	printf("\t\t\t\t\t     [1] Start\n");
	printf("\t\t\t\t\t     [2] About\n");
	printf("\t\t\t\t\t     [3] Exit\n");
	printLine();
}
/**
 * @brief Display the mode selection menu.
 */
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
/**
 * @brief Display the about menu options.
 */
void showAboutMenu(void)
{
	system(CLEAR);
	printTitle("                About");
	printf("\t\t\t\t\t     [1] About Game\n");
	printf("\t\t\t\t\t     [2] About Single-Player\n");
	printf("\t\t\t\t\t     [3] About MultiPlayer\n");
	printf("\t\t\t\t\t     [4] About Developer\n");
	printLine();
	printf("\t\t\t\t\t     [5] Back\n");
	printf("\t\t\t\t\t     [6] Exit\n");
	printLine();
}
/**
 * @brief Print descriptions for single-player modes
 */
void printSPDescription(void)
{
	printTitle("         About Single-Player");
	textNormal_B();
	printf("\t\t\t\t\t     Easy Mode:\n");
	textReset();
	printf("\t\t\t\t\t     Designed for relaxed play, the computer\n");
	printf("\t\t\t\t\t     makes random  moves, providing practice\n");
	printf("\t\t\t\t\t     and easier wins for players.\n\n");
	textNormal_B();
	printf("\t\t\t\t\t     Normal Mode:\n");
	textReset();
	printf("\t\t\t\t\t     Balanced challenge w/ smarter computer\n");
	printf("\t\t\t\t\t     opponent.  Expect strategic moves  and\n");
	printf("\t\t\t\t\t     moderate difficulty.\n\n");
	textNormal_B();
	printf("\t\t\t\t\t     Hard Mode:\n");
	textReset();
	printf("\t\t\t\t\t     For players seeking serious challenge.\n");
	printf("\t\t\t\t\t     Highly  intelligent  computer opponent\n");
	printf("\t\t\t\t\t     employs  advanced strategies. Ultimate\n");
	printf("\t\t\t\t\t     test of Tic-Tac-Toe skills.\n");
	printLine();
	pressEnter();
}
/**
 * @brief Print a description of multiplayer mode.
 */
void printMPDescription(void)
{
	printTitle("         About MultiPlayer");
	printf("\t\t\t\t\t     Two players can play against eachother\n");
	printf("\t\t\t\t\t     on same computer. This mode is perfect\n");
	printf("\t\t\t\t\t     for social gaming & allows friends  or\n");
	printf("\t\t\t\t\t     family members to compete in a classic\n");
	printf("\t\t\t\t\t     game of Tic-Tac-Toe. Players can input\n");
	printf("\t\t\t\t\t     their names, and the game  keeps track\n");
	printf("\t\t\t\t\t     of their scores, adding  a competitive\n");
	printf("\t\t\t\t\t     element to the gameplay.\n");
	printLine();
	pressEnter();
}
/**
 * @brief Print information about the program developer.
 */
void printDeveloper(void)
{
	printTitle("          Program Developer");
	printf("\t\t\t\t\t     Name: Amr Mohamed Abdulzaher\n");
	printf("\t\t\t\t\t     Email: amrnassareng@gmail.com\n");
	printf("\t\t\t\t\t     Linkedin: linkedin.com/in/amrnassareng\n");
	printf("\t\t\t\t\t     GitHub: github.com/AmrMAbdulzaher\n");
	printLine();
	pressEnter();
}
/**
 * @brief Print a general description of the program.
 */
void printDescription(void)
{
	printTitle("         Program Description");
	printf("\t\t\t\t\t     Console based  Tic-Tac-Toe  Game  that\n");
	printf("\t\t\t\t\t     offers both singleplayer & multiplayer\n");
	printf("\t\t\t\t\t     modes.It has multiple dificulty levels\n");
	printf("\t\t\t\t\t     for singleplayer mode,allowing players\n");
	printf("\t\t\t\t\t     to challenge against computer opponent\n");
	printf("\t\t\t\t\t     In  multiplayer  mode, two players can\n");
	printf("\t\t\t\t\t     take turns playing against each other.\n");
	printLine();
	pressEnter();
}
/**
 * @brief Prompt the user to press Enter to continue.
 */
void pressEnter(void)
{
	printf("\t\t\t\t\t            Press ENTER to continue.");
	getchar();
}
/**
 * @brief Print a title with a given text.
 *
 * @param text The text to display in the title.
 */
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
/**
 * @brief Display the single-player mode selection menu.
 */
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
/**
 * @brief Display the game board, including the score.
 */
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
/**
 * @brief Show options after the game ends to continue or exit.
 */
void showWhatNext(void)
{
	printTitle(titleText);
	printTitle("              What Next?");
	printf("\t\t\t\t\t     [1] Play Again\n");
	printf("\t\t\t\t\t     [2] Back to Main Menu\n");
	printf("\t\t\t\t\t     [3] Exit Game\n");
	printLine();
}
/**
 * @brief Show the exit menu options for confirming the game exit.
 */
void showExitMenu(void)
{
	system(CLEAR);
	printTitle("    Are you sure you want to Exit?");
	printf("\t\t\t\t\t     [1] Yes\n");
	printf("\t\t\t\t\t     [2] No\n");
	printLine();
}