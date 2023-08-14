#include "main.h"

//gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2


int main(int argc, char ** argv){
    
	int a = sdlGame();
	if (a == 1){
		return 1;
	}
	return 0;;
}


//SDL


// SDL and game 
int sdlGame(){
	int cote = 60;
	struct Cell ** rects = generateRects(cote);


	SDL_Window* window = SDL_CreateWindow(
		"GAMELIFE",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1000,
		1000,
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
	const int targetFPS = 1;
    const int frameDelay = 1000 / targetFPS;
    
    // Time variables
    Uint32 frameStart;
    int frameTime;

	int quit = 0;
	SDL_Event event;
	int play = 0;

	while(!quit){

		frameStart = SDL_GetTicks();
		
		while (SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				quit = 1;
			}else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Check if left mouse button is clicked
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int mouseX = event.button.x;
                    int mouseY = event.button.y;
                    
                    int row = mouseX / (10 + 2);
					int col = mouseY / (10 + 2);
					// printf("%d, %d\n", mouseX, mouseY);
					// printf("%d, %d\n", row, col);
                    rects[row][col].state = !rects[row][col].state;// Update the state
                }
            } else if (event.type == SDL_KEYDOWN){
				if (event.key.keysym.sym == SDLK_SPACE) {
                    play = !play; // Toggle the pause state
                }
			}
		}
		

		SDL_SetRenderDrawColor(renderer, 230, 230, 230, 200); // White
		SDL_RenderClear(renderer);

		// Front
		SDL_SetRenderDrawColor(renderer, 200, 180, 80,255);
	
		
		// print2DArray(rects, cote);
		for (int i = 0; i < cote; i++){
			for (int j = 0; j < cote; j++){
				if(rects[i][j].state == 1){
					SDL_RenderFillRect(renderer, &rects[i][j].rect);
				}
				else{
					SDL_RenderDrawRect(renderer, &rects[i][j].rect);
				}
			}
		}
		if(havelife(rects, cote) && play == 1 ){
			rects = newGen(rects,cote);
			
		}

		if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        	}
		
		SDL_RenderPresent(renderer);
		frameTime = SDL_GetTicks() - frameStart; 

        
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	for (int i = 0; i < cote; i++) {
		free(rects[i]);
	}
	free(rects);
	return 0;
}

struct Cell ** generateRects(int cote){
	int width = 10;
	int height = 10;
	int cellSpacing = 2;

	struct Cell ** board = (struct Cell**)malloc(cote * sizeof(struct Cell*));
	for (int i = 0; i < cote; i++) {
        board[i] = ( struct Cell *)malloc(cote * sizeof(struct  Cell));
        for (int j = 0; j < cote; j++) {
			struct Cell * cell = &board[i][j];
			cell->rect.w = width;
            cell->rect.h = height;
            cell->rect.x = i * (width + cellSpacing);
           	cell->rect.y = j * (height + cellSpacing);
            
			cell->state = 0;
        }
        
    }
	return board;
}

char ** generateBoard(int cote){

	char** board = (char**)malloc(cote * sizeof(char*));

    for (int i = 0; i < cote; i++) {
        char* ligne = (char*)malloc((cote + 1) * sizeof(char)); 
        for (int j = 0; j < cote; j++) {
            ligne[j] = 'o'; 
        }
        ligne[cote] = '\0'; 
        board[i] = ligne;
    }
	return board;
}    

void print2DArray(struct Cell ** board, int cote) {
	
    for (int i = 0; i < cote; i++) {
        for (int j = 0; j < cote; j++) {
			if (board[i][j].state == 1){
            	printf("%c", 'x');
			}
			else {
				printf("%c", 'o');
			}
        }
        printf("\n");
    }
	printf("\n");
}

int havelife(struct Cell **board, int cote){
	for (int i = 0; i < cote; i++) {
        for (int j = 0; j < cote; j++) {  
			if(board[i][j].state == 1){
				return 1;
			}
        }
    }
	return 0;
}

struct Cell **newGen(struct Cell **board, int cote) {
    struct Cell **newBoard = (struct Cell **)malloc(cote * sizeof(struct Cell *));
    for (int i = 0; i < cote; i++) {
        newBoard[i] = (struct Cell *)malloc(cote * sizeof(struct Cell)); // Allocate memory for each row
        for (int j = 0; j < cote; j++) {
            int count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue;
                    int coorX = i + x;
                    int coorY = j + y;
                    if (coorX >= 0 && coorX < cote && coorY >= 0 && coorY < cote) {
                        if (board[coorX][coorY].state == 1) {
                            count++;
                        }
                    }
                }
            }
			newBoard[i][j].rect = board[i][j].rect;
            if (count == 3) {
                newBoard[i][j].state = 1;
            } else if (count == 2) {
                newBoard[i][j].state = board[i][j].state;
            } else {
                newBoard[i][j].state = 0;
            }
        }
    }

    // Free the old board
    for (int i = 0; i < cote; i++) {
        free(board[i]);
    }
    free(board);

    return newBoard;
}
