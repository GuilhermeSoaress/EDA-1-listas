#include <stdio.h>

int n;
int x=0;
long int fib[81];

long int fibonacci(int n){
    if(x==0){
        x++;
        fib[1] = 1;
        fib[2] = 1;

        for(int i = 3; i<81; i++){
            fib[i]=-1;
        }
    }
    if(fib[n]!=-1){
        return fib[n];
    }
    fib[n] = fibonacci(n-1) + fibonacci(n-2);
    return fib[n];
}

int main(){
    scanf("%d", &n);
    printf("%ld", fibonacci(n));
}