


void filter(int type, char *key, int nb_ligne, Liste SearchResult, PERSONNE *dataTab, int location){

    clock_t beginFilter = clock();
    clock_t beginPrint;
    clock_t endPrint;
    unsigned long millisPrint = 0;
    
    if(location == 0){
        for(int i = 0; i < nb_ligne; i++){
            int j = 0;
            int isEgal = 1;
            while(j < strlen(key) && isEgal == 1){
                switch (type)
                {
                case 1:
                    if(dataTab[i].name[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 2:
                    if(dataTab[i].surname[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 3:
                    if(dataTab[i].city[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 4:
                    if(dataTab[i].department[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 5:
                    if(dataTab[i].num[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 6:
                    if(dataTab[i].mail[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 7:
                    if(dataTab[i].job[j] != key[j]){
                        isEgal = 0;
                    }
                    break;

                default:
                    break;
                }
                j++;
            }
            if(isEgal == 1){
                beginPrint = clock();
                printValue(&dataTab[i]);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult.start == NULL) SearchResult = *initialisation(&dataTab[i]);
                else insertion(&SearchResult, &dataTab[i]);
            }
        }
    }
    else{
        for(int i = 0; i < nb_ligne; i++){
            int j = strlen(key);
            int isEgal = 1;
            while(j >= 0 && isEgal == 1 /*&& strlen(dataTab[i].name) > strlen(dataTab[i].name)-j*/){
                switch (type)
                {
                case 1:
                    if(dataTab[i].name[strlen(dataTab[i].name)-j] != key[strlen(key)-j]){
                        isEgal = 0;
                    }
                    break;
                case 2:
                    if(dataTab[i].surname[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 3:
                    if(dataTab[i].city[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 4:
                    if(dataTab[i].department[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 5:
                    if(dataTab[i].num[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 6:
                    if(dataTab[i].mail[j] != key[j]){
                        isEgal = 0;
                    }
                    break;
                case 7:
                    if(dataTab[i].job[j] != key[j]){
                        isEgal = 0;
                    }
                    break;

                default:
                    break;
                }
                j--;
            }
            if(isEgal == 1){
                beginPrint = clock();
                printValue(&dataTab[i]);
                endPrint = clock();
                millisPrint += endPrint - beginPrint;

                if(SearchResult.start == NULL) SearchResult = *initialisation(&dataTab[i]);
                else insertion(&SearchResult, &dataTab[i]);
            }
        }
    }
    clock_t endFilter = clock();
    millisPrint = millisPrint * 1000 / CLOCKS_PER_SEC;
    unsigned long millisFilter = ((endFilter -  beginFilter) * 1000 / CLOCKS_PER_SEC) - millisPrint;
    printf("\n");
    printf("Temps d'execution du filtre: %ld ms\n", millisFilter);
    printf("Temps d'execution de l'affichage des resultats: %ld ms\n", millisPrint);
    printf("\n");
}
