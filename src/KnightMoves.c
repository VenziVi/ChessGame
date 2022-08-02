#include "KnightMoves.h"
#include "Movements.h"

#include <stdio.h>
#include <string.h>

void setKnightDirection(board *playBoard, result *result, char *direction, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;

    if (strcmp(direction, "ul") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - 2, currCol - 1))
        {
            result->directions[result->moveCounter++] = strdup("up-left");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row -= 2, inputData->col -= 1, inputData);
        }
        
    }
    else if (strcmp(direction, "ur") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - 2, currCol + 1))
        {
            result->directions[result->moveCounter++] = strdup("up-right");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row -= 2, inputData->col += 1, inputData);
        }
    }
    else if (strcmp(direction, "ru") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - 1, currCol + 2))
        {
            result->directions[result->moveCounter++] = strdup("right-up");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row -= 1, inputData->col += 2, inputData);
        }
    }
    else if (strcmp(direction, "rd") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + 1, currCol + 2))
        {
            result->directions[result->moveCounter++] = strdup("right-down");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row += 1, inputData->col += 2, inputData);
        }
    }
    else if (strcmp(direction, "dl") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + 2, currCol - 1))
        {
            result->directions[result->moveCounter++] = strdup("down-left");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row += 2, inputData->col -= 1, inputData);
        }
    }
    else if (strcmp(direction, "dr") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + 2, currCol + 1))
        {
            result->directions[result->moveCounter++] = strdup("down-right");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row += 2, inputData->col += 1, inputData);
        }
    }
    else if (strcmp(direction, "lu") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - 1, currCol - 2))
        {
            result->directions[result->moveCounter++] = strdup("left-up");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row -= 1, inputData->col -= 2, inputData);
        }
    }
    else if (strcmp(direction, "ld") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + 1, currCol - 2))
        {
            result->directions[result->moveCounter++] = strdup("left-down");
            resetOldPosition(playBoard, currRow, currCol);
            makeMove(playBoard, inputData->row += 1, inputData->col -= 2, inputData);
        }
    }
    else
    {
        printf("INVALID DIRECTION!\n");
    }
    
}