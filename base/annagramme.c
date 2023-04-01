#include "headertest.h"

int main(void) {
  if (estAnnagramme("bonjour", "coreen") == 0){
        printf("C'est un annagramme");
  }
  else
    printf("Ce n'est pas un anngramme");
}

int countCaract(char mot[]){
    int i = 0;
    while(mot[i]){
        i++;
    }
    return i;
}

int estAnnagramme(char mot1[], char mot2[]){
    if (countCaract(mot1) == countCaract(mot2))
    {
        int diff = 0; 
        for (int i = 0; i < countCaract(mot1); i ++ ){
            diff = 0; 
            for (int j = 0; j < countCaract(mot2); j ++ ){
                if(mot1[i] == mot2[j]){
                    diff = 0;
                    break;
                } 
                else{
                    diff = 1;
                }
            }
        }
        if (diff == 1){
            return 1;
        }
        
        return 0;
    } 
    else 
        return 1;

}

