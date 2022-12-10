#include "KnightMoves.h"
#include "Movements.h"

#include <stdio.h>
#include <string.h>

typedef struct
{
    int row;
    int col;
    char dir[20];
} Moove;

static void setDirection(board *playBoard, int currRow, int currCol, result *result,
                         input *inputData, Moove *moove)
{
    if (checkIsDirectionValid(playBoard, currRow + moove->row, currCol + moove->col))
    {
        result->directions[result->moveCounter++] = strdup(moove->dir);
        resetOldPosition(playBoard, currRow, currCol);
        makeMove(playBoard, inputData->row += moove->row, inputData->col += moove->col, inputData);
    }
}

void setKnightDirection(board *playBoard, result *result, char *direction, input *inputData)
{
    int currRow = inputData->row;
    int currCol = inputData->col;
    Moove moove;

    if (strcmp(direction, "ul") == 0)
    {
        moove.row = -2;
        moove.col = -1;
        strcpy(moove.dir, "up-left");        
    }
    else if (strcmp(direction, "ur") == 0)
    {
        moove.row = -2;
        moove.col = 1;
        strcpy(moove.dir, "up-right");
    }
    else if (strcmp(direction, "ru") == 0)
    {
        moove.row = -1;
        moove.col = 2;
        strcpy(moove.dir, "right-up");
    }
    else if (strcmp(direction, "rd") == 0)
    {
        moove.row = 1;
        moove.col = 2;
        strcpy(moove.dir, "right-down");
    }
    else if (strcmp(direction, "dl") == 0)
    {
        moove.row = 2;
        moove.col = -1;
        strcpy(moove.dir, "down-left");
    }
    else if (strcmp(direction, "dr") == 0)
    {
        moove.row = 2;
        moove.col = 1;
        strcpy(moove.dir, "down-right");
    }
    else if (strcmp(direction, "lu") == 0)
    {
        moove.row = -1;
        moove.col = -2;
        strcpy(moove.dir, "left-up");
    }
    else if (strcmp(direction, "ld") == 0)
    {   
        moove.row = 1;
        moove.col = -2;
        strcpy(moove.dir, "left-down");
    }
    else
    {
        printf("INVALID DIRECTION!\n");
        return;
    }
    
    setDirection(playBoard, currRow, currCol, result, inputData, &moove);
}