int searchBySimpleHash(int sizeTab, PERSONNE *dataTab, int *keepedNumber){

    int type;
    Liste SearchResult;
    Liste hashedTab[sizeTab];

    printf("Par quel type voulez vous effectuer la recherche ?\n");
    printf("\t1 - Nom\n\t2 - Prenom\n\t3 - Ville\n\t4 - Departement\n");
    printf("\t5 - Numero\n\t6 - Mail\n\t7 - Metier\n");
    scanf("%d", &type);

    clock_t beginHash = clock();
    
    hashTab(type, dataTab, sizeTab, hashedTab);

    clock_t endHash = clock();
    unsigned long millisHash = (endHash -  beginHash) * 1000 / CLOCKS_PER_SEC;
    printf("\n");

    printf("Que voulez vous rechercher ?\n");
    char key[20];
    scanf("%s", &key);
    int moins = 0;
    
    hashSearch(type, key, sizeTab, hashedTab, &SearchResult);
    printf("Temps d'execution du hachage: %ld ms\n", millisHash);
    printf("\n");
    

    return moins;
}


int searchByMultipleHash(int sizeTab, PERSONNE *dataTab, int *keepedNumber){

    int type;
    Liste SearchResult;
    Liste hashedTab[sizeTab];

    printf("Par quel type voulez vous effectuer la recherche ?\n");
    printf("\t1 - Nom\n\t2 - Prenom\n\t3 - Ville\n\t4 - Departement\n");
    printf("\t5 - Numero\n\t6 - Mail\n\t7 - Metier\n");
    scanf("%d", &type);


    hashTab(type, dataTab, sizeTab, hashedTab);
    printf("Que voulez vous rechercher ?\n");
    char key[20];
    scanf("%s", &key);
    int moins = 0;


    char keyCopy[20];
    int j = 0;
    char lsChar[] = "abcdefghijqlmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int j = 0; j < strlen(keyCopy); j++){
        for(int i = 0; i < 52; i++){
            strcpy(keyCopy, key);
            if(key[j] != lsChar[i]){
                keyCopy[j] = lsChar[i];
                hashSearch(type, keyCopy, sizeTab, hashedTab, &SearchResult);
            }
        }
    }
    for(int i = 0; i < strlen(key); i++){
        strcpy(keyCopy, key);
        keyCopy[i] = ' ';
        for(int j = i; j < strlen(key); j++){
            keyCopy[j] = key[j+1];
        }
        hashSearch(type, keyCopy, sizeTab, hashedTab, &SearchResult);
    }
    for(int i = 0; i < strlen(key)+1; i++){
        for(int j = 0; j < 52; j ++){
            strcpy(keyCopy, key);
            for(int k = strlen(key); k > i-1; k--){
                keyCopy[k] = key[k-1];
            }
            keyCopy[i] = lsChar[j];
            hashSearch(type, keyCopy, sizeTab, hashedTab, &SearchResult);
        }
    }
    hashSearch(type, key, sizeTab, hashedTab, &SearchResult);

    CELL *actuel = SearchResult.start;
    printf("iciiii %s\n", actuel->value->city);
    if(actuel == NULL) printf("Il n y a pas de %s dans la liste\n", key); // Pb sur la detection de struct vide
    return moins;
}