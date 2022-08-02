#include "Board.h"
#include "ReadInput.h"
#include "Validations.h"
#include "RandomInput.h"
#include "FileInput.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getBoardSize(void)
{
    int value = 0;
    char c = 0;
    do
    {
        c = getchar();
        printf("Enter board size (between 4 and 50): ");
        scanf("%d", &value);

    } while (!validateBoardSize(value));
    
    return value;
}

static void getFigurePosition(input *inputData, int boardSize)
{
    do
    {
        printf("Figure type must be 'k', 'q' or 'r': ");
        scanf(" %c", &inputData->figureType);
    }
    while (!validateFigureType(inputData));

    do
    {
        printf("Enter figure position between 0 and %d: ", boardSize - 1);
        scanf("%d %d", &inputData->row, &inputData->col);

    } while (!outOfBoundsCheck(boardSize, inputData->row, inputData->col));
}

int setPawnsCount(int boardSize)
{
    int value = 0;
    int maxPawnsCount = boardSize * boardSize;

    do
    {
        printf("Enter number of pawns (between 1 and %d): ", maxPawnsCount - 1);
        scanf("%d", &value);

    } while (!validatePawnsCount(boardSize, value));
    
    return value;
}

static void getPawnsPositions(input *inputData, int boardSize)
{
    inputData->pawnsCount = setPawnsCount(boardSize);

    bool areInvalid = false;
    int sizeOfPositions = inputData->pawnsCount * 2;
    inputData->positions = malloc(sizeof(int) * sizeOfPositions);

    printf("Enter pawns positions (between 0 and %d): ", boardSize);

    do
    {
        if (areInvalid)
        {
            printf("There are matching positions!\n");
            printf("Enter new pawns posititons (between 0 and %d): ", boardSize);
            areInvalid = false;
        }
        
        for (int i = 0; i < sizeOfPositions; i += 2)
        {
            scanf("%d %d", &inputData->positions[i], &inputData->positions[i + 1]);
        }

        areInvalid = true;

    } while (!validatePawnsPositions(boardSize, inputData));

}

char chooseInputType(void)
{
    char result = 0;
    
    printf("Choose input type: \n");
    printf("--manual   --> 1\n");
    printf("--file.txt --> 2\n");
    printf("--random   --> 3\n");

    scanf("%c", &result);

    return result;
}

static void setDataManual(int *boardSize, input *manualInput)
{ 
    (*boardSize) = getBoardSize();

    getFigurePosition(manualInput, *boardSize);

    getPawnsPositions(manualInput, *boardSize);
}


int setData(int *boardSize, input *inputData, char inputType)
{
    if (inputType == '1')
    {
        setDataManual(boardSize, inputData);
    }
    else if (inputType == '2')
    {
        bool isDataValid = setDataFromFile(boardSize, inputData); 
        
        if (isDataValid == false)
        {
            printf("Incorect file input!");
            return 0;
        }
    }
    else if (inputType == '3')
    {
        setRandomData(boardSize, inputData);
    }
    else
    {
        printf("Invalid input type!");
        return 0;
    }

    return 1;
}