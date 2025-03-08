#ifndef BOARD_H_
#define BOARD_H_

typedef struct Board
{
    int gridSize;
    int ultGridSize;
    int playsquare;
    int moveCounter;
    int currentPlayer;
    int gameOver;
    int winner;
    int** state;
    int** ultState;
    int** possibleMoves;
} Board;

void _Init_Board(struct Board**);

#endif