#include<stdio.h>
#include<time.h>
#include<stdlib.h>




int *allocation(){

    int *tab;
    tab = malloc(10 * sizeof(int));
    return tab;
}


void remplissage(int tab[]){

    for(int i = 0; i < 10; i++){
        tab[i] = rand()%100;
    }
}

void affichage(int tab[]){

    for(int i = 0; i < 20; i++){
        if(i == 10) printf("\n");
        printf("tab[%d] = %d\n", i, tab[i]);
    }
}


void main(){
    

    clock_t begin = clock();
    for(int i = 0; i < 100; i++)
    printf("salut\n");
    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    printf("Temps d'execution : %ld ms\n", millis);
    /*
    srand(time(NULL));
    int *tab1 = allocation();
    int *tab2 = allocation();
    int *tab3 = allocation();
    remplissage(tab1);
    remplissage(tab2);
    remplissage(tab3);
    affichage(tab2);
    printf("\n");
    realloc(tab2, 20 * sizeof(int));
    affichage(tab2);*/

}