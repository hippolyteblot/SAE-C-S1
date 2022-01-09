#include "../Struct/string_list.h"
#include "../Search/hashing.h"
#include "../Search/hash_search.h"
#include "../Search/print_hash_result.h"
#include "../Search/search_by_simple_hash.h"
#include "../Sort/quicksort.h"
#include "../Search/missing_data_count.h"
#include "../Other/write_data.h"
#include "../Other/modify_data.h"
#include "../Search/filter.h"
#include "../menu.h"



void printKeepedData(PERSONNE *tab, int sizeTab){

    for(int i = 0; i < sizeTab; i++){
        if(tab[i].keeped !=  -1) printValue(&tab[i]);
    }
}


void menu(PERSONNE *dataTab, int sizeTab){

    int actionChoice;
    int keepedNumber = sizeTab;
    int searchOrFilter;
/*
    printf("Vous pouvez maintenant appliquer des filtres, ");
    printf("effectuer des recherches et afficher les donnees retenues apres ");
    printf("l'application de ces conditions\n");
*/
/*
    printf("Que souhaitez vous faire ?\n");
    printf("\t1 - Afficher les donnees (%d au total)\n", keepedNumber);
    printf("\t2 - Trier les donnees\n");
    printf("\t3 - Rechercher (pour eventuellement modificatier ou supprimer des valeurs)/filtrer les donnees\n");
    printf("\t4 - Ajouter une personne\n"); // A faire
    printf("\t5 - Rechercher le nombre de personne pour lequels un champ est manquant\n");
    printf("\t6 - Creer un nouveau fichier avec les donnees actuelles\n");
    printf("\t7 - Quitter\n");
    printf("Rentrez le nombre correspondant\n");

    scanf("%d", &actionChoice);
    */
    actionChoice = Mselect("Que souhaitez vous faire ?",7
            ,"\t1 - Afficher les donnees"
            ,"\t2 - Trier les donnees"
            ,"\t3 - Rechercher (pour eventuellement modificatier ou supprimer des valeurs)/filtrer les donnees"
            ,"\t4 - Ajouter une personne"
            ,"\t5 - Rechercher le nombre de personne pour lequels un champ est manquant"
            ,"\t6 - Creer un nouveau fichier avec les donnees actuelles"
            ,"\t7 - Quitter")+1;
    system("cls");
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
        clock_t beginSort = clock();
        quickSort(dataTab, 0, sizeTab-1, type);
        clock_t endSort = clock();
        unsigned long millisSort = (endSort -  beginSort) * 1000 / CLOCKS_PER_SEC;
        printf("Temps d'execution du tri: %ld ms\n", millisSort);

        break;
    case 3:

        printf("Voulez vous effectuer une recherche ou un filtre ?\n");
        printf("\t1 - Recherche\n");
        printf("\t2 - Filtre\n");
        scanf("%d", &searchOrFilter);
        if(searchOrFilter == 1){
            int whichData;
            printf("Pour rechercher une personne precise, vous allez devoir renseigner son nom, son prenom ");
            printf("ainsi que son numero de telephone ou simplement son adresse mail.\n");
            printf("Que preferez vous ?\n");
            printf("\t1 - Entrer le nom, le prenom et le numero\n");
            printf("\t2 - Entrer l'adresse mail\n");
            scanf("%d", &whichData);
            Liste SearchResult;
            SearchResult.start == NULL;
            if(whichData == 1){
                exit(EXIT_SUCCESS);
            }
            else{
                Liste hashedTab[sizeTab];
                hashTab(6, dataTab, sizeTab, hashedTab);
                printf("Veuillez entrer l'adresse mail de la personne a rechercher :\n");
                char key[20];
                scanf("%s", &key);
                int moins = 0;
                hashSearch(6, key, sizeTab, hashedTab, &SearchResult);
            }
            if(SearchResult.start == NULL) printf("La recherche n'a donnee aucun resultat\n");
            else{
                int action;
                CELL *result = SearchResult.start;
                printValue(result->value);
                printf("Que souhaitez vous faire avec ces donnees ?\n");
                printf("\t1 - Modifier une valeur\n");
                printf("\t2 - Supprimer cette personne de l'annuaire\n");
                printf("\t3 - Ne rien faire\n");
                scanf("%d", &action);
                switch (action)
                {
                case 1:
                    modifyData(result->value);
                    break;
                case 2:
                    result->value->keeped = -1;
                    break;
                case 3:
                    /* code */
                    break;
                
                default:
                    break;
                }
            }
            
        }
        else{
            int choice;
            printf("Voulez vous afficher les personnes ayant une valeur en particulier ou voulez ");
            printf("vous rechercher une sous-chaine au debut ou a la fin d'une attribut ?\n");
            printf("\t1 - Rechercher un attribut\n");
            printf("\t2 - Rechercher une sous-chaine\n");
            scanf("%d", &choice);
            if(choice == 1){

                int searchType;
                printf("Voulez vous effectuer une recherche stricte (hachage simple) ou ");
                printf("une recherche approximative a un caractere pres (hachage approximatif) ? \n");
                printf("\t1 - Recherche stricte\n");
                printf("\t2 - Recherche approximative\n");
                scanf("%d", &searchType);
                if(searchType == 1)
                    searchBySimpleHash(sizeTab, dataTab, &keepedNumber);
                else
                    searchByMultipleHash(sizeTab, dataTab, &keepedNumber);
            }
            else{
                int location;
                char key[20];
                Liste SearchResult;
                printf("Par quel type voulez vous filtrer les donnees ?\n");
                printf("\t1 - Nom\n\t2 - Prenom\n\t3 - Ville\n\t4 - Departement\n");
                printf("\t5 - Numero\n\t6 - Mail\n\t7 - Metier\n");
                scanf("%d", &type);
                printf("Voulez vous verifier l'existence de la sous-chaine au debut ou a la fin ?(0 = debut, 1 = fin)\n");
                scanf("%d", &location);
                printf("Quelle sous-chaine voulez vous rechercher ?\n");
                scanf("%s", &key);
                filter(type, key, sizeTab, SearchResult, dataTab, location);
            }
        }
        break;
    case 5: ;
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
    case 6:;
        char nameFile[30];
        printf("Rentrez le nom du fichier (il sera enregistre dans Data):\n");
        scanf("%s", &nameFile);
        writeData(dataTab, nameFile, sizeTab);
        break;
    case 7:
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
}

