#ifndef CHESS_VALIDATIONS
#define CHESS_VALIDATIONS

#include "Board.h"
#include <stdbool.h>

bool validatePawnsPositions(int boardSize, input *inputData);
bool validatePawnsCount(int boardSize, int pawnsCount);
bool validateFigureType(input *inputData);
bool validateBoardSize(int boardSize);
bool outOfBoundsCheck(int boardSize, int row, int col);

#endif // CHESS_VALIDATIONS