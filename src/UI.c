#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

void printBoard(board *playBoard)
{
    printf("\n");
    for (int row = 0; row < playBoard->boardSize; row++)
    {
        for (int col = 0; col < playBoard->boardSize; col++)
        {
            printf("%s  ", playBoard->field[row][col]);
        }

        printf("\n");
    }

    printf("\n");
}

void printTotalMoves(result *result)
{
    FILE *f_ptr = fopen("files/out.txt", "w");

    fprintf(f_ptr, "Moves count: %d\n", result->moveCounter);
    fprintf(f_ptr, "Moves: ");

    for (int i = 0; i < result->moveCounter; i++)
    {
        fprintf(f_ptr, "%s | ", result->directions[i]);
    }
    
    fclose(f_ptr);
}
