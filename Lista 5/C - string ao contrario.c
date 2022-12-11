#include <stdio.h>

void isc(char *str){
    if(str[0] == '\0')return;
    isc(&str[1]);
    printf("%c", str[0]);
}

int main(){
    char *str[500];
    scanf("%s", &str); 
    isc(&str);
    printf("\n");
}