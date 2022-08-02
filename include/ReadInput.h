#ifndef CHESS_READINPUT
#define CHESS_READINPUT

#include "Board.h"
#include <stdlib.h>

typedef struct 
{
    char figureType;
    int row;
    int col;
    int pawnsCount;
    int* positions; 
} input;

int setData(int *boardSize, input *inputData, char inputType);
char chooseInputType(void);
void readInput(int *boardLenght, int *firstPointPos, int *secondPointPos, int numOfPawns, int positionArr[][2]);
int setPawnsCount(int boardSize);
int getBoardSize(void);

#endif // CHESS_READINPUT