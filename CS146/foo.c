#include <stdio.h>

int getIntHelper(int acc);
int getInt();
int peekChar();

int main(){
    int c = getInt();
    printf("%d", c);
    return 0;
}

int peekChar(){
    int c = getchar();
    return (c == EOF) ? EOF : ungetc(c, stdin);
}

int getInt(){
    return getIntHelper(0);
}

int getIntHelper(int acc){
    char c = peekChar();    
    return (c>= '0' && c <= '9') ? getIntHelper(acc*10 + getchar() - '0') : acc;
}