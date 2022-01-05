#include <stdio.h>


void printHashResult(CELL *actuel, char *key, int type){

    printf("Voici le type %d", type);
    switch (type)
    {
    case 1:
        while(actuel != NULL){
            printf("boucle\n");
            printf("Si c'est ca merci wola %s", actuel->value.name);
            if(strcmp(actuel->value.name, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        printf("fini");
        break;
    case 2:
        printf("ok\n\n\n");
        while(actuel != NULL){
            if(strcmp(actuel->value.surname, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 3:
        while(actuel != NULL){
            if(strcmp(actuel->value.city, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 4:
        while(actuel != NULL){
            if(strcmp(actuel->value.department, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 5:
        while(actuel != NULL){
            if(strcmp(actuel->value.num, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 6:
        while(actuel != NULL){
            if(strcmp(actuel->value.mail, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 7:
        while(actuel != NULL){
            if(strcmp(actuel->value.job, key) == 0)
                printValue(actuel->value);
            actuel = actuel->pt;
        }
        break;

    default:
        break;
    }
    
}