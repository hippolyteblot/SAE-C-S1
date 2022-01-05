#include<stdio.h>


void writeData(PERSONNE *dataTab, char *nameFile, int nbLine){
    char path[40] = "Data/";
    strcat(path, nameFile);
    FILE *fic = fopen(path, "w");
    for(int i = 0; i < nbLine; i++){
        if(dataTab[i].keeped == 2)
            fprintf(fic, "%s,%s,%s,%s,%s,%s, %s\n", dataTab[i].surname, dataTab[i].name, dataTab[i].city, dataTab[i].department, dataTab[i].num, dataTab[i].mail, dataTab[i].job);   
    }
    fclose(fic);
    printf("Les donnees ont bien ete enregistrees dans le fichier %s\n", nameFile);
    
}

void writeKeepedData(Liste SearchResult, char *nameFile, int nbLine){
    CELL *actuel = SearchResult.start;
    char path[40] = "Data/";
    strcat(path, nameFile);
    FILE *fic = fopen(path, "w");
    while (actuel != NULL){
        fprintf(fic, "%s,%s,%s,%s,%s,%s, %s\n", actuel->value.surname, actuel->value.name, actuel->value.city, actuel->value.department, actuel->value.num, actuel->value.mail, actuel->value.job);
        actuel = actuel->pt;
    }
}
        