#include<stdio.h>
#include<stdlib.h>

    typedef int Item;

    #define less(A,B) (A<B) //macro para compara se o número A é menor que o número B
    #define exch(A,B) {Item tt = A;\
                             A=B;\
                             B=tt;\
                            } //macro que troca o valor de A por B
    #define cmpexch(A,B) {if(less(B,A)) exch(A,B)} //macro que troca os valores se B for maior que A
    #define eq(A,B) (A==B) //macro que ve se A e B são iguais

//int vetor[7]={86,15,3,25,37,42,13}; vetor fixo para teste

    //v é o vetor 
    //l é o valor mais a esquerda do vetor
    //r é o valor mais a direita do vetor 
void selectionsort(Item *v, int l, int r){
    for(int i=l; i<r ; i++){
        int min =i;
        for(int j= i+1; j<= r;j++){//for onde o j assume o valor de l+1; ir ate o j ser igual ao r
            if(less(v[j],v[min])){//compara se j(o elemento a direita do l) é maior que o i
                min =j;// troca o valor de j por se o elemento for menor que o l
            }
        }
        exch(v[i],v[min]);//troca os valores termo da direita pelo da esquerda, pois esse par ja esta ordenado
    }
}

void bubblesort(Item *v, int l, int r){
    for(int i=l; i<r; i++){// cria um laço para percorrer todo o vetor
        for(int j=l; j<r;j++){// cria um laço para realizar as interações
            if(less(v[j+1],v[j])){//compara o dois termos , o da frente com o de tras
                exch(v[j+1],v[j]);//ordena os termos 
            }
        }
    }
}

void insertionsort(Item *v, int l , int r){
    for(int i=r; i>l; i--){//cria um laço começando do ultimo termo a direita 
        cmpexch(v[i-1],v[i]);//troca os termos se o da direita for menor que o da esquerda
    }
    for(int i= l+2; i<=r;i++){//cria um laço com o terceiro termo do vetor para compara os dois anteriores
        Item m= v[i]; 
        int j= i;
        while(less(m,v[j-1])){//cria um laço comparando o termo l+1 com o l+2
            v[j]=v[j-1];//troca o termo l+2 pelo l+1 se ele for menor 
            j--;
        }
        v[j]=m;//troca o valor de v[l+1] por v[l+2]
    }
}

int bb(Item *v,int l , int r,Item b){//busca binaria , Item b é o número a ser procurado 
    if(r<l){
        return printf("-1");//se rodar todo o vetor e não achar o Item b printa -1
    }
    int meio = (l+r)/2;
    if(eq(b,v[meio])){
        return printf("%d\n",&v[meio]);//achou printa o local de memória dele
    }else if(less(b,v[meio])) {//divide o vetor na parte a esquerda para procurar o número , esse laço divide quantas vezes for necessaria ate achar o b ou terminar  vetor
        return bb(v,l,meio-1,b);//chama a busca binaria com a metadade a esquerda do vetor
    }else if(less(v[meio],b)){//divide o vetor na parte a direita para procurar o número , esse laço divide quantas vezes for necessaria ate achar o b ou terminar  vetor
        return bb(v,meio+1,r,b);//chama a busca binaria com a metadade a direita do vetor
    }
}

void merge(Item *v, int l ,int m ,int r){
    int ia= l, ib= m+1;
    Item *aux = (Item*)malloc(sizeof(Item)*(r-l+1));
    int iaux= 0;
    while(ia<=m && ib <= r){
        if(less(v[ib],v[ia])){
            aux[iaux++]=v[ib++];
        }else{
            aux[iaux++] =v[ia++];
        }
    }while(ia<=m){
        aux[iaux++]=v[ia++];
    }while(ib<=r){
        aux[iaux++]=v[ib++];
    }
    for(int i= 0; i< r-l+1;i++){
        v[l++] =aux[i];
    }
}

void mergesort(Item *v,int l, int r){
    if(r-l==0){
        return ;
    }
    int m =(r+l)/2;
    mergesort(v,l,m);
    mergesort(v,m+1,r);
    merge(v,l,m,r);
    
}

int main(){
    int n;//tamanho do vetor
    scanf("%d",&n);//escolhe o tamnho do vetor
    int vetor[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&vetor[i] );//preenche o valor da posição i
    }
    //Apenas tire o comit da função que for usar 
    //selectionsort(vetor,0,n);
    //bubblesort(vetor,0, n);
    //insertionsort(vetor,0,n);
    for(int i=0;i<n;i++)//printa o vetor
    {
        printf("%d\n",vetor[i]);
    }
    int x;
    scanf("%d",&x);//escolhe o número que vai ser procurado pela busca binaria
    bb(vetor,0,n,x);
}