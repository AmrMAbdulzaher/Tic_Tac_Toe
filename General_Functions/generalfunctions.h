#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#define clearBuffer() while(getchar() != '\n')
#define POSTIONS_NUM 9

void switchChoice(void);
void welcomeScreen(void);
void mainMenu(void);
void chooseMode();
void resetField(void);
unsigned char isEnd(void);
char winnerChar(void);
unsigned char isWinRows(void);
unsigned char isWinCols(void);
unsigned char isWinDiags(void);
void userTurnInput(void);
unsigned char isDone(void);
void aboutMenu(void);
unsigned char winMove(void);
unsigned char blockMove(void);

#endif