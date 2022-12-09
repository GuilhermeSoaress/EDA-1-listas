#include <stdio.h>

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main(){
    int a = 50, b = 10;
    swap(&a, &b);
    printf("%d %d", a, b);
}