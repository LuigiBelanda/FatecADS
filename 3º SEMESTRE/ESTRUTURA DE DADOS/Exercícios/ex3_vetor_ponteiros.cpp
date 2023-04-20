#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void dados_ponteiro(int tamanho_vetor, int *ponteiro);
void pegando_dados(int tamanho_vetor, int *ponteiro);
void ordena_vetor(int tamanho_vetor, int *ponteiro);
void mostra_dados_vetor(int tamanho_vetor, int *ponteiro);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int *ponteiro;
    int tamanho_vetor;

    do
    {
        // Tamanhao do vetor
        printf("Tamanho do vetor que você deseja (precisa ser algo igual ou maior que 20 e menor ou igual a 100): ");
        scanf("%d%*c", &tamanho_vetor);

        // Verificação se o tamamnho do vetor está entre 20 e 100
        if(tamanho_vetor >= 20 && tamanho_vetor <= 100)
        {
            // alocando a memória com o malloc para a criação das posições do vetor
            ponteiro = (int *) malloc (tamanho_vetor * sizeof(int));

            // Verifica se conseguiu ou não a posição de memória
            if(ponteiro == NULL)
            {
                printf("\n\nSem posição de memória disponível. O programa será encerrado!\n\n");
                exit(1);
            }

            dados_ponteiro(tamanho_vetor, ponteiro);
            pegando_dados(tamanho_vetor, ponteiro);

            printf("\n\n\n############# MOSTRANDO DADOS - VETOR ORIGINAL #############\n\n");
            mostra_dados_vetor(tamanho_vetor, ponteiro);

            ordena_vetor(tamanho_vetor, ponteiro);

            printf("\n\n\n############# MOSTRANDO DADOS - VETOR ORDENADO #############\n\n");
            mostra_dados_vetor(tamanho_vetor, ponteiro);
        }
    } while(tamanho_vetor < 20 || tamanho_vetor > 100);

    free(ponteiro);

    printf("\n\n");
    getchar();
    return 0;
}

void dados_ponteiro(int tamanho_vetor, int *ponteiro)
{
    // Endereço de memória do ponteiro
    printf("\n\n\n\n############# ENDEREÇO DE MEMÓRIA DO PONTEIRO #############\n\n");
    printf("Endereço de memória do ponteiro: %x", &ponteiro);

    // ConteÚdo do ponteiro - endereço de memória que ele está apontando
    printf("\n\n\n\n############# CONTEÚDO DO PONTEIRO - ONDE ESTÁ APONTANDO #############\n\n");
    printf("Endereço de memória para onde o ponteiro está apontando: %x", ponteiro);

    // verificando os endereços de memória reservados para o vetor
    printf("\n\n\n\n############# ENDEREÇO DE MEMÓRIA DAS POSIÇÕES CRIADAS COM O MALLOC #############\n");
    for(int i = 0; i < tamanho_vetor; i++)
    {
        printf("\nEndereço de memória da posição [ %d ] = %x", i, &ponteiro[i]);
    }
}

void pegando_dados(int tamanho_vetor, int *ponteiro)
{
    int numeros_digitados[tamanho_vetor];
    int contador = 0, numero;
    bool numero_duplicado;

    // verificando os dados em cada posição do vetor e testando se o ponteiro está certp
    printf("\n\n\n\n############# COLOCANDO DADOS PELO PONTEIRO #############\n\n");

    for(int i = 0; i < tamanho_vetor; i++)
    {
        do
        {
            numero_duplicado = false;

            printf("Posição [ %d ] - Endereço de memória [ %x ] = ", i, &ponteiro[i]);
            scanf("%d%*c", &numero);

            // verifica se  o numero já fi digitado anteriormente
            for (int j = 0; j < contador; j++) {
                if (numeros_digitados[j] == numero) {
                    printf("\nO número %d já foi digitado anteriormente, por favor digite outro número.\n\n", numero);
                    numero_duplicado = true;
                    break;
                }
            }
        } while (numero_duplicado == true);

        // adicionando o número ao vetor auxiliar e ao vetor principal
        numeros_digitados[contador] = numero;
        ponteiro[i] = numero;

        contador++;
    }
}

void ordena_vetor(int tamanho_vetor, int *ponteiro)
{
    int aux;

    // Ordenando de forma crescente
    for(int i = 0; i < tamanho_vetor; i++)
    {
        for(int j = i + 1; j < tamanho_vetor; j++)
        {
            if(ponteiro[i] > ponteiro[j])
            {
                aux = ponteiro[i];
                ponteiro[i] = ponteiro[j];
                ponteiro[j] = aux;
            }
        }
    }
}

void mostra_dados_vetor(int tamanho_vetor, int *ponteiro)
{
    // Mostrando dados do vetor
    for(int i = 0; i < tamanho_vetor; i++)
    {
        printf("\nPosição [ %d ] - Endereço de memória [ %x ] = %d", i, &ponteiro[i], ponteiro[i]);
    }
}
