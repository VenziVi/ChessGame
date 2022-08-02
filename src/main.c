#include "Board.h"
#include "ReadInput.h"
#include "UI.h"
#include "Engine.h"

#include <stdio.h>

int main()
{
    char inputType = chooseInputType();
    board playBoard = {0};
    int boardSize = 0;
    input inputData = {0};
    inputData.pawnsCount = 0;

    int success = setData(&boardSize, &inputData, inputType);

    if (!success)
    {
        return 1;
    }
    
    playBoard = createBoard(boardSize);
    setFigure(&playBoard, &inputData);
    setPawns(&playBoard, &inputData);

    printBoard(&playBoard);

    playGame(&playBoard, &inputData);

    free(inputData.positions);
    inputData.positions = NULL;
    deinitBoard(&playBoard);

    return 0;

}