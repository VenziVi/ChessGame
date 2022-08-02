#include "Board.h"
#include "ReadInput.h"
#include "Validations.h"
#include "RandomInput.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static int* createPositionsArray(int size, int boardSize)
{

    int *positions = malloc(sizeof(int) * (size));
    int index = 0;

    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            positions[index] = i;
            positions[index + 1] = j; 
            index += 2;
        }
    }

    return positions;
}

static void removeFromPositions(int *positionsArray, int *size, int index)
{
    if (index >= 0 && index < (*size))
    {
        for (int i = index; i < (*size) - 1; i++)
        {
            positionsArray[i] = positionsArray[i + 1];
        }
    }
    
    (*size)--; 
}

static void setPawnsPositions(int *size, int *positionsArray, input *randomInput)
{
    time_t t;
    srand((unsigned) time(&t));
    int randPos = 1;

    for (int i = 0; i < randomInput->pawnsCount * 2; i+=2)
    {
        if ((*size) > 2)
        {
            do
            {
                randPos = rand() % ((*size) - 1);
             } while (randPos % 2 == 0);

            randomInput->positions[i] = positionsArray[randPos];
            randomInput->positions[i + 1] = positionsArray[randPos + 1];

            removeFromPositions(positionsArray, size, randPos);
            removeFromPositions(positionsArray, size, randPos);
        }
        else
        {
            randomInput->positions[i] = positionsArray[1];
            randomInput->positions[i + 1] = positionsArray[0];
        }
    }
    
}

static void setKnightPosition(int *size, int *positionsArray, input *randomInput)
{
    time_t t;
    srand((unsigned) time(&t));
    int randPos = 1;

    do
    {
        randPos = rand() % ((*size) - 1);
    } while (randPos % 2 == 0);

    randomInput->row = positionsArray[randPos];
    randomInput->col = positionsArray[randPos + 1];

    removeFromPositions(positionsArray, size, randPos);
    removeFromPositions(positionsArray, size, randPos);
}


void setRandomData(int *boardSize, input *randomInput)
{
    int* positionsArray = NULL;
    int size = 0; 

    (*boardSize) = getBoardSize();

    randomInput->figureType = 'k';

    size = (*boardSize) * (*boardSize) * 2;
    positionsArray = createPositionsArray(size, *boardSize);

    setKnightPosition(&size, positionsArray, randomInput);

    randomInput->pawnsCount = setPawnsCount(*boardSize);
    int pawnsPositionsSize = randomInput->pawnsCount * 2;
    randomInput->positions = malloc(sizeof(int) * pawnsPositionsSize);

    setPawnsPositions(&size, positionsArray, randomInput);

    free(positionsArray);
}