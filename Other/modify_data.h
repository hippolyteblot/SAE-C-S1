


void modifyData(PERSONNE *value){

    int choice;
    int reModify;
    char key[50];
    printf("Quel attribut voulez vous modifier ?\n");
    printf("\t1 - Nom\n\t2 - Prenom\n\t3 - Ville\n\t4 - Departement\n");
    printf("\t5 - Numero\n\t6 - Mail\n\t7 - Metier\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Quelle valeur voulez vous entrer pour le nom ?\n");
        scanf("%s", &key);
        strcpy(value->name, key);
        break;
    case 2:
        printf("Quelle valeur voulez vous entrer pour le surnom ?\n");
        scanf("%s", &key);
        strcpy(value->surname, key);
        break;
    case 3:
        printf("Quelle valeur voulez vous entrer pour le ville ?\n");
        scanf("%s", &key);
        strcpy(value->city, key);
        break;
    case 4:
        printf("Quelle valeur voulez vous entrer pour le departement ?\n");
        scanf("%s", &key);
        strcpy(value->department, key);
        break;
    case 5:
        printf("Quelle valeur voulez vous entrer pour le nom ?\n");
        scanf("%s", &key);
        strcpy(value->num, key);
        break;
    case 6:
        printf("Quelle valeur voulez vous entrer pour le nom ?\n");
        scanf("%s", &key);
        strcpy(value->mail, key);
        break;
    case 7:
        printf("Quelle valeur voulez vous entrer pour le nom ?\n");
        scanf("%s", &key);
        strcpy(value->job, key);
        break;
    
    default:
        break;
    }
    printf("Voulez vous modifier une valeur a nouveau ?\n");
    printf("\t1 - Oui\n");
    printf("\t2 - Non\n");
    scanf("%d", &reModify);
    if(reModify == 1)
        modifyData(value);
}