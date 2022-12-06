#include <stdio.h>
#include <stdlib.h>


int fat(int numero)
{
    if (numero<1)
    {
        return 1;
    }
    else
    {
        return numero * fat(numero-1);
    }
}

int main()
{
    int valor;

    printf("\nDigite o valor que voce quer o fatorial: ");
    scanf("%d",&valor);

    printf("\nResultado: %d", fat(valor));

    return 0;
}
