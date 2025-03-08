#include "board.h"
#include <stdlib.h>
#include <stdio.h>

void _Init_Board(Board** board)
{
    int* state = malloc((*board)->gridSize * (*board)->gridSize * sizeof(int));
    for(int i = 0; (*board)->gridSize * (*board)->gridSize > i; ++i) {
        state[i] = 17;
    }
    free((*board)->state);
    (*board)->state = &state;
}