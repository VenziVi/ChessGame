#include "Board.h"
#include "ReadInput.h"
#include "Validations.h"
#include "FileInput.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool readInputFromFile(FILE *file_ptr, int *boardSize, input *txtInput)
{
    int currPawnsCount = 0;
    int currRow = 1;
    int index = 0;

    fscanf(file_ptr, "%d\n", boardSize);

    if (validateBoardSize(*boardSize) == false)
    {
        return false;
    }
    
    fscanf(file_ptr, "%c %d %d\n", &txtInput->figureType, &txtInput->row, &txtInput->col);

    if (!validateFigureType(txtInput) || 
        !outOfBoundsCheck(*boardSize, txtInput->row, txtInput->col))
    {
        return false;
    }
    
    fscanf(file_ptr, "%d\n", &txtInput->pawnsCount);

    if (!validatePawnsCount(*boardSize, txtInput->pawnsCount))
    {
        return false;
    }

    txtInput->positions = malloc((sizeof(int) * (txtInput->pawnsCount) * 2));

    while (currRow > 0 && currPawnsCount < txtInput->pawnsCount)
    {
        currRow = fscanf(file_ptr, "%d %d\n", &txtInput->positions[index], &txtInput->positions[index + 1]);
        index += 2;
        currPawnsCount++;
    }

    if (validatePawnsPositions(*boardSize, txtInput) == false)
    {
        return false;
    }

    return true;
}

bool setDataFromFile(int *boardSize, input *txtInput)
{
    char filePath[260] = {0};
    bool isValid = false;
    printf("Enter file path: ");
    scanf("%s", filePath);

    FILE *file_ptr = NULL;
    file_ptr = fopen(filePath, "r");

    if (file_ptr == NULL)
    {
        printf("Cannot open file: %s", filePath);   
        exit(1);
    }

    isValid = readInputFromFile(file_ptr, boardSize, txtInput);

    fclose(file_ptr);

    return isValid;
}