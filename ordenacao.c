#include <stdio.h>
#include <stdlib.h>


//ordenacao crescente
void ordenacao(int vet[], int tam)
{

    for (int i = 0; i <tam ; i++)
    { 
        for (int o=0; o<tam ; o++)
        {
            int aux;
            if (vet[i]<=vet[o])
            {
                aux = vet[i];
                vet[i] = vet[o];
                vet[o] = aux;
            }
        }
    }
    
}

void ord_decrescente(int vet[], int tam)
{

    for (int i = 0; i <tam ; i++)
    { 
        for (int o=0; o<tam ; o++)
        {
            int aux;
            if (vet[i]>=vet[o])
            {
                aux = vet[i];
                vet[i] = vet[o];
                vet[o] = aux;
            }
        }
    }
    
}

int main()
{
    int valor;

    printf("\nDigite o tamanho do vetor: ");
    scanf("%d",&valor);

    int vet[valor];

    for (int i=0; i< valor; i++)
    {
        printf("\nDigite o %d valor: ", i+1);
        scanf("%d",&vet[i]);
    }

    printf("\n\t\t");
    printf("\nOrdenacao  crescente");
    ordenacao(vet, valor);
    for (int i=0; i< valor; i++)
    {
        printf("\nindece: %d \tvalor: %d", i+1 ,vet[i]);
    }
    
    printf("\n\t\t");
    printf("\nOrdenacao  decrescente");
    ord_decrescente(vet, valor);
    for (int i=0; i< valor; i++)
    {
        printf("\nindece: %d \tvalor: %d", i+1 ,vet[i]);
    }

    return 0;
}