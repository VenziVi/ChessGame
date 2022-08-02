#ifndef CHESS_MOVEMENT
#define CHESS_MOVEMENT

#include "Board.h"
#include "Engine.h"
#include <stdlib.h>
#include <stdbool.h>

void resetOldPosition (board *playBoard, int row, int col);
void makeMove(board *playBoard, int row, int col, input *inputData);
bool checkIsDirectionValid(board *playBoard, int row, int col);
void getPawnsRightDirection(board *playBoard, int fields, input *inputData);
void getPawnsUpDirection(board *playBoard, int fields, input *inputData);
void getPawnsLeftDirection(board *playBoard, int fields, input *inputData);
void getPawnsDownDirection(board *playBoard, int fields, input *inputData);
void getPawnsDownLeftDirection(board *playBoard, int fields, input *inputData);
void getPawnsDownRightDirection(board *playBoard, int fields, input *inputData);
void getPawnsUpLeftDirection(board *playBoard, int fields, input *inputData);
void getPawnsUpRightDirection(board *playBoard, int fields, input *inputData);

#endif // CHESS_MOVEMENT