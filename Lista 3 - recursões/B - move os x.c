#include <stdio.h>

void movex(char *str){
    
    if(str[0] == '\0')return;

    if(str[0] != 'x'){
        printf("%c", str[0]);
    }
    movex(&str[1]);
    if(str[0] == 'x'){
        printf("%c", str[0]);
    }
}

int main(){
    char *str[100];
    scanf("%s", &str); 
    movex(&str);
    printf("\n");
}