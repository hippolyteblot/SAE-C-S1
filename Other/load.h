
#include "../Other/cut_line.h"



void load(PERSONNE *tab, FILE *fic, int length){

    char buffer[400];
    for(int i = 0; i < length; i++){
        fgets(buffer, 200, fic);
        tab[i] = cutLine(buffer);
    }
}