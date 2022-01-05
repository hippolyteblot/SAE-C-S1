#include<stdio.h>
#include<stdlib.h>

int lineCount(char *dir){

    int count = 0;
    char c;
    FILE *fic = fopen(dir, "r");
    if(fic == NULL){
        printf("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }

    while((c = fgetc(fic)) != EOF){
        if(c == '\n') count++;
    }
    fclose(fic);
    return count;
}