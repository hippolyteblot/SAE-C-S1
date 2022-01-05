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
    printf("\n\t%d\n", type);
    SearchResult = hashSearch(type, key, sizeTab, hashedTab, SearchResult);
    printf("1\n");
    CELL *actuel = SearchResult.start;
    printf("2\n");
    printf("%s\n", actuel->value.city);
    if(actuel == NULL) printf("Il n y a pas de %s dans la liste\n", key); // Pb sur la detection de struct vide
    return moins;
}