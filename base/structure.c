#include "structure.h"

/*
(*monPointer).un_champ EQUIVAUT à  monPoiteur -> unChamp;
*/

int main(void){


    struct Player pA= {0, 0, 0};

    create_player(&pA);

    
    printf("Nom du joueur : %s\n", pA.username);
    printf("PV : %d | PM : %d\n", pA.hp, pA.mp );
    
}

void create_player(Player *p){
    strcpy(p->username, "Luffy");
    p->hp = 100;
    p->mp = 80;
}