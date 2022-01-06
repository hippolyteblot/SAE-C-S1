#include <stdio.h>


PERSONNE cutLine(char *ligne){
    
    PERSONNE x;
    
    
    int type = 0;
    int pos_type = 0;
    int i = 0;
    x.surname[0] = '\0';
    x.name[0] = '\0';
    x.city[0] = '\0';
    x.department[0] = '\0';
    x.num[0] = '\0';
    x.mail[0] = '\0';
    x.job[0] = '\0';
    x.keeped = 1;

    while (ligne[i] != '\0'){
        if (ligne[i] == ','){
            type++;
            pos_type = 0;
        }
        else if (ligne[i] == '\n') printf("");
        else {
            if (type == 0){
            x.surname[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.surname[pos_type] = '\0';
            }

            if (type == 1){
            x.name[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.name[pos_type] = '\0';
            }

            if (type == 2){
            x.city[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.city[pos_type] = '\0';
            }

            if (type == 3){
            x.department[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.department[pos_type] = '\0';
            }

            if (type == 4){
            x.num[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.num[pos_type] = '\0';
            }

            if (type == 5){
            x.mail[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == ',')
                x.mail[pos_type] = '\0';
            }

            if (type == 6){
            x.job[pos_type] = ligne[i];
            pos_type++;
            if (ligne[i+1] == '\n')
                x.job[pos_type] = '\0';
            }
        }
        i++;
    }

    //fscanf(&ligne, "%s,%s,%s,%s,%s,%s,%s", &x.surname, &x.name, &x.city, &x.department, &x.num, &x.mail, &x.job);
    //printValue(x);

    return x;
}