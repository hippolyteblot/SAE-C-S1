#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define chemin "Data/annuaire.csv"

typedef struct Personne {

    char name[20];
    char surname[20];
    char city[20];
    char department[6];
    char num[15];
    char mail[50];
    char job[30];

}PERSONNE;

unsigned long hash(char *str, int lenght) {

        unsigned long hash = 5381;
        int c;
        while ((c = *str++)){
            if(c != 10) hash = ((hash << 5) + hash) + c;
        }
        return hash % lenght;

}

PERSONNE cutLine(char *ligne){
    
    PERSONNE x;
    
    int type = 0;
    int pos_type = 0;
    int i = 0;

    x.surname[0] = '\0';
    x.name[0] = '\0';
    x.city[0] = '\0';
    x.department[0] = '\0';
    x.num[0] = '\0';
    x.mail[0] = '\0';
    x.job[0] = '\0';

    while (ligne[i] != '\0'){
        if (ligne[i] == ','){
            type++;
            pos_type = 0;
        }
        else if (ligne[i] == '\n') printf("");
        else {
            if (type == 0){
            x.surname[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.surname[pos_type] = '\0';
            }

            if (type == 1){
            x.name[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.name[pos_type] = '\0';
            }

            if (type == 2){
            x.city[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.city[pos_type] = '\0';
            }

            if (type == 3){
            x.department[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.department[pos_type] = '\0';
            }

            if (type == 4){
            x.num[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.num[pos_type] = '\0';
            }

            if (type == 5){
            x.mail[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.mail[pos_type] = '\0';
            }

            if (type == 6){
            x.job[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == '\n')
                x.job[pos_type] = '\0';
            }
        }
        i++;
    }
    return x;
}

void load(PERSONNE *tab, FILE *fic, const int length){

    char buffer[length];
    for(int i = 0; i < length; i++){
        fgets(buffer, 200, fic);
        tab[i] = cutLine(buffer);
    }
}

void printValue(PERSONNE value){

    printf("\nnom = %s\n", value.name);
    printf("prenom = %s\n", value.surname);
    printf("ville =  %s\n", value.city);
    printf("departement =  %s\n", value.department);
    printf("mail =  %s\n", value.mail);
    printf("metier =  %s\n", value.job);
}


typedef struct Cell CELL;
struct Cell{

    PERSONNE value;
    CELL *pt;
};

typedef struct Liste Liste;
struct Liste{

    CELL *start;
};

Liste *initialisation(PERSONNE tabValue){

    Liste *liste = malloc(sizeof(*liste));
    CELL *cellule = malloc(sizeof(*cellule));

    if (liste == NULL || cellule == NULL)
    {
        exit(EXIT_FAILURE);
    }

    cellule->value = tabValue;
    cellule->pt = NULL;
    liste->start = cellule;

    return liste;
}

void insertion(Liste *liste, PERSONNE value){

    CELL *new = malloc(sizeof(*new));
    if (liste == NULL || new == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->value = value;

    CELL *actuel = liste->start;
    new->pt = liste->start;
    liste->start = new;
    while(actuel->pt != NULL){
        printf("ouai bon flemme de compter\n");
        printf("%s\n", actuel->value.name);
        actuel = actuel->pt;
    }
    printf("fini\n");
}

Liste hashSearch(char *key, int nb_ligne, Liste *hashTab, Liste SearchResult){

    int hashed = hash(key, nb_ligne);
    CELL *actuel = hashTab[hashed].start;
    while (actuel != NULL){
        if(strcmp(actuel->value.surname, key) == 0)
            printValue(actuel->value);
            if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
            else insertion(&SearchResult, actuel->value);
        actuel = actuel->pt;
    }
    return SearchResult;
}


int main(){

    int nb_ligne = 5000;
    int size;
    int type;
    int idd;
    FILE * fic = fopen(chemin,"r");
    PERSONNE tab[5000];
    
    load(tab, fic, nb_ligne);

    Liste hashTab[5000];
    printf("Par quel type voulez vous effectuer la recherche ?\n");
    printf("\t1 - Nom\n\t2 - Prenom\n\t3 - Ville\n\t4 - Departement\n");
    printf("\t5 - Numero\n\t6 - Mail\n\t7 - Metier\n");
    scanf("%d", &type);



    switch (type)
    {
    case 1:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].name[0] != '\0'){
                int indice = hash(tab[i].name, nb_ligne);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }printf("Que voulez vous rechercher ?\n");
        char name[20];
        scanf("%s", &name);
        printf("Voulez vous effectuer une recherche approchee ?\n(0 non, 1 oui)\n");
        int NameApproche;
        scanf("%d", &NameApproche);
        idd = hash(name, nb_ligne);
        printf("%d\n", idd);
        Liste SearchResultName;
        if(NameApproche == 0){
            SearchResultName = hashSearch(name, 5000, hashTab, SearchResultName);
            CELL *actuel = SearchResultName.start;
            if(actuel == NULL) printf("Il n y a pas de %s dans la liste\n", name);
            else{
                while (actuel != NULL){
                    if(strcmp(actuel->value.name, name) == 0)
                        printValue(actuel->value);
                    actuel = actuel->pt;
                }
            }
        }
        else{
            char name2[20];
            int j = 0;
            char lsChar[] = "abcdefghijqlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            for(int j = 0; j < strlen(name); j++){
                for(int i = 0; i < 52; i++){
                    strcpy(name2, name);
                    if(name[j] != lsChar[i]){
                        name2[j] = lsChar[i];
                        hashSearch(name2, 5000, hashTab, SearchResultName);
                    }
                }
            }
            for(int i = 0; i < strlen(name); i++){
                strcpy(name2, name);
                name2[i] = ' ';
                for(int j = i; j < strlen(name); j++){
                    name2[j] = name[j+1];
                }
                hashSearch(name2, 5000, hashTab, SearchResultName);
            }
            for(int i = 0; i < strlen(name)+1; i++){
                for(int j = 0; j < 52; j ++){
                    strcpy(name2, name);
                    for(int k = strlen(name); k > i-1; k--){
                        name2[k] = name[k-1];
                    }
                    name2[i] = lsChar[j];
                    hashSearch(name2, 5000, hashTab, SearchResultName);
                }
            }
            SearchResultName = hashSearch(name, 5000, hashTab, SearchResultName);
            CELL *actuel = SearchResultName.start;
            if(actuel == NULL) printf("Il n y a pas de %s dans la liste\n", name);
            else{
                while (actuel != NULL){
                    if(strcmp(actuel->value.name, name) == 0)
                        printValue(actuel->value);
                    actuel = actuel->pt;
                }
            }
        }
        break;
    
    case 2:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].surname[0] != '\0'){
                int indice = hash(tab[i].surname, nb_ligne);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        printf("Que voulez vous rechercher ?\n");
        char surname[20];
        scanf("%s", &surname);
        printf("Voulez vous effectuer une recherche approchee ?\n(0 non, 1 oui)\n");
        int SurnameApproche;
        scanf("%d", &SurnameApproche);
        idd = hash(surname, nb_ligne);
        printf("%d\n", idd);
        Liste SearchResultSurname;
        if(SurnameApproche == 0){
            SearchResultSurname = hashSearch(surname, 5000, hashTab, SearchResultSurname);
            CELL *actuel = SearchResultSurname.start;
            if(actuel == NULL) printf("Il n'y a pas de %s dans la liste", surname);
            else{
                while (actuel != NULL){
                    if(strcmp(actuel->value.surname, surname) == 0)
                        printValue(actuel->value);
                    actuel = actuel->pt;
                }
            }
        }
        else{
            char surname2[20];
            int j = 0;
            char lsChar[] = "abcdefghijqlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            for(int j = 0; j < strlen(surname); j++){
                for(int i = 0; i < 52; i++){
                    strcpy(surname2, surname);
                    if(surname[j] != lsChar[i]){
                        surname2[j] = lsChar[i];
                        SearchResultSurname = hashSearch(surname2, 5000, hashTab, SearchResultSurname);
                    }
                }
            }
            for(int i = 0; i < strlen(surname); i++){
                strcpy(surname2, surname);
                surname2[i] = ' ';
                for(int j = i; j < strlen(surname); j++){
                    surname2[j] = surname[j+1];
                }
                SearchResultSurname = hashSearch(surname2, 5000, hashTab, SearchResultSurname);
            }
            for(int i = 0; i < strlen(surname)+1; i++){
                for(int j = 0; j < 52; j ++){
                    strcpy(surname2, surname);
                    for(int k = strlen(surname); k > i-1; k--){
                        surname2[k] = surname[k-1];
                    }
                    surname2[i] = lsChar[j];
                    SearchResultSurname = hashSearch(surname2, 5000, hashTab, SearchResultSurname);
                }
            }
            SearchResultSurname = hashSearch(surname, 5000, hashTab, SearchResultSurname);
            CELL *actuel = SearchResultSurname.start;
            if(actuel == NULL) printf("Il n y a pas de %s dans la liste\n", surname);
            else{
                while (actuel != NULL){
                    if(strcmp(actuel->value.surname, surname) == 0)
                        printValue(actuel->value);
                    actuel = actuel->pt;
                }
            }
        }
        break;
    
    case 3:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].city[0] != '\0'){
                int indice = hash(tab[i].city, nb_ligne);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }printf("Que voulez vous rechercher ?\n");
        char city[20];
        scanf("%s", &city);
        idd = hash(city, nb_ligne);
        printf("%d\n", idd);
        if(hashTab[idd].start != NULL && strcmp(hashTab[idd].start->value.city, city) == 0){
            printValue(hashTab[idd].start->value);
            CELL *actuel = hashTab[idd].start->pt;
            while (actuel != NULL){
                if(strcmp(actuel->value.city, city) == 0)
                    printValue(actuel->value);
                actuel = actuel->pt;
            }
        }
        else printf("%s n'existe pas dans la liste", city);
        break;
    
    case 4:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].department[0] != '\0'){
                int indice = hash(tab[i].department, nb_ligne);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }printf("Que voulez vous rechercher ?\n");
        char department[20];
        scanf("%s", &department);
        idd = hash(department, nb_ligne);
        printf("%d\n", idd);
        if(hashTab[idd].start != NULL && strcmp(hashTab[idd].start->value.department, department) == 0){
            printValue(hashTab[idd].start->value);
            CELL *actuel = hashTab[idd].start->pt;
            while (actuel != NULL){
                if(strcmp(actuel->value.department, department) == 0)
                    printValue(actuel->value);
                actuel = actuel->pt;
            }
        }
        else printf("%s n'existe pas dans la liste", department);
        break;

    case 5:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].num[0] != '\0'){
                int indice = hash(tab[i].num, nb_ligne);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }printf("Que voulez vous rechercher ?\n");
        char num[20];
        scanf("%s", &num);
        idd = hash(num, nb_ligne);
        printf("%d\n", idd);
        if(hashTab[idd].start != NULL && strcmp(hashTab[idd].start->value.num, num) == 0){
            printValue(hashTab[idd].start->value);
            CELL *actuel = hashTab[idd].start->pt;
            while (actuel != NULL){
                if(strcmp(actuel->value.num, num) == 0)
                    printValue(actuel->value);
                actuel = actuel->pt;
            }
        }
        else printf("%s n'existe pas dans la liste", num);
        break;

    case 6:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].mail[0] != '\0'){
                int indice = hash(tab[i].mail, nb_ligne);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }printf("Que voulez vous rechercher ?\n");
        char mail[20];
        scanf("%s", &mail);
        idd = hash(mail, nb_ligne);
        printf("%d\n", idd);
        if(hashTab[idd].start != NULL && strcmp(hashTab[idd].start->value.mail, mail) == 0){
            printValue(hashTab[idd].start->value);
            CELL *actuel = hashTab[idd].start->pt;
            while (actuel != NULL){
                if(strcmp(actuel->value.mail, mail) == 0)
                    printValue(actuel->value);
                actuel = actuel->pt;
            }
        }
        else printf("%s n'existe pas dans la liste", mail);
        break;

    case 7:
        for(int i = 0; i < nb_ligne; i++){
            if(tab[i].job[0] != '\0'){
                int z = 0;
                char c = tab[i].job[z];
                int indice = hash(tab[i].job, nb_ligne);
                if(hashTab[indice].start == NULL){
                    printf("%s\n", tab[i].job);
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        printf("Que voulez vous rechercher ?\n");
        char job[20];
        scanf("%s", &job);
        idd = hash(job, nb_ligne);
        printf("%d\n", idd);
        if(hashTab[idd].start != NULL && strcmp(hashTab[idd].start->value.job, job) == 0){
            printValue(hashTab[idd].start->value);
            CELL *actuel = hashTab[idd].start->pt;
            while (actuel != NULL){
                if(strcmp(actuel->value.job, job) == 0)
                    printValue(actuel->value);
                actuel = actuel->pt;
            }
        }
        else printf("%s n'existe pas dans la liste", job);
        break;

    default:
        break;
    }
    printf("Incroyable");
    return 0;
}