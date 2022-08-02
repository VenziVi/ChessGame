#include "Validations.h"


bool outOfBoundsCheck(int boardSize, int row, int col)
{
    if (row >= boardSize || row < 0 ||
        col >= boardSize || col < 0)
    {
        return false;
    }

    return true;
}

static bool repeatingPositionsCheck(int fRow, int fCol, int sRow, int sCol)
{
    if (fRow == sRow && fCol == sCol)
    {
        return false;
    }

    return true;
}

bool validatePawnsPositions(int boardSize, input *inputData)
{
    int pawnRow = 0;
    int pawnCol = 0;

    for (int i = 0; i < (inputData->pawnsCount * 2); i+=2)
    {
        pawnRow = inputData->positions[i];
        pawnCol = inputData->positions[i + 1];

        if (outOfBoundsCheck(boardSize, pawnRow, pawnCol) == false)
        {
            return false;
        }
        
        if (repeatingPositionsCheck(pawnRow, pawnCol, inputData->row, inputData->col) == false)
        {
            return false;
        }

        for (int j = i + 2; j < (inputData->pawnsCount * 2); j+=2)
        {
            if(repeatingPositionsCheck(pawnRow, pawnCol, inputData->positions[j], inputData->positions[j + 1]) == false)
            {
                return false;
            }
        }
    }

    return true;
}

bool validateBoardSize(int boardSize)
{
    if (boardSize < 4 || boardSize > 50)
    {
        return false;
    }

    return true;
}

bool validateFigureType(input *inputData)
{
    if (inputData->figureType != 'k' && inputData->figureType != 'q' && inputData->figureType != 'r')
    {
        return false;
    }

    return true;
}

bool validatePawnsCount(int boardSize, int pawnsCount)
{
    if (pawnsCount < 1 || pawnsCount >= (boardSize * boardSize))
    {
        return false;
    }

    return true;
}
