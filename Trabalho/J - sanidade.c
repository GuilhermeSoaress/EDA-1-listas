#include <stdio.h>
#include <stdlib.h>

#define less(A,B) (A.elem<B.elem)
#define exch(A,B) { Item tt=A;\
                    A=B;\
                    B=tt;}
#define cmpexch(A,B){if(less(B, A)){exch(A,B)}}

typedef struct Item{
    unsigned long long elem, ant, prox;
}Item;

Item v[500000];

int separa(Item *v, int l, int r){
    Item p = v[r];
    int i = l-1, j = r;
    for( ; ; ){
        while(less(v[++i], p));
        while(less(p, v[--j]))
        if(j == l) break;
        if(i>=j) break;
        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quicksort(Item *v, int l, int r){
    if(l>=r) return;
    exch(v[(l+r)/2], v[r-1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[l], v[r-1]);
    cmpexch(v[r-1], v[r]);
    int j = separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}


int bb(Item *vetor, int n, unsigned long long b){
    int esq = 0, dir=n-1;
    while(esq<=dir){
        int meio = (esq + dir) / 2;
        if (vetor[meio].elem == b){
            return meio;
        }
        if (vetor[meio].elem < b){
            esq = meio+1;
        }else{
            dir = meio-1;
        }
    }
    return -1;
}


int sana(Item *v, Item e1, Item e2, int n){

    if (e1.prox==e2.elem || e2.ant==e1.elem){
        return 1;
    }
    int x = bb(v, n, e1.prox);

    if (x==-1 || v[x].ant!=e1.elem){
        return 0;
    } 
    
    return sana(v, v[x], e2, n);
}


int main(){

    Item ptr1, ptr2;

    int i=0;

    while(scanf("%llx %llx %llx", &v[i].elem, &v[i].ant, &v[i].prox)!=EOF){
        i++;
    }

    ptr1 = v[0];
    ptr2 = v[1];

    quicksort(v, 0, i);
    
    if(sana(v, ptr1, ptr2, i)){
        printf("sana\n");
    }else{
        printf("insana\n");
    }
    
    return 0;
}