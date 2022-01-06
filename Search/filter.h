


void filter(int type, char *key, int nb_ligne, Liste SearchResult, PERSONNE *dataTab, int location){

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
                printValue(dataTab[i]);
                if(SearchResult.start == NULL) SearchResult = *initialisation(dataTab[i]);
                else insertion(&SearchResult, dataTab[i]);
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
                printValue(dataTab[i]);
                if(SearchResult.start == NULL) SearchResult = *initialisation(dataTab[i]);
                else insertion(&SearchResult, dataTab[i]);
            }
        }
    }

}
