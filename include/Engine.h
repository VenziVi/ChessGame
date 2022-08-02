#ifndef CHESS_ENGINE
#define CHESS_ENGINE

#include "Board.h"
#include <stdlib.h>

typedef struct 
{
    int moveCounter;
    char **directions;
} result;

void playGame(board *playBoard, input *txtInput);

#endif // CHESS_ENGINE