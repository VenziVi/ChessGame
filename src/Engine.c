#include "Engine.h"
#include "RookMoves.h"
#include "KnightMoves.h"
#include "QueenMoves.h"
#include "UI.h"

#include <stdio.h>


static void deinitResult(result *currentResult)
{
    for (int i = 0; i < currentResult->moveCounter; i++)
    {
        free(currentResult->directions[i]);
        currentResult->directions[i] = NULL;
    }
    
    free(currentResult->directions);
    currentResult->directions = NULL;
}

void playGame(board *playBoard, input *inputData)
{
    result currentResult = {0};
    currentResult.moveCounter = 0;

    int capacity = 10;
    currentResult.directions = malloc(sizeof(char*) * capacity);

    char directionStr[3] = {0};
    int fields = 0;

    while (inputData->pawnsCount > 0)
    {
        if ((capacity - 1) == currentResult.moveCounter)
        {
            capacity *= 2;
            currentResult.directions = realloc(currentResult.directions, sizeof(char*) * capacity);
        }

        if (inputData->figureType == 'k')
        {
            printf("Enter direction: ");
            scanf("%s", directionStr);
            setKnightDirection(playBoard, &currentResult, directionStr, inputData);
        }
        else if (inputData->figureType == 'r')
        {
            printf("Enter direction and fields: ");
            scanf("%s %d", directionStr, &fields);
            setRookDirection(playBoard, &currentResult, directionStr, fields, inputData);
        }
        else if (inputData->figureType == 'q')
        {
            printf("Enter direction and fields: ");
            scanf("%s %d", directionStr, &fields);
            setQueenDirection(playBoard, &currentResult, directionStr, fields, inputData);
        }
        
        printBoard(playBoard);

    }

    printTotalMoves(&currentResult);
    deinitResult(&currentResult);
}