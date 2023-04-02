#include "main.h"

/*
	SDL_RENDERER_SOFTWARE
	SDL_RENDERER_ACCELERATE
	SDL_RENDERER_PRESENTVSYNC
	SDL_RENDERER_TARGETTEXTURE
	Voir les differents commits pour les examples 
*/

int main(int argc, char **argv){
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	//lancement SDL
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Init SDL");

	//Création de fenetre et rendu
	if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
		SDL_ExitWithError("Unable to create the windows and the render");
	

	//Execution du programme
	/*_____________________________________________________________*/
	SDL_bool program_launched = SDL_TRUE;
	while(program_launched){
		SDL_Event event;

		while(SDL_PollEvent(&event)){

			switch(event.type){
				case SDL_MOUSEMOTION:
					printf("%d / %d\n", event.motion.x, event.motion.y);
					break;
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				default:
					break;
			}
		}
	}

	/*_____________________________________________________________*/

	//PENSER A TOUT DETRUIRE, RISQUE DE FUITE MEMOIRE
	SDL_ClearMemory(window, renderer);
	SDL_Quit();
	return EXIT_SUCCESS;
}

void SDL_ExitWithError(const char *message){
	SDL_Log("Error : %s > %s \n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void SDL_ClearMemory(SDL_Window *window, SDL_Renderer *renderer ){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}