#ifndef GAMELIFE
#define GAMELIFE

#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>

#endif

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 426*

#define LEN 8
#define HEIGHT 8

typedef enum State{
	death,
	alive
} State;

typedef struct Cell{
	State state;
	int x_coor;
	int y_coor;
} Cell;

int cellToAlive(Cell *cell, Cell cells[][LEN]);

struct Cell *getCell(int x_coor, int y_coor, Cell cells[][LEN]);

void printCell(Cell cells[][LEN]);