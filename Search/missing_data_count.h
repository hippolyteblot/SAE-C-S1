void missingDataCount(PERSONNE *dataTab, int nbLine, int *count){
    for(int i = 0; i < nbLine; i++){
        if(dataTab[i].name[0] == '\0') count[0]++;
        if(dataTab[i].surname[0] == '\0') count[1]++;
        if(dataTab[i].city[0] == '\0') count[2]++;
        if(dataTab[i].department[0] == '\0') count[3]++;
        if(dataTab[i].num[0] == '\0') count[4]++;
        if(dataTab[i].mail[0] == '\0') count[5]++;
        if(dataTab[i].job[0] == '\0') count[6]++;
    }
}