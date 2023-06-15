#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int num = 0, qtd_pares = 0, qtd_impares = 0, qtd_primos = 0, contador_de_divisores = 0;

    printf("Escolha um número entre 0 e 100: ");
    scanf("%d%*c", &num);

    // verificando se é um número de 0 a 100, nem menor que 0, nem maior que 100
    if(num >= 0 && num <= 100)
    {
        // verificando se o num é == 0
        if(num == 0)
        {
            printf("\n0 (zero) é um número neutro!");
        }
        else
        {
            // pegando nums pares, impares e primos
            printf("\n\n");
            for(int i = 1; i <= num; i++)
            {
                // pares
                if(i % 2 == 0)
                {
                    printf("\nNum (%d) - PAR", i);
                    qtd_pares++;
                }
                // impares
                else
                {
                    printf("\nNum (%d) - IMPAR", i);
                    qtd_impares++;
                }

                // primos
                for(int j = 1; j <= num; j++)
                {
                    if(i % j == 0)
                    {
                        contador_de_divisores++;
                    }
                }

                if(contador_de_divisores == 2)
                {
                    printf("\nNum (%d) - PRIMO", i);
                    qtd_primos++;
                }

                contador_de_divisores = 0;
            }

            // qtd de tudo
            printf("\n\nQtd de nums pares = %d", qtd_pares);
            printf("\nQtd de nums impares = %d", qtd_impares);
            printf("\nQtd de nums primos = %d", qtd_primos);
        }
    }
    else
    {
        printf("\n\nInfelizmente só aceitamos números ENTRE 0 e 100!");
    }

    printf("\n");
    return 0;
}
