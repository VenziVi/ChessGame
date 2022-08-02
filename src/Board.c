#include "Board.h"

#include <stdlib.h>
#include <string.h>

static void fillBoard(int boardSize, board *newBoard)
{
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            if (row % 2 == 0)
            {
                if (col % 2 == 0)
                {
                    newBoard->field[row][col] = strdup(WHITEFIELD);
                }
                else
                {
                    newBoard->field[row][col] = strdup(BLACKFIELD);
                }
            }
            else if (row % 2 != 0)
            {
                if (col % 2 == 0)
                {
                    newBoard->field[row][col] = strdup(BLACKFIELD);
                }
                else
                {
                    newBoard->field[row][col] = strdup(WHITEFIELD);
                }
            }    
        }
    }
}

board createBoard(int boardSize)
{
    board newBoard = {0};
    newBoard.boardSize = boardSize;

    newBoard.field = (char***)malloc(sizeof(char**) * boardSize);

    for (int i = 0; i < boardSize; i++)
    {
        newBoard.field[i] = (char**)malloc(sizeof(char*) * boardSize);
    }
    
    fillBoard(boardSize, &newBoard);

    return newBoard;
}

void setFigure(board *playBoard, input *inputData)
{
    char *figure = NULL;

    if (inputData->figureType == 'k')
    {
        figure = KNIGHT;
    }
    else if (inputData->figureType == 'q')
    {
        figure = QUEEN;
    }
    else if (inputData->figureType == 'r')
    {
        figure = ROOK;
    }

    strcpy(playBoard->field[inputData->row][inputData->col], figure);
}

void setPawns(board *playboard, input *inputData)
{
    int row = 0;
    int col = 0;

    for (int i = 0; i < (inputData->pawnsCount * 2); i+=2)
    {
        row = inputData->positions[i];
        col = inputData->positions[i + 1];
        strcpy(playboard->field[row][col], PAWN);
    }
}

void deinitBoard(board *playBoard)
{
    for (int row = 0; row < playBoard->boardSize; row++)
    {
        for (int col = 0; col < playBoard->boardSize; col++)
        {
            free(playBoard->field[row][col]);
            playBoard->field[row][col] = NULL;
        }
        
        free(playBoard->field[row]);
        playBoard->field[row] = NULL;
    }
    
    free(playBoard->field);
    playBoard->field = NULL;

}