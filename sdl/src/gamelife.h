#ifndef GAMELIFE
#define GAMELIFE

#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>

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

void initCellsTbm(Cell ***cells,int lenght, int height);

void freeCellsTbm(Cell **cells, int height);

void printCell(Cell **cells, int lenght, int height);

int cellToAlive(Cell *cell, Cell **cells);

bool haveCellAlive(Cell **cells, int lenght, int height);

void addCellToInto(Cell *cell, Cell **cellsPointer, int *numCellPointer);

void changeState(Cell **cells, int *sizeCells);