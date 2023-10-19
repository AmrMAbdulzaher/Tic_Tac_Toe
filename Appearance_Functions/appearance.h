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
#define textCyan()  printf("\033[0;36m")
#define _reset_ "\033[0m"
#define _bold_ "\e[1m"

#define programDscrp "Hello this is XO GAME."
#define dscrpTextTime 20000
#define devName "Amr Mohamed Abdulzaher"
#define devEmail "amrnassareng@gmail.com"
#define devLinkedin "www.linkedin.com/in/amrnassareng"
#define devGitHub "www.github.com/AmrMAbdulzaher"
#define devTextTime 30000

#define CLEAR "clear || cls"
#define printLine() printf("=================================\n")

void drawFreePalestine(void);
void printMainMenu(void);
void printModeMenu(void);
void printAboutMenu(void);
void printDeveloper(void);
void printDescription(void);
void pressEnter(void);
void showField(void);
void printSPMenu(void);
void printTitle(const char* text);
void printAnimatedText(const char* text,const unsigned int time_ms);

#endif