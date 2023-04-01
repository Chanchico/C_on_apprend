#include <stdio.h>

/*
Décleration tableau

<type> <nom_tableau>[<taille_tableau>]

*/

void modifier_tableau(int tableau[], int taille_tableau);

int main(){
    int tableau[5] = {1, 2, 3, 4, 5};
    printf("Tableau avant modif\n");	
    for(int i = 0; i < 5; i++){
        printf("%d", tableau[i]);
    }
    printf("\n");

    modifier_tableau(tableau, 5);
    printf("Tableau apres modif\n");
    for(int i = 0; i < 5; i++){
        printf("%d", tableau[i]);
    } 

}


void modifier_tableau(int tableau[], int taille_tableau){
    for(int i = 0; i < taille_tableau; i++){
        tableau[i] = 0;
    }
}
