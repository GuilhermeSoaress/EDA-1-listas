#include <stdio.h>
#include <string.h>

int cont = 0;
int cont2 = 0;
char *Isub;
int Sub(char *str, char *sub){
    if(*str == '\0'){
        if(cont > strlen(Isub)){
            return (cont + cont2);
        }else{
            return cont;
        }
    }
    if(*str == *sub){
        cont++;
        return Sub(str + 1, sub + 1);
    }else {
        if(cont < strlen(sub)){
            cont = 0;
            return Sub(str + 1, Isub);
        }else{ 
            if(cont == strlen(Isub)){
                if(*str == *Isub){
                    return Sub(str, Isub);
                } else{
                    cont2++;
                    return Sub(str + 1, Isub);
                }
            } else{
                if(cont == (2 * strlen(Isub))){
                    return Sub(str + 1, sub);
                } else{
                    int rest =  cont - strlen(Isub);
                    cont = cont - rest;
                    cont2 = cont2 + rest;
                    return Sub(str, Isub);
                }
            }
        }
    }
}

int main(){
    char str[101], sub[101];
    scanf("%s", str);
    scanf("%s", sub);
    Isub = sub;
    printf("%d\n", Sub(str, sub));
}
