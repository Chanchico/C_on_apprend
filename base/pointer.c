#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int len);
void chV(int *arr, int iToChange, int newValue);
void print2DArray(int **arr, int rows, int columns);
int pointer(int *a);
void changePointer(int *a);
int ajout(int a);
void chVaOfTowDimArr(int **arr, int row, int col, int value);
void revuePointer();
void newArray(int **arr);


int main(){
	revuePointer();

	//test pointer array 1d
	int a [] = {1, 5, 6};
	printArr(a, 3);
	chV(a, 1, 3);
	printArr(a, 3);

	//test pointer 2d
	int rows = 2;
    int cols = 3;
	int **dArr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dArr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dArr[i][j] = i * cols + j + 1;
        }
    }

	printf("Before changing:\n");
    print2DArray(dArr, rows, cols);

	chVaOfTowDimArr(dArr, 0, 0, 8); // Change the value at row 0, column 0 to 8

	printf("\nAfter changing:\n");
    print2DArray(dArr, rows, cols);

	printf("\nNew array test, cela ne changera pas vraiment l array\n");

	newArray(dArr);

	print2DArray(dArr, rows, cols);

	  for (int i = 0; i < rows; i++) {
        free(dArr[i]);
    }
    free(dArr);

	return 0;
}

void newArray(int **arr){
	int rows = 2;
    int cols = 3;
	int **dArr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dArr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dArr[i][j] = i * cols + j + 1;
        }
    }
	arr = dArr;

	for (int i = 0; i < rows; i++) {
        free(dArr[i]);
    }
    free(dArr);
}

void chVaOfTowDimArr(int **arr, int row, int col, int value){
	arr[row][col] = value;
}

void revuePointer(){
	int a = 3;
	int *adresse = &a;
	printf("l'address de a = %d \n", adresse);
	int b = pointer(&a);
	printf("Ne change pas a = %d,  b = %d\n", a, b );
	ajout(a);
	changePointer(&a);
	printf("Ici on change la valeur de a il est par consequent modifier a = %d\n", a);
}

void printArr(int * arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void chV(int * arr, int iToChange, int newValue){
	(arr)[iToChange] = newValue;
}



void print2DArray(int** arr, int rows, int columns) {
	
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {	
            printf("%d ", arr[i][j]);

        }
        printf("\n");
    }
}

int pointer(int * a){
	return *a + 3;
}

void changePointer(int *a){
	*a = 6;
}

int ajout(int a){
	return a + 4;
}

