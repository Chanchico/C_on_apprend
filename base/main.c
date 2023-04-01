#include <stdio.h>

/*
Pointeur : variable qui contient une adresse mémoire

%d -> afficher valeur d'une variable (int)

[VARIABLE]
    maVariable : valeur de la variable
    &maVariable : adresse de la variable

[POINTEUR]
    monPointeur : adresse de la variable
    *monPointeur : valeur de la variable pointée
    &monPointeur : adresse de la variable pointée
*/

void inverser_nombre(int *nombreA, int *nombreB){
    int temporaire = 0;
    temporaire = *nombreB;
    *nombreB = *nombreA;
    *nombreA = temporaire;
}




int main(void) {
    int  a = 28;
    int  b = 15;

    int * pointeurA = &a;
    int * pointeurB = &b;
    printf("Avant l'inversion : a = %d et b = %d\n", a, b);
    inverser_nombre(pointeurA, pointeurB);
    printf("Apres l'inversion : a = %d et b = %d \n", a, b);

}