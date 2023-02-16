#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 101
#define MAX_HISTORY 101

typedef struct Stack{
    char history[MAX_HISTORY][MAX_LEN];
    int topo;
} Stack;

void push(Stack *pilha, char *str) {
    strcpy(pilha->history[++pilha->topo], str);
}

char *pop(Stack *pilha) {
    if (pilha->topo < 0) {
        return "NULL";
    }
    return pilha->history[pilha->topo--];
}

int main() {
    Stack pilha;
    pilha.topo = -1;

    char command[101];
    char str[MAX_LEN];
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "inserir") == 0) {
            getchar();  
            fgets(str, MAX_LEN, stdin); 
            str[strlen(str) - 1] = '\0';  
            push(&pilha, str);
        } else if (strcmp(command, "desfazer") == 0) {
            printf("%s\n", pop(&pilha));
        }
    }
    return 0;
}
