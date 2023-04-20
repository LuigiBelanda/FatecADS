#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Portuguese"); //definição de linguagem para português
    //declaração de variáveis locais
    float *ponteiro; //variável para armazenar endereço de memória onde a infrmação será salva
    int i, tam; //armazena o número de elemetos do vetor
    //solicita o número de posições do vetor
    printf ("\nDigite o número de posições que terá o vetor: ");
    scanf ("%d", &tam);
    //multiplicando as posições pelo sizeof o sistema cria um valor unidimensional
    ponteiro = (float*) malloc (tam * sizeof(tam));
    //a partir daqui se trabalha como um vetor normal
    for (i = 0; i < tam; i++){
        printf ("\nDigite o valor do elemento [%d]: ", i);
        scanf ("%f", &ponteiro[i]);
    }
    //escrever elementos armazenado no vetor
    printf ("\n\n\n-----------------------\n\n\n");
    for (i = 0; i < tam; i++){
        printf ("\nElemento [%d] - Memória (%p): %.2f", i, &ponteiro[i], ponteiro[i]);
    }
    free (ponteiro);
    return 0;
}
