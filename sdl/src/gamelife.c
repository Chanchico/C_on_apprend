#include "gamelife.h"

int main(int argc, char **argv){
    Cell **cells;
    //Cell *cellsToAlive []= NULL;
    
    //size_t lenCellToAlive = 0;
    //size_t *lenCellToAlivePointer = &lenCellToAlive;

    printf("%d\n", argc);
    printf("%s\n", argv[argc]);


    initCellsTbm(&cells, LEN, HEIGHT); 

    cells[0][0].state = alive;
    cells[1][0].state = alive;
    cells[1][2].state = alive;

    // printf("Coordonner pour getcell [%d, %d]\n", cells[3][4].x_coor, cells[3][4].y_coor);

    // printf("test cell alive %d\n", haveCellAlive(cells, LEN, HEIGHT));

    int generation = 0;

    while(haveCellAlive(cells, LEN, HEIGHT)){
        printCell(cells, LEN, HEIGHT);
        printf("\n");
        Cell **cellsToAlive = malloc(sizeof(Cell));
        Cell **cellsToKill = malloc(sizeof(Cell));

        int sizeCellsToAlive = 1;

        int sizeCellsToKill = 1;

        for(int i = 0; i < LEN; i++){
            for(int j = 0; j < HEIGHT; j++){
                Cell cell = cells[i][j];
                printf("[%d, %d]\n", i, j);
                cellToAlive(&cell, cells );
                printf("ici\n");
                
            }
        }
        changeState(cellsToAlive, &sizeCellsToAlive);
        changeState(cellsToKill, &sizeCellsToKill);
        printf("ici2\n");
        free(cellsToAlive);
        free(cellsToKill);
        
        generation ++;
    }
   

    

    freeCellsTbm(cells, HEIGHT);

    return 0;
}


int cellToAlive(Cell *cell, Cell **cells){
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

            if (cells[i][j].state == alive)
                cellAliveAround ++;
        }
    }
    if (cellAliveAround == 3)
        return 1;
    else if (cellAliveAround == 2)
        return 0;
    else
        return -1;
}

void printCell(Cell **cells, int lenght, int height){
    int i = 0;
    int j = 0;
    for(i = 0; i < height; i++){
        for(j = 0; j < lenght; j++){
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

void addCellToInto(Cell *cell, Cell **cellsPointer, int *numCellPointer){
    Cell *cells = *cellsPointer;
    
    int sizeCells = *numCellPointer;
    if(sizeCells >= 1){
        size_t newLen = sizeof(Cell) * (sizeCells + 1);
        cells = realloc(cells, newLen);
    }
    else{
        cells = malloc(sizeof( Cell));
    }

    if(cells == NULL){
        printf("Failed to allocate memory\n");
        exit(1);
    } 
  
    cells[sizeCells] = *cell;
    sizeCells ++;

    *numCellPointer = sizeCells;
    *cellsPointer = cells;
}

void initCellsTbm(Cell ***cells,int lenght, int height){
    *cells = (Cell **)malloc(sizeof(Cell *) * height);
    for(int i = 0; i < height; i++){
        (*cells)[i] = (Cell *)malloc(sizeof(Cell) * lenght);

        for(int j = 0; j < lenght; j++){
            (*cells)[i][j].x_coor = i;
            (*cells)[i][j].y_coor = j;
            (*cells)[i][j].state = death;
        }
    }
}

void freeCellsTbm(Cell **cells, int height){
    for(int i = 0; i < height; i++){
        free(cells[i]);
    }
    free(cells);
}

bool haveCellAlive(Cell **cells, int lenght, int height){
    int i = 0;
    int j = 0;
    int counter = 0;
    for(i = 0; i < height; i++){
        for(j = 0; j < lenght; j++){
            if(cells[i][j].state == alive)
                counter++;
        }
    }
    return counter != 0;
}

void changeState(Cell **cells, int *sizeCells){
    for (int i = 0; i < *sizeCells; i++){
        if(cells[i]->state == alive){
            cells[i]->state = death;
        }
        else if(cells[i]->state == death){
            cells[i]->state = alive;
        }
    }
 
}
