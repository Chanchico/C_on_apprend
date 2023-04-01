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
	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		SDL_ExitWithError("Init SDL");
		exit(EXIT_FAILURE);
	}

	//Création de fenetre 
	
	window = SDL_CreateWindow("Premier Fenêtre SDL2", 100, 100, 800, 600, 0);
	if(window == NULL ){
		SDL_ExitWithError("Create Window failed");
	}

	//Execution du programme
	/*_____________________________________________________________*/
	//Creation du rendu 
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	if (renderer == NULL){
		SDL_ExitWithError("Creating renderer");
	}

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