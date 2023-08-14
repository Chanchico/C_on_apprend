#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <SDL.h>

struct Cell {
    SDL_Rect rect;
    int state;
};

int fn_SDL();

int sdlGame();

void print2DArray(struct Cell ** board, int cote);
char ** generateBoard(int cote);
int havelife(struct Cell **board, int cote);
struct Cell **newGen(struct Cell **board, int cote);
void game();
struct Cell ** generateRects(int cote);


