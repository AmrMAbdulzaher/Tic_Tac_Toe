#ifndef APPEARANCE_H
#define APPEARANCE_H

#ifdef _WIN32
#include <windows.h>
#define sleep sleep
#else
#include <unistd.h>
#define sleep usleep
#endif

#define textReset()  printf("\033[0m")
#define textNormal_B() printf("\e[1m")
#define textRed_B()  printf("\033[1;31m")
#define whiteBG() printf("\e[47m");
#define textWhite_B() printf("\e[1;37m");
#define textBlack_B() printf("\e[1;90m");
#define textBlue_B()  printf("\033[1;34m")
#define textGreen_B()  printf("\033[1;32m")
#define textYellow()  printf("\e[1;33m")
#define _reset_ "\033[0m"
#define _bold_ "\e[1m"

#define CLEAR "clear || cls"
#define printLine() printf("\t\t\t\t\t     ======================================\n")
#define shiftTextLeft() printf("\t\t\t\t\t     ")

void drawFreePalestine(void);
void showMainMenu(void);
void showModeMenu(void);
void showAboutMenu(void);
void printDeveloper(void);
void printDescription(void);
void pressEnter(void);
void showField(void);
void showSPMenu(void);
void printTitle(const char* text);
void printAnimatedText(const char* text,const unsigned int time_ms);
void showWhatNext(void);
void showExitMenu(void);
void printSPDescription(void);
void printMPDescription(void);

#endif