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
                if(pos_type > 40){printf("Pb de size surname\n"); exit(EXIT_FAILURE);}
                x.surname[pos_type] = ligne[i];
                pos_type++;
                if (ligne[i+1] == ',')
                    x.surname[pos_type] = '\0';
            }

            if (type == 1){
                if(pos_type > 40){printf("Pb de size name\n"); exit(EXIT_FAILURE);}
                x.name[pos_type] = ligne[i];
                pos_type++;
                if (ligne[i+1] == ',')
                    x.name[pos_type] = '\0';
            }

            if (type == 2){
                if(pos_type > 40){printf("Pb de size city\n"); exit(EXIT_FAILURE);}
                x.city[pos_type] = ligne[i];
                pos_type++;
                if (ligne[i+1] == ',')
                    x.city[pos_type] = '\0';
            }

            if (type == 3){
                if(pos_type > 8){printf("Pb de size department\n"); exit(EXIT_FAILURE);}
                x.department[pos_type] = ligne[i];
                pos_type++;
                if (ligne[i+1] == ',')
                    x.department[pos_type] = '\0';
            }

            if (type == 4){
                if(pos_type > 15){printf("Pb de size num\n"); exit(EXIT_FAILURE);}
                x.num[pos_type] = ligne[i];
                pos_type++;
                if (ligne[i+1] == ',')
                    x.num[pos_type] = '\0';
            }

            if (type == 5){
                if(pos_type > 50){printf("Pb de size mail\n"); exit(EXIT_FAILURE);}
                x.mail[pos_type] = ligne[i];
                pos_type++;
                if (ligne[i+1] == ',')
                    x.mail[pos_type] = '\0';
            }

            if (type == 6){
                if(pos_type > 40){printf("Pb de size job\n"); exit(EXIT_FAILURE);}
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