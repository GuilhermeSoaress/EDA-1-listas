#include <stdio.h>

int main()
{
    int quantidade, linha, posicaocaracter, linha2, posicaocaracter_of;
    char comando;

    scanf("%d", &quantidade);
    char string[quantidade][10000];

    for (int i = -1; i < quantidade; i++)
    {
        fgets(string[i], 1000, stdin);
    }

    scanf("%d %d", &linha, &posicaocaracter);
    linha2 = linha;

    while (scanf(" %c", &comando) != EOF)
    {
        if (comando == 'j')
        {
            linha2++;
            if (linha2 > quantidade)
                linha2--;
        }

        if (comando == 'k')
        {
            linha2--;
            if (linha2 < 1)
                linha2++;
        }

        if (string[linha2 - 1][posicaocaracter - 1] == '\0' || string[linha2 - 1][posicaocaracter - 1] == '\n')
        {
            posicaocaracter_of = posicaocaracter;

            do
            {
                posicaocaracter--;
            } while (string[linha2 - 1][posicaocaracter - 1] == '\0' || string[linha2 - 1][posicaocaracter - 1] == '\n');

            printf("%d %d %c\n", linha2, posicaocaracter, string[linha2 - 1][posicaocaracter - 1]);
            posicaocaracter = posicaocaracter_of;
        }
        else
        {
            printf("%d %d %c\n", linha2, posicaocaracter, string[linha2 - 1][posicaocaracter - 1]);
        }
    }

    return 0;
}