


void hashSearch(int type, char *key, int nb_ligne, Liste *hashTab, Liste *SearchResult){

    clock_t beginSearch = clock();
    clock_t beginPrint;
    clock_t endPrint;
    unsigned long millisPrint = 0;


    int hashed = hash(key, nb_ligne);
    CELL *actuel = hashTab[hashed].start;
    switch (type)
    {
    case 1:
        while (actuel != NULL){
            if(strcmp(actuel->value->name, key) == 0){

                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            }
            actuel = actuel->pt;
        }
        break;
    case 2:
        while (actuel != NULL){
            if(strcmp(actuel->value->surname, key) == 0){
                
                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            }
            actuel = actuel->pt;
        }
        break;
    case 3:
        while (actuel != NULL){
            if(strcmp(actuel->value->city, key) == 0){
                
                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            }
            actuel = actuel->pt;
        }
        break;
    case 4:
        while (actuel != NULL){
            if(strcmp(actuel->value->department, key) == 0)
                
                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 5:
        while (actuel != NULL){
            if(strcmp(actuel->value->num, key) == 0)
                
                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 6:
        while (actuel != NULL){
            if(strcmp(actuel->value->mail, key) == 0)
                
                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 7:
        while (actuel != NULL){
            if(strcmp(actuel->value->job, key) == 0)
                
                beginPrint = clock();
                printValue(actuel->value);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult->start == NULL) *SearchResult = *initialisation(actuel->value);
                else insertion(SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    
    default:
        break;
    }
    clock_t endSearch = clock();
    millisPrint = millisPrint * 1000 / CLOCKS_PER_SEC;
    unsigned long millisSearch = (endSearch -  beginSearch) * 1000 / CLOCKS_PER_SEC - millisPrint;
    printf("\n");
    printf("Temps d'execution de la recherche: %ld ms\n", millisSearch);
    printf("Temps d'execution de l'affichage des resultats: %ld ms\n", millisPrint);
}