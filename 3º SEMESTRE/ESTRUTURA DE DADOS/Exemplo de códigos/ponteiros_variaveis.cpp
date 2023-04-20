#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Portuguese"); //definição de linguagem para português
    //ponteiro = (int *)malloc (sizeof(int));
    int *p;
    p = (int *)malloc (sizeof(int));
    printf ("Endereço de b: %p", &p);
    printf ("\nEndereço onde p aponta: %p", p);
    printf ("\nValor aramzenado onde P aponta: %d", *p);
    printf ("\n\n\n\n\n---------------------");
    printf ("\nDigite um novo valor pra *p: ");
    scanf ("%d", &*p);
    printf ("\nEndereço de b: %p", &p);
    printf ("\nEndereço onde p aponta: %p", p);
    printf ("\nValor aramzenado onde P aponta: %d", *p);

    /*Nesse caso se eu trocar o endereço para onde P aponta, eu perco a referência do dado e ele fica
    perdido na memória*/
    int a;
    p = &a;
    printf ("\n\n\n\n\n\n----------------------");
    printf ("\nPerdi a referência do dado antigo de b, dessa forma não consigo mais recuperar o endereço antigo");
    printf ("\nEndereço de b: %p", &p);
    printf ("\nEndereço onde p aponta: %p", p);
    printf ("\nValor armazenado onde P aponta: %d", *p);
    free (p);
    return (0);

}