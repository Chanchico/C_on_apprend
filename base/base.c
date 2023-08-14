#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct personneStr
{
    char* nom;
    int tailleCm;
};

typedef struct personneStr* personne;

int main(int argc, char *argv[ ]){
    // char mot[] = "Et la marine va venir a Malte";
    // char* newWord = deleteSpace(mot); 
    // lowerWord(newWord);
    // deleteSpace(newWord);
    // printf("%s", newWord);
    // printf("%d", palindrome(newWord));
    // free(newWord);

    // char ** board = generateBoard(8, 8);

    // print2DArray(board, 8, 8);

    //  for (int i = 0; i < 8; i++) {
    //     free(board[i]);
    // }
    // free(board);

    personne personne1 = (personne)malloc(sizeof(struct personneStr));
    personne1->nom = strdup("francisco");
    personne1->tailleCm = 178;

    printf("%s\n", personne1->nom);
    printf("%d\n", personne1->tailleCm);

    free(personne1);
    return 0;
} 


void sortTableInDescendingOrder(int *table, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (table[i] > table[j]) {
                int temp = table[j];
                table[j] = table[i];
                table[i] = temp;
            }
        }
    }
}

void sortTableInAscendingOrder(int * table, int size){
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if (table[i] < table[j]) {
                int temp = table[j];
                table[j] = table[i];
                table[i] = temp;
            }
        }
    }
}

int anagramme(char *word1, char* word2){
    int nbrIdentiqueLettre = 0;
    int taille1 = countLetter(word1);
    if (taille1 != countLetter(word1)){
        return 0;
    } else {
        for(int i = 0; i < taille1; i++ ){
            for (int j = 0; j < taille1; j++){
                if(word1[i]== word2[j]){
                    nbrIdentiqueLettre ++;
                    break;
                }
            }
        }
    }
    return nbrIdentiqueLettre == taille1;
    
}

void lowerWord(char * word){
    int len = countLetter(word);
    for(int i = 0; i < len; i++){
        word[i] = tolower(word[i]);
    } 
}

char* deleteSpace( char* word){
    int lenChar = countLetter(word);
    int t = 1;
    int j = 0;
    char* newWord = (char*)malloc(t);
    for(int i = 0; i < lenChar; i++){
        if (word[i] != ' '){
            t ++;
            newWord = (char*)realloc(newWord, t);
            newWord[j] = word[i];
            j++;
        }
    }
    newWord[j] = '\0';
    return newWord;
}

int palindrome(char *word){
    int lenChar = countLetter(word);
    if (lenChar % 2 == 1){
        lenChar ++;  
    }
    printf("%d\n", lenChar);
    int compteur = 0;
    for(int i = 0; i < lenChar/2; i++){
        if(word[i] == word[countLetter(word) - (1  + i )]){
            compteur ++;
        }
        else{
            break;
        }
    }
    return compteur == lenChar/2;
}

int countLetter(char *word){
    int i = 0;
    while (word[i] != '\0') {
        i++;
    }
    return i;
}

void printTable(int *table, int size){
    for (int i = 0; i < size; i++){
        if (i == size - 1){
             printf("%d\n", table[i]);
             break;
        }
        printf("%d, ", table[i]);
    }
}

char ** generateBoard(const int width, const int  height){
    char** board = (char**)malloc(height * sizeof(char*));

    for (int i = 0; i < height; i++) {
        char* ligne = (char*)malloc((width + 1) * sizeof(char)); // +1 for the null-terminator
        for (int j = 0; j < width; j++) {
            ligne[j] = 'o'; // Set the default value for each cell to 'o'
        }
        ligne[width] = '\0'; // Null-terminate the string
        board[i] = ligne;
    }

    return board;

}

void print2DArray(char** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

void testBufferOverflow(){
    char mot[10];
    scanf("%s", mot);
    printf("%s",mot);
}
