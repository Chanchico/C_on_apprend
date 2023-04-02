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

	///lancement SDL
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError("Init SDL");

	//Création de fenetre et rendu
	if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) != 0)
		SDL_ExitWithError("Unable to create the windows and the render");
	

	//Execution du programme
	/*_____________________________________________________________*/
	SDL_Surface *image = NULL;
	SDL_Texture *texture = NULL;

	image = SDL_LoadBMP("src/sample.bmp");
	if(image == NULL)
		{
			SDL_ClearMemory(window, renderer);
			SDL_ExitWithError("Unable to load the image");
		}

	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image); //On libere la mémoire !!

	if(texture == NULL){
		SDL_ClearMemory(window, renderer);
		SDL_ExitWithError("Unable to create the texture");
	}

	SDL_Rect rectangle;

	if (SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0){
		SDL_ClearMemory(window, renderer);
		SDL_ExitWithError("Unable to create the texture");
	}
	
	rectangle.x = (WINDOW_WIDTH - rectangle.w) / 2;
	rectangle.y = (WINDOW_HEIGHT - rectangle.h) /2;

	if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0){
		SDL_ClearMemory(window, renderer);
		SDL_ExitWithError("Unable to display the texture");
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	/*_____________________________________________________________*/

	//PENSER A DETRUIRE TOUT RISQUE DE FUITE MEMOIRE
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