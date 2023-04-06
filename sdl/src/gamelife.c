#include "gamelife.h"

int main(int argc, char **argv){
    Cell cells [HEIGHT][LEN]; 

    int i = 0;
    int j = 0;

    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < LEN; j++){
            cells[i][j].x_coor = i;
            cells[i][j].y_coor = j;
            if(i == 0 && j == 0){
                cells[i][j].state = alive;
            }
            else if(i == 1 && j == 0){
                cells[i][j].state = alive;
            }
            else if(i == 1 && j == 2){
                cells[i][j].state = alive;
            }
            else{
                cells[i][j].state = death;
            }
        }
    }

    printCell(cells);

    struct Cell *cell = getCell(1, 1, cells);

    printf("resultat cellule 1,1: %d\n", cellToAlive(cell, cells));

    printf("[%d,%d]\n", cell->x_coor, cell->y_coor);

    if(cellToAlive(cell, cells) == 1){
        printf("ok\n");
       cell->state = alive; 
    }
    

    printCell(cells);

    return 0;
}

struct Cell *getCell(int x_coor, int y_coor, Cell cells[][LEN] ){
    return &cells[x_coor][y_coor];
}

int cellToAlive(Cell *cell, Cell cells[][LEN]){
    int cellAliveAround = 0;
	for(int i = -1; i < 2; i++){
		for (int j = -1; j < 2; j++){
            if(i == 0 && j == 0)
                continue;
            int coorXToVerifie = cell->x_coor + j;
            int coorYToVerifie = cell->x_coor + i;
            if (coorXToVerifie == -1 || coorXToVerifie == LEN  || 
                coorYToVerifie == -1 || coorYToVerifie == HEIGHT ) 
                break;

           

           // printf("on regarde a %d, %d \n", coorXToVerifie, coorYToVerifie);
            if (getCell(coorXToVerifie, coorYToVerifie, cells)->state == alive)
            cellAliveAround ++;
        }
    }
    printf("cellAlive resultat %d\n", cellAliveAround);
    if (cellAliveAround == 3)
        return 1;
    else if (cellAliveAround == 2)
        return 0;
    else
        return -1;
}

void printCell(Cell cells[][LEN]){
    int i = 0;
    int j = 0;
    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < LEN; j++){
            if(cells[i][j].state == alive ){
                printf("X");
            }
            else{
                printf("0");
            }
        }
        printf("\n");
    }
}



