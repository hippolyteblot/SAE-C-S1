//
// Created by Androlink on 09/01/2022.
//

#ifndef SAE_C_ALGO_MENU_H
#define SAE_C_ALGO_MENU_H

void Color(int couleurDuTexte,int couleurDeFond);
int get_confirmation(char reponse_par_default);
int Mselect(char legend[],int n , ...);
int Mtype();
int Minput(char legend[],int lenght,char input[]);
int Mdir(char legend[]);

#endif //SAE_C_ALGO_MENU_H
