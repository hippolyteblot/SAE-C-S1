


Liste hashSearch(int type, char *key, int nb_ligne, Liste *hashTab, Liste SearchResult){

    int hashed = hash(key, nb_ligne);
    CELL *actuel = hashTab[hashed].start;
    switch (type)
    {
    case 1:
        while (actuel != NULL){
            if(strcmp(actuel->value.name, key) == 0){
                printf("2\n");
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            }
            else printf("3\n");
            actuel = actuel->pt;
        }
        break;
    case 2:
        while (actuel != NULL){
            if(actuel == NULL) printf("AHHH JE TAI EU\n");
            else printf("malheureusement cest ok\n");
            if(strcmp(actuel->value.surname, key) == 0){
                actuel->value.keeped = 2;
                printf("ok %d\n", actuel->pt);
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            }
            actuel = actuel->pt;
        }
        break;
    case 3:
        while (actuel != NULL){
            if(strcmp(actuel->value.city, key) == 0){
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            }
            actuel = actuel->pt;
        }
        break;
    case 4:
        while (actuel != NULL){
            if(strcmp(actuel->value.department, key) == 0)
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 5:
        while (actuel != NULL){
            if(strcmp(actuel->value.num, key) == 0)
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 6:
        while (actuel != NULL){
            if(strcmp(actuel->value.mail, key) == 0)
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    case 7:
        while (actuel != NULL){
            if(strcmp(actuel->value.job, key) == 0)
                printValue(actuel->value);
                if(SearchResult.start == NULL) SearchResult = *initialisation(actuel->value);
                else insertion(&SearchResult, actuel->value);
            actuel = actuel->pt;
        }
        break;
    
    default:
        break;
    }
    
    if(actuel == NULL) return ;
    return SearchResult;
}