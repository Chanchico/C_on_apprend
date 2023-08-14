#include "main.h"


int fn_SDL(){
	SDL_Window* window = SDL_CreateWindow(
		"GAMELIFE",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_SHOWN

	 );

	if(!window){
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (!renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return 1;
    }
	
	 SDL_Rect rect;  // Declare an SDL_Rect structure

    // Set the dimensions and position of the rectangle
    rect.x = 10;
    rect.y = 10;
    rect.w = 10;
    rect.h = 10;


	
	int quit = 0;
	SDL_Event event;

	while(!quit){
		while (SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				quit = 1;
			}
		}
	
	// BackGround
    SDL_SetRenderDrawColor(renderer, 230, 230, 230, 200); // White
	SDL_RenderClear(renderer);

	// Front
	SDL_SetRenderDrawColor(renderer, 200, 180, 80,255);

	for(int i = 0; i < 3; i++ ){
		for(int j = 0; j < 3; j++){
			SDL_RenderFillRect(renderer, &rect);
			rect.x = rect.x + rect.w + 2;
		}
		rect.y = rect.y + rect.h + 2;
	}
	SDL_RenderPresent(renderer);
	Sleep(1500);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}