#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

typedef struct estrutura {
    int codigo;
    int ra;
};
int main()
{
    setlocale(LC_ALL, "Portuguese"); //definição de linguagem para português

    int *ponteiro; //criação do ponteiro tipo inteiro
    ponteiro = (int *)malloc (sizeof(int));
    *ponteiro = 10;
    printf ("%d", *ponteiro);

    estrutura *novo; //criação do ponteiro tipo estrutura
    novo = (estrutura *)malloc (sizeof(estrutura)); //alocação de espaço de memória para a esturura
    novo->codigo = 5; //armazenando valor no campo código
    novo->ra = 2022; //armazenando valor do campo RA

    //prints de dados
    printf ("\nCodigo do aluno: %d", novo->codigo);
    printf ("\nRA do aluno: %d", novo->ra);
    //liberar espaço utilizado na memória
    free (novo);
    free (ponteiro);
}
