#include <stdio.h>

int somaDigitos(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int tamanhoStr(char* n) {
    int i = 0;
    while (n[i] != '\0') {
        i++;
    }
    return i;
}

int charpint(char c) {
    return c - 48;
}

int divisivelPor9(int n) {
    int rodada = 0;
    int somaDigito = n;
    
    while (somaDigito > 9) {
       somaDigito = somaDigitos(somaDigito);
       rodada+=1;
    }
    
    if (somaDigito == 9) {
        return rodada + 1; 
    }
    return -1;
}

int charDivisivelPor9(char* n) {
    int somaInicial = 0;
    int size = tamanhoStr(n);
    for (int i = 0; i < size; i++) {
        somaInicial += charpint(n[i]);
    }
    if (somaInicial < 9) {
        return -1;
    }
    int divisivel = divisivelPor9(somaInicial);
    
    if (divisivel > 0) {
        return divisivel;
    }
    return -1;
}

int main()
{
    while(1) {
        char number[1001];
        scanf("%s", number);
        
        if (tamanhoStr(number) == 1 && number[0] == '0') {
            break;
        }
        
        int rounds = charDivisivelPor9(number);
        if (rounds >= 0) {
            printf("%s is a multiple of 9 and has 9-degree %lld\n", number, rounds);
        } else {
            printf("%s is not a multiple of 9\n", number);
        }
    }
    return 0;
}