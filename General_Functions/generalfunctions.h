#ifndef GENERALFUNCTIONS_H
#define GENERALFUNCTIONS_H

#define clearBuffer() while(getchar() != '\n')
#define POSTIONS_NUM 9
#define isAvailablePosition ((position >= 1) && (position <= POSTIONS_NUM) && (scanReturn == 1) && (field[row][col] != 'X') && (field[row][col] != 'O'))
#define isUsedPosition ((field[row][col] == 'X') || (field[row][col] == 'O'))

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
unsigned char userTurnInput(void);
unsigned char getGameStat(void);
void aboutMenu(void);
void exitGame(void);
#endif