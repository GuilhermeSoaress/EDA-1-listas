int faz_conta_direito(int parcelas, char op){
    int ci[parcelas];
    int result = 0;
    
    if (op == '+'){
        for (int i=0; i<parcelas; i++){
            scanf("%d", &ci[i]);
            result += ci[i];
        }
    }

    if (op == '-'){
    
        for (int i=0; i<parcelas; i++){
            scanf ("%d", &ci[i]);
            result -= ci[i];
        }
        result = result + 2 * ci[0];
    }
    return result;
}

int main(){
    int n = faz_conta_direito(4, '+');
    printf("%d", n);
}