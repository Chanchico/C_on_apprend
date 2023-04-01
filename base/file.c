#include <stdio.h>
#include <stdlib.h>

/*
    fopen(<ficher>, <mode_ouverture>) : r (lecture, doit exister)
                                        w (écriture seule)
                                        a (ajout en fin de fichier) 
                                        r+ (lecture/écriture, doit exister)
                                        w+ (lecture/écriture, suppime contenue)
                                        a+ (ajout lecture écriture, fin de fichier)
                                    
    fclose(<fichier>) : fermer un fichier ouvert
    feof(fichier): tester la fin d'un fichier
    [LECTURE]
    fgetc() : lire un caractere
    fgets(chaine, taillechaine, fichier) : lit ligne
    

    [ECRIURE]

*/

int main(void){
    FILE *fic = fopen("sauvegarde.txt", "r");
    int lettre = 0;

    if(fic == NULL)
        exit(1);

    while((lettre = fgetc(fic)) != EOF){
        printf("%c", lettre);
    }

    return 0; 
}

int myFunction(int a){
    int len = 67;
    for(int i = 0; i < len; i++ ){
        if (len > 54){
            len ++;
            break;
        }
    }
}