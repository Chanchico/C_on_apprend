#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <SDL.h>
#include <stdlib.h>

void SDL_ExitWithError(const char *message);
void SDL_ClearMemory(SDL_Window *window, SDL_Renderer *renderer);

#endif

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 426