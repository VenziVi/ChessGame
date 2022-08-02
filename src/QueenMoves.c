#include "QueenMoves.h"
#include "Movements.h"

#include <stdio.h>
#include <string.h>

void setQueenDirection(board *playBoard, result *result, char *direction, int fields, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;

    if (strcmp(direction, "r") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow, currCol + fields))
        {
            result->directions[result->moveCounter++] = strdup("right");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsRightDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row, inputData->col += fields, inputData);
        }
    }
    else if (strcmp(direction, "u") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - fields, currCol))
        {
            result->directions[result->moveCounter++] = strdup("up");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsUpDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row -= fields, inputData->col, inputData);
        }
    }
    else if (strcmp(direction, "l") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow, currCol - fields))
        {
            result->directions[result->moveCounter++] = strdup("left");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsLeftDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row, inputData->col -= fields, inputData);
        }
    }
    else if (strcmp(direction, "d") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + fields, currCol))
        {
            result->directions[result->moveCounter++] = strdup("down");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsDownDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row += fields, inputData->col, inputData);
        }
    }
    else if (strcmp(direction, "ur") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - fields, currCol + fields))
        {
            result->directions[result->moveCounter++] = strdup("up-right");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsUpRightDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row -= fields, inputData->col += fields, inputData);
        }
    }
    else if (strcmp(direction, "ul") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow - fields, currCol - fields))
        {
            result->directions[result->moveCounter++] = strdup("up-left");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsUpLeftDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row -= fields, inputData->col -= fields, inputData);
        }
    }
    else if (strcmp(direction, "dr") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + fields, currCol + fields))
        {
            result->directions[result->moveCounter++] = strdup("down-right");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsDownRightDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row += fields, inputData->col += fields, inputData);
        }
    }
    else if (strcmp(direction, "dl") == 0)
    {
        if (checkIsDirectionValid(playBoard, currRow + fields, currCol - fields))
        {
            result->directions[result->moveCounter++] = strdup("down-left");
            resetOldPosition(playBoard, currRow, currCol);
            getPawnsDownLeftDirection(playBoard, fields, inputData);
            makeMove(playBoard, inputData->row += fields, inputData->col -= fields, inputData);
        }
    }
    else
    {
        printf("INVALID DIRECTION!\n");
    }
}