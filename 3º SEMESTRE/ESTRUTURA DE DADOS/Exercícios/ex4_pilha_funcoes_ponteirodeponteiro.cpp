#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct aluno{
    int ra;
    aluno *prox;
};

void adicionar(aluno **t);
void listar(aluno **t);
void remover(aluno **t);
void limpar(aluno **t);

int main()
{
    aluno *topo = NULL, *aux;
    int op;

    do
    {
        printf("\n[1] - Adicionar \n[2] - Listar \n[3] - Remover \n[4] - Limpar \n[5] - Sair\nQual opção deseja: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                adicionar(&topo);
                break;
            case 2:
                listar(&topo);
                break;
            case 3:
                remover(&topo);
                break;
            case 4:
                limpar(&topo);
                break;
            case 5:
                printf("\n\nSaindo do sistema...\n");
                break;
        }
    }while(op != 5);

    return 0;
}

void adicionar(aluno **t)
{
    aluno *novo = (aluno*) malloc(sizeof(aluno));

    printf("\nDigite o RA do aluno: ");
    scanf("%d", &novo->ra);

    novo->prox = *t;
    *t = novo;
}

void listar(aluno **t)
{
    aluno *topo = NULL, *aux;

    if(*t == NULL){
        printf("\n\nSEM REGISTROS\n");
    }
    else
    {
        aux = *t;

        while(aux != NULL)
        {
            printf("\nRA: %d", aux->ra);
            aux = aux->prox;
        }
    }

    printf("\n");
}

void remover(aluno **t)
{
    aluno *topo = NULL, *aux;

    if(*t == NULL)
    {
        printf("\n\nSEM REGISTROS\n");
    }
    else
    {
        aux = *t;
        *t = aux -> prox;
        free(aux);
    }
}

void limpar(aluno **t)
{
    aluno *topo = NULL, *aux;
    aluno *prox;

    if(*t == NULL)
    {
        printf("\n\nSEM REGISTROS\n");
    }
    else
    {
        while(*t != NULL)
        {
            aux = *t;
            *t = aux->prox;
            free(aux);
        }
    }
}
