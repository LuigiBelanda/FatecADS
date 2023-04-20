#include <stdio.h>
#include <locale.h>

void print_array(int vet[], int vet_lenght);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int contador = 0, aux = 0;

    int vet[] = {1000, 19, 256, 99, 16, 32, 14, 13, 1240, 500, 10, 9, 8, 7, 6, 12345, 4, 3, 2, 1, 70, 90, 100, 67, 88, 22};
    int vet_lenght = sizeof(vet) / sizeof(vet[0]);

    printf("\n\nO vetor tem %d numeros\n", vet_lenght);

    // verifica tamanho do array
    if(vet_lenght >= 20 && vet_lenght <= 100)
    {
        // ve se tem números repetidos
        for(int i = 0; i < vet_lenght; i++)
        {
            for(int j = i + 1; j < vet_lenght; j++)
            {
                if(vet[i] == vet[j])
                {
                    printf("\nPos %d - num %d == Pos %d - num %d", i, vet[i], j, vet[j]);
                    contador++;
                }
            }
        }

        if(contador > 0)
        {
            printf("\n\nPor termos ocorrências de repetições de números não podemos continuar!");
        }
        else
        {
            // print array original
            printf("\n\n\nArray original\n");
            print_array(vet, vet_lenght);

            // ordenando vetor - ordem crescente
            for(int i = 0; i < vet_lenght; i++)
            {
                for(int j = i + 1; j < vet_lenght; j++)
                {
                    if(vet[i] > vet[j])
                    {
                        aux = vet[j];
                        vet[j] = vet[i];
                        vet[i] = aux;
                    }
                }
            }

            // print array ordenado
            printf("\n\n\nArray ordenado\n");
            print_array(vet, vet_lenght);
        }
    }
    else
    {
        printf("\n\nInfelizmente só aceitamos no mínimo 20 números no array e no máximo 100\n\n");
    }

    printf("\n");
    return 0;
}

void print_array(int vet[], int vet_lenght)
{
    for(int i = 0; i < vet_lenght; i++)
    {
        printf("\nPosição %d -- número %d", i, vet[i]);
    }
}
