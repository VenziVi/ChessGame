#ifndef CHESS_BOARD
#define CHESS_BOARD

#include "ReadInput.h"

#define WHITEFIELD "\u25A0"
#define BLACKFIELD "\u25A1"
#define KNIGHT "\u265E"
#define PAWN "\u265F"
#define QUEEN "\u265B"
#define ROOK "\u265C"

typedef struct
{
    char ***field;
    int boardSize;
} board;

board createBoard(int boardSize);
void setFigure(board *playBoard, input *inputData);
void setBoardField(int row, int col, board *newBoard, const char symbol[]);
void setPawns(board *playboard, input *txtInput);
void deinitBoard(board *playBoard);

#endif //CHESS_BOARD
