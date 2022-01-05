#include "../Search/hashing.h"
#include "../Search/hash_search.h"
#include "../Search/print_hash_result.h"
#include "../Search/search_by_simple_hash.h"


void printKeepedData(PERSONNE *tab, int sizeTab){

    for(int i = 0; i < sizeTab; i++){
        if(tab[i].keeped ==  1) printValue(tab[i]);
    }
}


void menu(PERSONNE *dataTab, int sizeTab){

    int actionChoice;
    int keepedNumber = sizeTab;
    int searchOrFilter;

    printf("Vous pouvez maintenant appliquer des filtres, ");
    printf("effectuer des recherches et afficher les donnees retenues apres ");
    printf("l'application de ces conditions\n");
    printf("Si vous effectuer plusieurs filtres ou recherches, les donnees ");
    printf("retenues seront celles correspondants a tous ces criteres.\n");

    printf("Que souhaitez vous faire ?\n");
    printf("\t1 - Afficher les donnees (%d au total)\n", keepedNumber);
    printf("\t2 - Trier les donnees\n");
    printf("\t3 - Rechercher/filtrer les donnees\n");
    printf("\t4 - Reinitialiser les donnees retenues\n");
    printf("\t5 - Ajouter une personne\n");
    printf("\t6 - Supprimer une personne\n");
    printf("\t7 - Rechercher le nombre de personne pour lequels un champ est manquant\n");
    printf("\t8 - Creer un nouveau fichier avec les donnees actuelles\n");
    printf("\t9 - Quitter\n");
    printf("Rentrez le nombre correspondant\n");

    scanf("%d", &actionChoice);
    switch (actionChoice)
    {
    case 1:
        printKeepedData(dataTab, sizeTab);
        break;
    case 2: ;
        int type;
        printf("Par quel type voulez vous trier le tableau ?\n");
        printf("\t1 - Nom\n\t2 - Prenom\n\t3 - Ville\n\t4 - Departement\n");
        printf("\t5 - Numero\n\t6 - Mail\n\t7 - Metier\n");
        scanf("%d", &type);
        quickSort(dataTab, 0, sizeTab-1, type);
        break;
    case 3:

        printf("Voulez vous effectuer une recherche ou un filtre ?\n");
        printf("\t1 - Recherche\n");
        printf("\t2 - Filtre\n");
        scanf("%d", &searchOrFilter);
        if(searchOrFilter == 1){
            int searchType;
            printf("Voulez vous effectuer une recherche stricte (hachage simple), ");
            printf("une recherche approximative a un caractere pres (hachage approximatif), ");
            printf("ou une recherche de sous-chaine a l'interieur des valeurs ");
            printf("(algorithme de Boyer-Moore) ? \n");
            printf("\t1 - Recherche stricte\n");
            printf("\t2 - Recherche approximative\n");
            printf("\t3 - Recherche de sous-chaine\n");
            scanf("%d", &searchType);
            switch (searchType)
            {
            case 1:
                searchBySimpleHash(sizeTab, dataTab, &keepedNumber);
                break;
            
            default:
                searchByMultipleHash(sizeTab, dataTab, &keepedNumber);
                break;
            }
        }
        break;
    case 7: ;
        int count[7] = {0, 0, 0, 0, 0, 0, 0};
        missingDataCount(dataTab, sizeTab, count);
        printf("%d ont un nom non renseigne\n", count[0]);
        printf("%d ont un prenom non renseigne\n", count[1]);
        printf("%d ont un ville non renseigne\n", count[2]);
        printf("%d ont un departement non renseigne\n", count[3]);
        printf("%d ont un numero non renseigne\n", count[4]);
        printf("%d ont un mail non renseigne\n", count[5]);
        printf("%d ont un metier non renseigne\n", count[6]);
        break;
    case 8:;
        char nameFile[30];
        printf("Rentrez le nom du fichier (il sera enregistre dans Data):\n");
        scanf("%s", &nameFile);
        //writeKeepedData(, nameFile, sizeTab);
        break;
    case 9:
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

