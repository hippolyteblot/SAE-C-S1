#include <stdio.h>

void printValue(PERSONNE *value){

    printf("\nnom = %s\n", value->name);
    printf("prenom = %s\n", value->surname);
    printf("ville =  %s\n", value->city);
    printf("departement =  %s\n", value->department);
    printf("numero =  %s\n", value->num);
    printf("mail =  %s\n", value->mail);
    printf("metier =  %s\n", value->job);
}