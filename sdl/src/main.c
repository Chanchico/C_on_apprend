#include "main.h"

/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATE
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
*/

int main(int argc, char **argv){
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	
	///lancement SDL
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Init SDL");

	//Création de fenetre et rendu
	if(SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
		SDL_ExitWithError("Unable to create the windows and the render");
	

	//Execution du programme
	/*_____________________________________________________________*/
	if(SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE) != 0)
		SDL_ExitWithError("Unable to change the render color");
	
	if(SDL_RenderDrawPoint(renderer, 155, 455) != 0)
		SDL_ExitWithError("Unable to print the point");

	if(SDL_RenderDrawLine(renderer, 50, 50, 50, 300))
		SDL_ExitWithError("Unable to print the line");

	SDL_Rect rectangle;
	rectangle.x = 300;
	rectangle.y = 300;
	rectangle.w = 100;
	rectangle.h = 50;

	if(SDL_RenderDrawRect(renderer, &rectangle) != 0)
		SDL_ExitWithError("Unable to print the rectangle");

	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	/*_____________________________________________________________*/

	//ON PENSE A DETRUIRE TOUT RISQUE DE FUITE MEMOIRE
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
	SDL_Log("Error : %s > %s \n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}