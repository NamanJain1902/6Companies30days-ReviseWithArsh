
bool isDelimiter(char ch) {
    char delimeters[] = {' ', '-', '.', ','};
    for(int i=0; i<(int)(sizeof(delimeters)/sizeof(delimeters[0])); ++i) {
        if(ch == delimeters[i]) return true;
    }
    return false;
}