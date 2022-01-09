#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdarg.h>
#include<windows.h>
#include<dirent.h>
#include <errno.h>
#include "menu.h"

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    /*
    0 : Noir
    1 : Bleu foncé
    2 : Vert foncé
    3 : Turquoise
    4 : Rouge foncé
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris foncé
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
     */
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int get_confirmation(char reponse_par_default){
    //returne 1 si oui
    //        0 si non
    char c=getch();

    switch(reponse_par_default){
        case 'y' :
        case 'O' :
        case 'o' :
            if(c=='o'||c=='y'||c=='\r'||c=='\n')return 1;
            else return 0;
        case 'N':
        case 'n':
        default:
            if(c=='o'||c=='y')return 1;
            else return 0;
            break;//pas obligatoire mais...
    }
}

int Mselect(char legend[],int n , ...){

    /*
     * retourne -1 si appuie sur ESC
     * sinon retourne une valeur entre 0 et le nombre d'entré n-1
     */

    printf("%s",legend);

    va_list ap;

    va_start(ap, n);

    char *parametre[n];
    for(int j=0;j<n;j++){
        parametre[j]=va_arg(ap,char*);
    }
    int select=0;

    int key=64;
    //---------boucle de selection----------------------
    while(key != 13){
        system("cls");
        printf("%d %d\n",select,key);
        key=64;
        //--------------------boucle d'affichage--------------------------
        for(int j=0;j<n;j++){
            printf("\t");
            if(select==j)printf("->");
            else printf("  ");

            printf("%s\n",parametre[j]);
        }
    //------------position selection-------------------
        key=getch();
        if(key==224){
            key=getch();
            if(key==80 && select<n-1)select+=1;
            if(key==72 && select>0)select-=1;

        }
        if(key==27)return -1;
        key==224;
}
    return select;
}





int Mtype(){

    int line=0;

    //------------------table d'ecriture---------------
    char name[20]={0};
    char lastname[20]={0};
    char tel[15]={0};

    //-----------------curseur d'ecriture----------------
    int cursor_name=0;
    int cursor_lastname=0;
    int cursor_tel=0;

    char key;


    while(key!=27) {
        system("cls");
        printf("key: %d\n",key);
        printf("line: %d\n",line);
//-------------------------------------affichage-------------------------------------
        if(line==0)printf("\033[7;01mname: %20s\n",name); else printf("  name: %20s\n",name);

        if(line==1)printf("\033[7;01mlastname: %20s\n",lastname); else printf("  lastname: %20s\n",lastname);

        if(line==2)printf("\033[7;01mtel: %20s\n",tel); else printf("  tel: %20s\n",tel);

//-------------------------------------ecriture---------------------------

        key=getch();
        if(key>='a' && key<='z') {
            switch (line) {
                case 0://---------name-----------------
                    if (cursor_name < 18) {
                        name[cursor_name] = key;
                        name[cursor_name + 1] = '\0';
                        cursor_name++;
                    }
                    break;
                case 1://---------lastname-----------------
                    if (cursor_lastname < 18) {
                        lastname[cursor_lastname] = key;
                        lastname[cursor_lastname + 1] = '\0';
                        cursor_lastname++;
                    }
                    break;


            }
        }if(key>='0' && key<='9') {
            switch (line) {
                case 2://---------tel-----------------
                    if (cursor_tel < 14) {
                        tel[cursor_tel] = key;
                        tel[cursor_tel + 1] = '\0';
                        cursor_tel++;
                        if(cursor_tel==2 || cursor_tel==5 || cursor_tel==8 || cursor_tel==11){tel[cursor_tel] = '.';cursor_tel++;tel[cursor_tel] = '\0';}
                    }
                    break;
                case 3://---------code-----------------
                    if (cursor_lastname < 18) {
                        lastname[cursor_lastname] = key;
                        lastname[cursor_lastname + 1] = '\0';
                        cursor_lastname++;
                    }
                    break;


            }
//------------------------supression------------------------------------
        }else if(key==8){
            switch(line){
                case 0://---------name-----------------
                    if(cursor_name>=0) {
                        cursor_name--;
                        name[cursor_name] = '\0';
                    }
                    break;
                case 1://---------lastname-----------------
                    if(cursor_lastname>=0) {
                        cursor_lastname--;
                        lastname[cursor_lastname] = '\0';
                    }
                    break;
                case 2://---------tel-----------------
                    if(tel[cursor_tel-1]=='.'){
                        cursor_tel--;
                        tel[cursor_tel] = '\0';
                    }
                    if(cursor_tel>=0) {
                        cursor_tel--;
                        tel[cursor_tel] = '\0';
                    }

                    break;

            }
//---------------------mouvement----------------------------------------------
        }else if(key==72 && line>0)line--;
        else if(key==80 && line<2)line++;


    }





}
int Minput(char legend[],int lenght,char input[]){
    int cursor=strlen(input);
    char key;

    while(key != 13) {
        system("cls");
        printf("%s: ", legend);
        printf("%s\n", input);

        key = getch();

        if (key >= 'a' && key <= 'z') {
            if (cursor < lenght - 2) {
                input[cursor] = key;
                input[cursor + 1] = '\0';
                cursor++;
            }
        }
        if (key == 8) {
            if (cursor >= 0) {
                cursor--;
                input[cursor] = '\0';
            }
        }
    }
}


int countdir(char path[]){//-----------------------------------

    puts(path);//------
    int file_count = 0;//compteur

    DIR *dirp=NULL;
    dirp = opendir(path);//repertoire

    struct dirent *entry=NULL;//fichier lu


    while ((entry = readdir(dirp)) != NULL) {
        //puts("found");//------
            if(entry->d_name[strlen(entry->d_name)-1]=='v' && entry->d_name[strlen(entry->d_name)-2]=='s' && entry->d_name[strlen(entry->d_name)-3]=='c' && entry->d_name[strlen(entry->d_name)-4]=='.') {
                //puts(entry->d_name);
                file_count++;
            }

    }
    closedir(dirp);

return file_count;

}//----------------------------------------------------------------------
int Mdir(char legend[]){
    char save_path[30]={"Data"};
    /*
     * retourne -1 si erreur
     *
     */
    DIR *save = NULL;
    struct dirent* fichierLu = NULL;
    save=opendir(save_path);

    //-----------------------------------------------test error-----------------
    if(save==NULL){/* Dossier inexistant */
        printf("le dossier de sauvegarde %s n'existe pas\n",save_path);
        printf("voulez vous le creer[O/n]");
        if(get_confirmation('o')) mkdir("Data");
        else return -1;
    }
    if (errno == EACCES) { /* Accès interdit */
        puts("Acces interdit");
        return -1;
    }


    //-----------------------------------------------init tab file (save)--------------------
    int c = countdir(save_path);
    char file[c][30];
    int file_count=0;
    while ((fichierLu = readdir(save)) != NULL) {
        //puts("found");//------
        int lenght=strlen(fichierLu->d_name);
        if(fichierLu->d_name[lenght-1]=='v' && fichierLu->d_name[lenght-2]=='s' && fichierLu->d_name[lenght-3]=='c' && fichierLu->d_name[lenght-4]=='.') {//test csv compatibilitie
            strcpy(file[file_count],"Data\\");//init dir
            strcat(file[file_count],fichierLu->d_name);//add name file to dir
            file_count++;

        }

    }

   //---------------------------------------real function------------------------------------------------
   int key=64;
    int line_selected=0;
    char import[70]={0};
    char name[20]={0};
    while(key != 13) {
        system("cls");
        puts(legend);
        //-----------------------------affichage------------------------------
        for (int i = 0; i < c; i++) {
            if (i == line_selected)Color(0, 15);
            puts(file[i]);
            Color(15, 0);
        }
        if(line_selected==c)Color(0, 15);
        puts("");
        printf("importer: %s\n",import);
        Color(15, 0);

        if(fopen(import,"r")==NULL){
            Color(4, 0);
            printf("fichier introuvable\n");
        }else{
            Color(2, 0);
            printf("fichier exitant\n");

        }
        Color(15, 0);
        if(line_selected==c+1)Color(0, 15);
        printf("nom du nouveau fichier: %s\n",name);
        Color(4, 0);
        puts("!!!attention il n'y a pas de protection de reecriture fichier!!!");
        Color(15, 0);



        key=getch();

        //-----------------------------gestion de l'ecriture et de mouvement--------------
            if(key==224 ){
                key = getch();
                if (key == 80 && line_selected < c+1) { line_selected += 1; }
                if (key == 72 && line_selected > 0) { line_selected -= 1; }
                key = 224;
            }
            else if(key== 13) {

                if (line_selected < c)
                    strcpy(save_path, file[line_selected]);
                else if(line_selected=c && fopen(import,"r")!=NULL){
                    char new_path[30];

                    strcpy(new_path,"Data\\");
                    strcat(new_path,name);
                    FILE *old=NULL;
                    FILE *new=NULL;
                    old=fopen(import,"r");
                    new=fopen(new_path,"w");
                    while(!feof(old)){
                        fprintf(new,"%c",fgetc(old));
                    }

                }
            }
            else if(key==47){// "/"
                if (line_selected == c && strlen(import)<25) {
                    import[strlen(import) + 1] = '\0';
                    import[strlen(import)] = '\\';
                }

            }
            else if( key <= 'z' && key >= 'A' || key==':' || key=='_' || key=='.') {


                if (line_selected == c && strlen(import)<49) {
                    import[strlen(import) + 1] = '\0';
                    import[strlen(import)] = key;
                }
                else if (line_selected == c+1 && strlen(name)<19) {
                    name[strlen(name) + 1] = '\0';
                    name[strlen(name)] = key;
                }
            }
            else if(key==8) {
                if (line_selected == c && strlen(import) > 0) {
                    import[strlen(import) - 1] = '\0';
                } else if (line_selected == c+1 && strlen(name) > 0) {
                    name[strlen(name) - 1] = '\0';
                }
            }

        }









    closedir(save);
}
/*
int main(){
    Mdir();
    //printf("%d\n",getch());
    //printf("%d\n",getch());
    //Mselect("",2,"test","test");
    getch();

}
 */