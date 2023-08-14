#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void game();
char ** generateBoard(int cote);

void print2DArray(char** board, int cote);
int havelife(char** board, int cote);
void newGen(char *** board, int cote);

int main(){
	game();
	return 0;
}

void game(){

	int cote = 15;
	char ** board = generateBoard(cote);

	board[5][4] = 'x';
	board[5][3] = 'x';
	board[5][5] = 'x';
	board[4][4] = 'x';
	// print2DArray(board, cote);
	// printf("\n");
	// newGen(&board, cote);

	// print2DArray(board, cote);
	// printf("\n");

	while(havelife(board, cote)){
		newGen(&board, cote);
		print2DArray(board, cote);
		printf("\n");
		Sleep(1500);
	}


	for (int i = 0; i < cote; i++) {
		free(board[i]);
	}
	free(board);
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


void print2DArray(char** board, int cote) {
    for (int i = 0; i < cote; i++) {
        for (int j = 0; j < cote; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int havelife(char** board, int cote){
	for (int i = 0; i < cote; i++) {
        for (int j = 0; j < cote; j++) {  
			if(board[i][j] == 'x'){
				return 1;
			}
        }
        
    }
	return 0;
}
// Ici memory leak

void newGen(char *** board, int cote){
	char** newBoard = (char**) malloc(cote * sizeof(char*));
	for (int i = 0; i < cote; i++) {
		newBoard[i] = (char*) malloc(cote * sizeof(char)); // Allocate memory for each row
		for (int j = 0; j < cote; j++) {
			int count = 0;
			// printf(" (%d %d), %c  \n",i , j,(*board)[i][j] );
			for (int x = -1; x <= 1; x++) {

				
				for (int y = -1; y <= 1; y++) {
					if (x == 0 && y == 0) continue;
					int coorX = i + x;
					int coorY = j + y;
					if (coorX >= 0 && coorX < cote && coorY >= 0 && coorY < cote) {
					
						if ((*board)[coorX][coorY] == 'x') {
							count++;
						}
					}
				}
			}
			if (count == 3) {
				newBoard[i][j] = 'x';
			}
			else if (count == 2) {
				newBoard[i][j] = (*board)[i][j];
			}
			else {
				newBoard[i][j] = 'o';
			}


		}
		newBoard[cote] = '\0'; 
	}
	// print2DArray(newBoard, cote);
	*board = newBoard;
	for (int i = 0; i < cote; i++) {
		free(newBoard[i]);
	}
	free(newBoard);

}