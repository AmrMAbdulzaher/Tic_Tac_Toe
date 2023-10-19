#ifndef APPEARANCE_H
#define APPEARANCE_H

#ifdef _WIN32
#include <windows.h>
#define sleep sleep
#else
#include <unistd.h>
#define sleep usleep
#endif

#define programDscrp "Hello this is XO GAME."
#define dscrpTextTime 10000
#define devName "Amr Mohamed Abdulzaher"
#define devEmail "amrnassareng@gmail.com"
#define devLinkedin "www.linkedin.com/in/amrnassareng"
#define devGitHub "www.github.com/AmrMAbdulzaher"
#define devTextTime 30000

#define CLEAR "clear || cls"
#define printLine() printf("=======================\n")

void printMainMenu(void);
void printModeMenu(void);
void printAboutMenu(void);
void printDeveloper(void);
void printDescription(void);
void pressEnter(void);
void showField(const char* text);
void printSPMenu(void);
void printTitle(const char* text);
void printAnimatedText(const char* text,const unsigned int time_ms);

#endif