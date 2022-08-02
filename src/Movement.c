#include "Board.h"
#include "Movements.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool checkIsDirectionValid(board *playBoard, int row, int col)
{
    if (row >= playBoard->boardSize || row < 0 || col >= playBoard->boardSize || col < 0)
    {
        printf("Invalid move! Please enter new move.\n");
        return false;
    }
    
    return true;
}

void resetOldPosition (board *playBoard, int row, int col)
{
    if (row % 2 == 0)
    {
        if (col % 2 == 0)
        {
            strcpy(playBoard->field[row][col], WHITEFIELD);
        }
        else
        {
            strcpy(playBoard->field[row][col], BLACKFIELD);
        }
    }
    else if (row % 2 != 0)
    {
        if (col % 2 == 0)
        {
            strcpy(playBoard->field[row][col], BLACKFIELD);
        }
        else
        {
            strcpy(playBoard->field[row][col], WHITEFIELD);
        }
    }    
}

void makeMove(board *playBoard, int row, int col, input *inputData)
{
    char *currField = playBoard->field[row][col];

    if (strcmp(currField, PAWN) == 0)
    {
        inputData->pawnsCount -= 1;
    }

    if (inputData->figureType == 'k')
    {
        strcpy(currField, KNIGHT);
    }
    else if (inputData->figureType == 'q')
    {
        strcpy(currField, QUEEN);
    }
    else if (inputData->figureType == 'r')
    {
        strcpy(currField, ROOK);
    }
}

void getPawnsRightDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;

    for (int col = currCol; col <= (currCol + fields); col++)
    {
        if(strcmp(playBoard->field[currRow][col], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, currRow, col);
        }
    }
}

void getPawnsUpDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    
    for (int row = currRow; row >= (currRow - fields); row--)
    {
        if(strcmp(playBoard->field[row][currCol], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, row, currCol);
        }
    }
}

void getPawnsLeftDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    
    for (int col = currCol; col >= (currCol - fields); col--)
    {
        if(strcmp(playBoard->field[currRow][col], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, currRow, col);
        }
    }
}

void getPawnsDownDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    
    for (int row = currRow; row <= (currRow + fields); row++)
    {
        if(strcmp(playBoard->field[row][currCol], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, row, currCol);
        }
    }
}

void getPawnsUpRightDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    int row = currRow;
    int col = currCol;

    while (col < (currCol + fields) && row > (currRow - fields))
    {
        if(strcmp(playBoard->field[row][col], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, row, col);
        }
        
        col++;
        row--;
    }
}

void getPawnsUpLeftDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    int row = currRow;
    int col = currCol;

    while (col > (currCol - fields) && row > (currRow - fields))
    {
        if(strcmp(playBoard->field[row][col], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, row, col);
        }
        
        col--;
        row--;
    }
}

void getPawnsDownRightDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    int row = currRow;
    int col = currCol;

    while (col < (currCol + fields) && row < (currRow + fields))
    {
        if(strcmp(playBoard->field[row][col], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, row, col);
        }
        
        col++;
        row++;
    }
}

void getPawnsDownLeftDirection(board *playBoard, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    int row = currRow;
    int col = currCol;

    while (col > (currCol - fields) && row < (currRow + fields))
    {
        if(strcmp(playBoard->field[row][col], PAWN) == 0)
        {
            inputData->pawnsCount -= 1;
            resetOldPosition(playBoard, row, col);
        }
        
        col--;
        row++;
    }
}