#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Aluno
{
    int ra;
    Aluno *prox;
};

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Ponteiros
    Aluno *inicio = NULL;
    Aluno *fim;
    Aluno *aux;

    int op;

    do
    {
        printf("\nO que você deseja fazer?: ");
        printf("\n\n1 - Adicionar");
        printf("\n2 - Listar");
        printf("\n3 - Remover");
        printf("\n4 - Limpar tudo");
        printf("\n5 - Sair");
        printf("\n\nFaça sua escolha: ");
        scanf("%d%*c", &op);

        // Adicionar
        if (op == 1)
        {
            aux = (Aluno *) malloc(sizeof(Aluno));

            printf("\n\nDigite o RA: ");
            scanf("%d%*c", &aux->ra);

            if(inicio == NULL)
            {
                aux->prox = NULL;
                inicio = aux;
            }
            else
            {
                fim->prox = aux;
            }

            fim = aux;
        }
        // listar
        else if(op == 2)
        {
            if(inicio == NULL)
            {
                printf("\n\nNão existem elementos na fila!\n\n");
            }
            else
            {
                aux = inicio;

                printf("\n\nLISTANDO TODOS OS ELEMENTOS\n");

                while(aux != NULL)
                {
                    printf("\nRA: %d", aux->ra);
                    aux = aux->prox;
                }

                printf("\n\n");
            }
        }
        // remover um elemento
        else if(op == 3)
        {
            if(inicio == NULL)
            {
                printf("\n\nNão existem elementos na fila!\n\n");
            }
            else if(inicio == fim)
            {
                free(inicio);
                inicio = NULL;
                fim = NULL;
            }
            else
            {
                aux = inicio;
                inicio = inicio->prox;
                free(aux);
            }
        }
        // limpar tudo
        else if(op == 4)
        {
            if(inicio == NULL)
            {
                printf("\n\nNão existem elementos na fila!\n\n");
            }
            else if(inicio == fim)
            {
                free(inicio);
                inicio = NULL;
                fim = NULL;
            }
            else
            {
                while(inicio != NULL)
                {
                    aux = inicio;
                    inicio = inicio->prox;
                    free(aux);
                }

                fim = NULL;
            }
        }
        else if(op == 5)
        {
            break;
        }
    } while(op != 5);

    printf("\n\n");
    getchar();
    return 0;
}


