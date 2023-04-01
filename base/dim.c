#include <stdio.h>
#include <stdlib.h>

/*
    sizeof(<donnee>)            : retourne la taille en octetc d'une donnée

    malloc(<taille_en_octects>) : allouer dynamiquement une zonne mémoire
    free(<donnee_allouee)       : libere la mémoire alloué dynamiquement 

    calloc(<donnee>, <taille_en_octects>) : alloue et initialise tout à 0;

    realloc(<donne>, <nouvelle_taille>)   : realloue 
*/
int main(void){
    int nombreJoueurs = 0;
    int *listeJoueurs = NULL;
    int i = 0;

    printf("Combien de joeurs ? ");
    scanf("%d", &nombreJoueurs);

    listeJoueurs = malloc(sizeof(int) * nombreJoueurs);

    if(listeJoueurs == NULL){
        exit(1);
    }

    for(i = 0; i < nombreJoueurs; i++){
        printf("Jouuer %d -> numero %d\n", i + 1, i * 3); 
        listeJoueurs[i] = i * 3;
    }

    for(i = 0; i < nombreJoueurs; i ++) {
        printf("[%d]", listeJoueurs[i]);
    }

    free(listeJoueurs);

    return 0 ;
}