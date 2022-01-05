unsigned long hash(char *str, int lenght) {

        unsigned long hash = 5381;
        int c;
        while ((c = *str++)){
            if(c != 10) hash = ((hash << 5) + hash) + c;
        }
        return hash % lenght;

}