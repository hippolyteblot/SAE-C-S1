
#include "../Other/cut_line.h"



void load(PERSONNE *tab, FILE *fic, int length){

    char buffer[400];
    for(int i = 0; i < length; i++){
        fgets(buffer, 200, fic);
        tab[i] = cutLine(buffer);
        PERSONNE x;
        //fscanf(fic, "%s,%s,%s,%s,%s,%s,%s\n", &x.surname, &x.name, &x.city, &x.department, &x.num, &x.mail, &x.job);
    }
}