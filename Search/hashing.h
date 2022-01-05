#include "../Struct/string_list.h"
#include "djb2.h"


void hashTab(int type, PERSONNE *tab, int sizeTab, Liste *hashTab){


    switch (type)
    {
    case 1:
        for(int i = 0; i < sizeTab; i++){
            
            if(tab[i].name[0] != '\0'){
                int indice = hash(tab[i].name, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;
    
    case 2:
        for(int i = 0; i < sizeTab; i++){
            if(tab[i].surname[0] != '\0'){
                int indice = hash(tab[i].surname, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;
    
    case 3:
        for(int i = 0; i < sizeTab; i++){
            if(tab[i].city[0] != '\0'){
                int indice = hash(tab[i].city, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;
    
    case 4:
        for(int i = 0; i < sizeTab; i++){
            if(tab[i].department[0] != '\0'){
                int indice = hash(tab[i].department, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;
    
    case 5:
        for(int i = 0; i < sizeTab; i++){
            if(tab[i].num[0] != '\0'){
                int indice = hash(tab[i].num, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;
    
    case 6:
        for(int i = 0; i < sizeTab; i++){
            if(tab[i].mail[0] != '\0'){
                int indice = hash(tab[i].mail, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;
    
    case 7:
        for(int i = 0; i < sizeTab; i++){
            if(tab[i].job[0] != '\0'){
                int indice = hash(tab[i].job, sizeTab);
                if(hashTab[indice].start == NULL){
                    hashTab[indice] = *initialisation(tab[i]);
                }
                else{
                    insertion(&hashTab[indice], tab[i]);
                }
            }
        }
        break;

    default:

        break;
    }
}