#include "compare_string_value.h"


void charSwap(PERSONNE *a, PERSONNE *b) 
{ 
    PERSONNE tmp = *a; 
    *a = *b;
    *b = tmp; 
}

int separe(PERSONNE *tab, int min, int max, int type){ 
    int indicePivot = max; // pivot 
    int i = min - 1; // Index of smaller element and indicates the right position of pivot found so far

    switch (type)
    {
    case 1:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].name, tab[indicePivot].name) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    case 2:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].surname, tab[indicePivot].surname) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    case 3:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].city, tab[indicePivot].city) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    case 4:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].department, tab[indicePivot].department) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    case 5:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].num, tab[indicePivot].num) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    case 6:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].mail, tab[indicePivot].mail) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    case 7:
        for (int j = min; j <= max - 1; j++){
            if (compareStrValue(tab[j].job, tab[indicePivot].job) == 1) // if (tab[j] < pivot)
            {
                i++; // increment index of smaller element 
                charSwap(&tab[i], &tab[j]); 
            } 
        } 
        charSwap(&tab[i + 1], &tab[max]); 
        break;
    default:
        break;
    }
    return (i + 1); 
    
} 


void quickSort(PERSONNE *tab, int min, int max, int type) {


    if (min < max) {
        

        int last = separe(tab, min, max, type); 
        quickSort(tab, min, last - 1, type); 
        quickSort(tab, last + 1, max, type); 
    }
} 