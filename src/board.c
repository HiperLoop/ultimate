#include "board.h"
#include <stdlib.h>
#include <stdio.h>

void _Init_Board(Board** board)
{
    (*board)->ultGridSize = ((*board)->gridSize)/3;
    (*board)->playsquare = -1;
    (*board)->moveCounter = 0;
    (*board)->gameOver = 0;
    (*board)->winner = 0;
    (*board)->currentPlayer = 1;
    int i;
    int* emptyState = malloc((*board)->gridSize * (*board)->gridSize * sizeof(int));
    for(i = 0; i < (*board)->gridSize * (*board)->gridSize; ++i) {
        emptyState[i] = 12;
    }
    (*board)->state = &emptyState;
    int* emptyUltState = malloc((*board)->ultGridSize * (*board)->ultGridSize * sizeof(int));
    for(i = 0; i < (*board)->ultGridSize * (*board)->ultGridSize; ++i) {
        emptyUltState[i] = 35;
    }
    (*board)->ultState = &emptyUltState;
    int* emptyMoves = malloc((*board)->gridSize * (*board)->gridSize * sizeof(int));
    for(i = 0; i < (*board)->gridSize * (*board)->gridSize; ++i) {
        emptyMoves[i] = 3;
    }
    (*board)->possibleMoves = &emptyMoves;
}