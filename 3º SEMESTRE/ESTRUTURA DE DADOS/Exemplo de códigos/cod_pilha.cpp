#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct aluno {
    int ra;
    char nome [30];
    aluno *prox;
};

int main(){
    setlocale(LC_ALL, "Portuguese"); //definição de linguagem para português
    aluno *topo = NULL, *aux;
    int op;

    do {
        printf ("\n1: Adicionar | 2: Listar | 3: Remover | 4: Limpar | 5: Sair: ");
        scanf ("%d", &op);

        switch (op){
            case 1:
                //alocando espaço na memória e guardando dados do usuário
                aux = (aluno*) malloc (sizeof(aluno));
                printf ("Digite o RA do aluno: ");
                scanf ("%d", &aux->ra);
                printf ("\nDigite o Nome do aluno: ");
                scanf ("%s", &aux->nome);

                //colocar o novo elemento no topo:
                aux->prox = topo;
                topo = aux;
            break;
            case 2:
                if (topo == NULL) //verifica se existe elemetos
                    printf ("\nNão existe elemento na pilha\n");
                else {
                    aux = topo; //posiciona auxiliar no topo
                    while (aux != NULL){ //percorre elementos até o fim
                        //printa os elementos
                        printf ("\nRA: %d", aux->ra);
                        printf ("\nNome: %s\n\n", aux->nome);
                        aux = aux->prox; //posiciona aux no próximo
                    }
                }
            break;
            case 3:
                if (topo == NULL) //verifica se existe elemetos
                        printf ("\nNão existe elemento na pilha");
                else {
                    aux = topo;
                    topo = topo->prox;
                    free(aux);
                }
            break;
            case 4:
                if (topo == NULL) //verifica se existe elemetos
                    printf ("\nNão existe elemento na pilha");
                else {
                    while (topo != NULL){
                        aux = topo;
                        topo = topo->prox;
                        free (aux);
                    }
                }
            break;
            case 5:
                printf ("\n\nSaindo do sistema");
            break;
            default:
                    printf ("\nDigite uma opção válida (1 a 5)");
            break;

        }

    }while (op != 5);

}