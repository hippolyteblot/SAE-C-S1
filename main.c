#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>

#include "Struct/personne.h"
#include "Other/print_value.h"
#include "Other/line_count.h"
#include "Other/load.h"
#include "Other/menu.h"
#include "Sort/quicksort.h"
#include "Sort/compare_string_value.h"
#include "Other/write_data.h"
#include "Search/missing_data_count.h"

#define chemin "Data/annuaire.csv"


void main(){


    char chargeData;
    int nbLineCharge;
    char allData;
    char fileName[] = "Data/annuaire.csv";

    system("cls");
    printf("Bienvenue sur notre logiciel de gestion de donnees.\n");
    printf("Voulez vous charger les donnees du fichier %s ?(O/N)\n", fileName);
    scanf("%c", &chargeData);
    fgetc(stdin);
    if(chargeData == 'O' || chargeData == 'o'){

        int nbLine = lineCount(fileName);

        printf("Voulez vous charger tout le fichier (%d lignes au total) ?(O/N)\n", nbLine);
        scanf("%c", &allData);
        fgetc(stdin);
        if(allData == 'O' || allData == 'o'){
            nbLineCharge = nbLine;
        }
        else{
            printf("Combien de lignes voulez vous charger ?\n");
            scanf("%d", &nbLineCharge);
        }
        
        FILE *fic = fopen(fileName, "r");
        if(fic == NULL){
            printf("Impossible d'ouvrir le fichier\n");
            exit(EXIT_FAILURE);
        }

        PERSONNE dataTab[nbLineCharge];
        load(dataTab, fic, nbLineCharge);
        fclose(fic);
        printf("Le fichier a ete charge.\n");

        while(1){
            menu(dataTab, nbLineCharge);
        }

    }
    else{
        char otherFile;
        printf("Souhaitez vous charger un autre fichier ?(O/N)\n");
        scanf("%c", &otherFile);
        if(otherFile == 'O' || otherFile == 'o'){
            printf("Veuillez rentrer l'adresse de votre fichier :\n");
            scanf("%s", &fileName);
            printf("Voulez vous charger les donnees du fichier %s ?(O/N)\n", fileName);
            scanf("%c", &chargeData);
            fgetc(stdin);
            if(chargeData == 'O' || chargeData == 'o'){
            }
        }
    }
}
