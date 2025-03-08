#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "board.h"

int main()
{
    Board* firstboard = calloc(1, sizeof(Board));
    firstboard->gridSize = 9;
    _Init_Board(&firstboard);
    int ** firstState = firstboard->state;
    printf("%d\n", (*firstState)[81]);
    int y = foo(3);
    printf("%d\n", y);
    return 0;
}