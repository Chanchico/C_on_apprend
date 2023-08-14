#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// # define VOID_C		"\x1b[32m0\x1b[00m"
# define VOID_C		"\xe2\xa3\xbf"
// # define LIFE_C		"\x1b[31m\xe2\x96\x89\x1b[00m"
# define LIFE_C		"\x1b[31m\xe2\xa3\xbf\x1b[00m"
# define NB_SIDE	20
# define NB_TURN	15
# define WAIT_TIME	0.5

void		game(void);
char		**generateBoard(void);

void		print2DArray(char** board);
int			havelife(char** board);
char		**newGen(char ** board);
void		free_board(char **board);

int main(void)
{
	game();
	return 0;
}

void game(void){

	char	**board = generateBoard();
	int		counter;

	board[5][4] = 'x';
	board[5][3] = 'x';
	board[5][5] = 'x';
	board[4][4] = 'x';
	counter = 0;
	while(havelife(board) && counter < NB_TURN){
		board = newGen(board);
		print2DArray(board);
		// CLEAR THE SCREEN (je ne sais pas si ça marche avec windows, ça devrait cependant marcher avec tout se qui est GNU/Linux)
		printf("\x1b[2J\x1b[H");
		Sleep(1500);
		counter++;
	}
	free_board(board);
}

void free_board(char **board)
{
	int	counter;

	counter = 0;
	while (counter < NB_SIDE)
		free(board[counter++]);
	free(board);
}

char ** generateBoard(){

	char** board = (char**)malloc(NB_SIDE * sizeof(char*));

	for (int i = 0; i < NB_SIDE; i++) {
		char* ligne = (char*)malloc((NB_SIDE + 1) * sizeof(char));
		for (int j = 0; j < NB_SIDE; j++) {
			ligne[j] = 'o';
		}
		ligne[NB_SIDE] = '\0';
		board[i] = ligne;
	}
	return board;
}


void print2DArray(char** board) {

	for (int i = 0; i < NB_SIDE; i++) {
		for (int j = 0; j < NB_SIDE; j++) {
			if (board[i][j] == 'o')
				printf("%s", VOID_C);
			else
				printf("%s", LIFE_C);
			// printf(" ");
		}
		printf("\n");
	}
}

int havelife(char** board){
	int count = 0;
	for (int i = 0; i < NB_SIDE; i++) {
		for (int j = 0; j < NB_SIDE; j++) {
			if(board[i][j] == 'x'){
				count ++;
				break;
			}
			if(count != 0){
				break;
			}
		}

	}
	return count != 0;
}
// Ici memory leak
char ** newGen(char ** board){
	char** newBoard = (char**) malloc(NB_SIDE * sizeof(char*));
	for (int i = 0; i < NB_SIDE; i++) {
		newBoard[i] = (char*) malloc(NB_SIDE * sizeof(char)); // Allocate memory for each row
		for (int j = 0; j < NB_SIDE; j++) {
			int count = 0;
			for (int x = -1; x <= 1; x++) {
				for (int y = -1; y <= 1; y++) {
					if (x == 0 && y == 0) continue;
					int coorX = i + x;
					int coorY = j + y;
					if (coorX >= 0 && coorX < NB_SIDE && coorY >= 0 && coorY < NB_SIDE) {
						if (board[coorX][coorY] == 'x') {
							count++;
						}
					}
				}
			}
			if (count == 3) {
				newBoard[i][j] = 'x';
			}
			else if (count == 2) {
				newBoard[i][j] = board[i][j];
			}
			else {
				newBoard[i][j] = 'o';
			}
		}
	}
	// il faut free l'acienne board, car le newBoard remplace le board
	free_board(board);
	return newBoard;
}
