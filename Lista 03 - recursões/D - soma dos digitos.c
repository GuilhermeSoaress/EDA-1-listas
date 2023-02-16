#include <stdio.h>

int soma(long long int n){
    if (n % 10 == n)
        return n;
    return ((n % 10) + soma(n / 10));
}
int main(){
    long long int n;
    scanf("%lld", &n);
    if(n<0 || n> 1000000000000){
        return 0;
    }
    printf("%lld\n", soma(n));
}