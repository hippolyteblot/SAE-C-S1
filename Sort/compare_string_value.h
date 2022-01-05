#include <string.h>

// Retourne 1 si str1 à une valeure plus faible que str2
int compareStrValue(char *str1, char *str2){

    int i = 0;
    while (i < strlen(str1) && i < strlen(str2) && str1[i] == str2[i]){
        i++;
    }
    if(str1[i] < str2[i] || i == strlen(str1)) return 1;
    else return 0;
}