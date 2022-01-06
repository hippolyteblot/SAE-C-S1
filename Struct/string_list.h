

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
        printf("lol nop\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->pt = liste->start;
    liste->start = new;
    
}