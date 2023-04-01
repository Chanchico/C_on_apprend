#ifndef STRUCTURE_H
# define STRUCTURE_H

#include <stdio.h>
#include <string.h>

typedef struct Player{
    signed char username[256];
    int hp;
    int mp;
} Player;

typedef enum Booleen{
    false,
    true
} Booleen;


void create_player(Player *p);



# endif