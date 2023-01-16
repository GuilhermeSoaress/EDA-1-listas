#include <stdio.h>

int main(){
    int c1, c2, c3, sum, t;
    scanf("%d %d %d", &c1, &c2, &c3);
    sum = c1 + c2 + c3;

    scanf("%d", &t);

    if (t == sum){
        printf("Acertou\n");
    } else{
        printf("Errou\n");
    }
}